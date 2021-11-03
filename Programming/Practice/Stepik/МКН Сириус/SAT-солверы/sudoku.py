from pycosat import solve
from itertools import combinations, product
import sys


def varnum(row, column, digit):
	return 100 * row + 10 * column + digit


def exactly_one_of(literals):
	clauses = [[l for l in literals]]
	for pair in combinations(literals, 2):
		clauses.append([-l for l in pair])
	return clauses


def one_digit_in_every_cell():
	clauses = []
	for row, column in product(range(1, 10), repeat=2):
		clauses += exactly_one_of([varnum(row, column, digit)
								   for digit in range(1, 10)])
	return clauses


def one_digit_in_every_row():
	clauses = []
	for row, digit in product(range(1, 10), repeat=2):
		clauses += exactly_one_of([varnum(row, column, digit)
								   for column in range(1, 10)])
	return clauses


def one_digit_in_every_column():
	clauses = []
	for column, digit in product(range(1, 10), repeat=2):
		clauses += exactly_one_of([varnum(row, column, digit)
								   for row in range(1, 10)])
	return clauses


def one_digit_in_every_block():
	clauses = []
	for row, column in product([1, 4, 7], repeat=2):
		for digit in range(1, 10):
			clauses += exactly_one_of(
				[varnum(row + a, column + b, digit)
				 for (a, b) in product(range(3), repeat=2)]
			)
	return clauses


def solve_puzzle(puzzle):
	clauses = []
	clauses += one_digit_in_every_cell()
	clauses += one_digit_in_every_row()
	clauses += one_digit_in_every_column()
	clauses += one_digit_in_every_block()

	for row, column in product(range(1, 10), repeat=2):
		if puzzle[row - 1][column - 1] != "*":
			digit = int(puzzle[row - 1][column - 1])
			clauses += [[varnum(row, column, digit)]]

	solution = solve(clauses)

	if isinstance(solution, str):
		return None

	result = []
	for row in range(1, 10):
		current_row = []
		for column in range(1, 10):
			for digit in range(1, 10):
				if varnum(row, column, digit) in solution:
					current_row.append(digit)
		result.append(current_row)
	return result


puzzle = [list(e.strip()) for e in sys.stdin.readlines()]
result = solve_puzzle(puzzle)

if result:
	print("\n".join(["".join([str(e) for e in element]) for element in result]))
else:
	print(-1)