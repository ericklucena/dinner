# CIS 3110 Assignment Three - Part 1

## STUDENT
Erick Lucena Palmeira Silva     #0905100

## ABOUT
This program simulates a solution to the "Dining Philosophers" problem.

### ALGORITHM
To solve the problem, it was used the Dijkstra solution. All philosophers try to hold first the fork with lesser value (id), and after that, holds the fork with greater value. As result, the first philosopher will try to get the forks in a inverse order to the others, preventing a deadlock

## COMPILING THE PROGRAM
To compile this program type "make"

## RUNNING THE PROGRAM
To run the program type "./bin/dine [number of philosophers] [number of meals]"

