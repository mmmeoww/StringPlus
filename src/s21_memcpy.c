#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *dst = dest, *sc = (char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    dst[i] = sc[i];
  }
  dest = (void *)dst;
  return dest;
}
