# IS2101-ArithmeticOps-NNM24IS232
To implement signed integer multiplication and division algorithms using C programming

This repository contains C programs implementing three fundamental arithmetic algorithms:

1)Sequential (Shift-Add) Multiplication

.Supports signed integers using 2’s complement.
.Shows step-by-step shift and add logic.

2)Restoring Division Algorithm
.Works with positive integers.

3)Non-Restoring Division Algorithm.

.Similar to restoring division but with non-restoring logic.

.Trace output of each step (accumulator,dividend,quotient bits).

These programs simulate how arithmetic operations are performed at the hardware level. It lets you get handson experience on how hardware level calculation work and how you can improvise the time complexity by minimizing the steps (for ex: restoring to non restoring division algorithm).

.File Structure
.ShiftAddMultiplication.c – Implements sequential multiplication.
.RestoringDivision.c – Implements restoring division.
.Non_Restoring_Algorithm.c – Implements non-restoring division
.README.md – Project description and instructions
FOR COMPILETION:

gcc sequential Multiplication.c -o Sequential Multiplication
./Sequential Multiplication
gcc RestoringDivision.c -o RestoringDivision
./RestoringDivision
gcc non_Restoring_Algorithm.c -o nonRestoring
./NonRestoring

>OUTPUT OF SHIFT-ADD MULTIPLICATION.
<img width="975" height="462" alt="Screenshot 2025-09-09 215937" src="https://github.com/user-attachments/assets/512f53b6-75c2-4a61-bd24-8554a018a405" />

>OUTPUT OF RESTORING DIVISION.
<img width="1039" height="582" alt="Screenshot 2025-09-10 213952" src="https://github.com/user-attachments/assets/3c179f36-3791-4ca1-882e-406a603895fd" />

>OUTPUT OF NON-RESTORING DIVISION.
<img width="1044" height="554" alt="non_rest" src="https://github.com/user-attachments/assets/a15f4650-675c-435b-b47c-62d1d8070179" />









