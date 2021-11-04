import math
import sys


def output(point):
	print("{:.6} {:.6}".format(point[0] if point[0] != -0 else -point[0], C[1]))


def distance(point1, point2):
	x1, y1 = point1
	x2, y2 = point2
	return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5


def relation(A, B, C):
	x1, y1 = A
	x2, y2 = B
	x3, y3 = C

	rel = (x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)
	if rel < 0:
		return -1
	if rel > 0:
		return 1
	return 0


x1, y1, x2, y2 = map(int, input().split())

A = (x1, y1)
B = (x2, y2)

side = distance(A, B)
angle = 1.0471975511965977461542144610931676280657231331250352736583148641

zero_relation = relation(A, B, (0,0))

C = (
	round(A[0] + math.cos(angle) * side, 6),
	round(A[1] + math.sin(angle) * side, 6)
)
output(C)