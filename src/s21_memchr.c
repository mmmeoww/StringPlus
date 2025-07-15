#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = s21_NULL;
  while ((n--) > 0 && res == s21_NULL) {
    if (*(const char *)str == c) {
      res = (void *)str;
    }
    str += sizeof(char);
  }
  return res;
}
