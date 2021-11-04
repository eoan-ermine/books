from pycosat import solve
from itertools import combinations
import sys


def varnum(row, column):
	return 8 * row + column + 1


def zero_of(literals):
	clauses = [[l for l in literals]]
	clauses.extend([-l] for l in literals)
	return clauses


def exactly_one_of(literals):
	clauses = [[l for l in literals]]
	for pair in combinations(literals, 2):
		clauses.append([-l for l in pair])
	return clauses


def one_or_zero_of(literals):
	clauses = [[l for l in literals] + [-l for l in literals]]
	for pair in combinations(literals, 2):
		clauses.append([-l for l in pair])
	clauses.append([-l for l in literals])
	return clauses


def one_digit_in_every_row(N):
	clauses = []
	for row in range(1, N + 1):
		clauses += exactly_one_of([varnum(row, column)
								   for column in range(1, N + 1)])
	return clauses


def one_digit_in_every_column(N):
	clauses = []
	for column in range(1, N + 1):
		clauses += exactly_one_of([varnum(row, column)
								   for row in range(1, N + 1)])
	return clauses


def one_digit_in_every_diagonal(N):
	clauses = []
	
	# diagonal = [(1, 1), (2, 2) ...]	diagonal = [(2, 1), (3, 2)]
	# Correct

	for row in range(1, N):
		clauses += one_or_zero_of([varnum(row + i, 1 + i) for i in range(0, N) if (row + i <= N) and (1 + i <= N)])

	# diagonal = [(1, 2), (2, 3)] 		diagonal = [(1, 3), (2, 4)]
	# Correct

	for column in range(2, N):
		clauses += one_or_zero_of([varnum(1 + i, column + i) for i in range(0, N) if (column + i <= N) and (1 + i <= N)])
	
	# diagonal = [(8, 1), (7, 2)]		diagonal = [(8, 2), (7, 3)]
	# Correct

	for column in range(1, N):
		clauses += one_or_zero_of([varnum(N - i, column + i) for i in range(0, N) if (column + i <= N) and (8 - i >= 1)])

	# diagonal = [(2, 1), (1, 2)]		diagonal = [(3, 1), (2, 2), (1, 3)]
	# Correct

	for row in range(2, N):
		clauses += one_or_zero_of([varnum(row - i, 1 + i) for i in range(0, N) if (row - i >= 1) and (1 + i <= N)])

	return clauses


def solve_puzzle(n):
	clauses = []

	clauses += one_digit_in_every_row(n)
	clauses += one_digit_in_every_column(n)
	clauses += one_digit_in_every_diagonal(n)

	solution = solve(clauses)
	if isinstance(solution, str):
		return None

	result = []
	for row in range(1, n + 1):
		for column in range(1, n + 1):
			if varnum(row, column) in solution:
				result.append(column - 1)
	return result

if __name__ == "__main__":
	n = int(input())

	result = solve_puzzle(n)
	if result:
		print(" ".join([str(e) for e in result]))
	else:
		print(-1)