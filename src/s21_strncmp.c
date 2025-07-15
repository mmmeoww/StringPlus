#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  for (int i = 0; i < (int)n && res == 0; i++) {
    res += str1[i] - str2[i];
  }
  return res;
}
