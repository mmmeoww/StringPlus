#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = s21_NULL;
  int found = 0, i = 0;
  int haystack_len = s21_strlen(haystack), needle_len = s21_strlen(needle);
  while (i <= haystack_len - needle_len && !res) {
    int j = 0;
    found = 0;
    while (j < needle_len) {
      if (haystack[i + j] == needle[j]) {
        found++;
      }
      j++;
    }
    if (found == needle_len) {
      res = (char *)(haystack + i);
    }
    i++;
  }
  return res;
}
