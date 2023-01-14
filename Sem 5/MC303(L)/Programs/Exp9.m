Prob_Trans_Mat = input("Input Probability Transition Matrix: ")
k = size(Prob_Trans_Mat);
n = input("Input number of steps (n): ");
n_step_Transition_Matrix = eye(k(1));
for i=1:n
    n_step_Transition_Matrix = n_step_Transition_Matrix*Prob_Trans_Mat;
end
n_step_Transition_Matrix