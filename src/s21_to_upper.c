#include <stdlib.h>

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *res = s21_NULL;
  if (str != s21_NULL) {
    res = malloc(s21_strlen(str) + 1);
    if (res != s21_NULL) {
      for (s21_size_t i = 0; i < s21_strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          res[i] = str[i] - 32;
        } else {
          res[i] = str[i];
        }
      }
      res[s21_strlen(str)] = '\0';
    }
  }
  return (void *)res;
}
