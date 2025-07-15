#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  while ((n--) > 0 && res == 0) {
    res += *(char *)str1 - *(char *)str2;
    str1++;
    str2++;
  }
  return res;
}
