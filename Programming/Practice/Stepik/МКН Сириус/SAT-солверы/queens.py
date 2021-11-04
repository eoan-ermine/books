from pycosat import solve
from itertools import combinations, product
import sys


def varnum(row, column):
	return 100 * row + 10 * column


def exactly_one_of(literals):
	clauses = [[l for l in literals]]
	for pair in combinations(literals, 2):
		clauses.append([-l for l in pair])
	return clauses


def one_digit_in_every_row():
	clauses = []
	for row in range(1, 10):
		clauses += exactly_one_of([varnum(row, column)
								   for column in range(1, 10)])
	return clauses


def one_digit_in_every_column():
	clauses = []
	for column in range(1, 10):
		clauses += exactly_one_of([varnum(row, column)
								   for row in range(1, 10)])
	return clauses


def one_digit_in_every_diagonal():
	clauses = []
	
	# diagonal = [(1, 1), (2, 2) ...]	diagonal = [(2, 1), (3, 2)]
	# Correct

	for row in range(1, 8):
		clauses += exactly_one_of([varnum(row + i, 1 + i) for i in range(0, 8) if (row + i <= 8) and (1 + i <= 8)])

	# diagonal = [(1, 2), (2, 3)] 		diagonal = [(1, 3), (2, 4)]
	# Correct

	for column in range(2, 8):
		clauses += exactly_one_of([varnum(1 + i, column + i) for i in range(0, 8) if (column + i <= 8) and (1 + i <= 8)])
	
	# diagonal = [(8, 1), (7, 2)]		diagonal = [(8, 2), (7, 3)]
	# Correct

	for column in range(1, 8):
		clauses += exactly_one_of([varnum(8 - i, column + i) for i in range(0, 8) if (column + i <= 8) and (8 - i >= 1)])


	# diagonal = [(2, 1), (1, 2)]		diagonal = [(3, 1), (2, 2), (1, 3)]

	for row in range(2, 8):
		clauses += exactly_one_of([varnum(row - i, 1 + i) for i in range(0, 8) if (row - i >= 1) and (1 + i <= 8)])

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
	for row in range(1, 10):
		current_row = []
		for column in range(1, 10):
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