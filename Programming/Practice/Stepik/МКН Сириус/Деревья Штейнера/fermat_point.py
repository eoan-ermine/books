def line_intersection(line1, line2):
    xdiff = (line1[0][0] - line1[1][0], line2[0][0] - line2[1][0])
    ydiff = (line1[0][1] - line1[1][1], line2[0][1] - line2[1][1])

    def det(a, b):
        return a[0] * b[1] - a[1] * b[0]

    div = det(xdiff, ydiff)
    if div == 0:
       raise Exception('lines do not intersect')

    d = (det(*line1), det(*line2))
    x = det(d, xdiff) / div
    y = det(d, ydiff) / div
    return x, y


def distance(point1, point2):
	x1, y1 = point1
	x2, y2 = point2
	return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5


x1, y1, x2, y2, x3, y3 = map(int, input().split())

A = (x1, y1)
B = (x2, y2)
C = (x3, y3)

base = distance(B, C)

A_left = (A[0] - base, A[1])
A_right = (A[0] + base, A[1])

line1 = (A_left, C)
line2 = (A_right, B)

print(line_intersection(line1, line2))