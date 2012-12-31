#include <assert.h>
#include <stdbool.h>

int INPUT1 [MAX][MAX] = {{1, 0, 1, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 1, 0, 1}};
int INPUT2 [MAX][MAX] = {{1, 0, 1, 0}, {0, 0, 1, 0}, {1, 1, 1, 1}, {0, 1, 0, 1}};
int INPUT3 [MAX][MAX] = {{1, 0, 1, 0}, {0, 1, 1, 0}, {1, 1, 1, 1}, {0, 1, 0, 1}};

void test_has_parity () {
  assert (has_parity(INPUT1, 4) != 0);
  assert (has_parity(INPUT2, 4) == 0);
  assert (has_parity(INPUT3, 4) == 0);
}

void test_is_correctible () {
  int row, col;

  assert (is_correctible(INPUT2, 4, &row, &col) != 0);
  assert (row == 2);
  assert (col == 3);
  
  assert (is_correctible(INPUT3, 4, &row, &col) == 0);
}

int main () {
  test_has_parity();
  test_is_correctible();

  printf ("Hooray! All tests passed\n");

  return 0;
}
