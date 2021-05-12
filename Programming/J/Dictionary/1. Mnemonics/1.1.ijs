   a =: 0 1 2 3 NB. List of numbers
   b =: 3 2 1 0
   a + b NB. Pairwise addition of each element
3 3 3 3
   a * b NB. Pairwise multipliaction of each element
0 2 2 0
   a - b NB. Pairwise subtraction of each element
_3 _1 1 3
   a % b NB. Pairwise division of each element. _ is infinity. Division by zero is _
0 0.5 2 _
   a^b NB. Pairwise power of each element. Where first list element is base and second list element is power
0 1 2 1
   a^.b NB. Pairwise logarithm. Where first element is base. Log2(1) = _; Log0(3) = __
0 _ 0 __
   a < b NB. First element is left argument, second is right 
1 1 0 0
   a > b NB. Same as upper statement
0 0 1 1
   (a < b) + (a > b) NB. No comments required
1 1 1 1
   (a < b) +. (a > b) NB. Greates common divisor pairwise
1 1 1 1
   