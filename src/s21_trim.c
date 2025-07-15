#include <stdlib.h>

#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *new = s21_NULL;
  if (src != s21_NULL && trim_chars != s21_NULL) {
    int start = 0;
    int end = (int)s21_strlen(src) - 1;
    int length = (int)s21_strlen(src);

    while (start < length && s21_strchr(trim_chars, src[start]) != s21_NULL) {
      start++;
    }

    while (end >= start && s21_strchr(trim_chars, src[end]) != s21_NULL) {
      end--;
    }

    new = (char *)malloc((end - start + 2) * sizeof(char));
    if (new != s21_NULL) {
      s21_strncpy(new, src + start, end - start + 1);
      new[end - start + 1] = '\0';
    }
  }
  return new;
}