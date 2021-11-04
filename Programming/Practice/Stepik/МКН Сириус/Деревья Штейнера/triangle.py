import math


def distance(point1, point2):
	x1, y1 = point1
	x2, y2 = point2
	return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5


x1, y1, x2, y2 = map(int, input().split())

A = (x1, y1)
B = (x2, y2)

side = distance(A, B)
angle = 1.0471975511965977461542144610931676280657231331250352736583148641

C = (
	round(A[0] + math.cos(angle) * side, 6),
	round(A[1] + math.sin(angle) * side, 6)
)


print("{:06} {:06}".format(C[0] if C[0] != -0 else -C[0], C[1]))