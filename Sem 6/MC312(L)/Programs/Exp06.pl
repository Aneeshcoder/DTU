factorial(0, 1).
factorial(N, M) :- N > 0, Prev is N -1, factorial(Prev, M1), M is M1 * N.