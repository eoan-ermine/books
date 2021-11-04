import math


def distance(point1, point2):
	x1, y1 = point1
	x2, y2 = point2
	return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5


def fermatPoint(points):
	sides = []
	for i in range(len(points)):
		sides.append(distance(points[i], points[(i + 1) % len(points)]))
	squared_sides = [side ** 2 for side in sides]

	p = sum(sides) / 2
	S = (p * (p - sides[0]) * (p - sides[1]) * (p - sides[2])) ** 0.5

	for i in range(3):
		a, b, c = sides[i], sides[(i + 1) % 3], sides[(i + 2) % 3]
		sa, sb, sc = squared_sides[i], squared_sides[(i + 1) % 3], squared_sides[(i + 2) % 3]
		
		angle = math.acos((sa + sc - sb) / (2 * a * c))
		if angle > 2 * math.pi / 3:
			return points[i]

	bcs = []
	for i in range(len(points)):
		a, b, c = sides[i], sides[(i + 1) % 3], sides[(i + 2) % 3]
		sa, sb, sc = squared_sides[i], squared_sides[(i + 1) % 3], squared_sides[(i + 2) % 3]
		bcs.append((sa ** 2) - 2 * (b - c) ** 2 + sa*(sb + sc + 4 * (3 ** 0.5) * S))


	return (
	  (bcs[1]*points[0][0] + bcs[2]*points[1][0] + bcs[0]*points[2][0]) / (bcs[0] + bcs[1] + bcs[2]),
	  (bcs[1]*points[0][1] + bcs[2]*points[1][1] + bcs[0]*points[2][1]) / (bcs[0] + bcs[1] + bcs[2])
	)

	
x1, y1, x2, y2, x3, y3 = map(int, input().split())

A = (x1, y1)
B = (x2, y2)
C = (x3, y3)

T = fermatPoint([A, B, C])
print(round(T[0], 6), round(T[1], 6))
