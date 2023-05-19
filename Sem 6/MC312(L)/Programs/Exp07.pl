sum(0,0).
sum(N,M) :- N > 0, Prev is N -1, sum(Prev,M1), M is M1 + N.