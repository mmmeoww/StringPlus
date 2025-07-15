#include <stdlib.h>

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = s21_NULL;
  if (str != s21_NULL && src != s21_NULL && start_index <= s21_strlen(src)) {
    res = malloc(s21_strlen(src) + s21_strlen(str) + 1);
    if (res != s21_NULL) {
      s21_size_t i = 0;
      while (i < start_index) {
        res[i] = src[i];
        i++;
      }
      s21_size_t j = 0;
      while (j < s21_strlen(str)) {
        res[i + j] = str[j];
        j++;
      }
      i += j;
      while (src[start_index] != '\0') {
        res[i] = src[start_index];
        i++;
        start_index++;
      }
      res[i] = '\0';
    }
  }
  return (void *)res;
}
