find_max2(X, Y, X) :- X >= Y, !.
find_max2(X, Y, Y) :- X < Y.
find_max3(X, Y, Z, X) :- X >= Y, X >= Z, !.
find_max3(X, Y, Z, Y) :- Y >= X, Y >= Z, !.
find_max3(X, Y, Z, Z) :- Z >= Y, Z >= X.