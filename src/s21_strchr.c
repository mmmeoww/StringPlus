#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *ch = s21_NULL;
  int found = 0;
  while (*(char *)str != '\0' && !found) {
    if (*(char *)str == c) {
      ch = (char *)str;
      found = 1;
    }
    str++;
  }
  if (c == '\0') {
    ch = (char *)str;
  }
  return ch;
}
