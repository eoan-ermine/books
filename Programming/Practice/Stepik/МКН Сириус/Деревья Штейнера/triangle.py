import math
import sys


def output(point):
	print("{} {}".format(point[0] if point[0] != -0 else -point[0], C[1]))


def distance(point1, point2):
	x1, y1 = point1
	x2, y2 = point2
	return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5


def is_opposite_sides(a, b, f, t):
	ax, ay = a
	bx, by = b

	x1, y1 = f
	x2, y2 = t

	return ((y1 - y2) * (ax - x1) + (x2 - x1) * (ay - y1)) * ((y1 - y2) * (bx - x1) + (x2 - x1) * (by - y1)) < 0


def get_point(A, B, right):
	dx = B[0] - A[0]
	dy = B[1] - A[1]
	length = (dx * dx + dy*dy) ** 0.5

	dirX = dx / length
	dirY = dy / length

	height = (3 ** 0.5) / 2 * length

	cx = A[0] + dx * 0.5
	cy = A[1] + dy * 0.5

	pDirX = -dirY
	pDirY = dirX

	rx = 0
	ry = 0

	if right:
		rx = cx + height * pDirX
		ry = cy + height * pDirY
	else:
		rx = cx - height * pDirX
		ry = cy - height * pDirY

	return (round(rx, 6), round(ry, 6))


x1, y1, x2, y2 = map(int, input().split())

A = (x1, y1)
B = (x2, y2)

side = distance(A, B)
angle = 1.0471975511965977461542144610931676280657231331250352736583148641

zero = (0, 0)

C = get_point(A, B, False)
if is_opposite_sides(zero, C, A, B):
	output(C)
else:
	C = get_point(A, B, True)
	if is_opposite_sides(zero, C, A, B):
		output(C)