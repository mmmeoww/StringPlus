#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *ch = s21_NULL;
  if (s21_strcspn(str1, str2) != s21_strlen(str1)) {
    str1 += s21_strcspn(str1, str2);
    ch = (char *)str1;
  }
  return ch;
}
