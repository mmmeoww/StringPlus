#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last = s21_NULL;
  char *start = s21_NULL;
  if (str != s21_NULL) {
    last = str;
  }
  while (last != s21_NULL && *last != '\0' && s21_strchr(delim, *last)) {
    last++;
  }
  if (last != s21_NULL && *last != '\0') {
    start = last;
    while (*last != '\0' && !s21_strchr(delim, *last)) {
      last++;
    }
    if (*last != '\0') {
      *last = '\0';
      last++;
    } else {
      last = s21_NULL;
    }
  }

  return start;
}