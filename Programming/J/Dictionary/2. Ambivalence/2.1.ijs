a =: 3 1 4 1 5 9
b =: 'Canada'
#a NB. Len of list
1 0 1 0 1 3 # a NB. Returns list where values of a repeated n times
1 0 1 0 1 3 # b NB. Does the same
/: a
/: b
a /: a NB. Sorts vector a (in order specified by a)
a /: b NB. Sorts vector a in order specified by b
b /: a
b /: b
c =: 'can''t' NB. '' is escape sequence for '
c
#c
c /: c