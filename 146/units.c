#include <assert.h>
#include <stdbool.h>

#define SZ_BUF 50
#define SZ_TABLE 26

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

void test_build_freq_table () {
  int i;

  char *buf1 = "abbacdabbca";
  char *tab1 = build_freq_table (buf1, SZ_TABLE);
  assert (tab1 != NULL);
  assert (tab1[0] == 4);
  assert (tab1[1] == 4);
  assert (tab1[2] == 2);
  assert (tab1[3] == 1);
  for (i = 4; i < SZ_TABLE; i++) {
    assert (0 == tab1[i]);
  }
  free (tab1);

  // test empty string
  char *buf2 = "";
  char *tab2 = build_freq_table (buf2, SZ_TABLE);
  assert (tab2 != NULL);
  for (i = 0; i < SZ_TABLE; i++) {
    assert (0 == tab2[i]);
  }
  free (tab2);

  char *buf3 = "zzzzzzzzzzzzzzzzzzzzzz";
  char *tab3 = build_freq_table (buf3, SZ_TABLE);
  assert (tab3 != NULL);
  assert (tab3['z' - 'a'] == 22);
  for (i = 0; i < SZ_TABLE - 1; i++) {
    assert (0 == tab3[i]);
  }
  free (tab3);

  // Test the null cases
  assert (build_freq_table (NULL, SZ_TABLE) == NULL);
  assert (build_freq_table ("aastg", 0) == NULL);
}

// TODO: test the next sequence
// TODO :we're not testing valid sequences!
void test_next_seq () {
  // Frequency table and output buffer
  char *freq_table;
  char buf[SZ_BUF];

  // test 1, a trivial sequence
  {
    char *orig = "a";
    freq_table = build_freq_table (orig, SZ_ALPHABET);
    assert (strcmp (next_seq(orig, freq_table, SZ_ALPHABET, buf), "b") == 0);
    free (freq_table);
  }
  
  // test 1, a trivial sequence
  {
    char *orig = "abba";
    freq_table = build_freq_table (orig, SZ_ALPHABET);
    assert (strcmp (next_seq(orig, freq_table, SZ_ALPHABET, buf), "abbb") == 0);
    free (freq_table);
  }

  // testing carry
  {
    char *orig = "abab";
    freq_table = build_freq_table (orig, SZ_ALPHABET);
    assert (strcmp (next_seq(orig, freq_table, SZ_ALPHABET, buf), "abbb") == 0);
    assert (strcmp (next_seq(orig, freq_table, SZ_ALPHABET, buf), "bbbb") == 0);
    free (freq_table);
  }

  // no more sequences
  {
    char *orig = "bbbb";
    freq_table = build_freq_table (orig, SZ_ALPHABET);
    assert (next_seq(orig, freq_table, SZ_ALPHABET, buf) == NULL);
    free (freq_table);
  }

  // itsnotokproblembro, test the bad-guy-cases
  {
    char *orig = "bbbb";
    freq_table = build_freq_table (orig, SZ_ALPHABET);

    assert (next_seq (NULL, NULL, 0, NULL) == NULL && "null table");
    assert (next_seq (orig, freq_table, -1, buf) == NULL && "negative table size");
    assert (next_seq (orig, freq_table, SZ_TABLE, NULL) == NULL && "null buffer");
    free (freq_table);
  }
  
}

int main () {
  test_valid();
  test_build_freq_table();
  test_next_seq();

  printf ("Hooray! All tests passed\n");

  return 0;
}
