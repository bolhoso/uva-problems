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
#include <string.h>

#define MAX 51
#define EOF_SEQUENCE "#"
#define NO_SUCESSOR "No Successor"
#define SMALLEST_CHAR 'a'
#define SZ_ALPHABET 26

//================================================================================
// Assuming the sequence is composed by contigous characters
// Do otherwise on wrong answer
//================================================================================

/*
 * Given an array of occurrences (where 0 corresponds to letter a, 1 to b and so 
 * forth), check if the buffer s has exactly the same occurrences as specified
 * by occ
 */
int valid (char *occ, int sz_occ, char *s) {
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

  // Check for letters remaining 
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
char *next_seq (const char *s, char *freq_table, int sz_table, char *buf) {

  return NULL;
}

/*
 * Find the next sequence of characters and return it, valid or not. Returns NO_SUCESSOR
 * when such sequence doesn't exist
 */
char *next_seq2 (char *s) {
  char occurrences[10];

  // First of all, find the greatest char and count occurrences
  int len = strlen (s), i;
  char greatest = -127;
  for (i = 0; i < len; i++) {
    if (s[i] > greatest) greatest = s[i];
    occurrences[s[i]-'a']++;
  }


  // Ok, now we have the greatest, generate the next sequence by incrementing from
  // right to left
  char has_carry = 1;
  i = len;
  do {
    if (has_carry) {
      i--;
    }
    has_carry = 0;

    char c = s[i];
    if (++c % greatest == 0) {
      c = SMALLEST_CHAR;
      has_carry = 1;
    }

    s[i] = c;
  } while ((has_carry || !valid (occurrences, SZ_ALPHABET,s)) && i >= 0);

  if (i < 0) {
    return NO_SUCESSOR;
  }

  return s;
}

#ifndef TEST

int main () {
  char buf[MAX];

  do {
    // Read, strip \n and check for the end #
    fgets (buf, 50, stdin);
    buf[strlen(buf)-1] = '\0';
    if (strcmp (buf, EOF_SEQUENCE) == 0) {
      return 0;
    }

    printf ("%s\n", next_seq2 (buf));
  } while (1);

  return 0;
}

#else
#include "units.c"
#endif
