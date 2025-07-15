#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *ch = s21_NULL;
  while (*str != '\0') {
    if (*str == c) {
      ch = (char *)str;
    }
    str++;
  }
  if (c == '\0') {
    ch = (char *)str;
  }
  return ch;
}