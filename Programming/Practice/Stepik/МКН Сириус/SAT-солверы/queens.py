from pycosat import solve
from itertools import combinations, product
import sys

N = 8

def varnum(row, column):
	return 100 * row + 10 * column + 1


def exactly_one_of(literals):
	clauses = [[l for l in literals]]
	for pair in combinations(literals, 2):
		clauses.append([-l for l in pair])
	return clauses


def one_digit_in_every_row():
	clauses = []
	for row in range(N):
		clauses += exactly_one_of([varnum(row, column)
								   for column in range(N)])
	return clauses


def one_digit_in_every_column():
	clauses = []
	for column in range(N):
		clauses += exactly_one_of([varnum(row, column)
								   for row in range(N)])
	return clauses


def one_digit_in_every_diagonal():
	clauses = []

	for i in range(N - 1):
		clauses += exactly_one_of(
			[varnum(j, i + j) for j in range(N - i)]
		)

	for i in range(1, N - 1):
		clauses += exactly_one_of(
			[varnum(j + i, j) for j in range(N - i)]
		)

	for i in range(N - 1):
		clauses += exactly_one_of(
			[varnum(j, N - 1 - (i + j)) for j in range(N - i)]
		)

	for i in range(1, N - 1):
		clauses += exactly_one_of(
			[varnum(j + i, N - 1 - j) for j in range(N - i)]
		)

	return clauses


def solve_puzzle(puzzle):
	clauses = []

	clauses += one_digit_in_every_row()
	clauses += one_digit_in_every_column()
	clauses += one_digit_in_every_diagonal()

	solution = solve(clauses)

	if isinstance(solution, str):
		return None

	result = []
	for row in range(N):
		current_row = []
		for column in range(N):
			if varnum(row, column) in solution:
				current_row.append("*")
			else:
				current_row.append("X")
		result.append(current_row)
	return result


n = int(input())

puzzle = [["*" for _ in range(n)] for _ in range(n)]
result = solve_puzzle(puzzle)

if result:
	print("\n".join(["".join([str(e) for e in element]) for element in result]))
else:
	print(-1)