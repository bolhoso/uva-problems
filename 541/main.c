#include <malloc.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

#define MAX 100

int has_parity (int m[MAX][MAX], int sz) {
  int i, j;

  /* Verify the rows have parity */
  for (i = 0; i < sz; i++) {
    int sum = 0;
    for (j = 0; j < sz; j++) {
      sum += m[i][j];
    }

    /* count the number of odd rows/cols */
    if (sum % 2 != 0) {
      return 0;
    }
  }

  /* now scan the cols*/
  for (i = 0; i < sz; i++) {
    int sum = 0;
    for (j = 0; j < sz; j++) {
      sum += m[j][i];
    }

    /* count the number of odd rows/cols */
    if (sum % 2 != 0) {
      return 0;
    }
  }

  return 1;
}

int is_correctible(int m[MAX][MAX], int sz, int *row, int *col) {
  int i, j;
  int odd_row, odd_col;

  odd_row = odd_col = -1;

  /* Verify the rows have parity */
  for (i = 0; i < sz; i++) {
    int sum = 0;
    for (j = 0; j < sz; j++) {
      sum += m[i][j];
    }

    /* count the number of odd rows/cols */
    if (sum % 2 != 0) {

      /* corrupted! more than one row is odd */
      if (odd_row != -1) {
        return 0;
      }

      odd_row = i;
    }
  }

  /* now scan the cols*/
  for (i = 0; i < sz; i++) {
    int sum = 0;
    for (j = 0; j < sz; j++) {
      sum += m[j][i];
    }

    /* count the number of odd rows/cols */
    if (sum % 2 != 0) {
      /* corrupted! more than one row is odd */
      if (odd_col != -1) {
        return 0;
      }

      odd_col = i;
    }
  }

  *row = odd_row + 1;
  *col = odd_col + 1;
  return 1;
}

#ifdef ONLINE_JUDGE
int main () {
  int m[MAX][MAX];

  do {
    int n, i, j;
    scanf ("%d", &n);
    if (0 == n) 
      break;

    /* read the matrix */
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        scanf ("%d ", &(m[i][j]));
      }
    }

    if (has_parity(m, n)) {
      printf ("OK\n");
    } else {
      int row, col;
      if (is_correctible(m, n, &row, &col)) {
        printf ("Change bit (%d,%d)\n", row, col);
      } else {
        printf ("Corrupt\n");
      }
    }
  } while (1);

  return 0;
}
#else
  #include "units.c"
#endif
