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
	for row in range(N):
		clauses += exactly_one_of([varnum(row, column)
								   for column in range(N)])
	return clauses


def one_digit_in_every_column(N):
	clauses = []
	for column in range(N):
		clauses += exactly_one_of([varnum(row, column)
								   for row in range(N)])
	return clauses


def one_digit_in_every_diagonal(N):
	clauses = []
	
	# diagonal = [(0, 0), (1, 1), (7, 7)]	[(1, 0), (2, 1), (3, 2)]
	# Correct

	for row in range(N - 1):
		clauses += one_or_zero_of([varnum(row + i, i) for i in range(N) if (row + i < N) and (i < N)])

	# diagonal = [([(0, 1), (1, 2)] 		diagonal = [(0, 2), (1, 3)]
	# Correct

	for column in range(1, N - 1):
		clauses += one_or_zero_of([varnum(i, column + i) for i in range(N) if (column + i < N) and (i < N)])
	
	# diagonal = [(8, 1), (7, 2)]		diagonal = [(8, 2), (7, 3)]
	# Correct

	for column in range(N):
		clauses += one_or_zero_of([varnum(N - i, column + i) for i in range(N) if (column + i < N) and (N - i >= 0)])

	# diagonal = [(2, 1), (1, 2)]		diagonal = [(3, 1), (2, 2), (1, 3)]
	# Correct

	for row in range(1, N):
		clauses += one_or_zero_of([varnum(row - i, i) for i in range(N) if (row - i >= 0) and (i < N)])

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
	for row in range(n):
		for column in range(n):
			if varnum(row, column) in solution:
				result.append(column)
	return result


def check_pair(first, second):
	x1, y1 = first
	x2, y2 = second
	return not((x1 == x2) or (y1 == y2) or (abs(x1 - x2) == abs(y1 - y2)))


def check(result):
	for x1, y1 in enumerate(result):
		first_pair = (x1, y1)
		for x2, y2 in enumerate(result[x1 + 1:]):
			second_pair = (x1 + 1 + x2, y2)
			if not check_pair(first_pair, second_pair):
				return False
	return True


if __name__ == "__main__":
	n = int(input())

	result = solve_puzzle(n)
	if result:
		print(" ".join([str(e) for e in result]))
		print(check(result))