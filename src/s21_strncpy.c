#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  int src_len = 0;
  while (src[src_len] != '\0') {
    src_len++;
  }
  for (int i = 0; i < (int)n; i++) {
    if (i < src_len) {
      dest[i] = src[i];
    } else {
      dest[i] = '\0';
    }
  }
  return dest;
}
