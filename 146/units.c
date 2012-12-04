#include <assert.h>
#include <stdbool.h>

void test_valid () {
  char oc[SZ_ALPHABET];
  bzero ((char *)oc, sizeof (char) * SZ_ALPHABET);

  oc['a'-'a'] = 3;
  oc['b'-'a'] = 1;
  oc['c'-'a'] = 1;
  assert (valid  (oc, SZ_ALPHABET, "aaabc") && "Valid string");
  assert (!valid (oc, SZ_ALPHABET, "aabbc") && "Invalid string");
  assert (!valid (oc, SZ_ALPHABET, "abbc") && "Invalid string");
}

// TODO: test the next sequence
void test_next_seq () {

}

void test_next_valid () {

}

int main () {
  test_valid();

  printf ("Hooray! All tests passed\n");

  return 0;
}
