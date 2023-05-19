fibonacci(1,0).
fibonacci(2,1).
fibonacci(N,F) :- N>2, N1 is N-1, N2 is N-2, fibonacci(N1,F1), fibonacci(N2,F2), F is F1+F2.
fib(N) :- N>0, fibonacci(N,W), write(W), N1 is N-1, fib(N1).