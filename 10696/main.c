#include <stdio.h>

/*******************************************************************************
- Background
McCarthy is a famous theorician of computer science. In his work, he defined a 
recursive function, called f91, that takes as input a positive integer N and 
returns a positive integer defined as follows:

If N ≤ 100, then f91(N) = f91(f91(N+11));
If N ≥ 101, then f91(N) = N-10.

- The Problem
Write a program, that computes McCarthy's f91.

- The Input
The input tests will consist of a series of positive integers, each integer is 
at most 1,000,000. There will be at most 250,000 test cases. Each number is on 
a line on its own. The end of the input is reached when the number 0 is met. 
The number 0 shall not be considered as part of the test set.

- Output
The program shall output each result on a line by its own, following the format 
given in the sample output.

- Sample input
500
91
0

- Sample output
f91(500) = 490
f91(91) = 91
*******************************************************************************/

/*
 * Calculate McCarthy f91,
 * If N ≤ 100, then f91(N) = f91(f91(N+11));
 * If N ≥ 101, then f91(N) = N-10.
 */
int f91 (int n) {
  if (n <= 100) {
    return f91 (f91 (n+11));
  }

  return n - 10;
}

int main () {
  int n;
  do {
    scanf ("%d\n", &n);
    if (!n) { 
      return 0; 
    }

    printf ("f91(%d) = %d\n", n, f91(n));
  } while (n != 0);

  return 0;
}
