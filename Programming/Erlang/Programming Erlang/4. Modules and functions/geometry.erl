-module(geometry).
-export([test/0, area/1, perimeter/1]).

test() ->
	12 = area({rectangle, 3, 4}),
	144 = area({square, 12}),
	tests_worked.

area({rectangle, Width, Height}) -> Width * Height;
area({square, Side}) -> Side * Side;

% Exercise 1

area({circle, Radius}) ->
	math:pi() * Radius * Radius;

area({right_angled_triangle, A, B}) ->
	A * B.

perimeter({rectangle, A, B}) ->
	2 * (A + B);
perimeter({square, A}) ->
	4 * A;
perimeter({triangle, A, B, C}) ->
	A + B + C;
perimeter({rhombus, A}) ->
	4 * A;
perimeter({circle, Radius}) ->
	2 * math:pi() * Radius.
