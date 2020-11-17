# QuantumAnnealer
A Basic Quantum Annealer Simulator

##Future Features
For now, the Q matrix is hard coded in main, however later iterations will allow the matrix to be loaded from a CSV file.

##How it Works
The program takes a matrix Q, and for all possible states x, finds the cost c = (x^t)Qx.
It then finds the minimum cost function and prints which state x that was in.
