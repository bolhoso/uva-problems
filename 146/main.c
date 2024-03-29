/*******************************************************************************
- The problem
For example, suppose it is decided that a code will contain exactly 3 
occurrences of `a', 2 of `b' and 1 of `c', then three of the allowable 60 codes 
under these conditions are:
      abaabc
      abaacb
      ababac
These three codes are listed from top to bottom in alphabetic order. Among all 
codes generated with this set of characters, these codes appear consecutively in
this order.

Write a program to assist in the issuing of these identification codes. Your 
program will accept a sequence of no more than 50 lower case letters (which 
may contain repeated characters) and print the successor code if one exists or 
the message `No Successor' if the given code is the last in the sequence for 
that set of characters.

- The Input
Input will consist of a series of lines each containing a string representing 
a code. The entire file will be terminated by a line consisting of a single #.
Output will consist of one line for each code read containing the successor 
code or the words `No Successor'.

(Note from the programmer: Consider the 26 lower-case alphabet letters)

- Sample input
abaacb
cbbaa
#

- Sample output

ababac
No Successor
*******************************************************************************/
#include <malloc.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

#define MAX 52
#define EOF_SEQUENCE "#"
#define NO_SUCESSOR "No Successor"
#define SMALLEST_CHAR 'a'
#define SZ_ALPHABET 26

/*********************************************************************************
 Assuming the sequence is composed by contigous characters
 Do otherwise on wrong answer
*********************************************************************************/

/*
 * Given an array of occurrences (where 0 corresponds to letter a, 1 to b and so 
 * forth), check if the buffer s has exactly the same occurrences as specified
 * by occ
 */
int valid (char *occ, int sz_occ, char *s) {
  if (!occ || !s || sz_occ <= 0) {
    return 0;
  }
  
  char *oc = (char *) malloc (sizeof(char) * sz_occ);
  memcpy ((char *) oc, occ, sizeof(char) * sz_occ);

  while (*s) {
    int i = *s - 'a';
    oc[i]--;
    if (oc[i] < 0) {
      free (oc);
      return 0;
    }
    s++;
  }

  /* Check for letters remaining  */
  int i;
  for (i = 0; i < sz_occ; i++) {
    if (oc[i] > 0) {
      free (oc);
      return 0;
    }
  }

  free (oc);

  return 1;
}

/*
 * Build a dinamically allocated frequency table from the buffer
 * s. The table is consisted only of lower case letters
 */
char *build_freq_table (char *s, int sz_table) {
  if (!s || sz_table <= 0)
    return NULL;

  char *tab = (char *) malloc (sizeof (char) * sz_table);
  bzero ((char *) tab, sizeof (char) * sz_table);
  while (*s) {
    tab[*s-'a']++;
    s++;
  }
  return tab;
}

/*
 * Gives you the next sequence generate from the string *s. Returns
 * NULL when no such sequence exists (like, a 'zzzzz')
 */
char *next_seq (char *s, char *freq_table, int sz_table) {

  if (!s || !freq_table || sz_table <= 0) {
    return NULL;
  }

  char max_char = 'a';
  while (freq_table[max_char-'a'] > 0) max_char++;
  max_char--;

  char *buf = s;
  int has_carry = 1;
  int pos = strlen (s) - 1;
  while (pos >= 0 && has_carry) {
    has_carry = 0;

    /* if the current char is out of bound, then we have carry */
    (*(buf+pos))++;
    if (buf[pos] > max_char) {
      has_carry = 1;
      *(buf+pos) = 'a';

    }

    pos--;
  }

  if (pos < 0 && has_carry) {
    return NULL;
  }

  return s;
}

char *next_valid (char *s) {
  char *freq_table = build_freq_table (s, SZ_ALPHABET);

  int is_valid = 0;
  while (!is_valid && s) {
    s = next_seq (s, freq_table, SZ_ALPHABET);
    is_valid = valid (freq_table, SZ_ALPHABET, s);
  }

  free (freq_table);

  return s;
}

#ifndef TEST

int main () {
  char buf[MAX];

  do {
    /* Read, strip \n and check for the end # */
    fgets (buf, 50, stdin);
    buf[strlen(buf)-1] = '\0';
    if (strcmp (buf, EOF_SEQUENCE) == 0) {
      return 0;
    }

    char *s = next_valid (buf);
    if (!s) {
      printf ("No Successor\n");
    } else {
      printf ("%s\n", s);
    }
  } while (1);

  return 0;
}

#else
  #include "units.c"
#endif
