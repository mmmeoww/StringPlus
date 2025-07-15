#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_string_memchr) {
  printf("\nTesting s21_memchr:\n");
  char *str[] = {"Testing", "Of", "Memchr", "Function!", "", "a", "a"};
  size_t n[] = {27, 27, 27, 27, 0, 1, 1};
  int c[] = {'i', 'O', 'r', 'j', 'a', 'a', 'b'};
  for (int i = 0; i < 7; i++) {
    ck_assert_ptr_eq(s21_memchr(str[i], c[i], n[i]),
                     memchr(str[i], c[i], n[i]));
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_memchr(\"%s\",\"%c\", %lu) = "
        "memchr(\"%s\",\"%c\",%lu) = "
        "\"%s\"\n",
        str[i], c[i], n[i], str[i], c[i], n[i],
        (char *)s21_memchr(str[i], c[i], n[i]));
  }
}
END_TEST

START_TEST(test_s21_string_memcmp) {
  printf("\nTesting s21_memcmp:\n");
  char *str1[] = {"abc", "abc", "abd", "abc", "abcd", "abc",
                  "",    "a",   "b",   "abc", "ab",   "abc"};
  char *str2[] = {"abc", "abd", "abc", "abcd", "abc", "abc",
                  "",    "b",   "a",   "ab",   "abc", "def"};
  size_t n[] = {3, 3, 3, 3, 3, 0, 1, 1, 1, 3, 3, 3};
  for (int i = 0; i < 12; i++) {
    ck_assert_int_eq(s21_memcmp(str1[i], str2[i], n[i]),
                     memcmp(str1[i], str2[i], n[i]));
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_memcmp(\"%s\", \"%s\", %lu) = "
        "memcmp(\"%s\", \"%s\", %lu) "
        "= %d\n",
        str1[i], str2[i], n[i], str1[i], str2[i], n[i],
        s21_memcmp(str1[i], str2[i], n[i]));
  }
}
END_TEST

START_TEST(test_s21_string_memcpy) {
  printf("\nTesting s21_memcpy:\n");
  char dests1[7][20] = {0};
  char dests2[7][20] = {0};
  char *src[] = {"Hello, world!", "ABOBA", "C_ONE_LOVE", "omg",
                 "5th str",       "",      " "};
  size_t n[] = {14, 3, 1, 4, 0, 1, 1};
  for (int i = 0; i < 7; i++) {
    ck_assert_str_eq(s21_memcpy(dests1[i], src[i], n[i]),
                     memcpy(dests2[i], src[i], n[i]));
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_memcpy(\"\", \"%s\", %lu) = "
        "memcpy(\"\", \"%s\", %lu) = "
        "\"%s\"\n",
        src[i], n[i], src[i], n[i], dests1[i]);
  }
}
END_TEST

START_TEST(test_s21_string_memset) {
  printf("\nTesting s21_memset:\n");
  char str1[][10] = {"123123123", "", "abcdefg", "      ", "ABOBA", "ssssssss"};
  char str2[][10] = {"123123123", "", "abcdefg", "      ", "ABOBA", "ssssssss"};
  char str3[][10] = {"123123123", "", "abcdefg", "      ", "ABOBA", "ssssssss"};
  char c[] = {'7', 'k', ' ', 'A', 0, 'b'};
  size_t n[] = {5, 1, 0, 3, 5, 6};

  for (int i = 0; i < 6; i++) {
    ck_assert_str_eq(s21_memset(str1[i], (int)c[i], n[i]),
                     memset(str2[i], (int)c[i], n[i]));
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_memset(\"%s\", '%c', %lu) = "
        "memset(\"%s\", '%c', %lu) = "
        "\"%s\"\n",
        str3[i], c[i], n[i], str3[i], c[i], n[i], str1[i]);
  }
}
END_TEST

START_TEST(test_s21_string_strncat) {
  printf("\nTesting s21_strncat:\n");
  char dests[][25] = {"Hello,", "Hello,", "Hello,",         "",
                      "Hello,", "",       "Hello, \0extra", "Hello, world",
                      "Hello,"};
  char *srcs[] = {"world!", "world!", "",  "world!",      "world!",
                  "",       "world!", "!", " world! #@$%"};
  size_t n[] = {3, 10, 5, 5, 0, 5, 5, 1, 7};
  for (int i = 0; i < 9; i++) {
    ck_assert_str_eq(s21_strncat(dests[i], srcs[i], n[i]),
                     strncat(dests[i], srcs[i], n[i]));
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_strncat(\"%s\", \"%s\",\"%lu\") = "
        "stncat(\"%s\", "
        "\"%s\",\"%lu\") = %s\n",
        dests[i], srcs[i], n[i], dests[i], srcs[i], n[i],
        s21_strncat(dests[i], srcs[i], n[i]));
  }
}
END_TEST

START_TEST(test_s21_string_strchr) {
  printf("\nTesting s21_strchr:\n");
  char *str[] = {"",    "hello", "world", "apple",      "mississippi",
                 "end", "a",     "   ",   "!@#$%^&*()", "\0"};
  char ch[] = {'a', 'z', 'w', 'e', 's', '\0', 'a', ' ', '$', '\0'};
  for (int i = 0; i < 10; i++) {
    ck_assert_ptr_eq(s21_strchr(str[i], ch[i]), strchr(str[i], ch[i]));
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_str(\"%s\", \"%c\") = str(\"%s\", "
        "\"%c\") = \"%s\"\n",
        str[i], ch[i], str[i], ch[i], s21_strchr(str[i], ch[i]));
  }
}
END_TEST

START_TEST(test_s21_string_strncmp) {
  printf("\nTesting s21_strncmp:\n");
  char *str1[] = {"",
                  "",
                  "Hello",
                  "Hello",
                  "HelloWorld",
                  "Hello/0world",
                  "IdenticalStrings",
                  "hello"};
  char *str2[] = {"",
                  "Hello",
                  "HelloWorld",
                  "Hella",
                  "HelloEveryone",
                  "HelloWorld",
                  "IdenticalStrings",
                  "Hello"};
  unsigned long n[] = {5, 5, 5, 5, 5, 10, 17, 5};
  for (int i = 0; i < 8; i++) {
    if (s21_strncmp(str1[i], str2[i], n[i]) > 0) {
      ck_assert_int_gt(s21_strncmp(str1[i], str2[i], n[i]), 0);
      ck_assert_int_gt(strncmp(str1[i], str2[i], n[i]), 0);
      printf(
          "\033[0;32m[PASS]\033[0;0m s21_strncmp(\"%s\", \"%s\", %lu) > 0 && "
          "strncmp(\"%s\", "
          "\"%s\", "
          "%lu) > 0\n",
          str1[i], str2[i], n[i], str1[i], str2[i], n[i]);
    } else if (s21_strncmp(str1[i], str2[i], n[i]) < 0) {
      ck_assert_int_lt(s21_strncmp(str1[i], str2[i], n[i]), 0);
      ck_assert_int_lt(strncmp(str1[i], str2[i], n[i]), 0);
      printf(
          "\033[0;32m[PASS]\033[0;0m s21_strncmp(\"%s\", \"%s\", %lu) < 0 && "
          "strncmp(\"%s\", "
          "\"%s\", "
          "%lu) < 0\n",
          str1[i], str2[i], n[i], str1[i], str2[i], n[i]);
    } else {
      ck_assert_int_eq(s21_strncmp(str1[i], str2[i], n[i]), 0);
      ck_assert_int_eq(strncmp(str1[i], str2[i], n[i]), 0);
      printf(
          "\033[0;32m[PASS]\033[0;0m s21_strncmp(\"%s\", \"%s\", %lu) = "
          "strncmp(\"%s\", \"%s\", "
          "%lu) = 0\n",
          str1[i], str2[i], n[i], str1[i], str2[i], n[i]);
    }
  }
}
END_TEST

START_TEST(test_s21_string_strncpy) {
  printf("\nTesting s21_strncpy:\n");
  char *src[] = {"Hello, world!", "chocolatka", "vrode\0rabotaet", "omg...",
                 "biba i boba"};
  char dest1[5][20] = {0};
  char dest2[5][20] = {0};
  size_t n[] = {10, 0, 17, 2, 3};
  for (int i = 0; i < 5; i++) {
    ck_assert_str_eq(s21_strncpy(dest1[i], src[i], n[i]),
                     strncpy(dest2[i], src[i], n[i]));
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_strncpy(\"\",\"%s\", %lu) = "
        "strncpy(\"\",\"%s\", %lu) = "
        "\"%s\"\n",
        src[i], n[i], src[i], n[i], dest1[i]);
  }
  ck_assert_str_eq(s21_strncpy(dest1[1], src[3], n[3]),
                   strncpy(dest2[1], src[3], n[3]));
  printf(
      "\033[0;32m[PASS]\033[0;0m s21_strncpy(\"Hello,wor\",\"%s\", %lu) = "
      "strncpy(\"Hello,wor!\",\"%s\", "
      "%lu) = \"%s\"\n",
      src[3], n[3], src[3], n[3], dest1[3]);
}
END_TEST

START_TEST(test_s21_string_strcspn) {
  printf("\nTesting s21_strcspn:\n");
  char *str1[] = {"",         "Hello, shcoolboy", "aboba",
                  "ayou bro", "Hello, world!",    "abcdef",
                  "banana",   "rap\0trap\0yee"};
  char *str2[] = {"abc", "", "xyz", "o", "wo", "a", "na", "pt"};
  for (int i = 0; i < 8; i++) {
    ck_assert_uint_eq(s21_strcspn(str1[i], str2[i]), strcspn(str1[i], str2[i]));
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_strcspn(\"%s\", \"%s\") = "
        "strcspn(\"%s\", \"%s\") = %lu\n",
        str1[i], str2[i], str1[i], str2[i], s21_strcspn(str1[i], str2[i]));
  }
}
END_TEST

START_TEST(test_s21_string_strerror) {
  printf("\nTesting s21_strerror:\n");

  for (int i = 0; i < 107; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
    printf("\033[0;32m[PASS]\033[0;0m s21_strerror(%d) = strerror(%d) = %s\n",
           i, i, s21_strerror(i));
  }
}
END_TEST

START_TEST(test_s21_string_strlen) {
  printf("\nTesting s21_strlen:\n");
  char *str[] = {"",
                 "A",
                 "PRIVET",
                 "    ",
                 "\0qwerty",
                 "dj\0stonik",
                 "Hello, World! @$%^&*",
                 "This is a very long string used to test the strlen function.",
                 "Line 1\nLine 2\nLine 3"};
  for (int i = 0; i < 9; i++) {
    ck_assert_uint_eq(s21_strlen(str[i]), strlen(str[i]));
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_strlen(\"%s\") = strlen(\"%s\") = %lu\n",
        str[i], str[i], s21_strlen(str[i]));
  }
}
END_TEST

START_TEST(test_s21_string_strpbrk) {
  printf("\nTesting s21_strpbrk:\n");
  char *str1[] = {"",         "Hello, shcoolboy", "aboba",
                  "ayou bro", "Hello, world!",    "abcdef",
                  "banana",   "rap\0trap\0yee",   "pupu    bebebbebebe"};
  char *str2[] = {"abc", "", "xyz", "o", "wo", "a", "na", "pt", " "};
  for (int i = 0; i < 9; i++) {
    ck_assert_ptr_eq(s21_strpbrk(str1[i], str2[i]), strpbrk(str1[i], str2[i]));
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_strpbrk(\"%s\", \"%s\") = "
        "strpbrk(\"%s\", \"%s\") = "
        "\"%s\"\n",
        str1[i], str2[i], str1[i], str2[i], s21_strpbrk(str1[i], str2[i]));
  }
}
END_TEST

START_TEST(test_s21_string_strrchr) {
  printf("\nTesting s21_strrchr:\n");
  char *str1[] = {"",         "Hello, shcoolboy", "aboba",
                  "ayou bro", "Hello, world!",    "abcdef",
                  "banana",   "rap\0trap\0yee",   "pupu    bebebbebebe"};
  int ch[] = {'b', 0, 'x', 'o', 'l', 'a', 'n', 'p', ' '};
  for (int i = 0; i < 9; i++) {
    ck_assert_ptr_eq(s21_strrchr(str1[i], ch[i]), strrchr(str1[i], ch[i]));
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_strrchr(\"%s\", \'%c\') = "
        "strrchr(\"%s\", \'%c\') = "
        "\"%s\"\n",
        str1[i], ch[i], str1[i], ch[i], s21_strrchr(str1[i], ch[i]));
  }
}
END_TEST

START_TEST(test_s21_string_strstr) {
  printf("\nTesting s21_strstr:\n");
  char *haystacks[] = {
      "",       "short",        "beginning",         "ending",
      "middle", "notfound",     "special!@#$%^&*()", "with spaces",
      "12345",  "CaSeSeNsItIvE"};
  char *neddles[] = {"",    "verylongsubstring", "begin", "ing",
                     "ddl", "missing",           "!@#$",  "spaces",
                     "345", "SeNsItIvE"};
  for (int i = 0; i < 10; i++) {
    ck_assert_ptr_eq(s21_strstr(haystacks[i], neddles[i]),
                     strstr(haystacks[i], neddles[i]));
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_strstr(%s, %s) = strstr(%s, %s) = %s\n",
        haystacks[i], neddles[i], haystacks[i], neddles[i],
        s21_strstr(haystacks[i], neddles[i]));
  }
}
END_TEST

START_TEST(test_s21_string_strtok) {
  printf("\nTesting s21_strtok:\n");
  char *str1[] = {"",
                  "single",
                  "multiple,,delimiters,,here",
                  "  leading and trailing spaces  ",
                  "word1,word2.word3!word4",
                  "123abc456def",
                  "CaSeSeNsItIvE",
                  "nosplitshere"};
  char *delim[] = {" ", " ", ", ", " ", ",.!", "0123456789", "aA", " "};

  for (int i = 0; i < 8; i++) {
    char str1_copy[256];
    char str2_copy[256];
    strcpy(str1_copy, str1[i]);
    strcpy(str2_copy, str1[i]);
    char *token1 = s21_strtok(str1_copy, delim[i]);
    char *token2 = strtok(str2_copy, delim[i]);
    while (token1 || token2) {
      ck_assert_str_eq(token1, token2);
      token1 = s21_strtok(NULL, delim[i]);
      token2 = strtok(NULL, delim[i]);
    }
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_strtok(\"%s\", \"%s\") = strtok(\"%s\", "
        "\"%s\")\n",
        str1[i], delim[i], str1[i], delim[i]);
  }
}
END_TEST

START_TEST(test_s21_string_to_upper) {
  printf("\nTesting s21_to_upper:\n");
  char *str1[] = {"",
                  "single",
                  "i'm heRe)",
                  "  leaDing and traiLing spaCes  ",
                  "word1\0word2\0word3\0word4",
                  "123\tabc456d\nef",
                  "CaSeSeNsItIvE",
                  "@#$%^&*()",
                  NULL,
                  "xyz{|}"};
  char *ext[] = {"",
                 "SINGLE",
                 "I'M HERE)",
                 "  LEADING AND TRAILING SPACES  ",
                 "WORD1",
                 "123\tABC456D\nEF",
                 "CASESENSITIVE",
                 "@#$%^&*()",
                 NULL,
                 "XYZ{|}"};
  char *new = NULL;
  for (int i = 0; i < 10; i++) {
    new = s21_to_upper(str1[i]);
    if (ext[i] == NULL) {
      ck_assert_ptr_eq(new, ext[i]);
    } else {
      ck_assert_str_eq(new, ext[i]);
    }
    printf("\033[0;32m[PASS]\033[0;0m s21_to_upper(\"%s\") = \"%s\"\n", str1[i],
           new);
    free(new);
  }
}
END_TEST

START_TEST(test_s21_string_to_lower) {
  printf("\nTesting s21_to_lower:\n");
  char *str1[] = {"",
                  "SINGLE",
                  "i'm HeRe)",
                  "  LEADING and TRAILING SpaCes  ",
                  "WORD1\0WORD2\0WORd3\0WORD4",
                  "123ABC456d\neF",
                  "CaSeSeNsItIvE",
                  "@#$%^&*()",
                  NULL};
  char *ext[] = {"",
                 "single",
                 "i'm here)",
                 "  leading and trailing spaces  ",
                 "word1",
                 "123abc456d\nef",
                 "casesensitive",
                 "@#$%^&*()",
                 NULL};
  char *new = NULL;
  for (int i = 0; i < 9; i++) {
    new = s21_to_lower(str1[i]);
    if (ext[i] == NULL) {
      ck_assert_ptr_eq(new, ext[i]);
    } else {
      ck_assert_str_eq(new, ext[i]);
    }
    printf("\033[0;32m[PASS]\033[0;0m s21_to_lower(\"%s\") = \"%s\"\n", str1[i],
           new);
    free(new);
  }
}
END_TEST

START_TEST(test_s21_string_insert) {
  printf("\nTesting s21_insert:\n");
  char *src[] = {"",       "hello",  "bro", "example",
                 "string", "middle", NULL,  "abc"};
  char *str[] = {"test", "", "hello ", "test", " end", "insert ", "abc", NULL};
  size_t start_index[] = {0, 2, 0, 10, s21_strlen(src[4]), 3, 7, 4};
  char *ext[] = {"test",       "hello",         "hello bro", NULL,
                 "string end", "midinsert dle", NULL,        NULL};
  char *new = NULL;
  for (int i = 0; i < 8; i++) {
    new = s21_insert(src[i], str[i], start_index[i]);
    if (ext[i] == NULL) {
      ck_assert_ptr_eq(new, ext[i]);
    } else {
      ck_assert_str_eq(new, ext[i]);
    }
    printf(
        "\033[0;32m[PASS]\033[0;0m s21_insert(\"%s\", \"%s\", %lu) = \"%s\"\n",
        src[i], str[i], start_index[i], ext[i]);
    free(new);
  }
}
END_TEST

START_TEST(test_s21_string_trim) {
  printf("\nTesting s21_trim:\n");
  char *src[] = {"",          "tubik--",       "AAAAAaIZAtTTTTT",
                 "      bro", "exampleqwerty", "stringi_love21",
                 "abcdef",    "mac_dislike",   NULL,
                 "abc"};
  char *trim_balls[] = {"test", "",       "AT",  " ",   "qwerty",
                        "love", "abcdef", "ug;", "abc", NULL};
  char *ext[] = {"", "tubik--",     "aIZAt", "bro", "xampl", "stringi_love21",
                 "", "mac_dislike", NULL,    NULL};
  char *new = NULL;
  for (int i = 0; i < 10; i++) {
    new = s21_trim(src[i], trim_balls[i]);
    if (ext[i] == NULL) {
      ck_assert_ptr_eq(new, ext[i]);
    } else {
      ck_assert_str_eq(new, ext[i]);
    }
    printf("\033[0;32m[PASS]\033[0;0m s21_trim(\"%s\", \"%s\") = \"%s\"\n",
           src[i], trim_balls[i], ext[i]);
    free(new);
  }
}
END_TEST

START_TEST(test_s21_string_sprintf_c) {
  printf("\nTesting s21_sprintf_c:\n");

  char *buff = malloc(200);
  char *buff1 = malloc(200);

  ck_assert_int_eq(sprintf(buff, "|char: %c|", '\0'),
                   s21_sprintf(buff1, "|char: %c|", '\0'));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|char: %c|", '\0'));

  ck_assert_int_eq(sprintf(buff, "|char: %5c|", (char)255),
                   s21_sprintf(buff1, "|char: %5c|", (char)255));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|char: %5c|", (char)255));
  free(buff1);
  free(buff);
}
END_TEST

START_TEST(test_s21_string_sprintf_d) {
  printf("\nTesting s21_sprintf_d:\n");

  char *buff = malloc(200);
  char *buff1 = malloc(200);

  ck_assert_int_eq(sprintf(buff, "|int: %d & %d|", INT_MAX, INT_MIN),
                   s21_sprintf(buff1, "|int: %d & %d|", INT_MAX, INT_MIN));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|int: %d & %d|", INT_MAX, INT_MIN));

  ck_assert_int_eq(
      sprintf(buff, "|int: %+5d & %-10d & %+d & %+d|", 0, 123, 123, -123),
      s21_sprintf(buff1, "|int: %+5d & %-10d & %+d & %+d|", 0, 123, 123, -123));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf(
      "returned length = %d coincided\n",
      s21_sprintf(buff1, "|int: %+5d & %-10d & %+d & %+d|", 0, 123, 123, -123));

  ck_assert_int_eq(
      sprintf(buff, "|% d & % d & %5d & %5d|", 123, -123, 123, 123456),
      s21_sprintf(buff1, "|% d & % d & %5d & %5d|", 123, -123, 123, 123456));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|% d & % d & %5d & %5d|", 123, -123, 123, 123456));

  ck_assert_int_eq(sprintf(buff, "|%hd & %ld & %+10.5d & %-5d|", (short)32767,
                           2147483647L, 123, 0),
                   s21_sprintf(buff1, "|%hd & %ld & %+10.5d & %-5d|",
                               (short)32767, 2147483647L, 123, 0));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|%hd & %ld & %+10.5d & %-5d|", (short)32767,
                     2147483647L, 123, 0));

  free(buff1);
  free(buff);
}
END_TEST

START_TEST(test_s21_string_sprintf_f) {
  printf("\nTesting s21_sprintf_f:\n");
  char *buff = malloc(200);
  char *buff1 = malloc(200);
  ck_assert_int_eq(sprintf(buff, "|float: %.10f|", 0.0f),
                   s21_sprintf(buff1, "|float: %.10f|", 0.0f));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|float: %.10f|", 0.0f));
  ck_assert_int_eq(sprintf(buff, "|float: %.10f|", 1e-10f),
                   s21_sprintf(buff1, "|float: %.10f|", 1e-10f));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|float: %.10f|", 1e-10f));
  ck_assert_int_eq(sprintf(buff, "|%.3f|", 123.456789),
                   s21_sprintf(buff1, "|%.3f|", 123.456789));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|%.3f|", 123.456789));
  ck_assert_int_eq(sprintf(buff, "% -10.2f", 123.456),
                   s21_sprintf(buff1, "% -10.2f", 123.456));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "% -10.2f", 123.456));
  ck_assert_int_eq(sprintf(buff, "|float: %.10f|", 1e+16f),
                   s21_sprintf(buff1, "|float: %.10f|", 1e+16f));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|float: %.10f|", 1e+16f));
  ck_assert_int_eq(sprintf(buff, "%10f", 8.345),
                   s21_sprintf(buff1, "%10f", 8.345));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n", s21_sprintf(buff1, "%10f", 8.345));
  free(buff1);
  free(buff);
}
END_TEST

START_TEST(test_s21_string_sprintf_s) {
  printf("\nTesting s21_sprintf_s:\n");
  char *buff = malloc(200);
  char *buff1 = malloc(200);
  ck_assert_int_eq(sprintf(buff, "|string: %s|", ""),
                   s21_sprintf(buff1, "|string: %s|", ""));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|string: %s|", ""));
  ck_assert_int_eq(sprintf(buff, "|string: %s|", "   "),
                   s21_sprintf(buff1, "|string: %s|", "   "));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|string: %s|", "   "));
  ck_assert_int_eq(sprintf(buff, "|string: %s|", "hello\0world"),
                   s21_sprintf(buff1, "|string: %s|", "hello\0world"));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|string: %s|", "hello\0world"));
  ck_assert_int_eq(sprintf(buff, "|%.3s|", "hello"),
                   s21_sprintf(buff1, "|%.3s|", "hello"));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|%.3s|", "hello"));
  ck_assert_int_eq(sprintf(buff, "%10.5s", "Hello, World!"),
                   s21_sprintf(buff1, "%10.5s", "Hello, World!"));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "%10.5s", "Hello, World!"));
  ck_assert_int_eq(sprintf(buff, "%-10s", "aboba"),
                   s21_sprintf(buff1, "%-10s", "aboba"));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "%-10s", "aboba"));
  free(buff1);
  free(buff);
}
END_TEST

START_TEST(test_s21_string_sprintf_u) {
  printf("\nTesting s21_sprintf_u:\n");

  char *buff = malloc(200);
  char *buff1 = malloc(200);

  ck_assert_int_eq(sprintf(buff, "|uint: %u|", UINT_MAX),
                   s21_sprintf(buff1, "|uint: %u|", UINT_MAX));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|uint: %u|", UINT_MAX));

  ck_assert_int_eq(sprintf(buff, "|uint: %u|", 0),
                   s21_sprintf(buff1, "|uint: %u|", 0));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n",
         s21_sprintf(buff1, "|uint: %u|", 0));

  ck_assert_int_eq(sprintf(buff, "%hu", 65536),
                   s21_sprintf(buff1, "%hu", 65536));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n", s21_sprintf(buff1, "%hu", 65536));

  ck_assert_int_eq(sprintf(buff, "%10u", 8), s21_sprintf(buff1, "%10u", 8));
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n", s21_sprintf(buff1, "%10u", 8));
  free(buff1);
  free(buff);
}
END_TEST

START_TEST(test_s21_string_sprintf_multi_1) {
  printf("\nTesting s21_sprintf_multi:\n");
  char *buff = malloc(200);
  char *buff1 = malloc(200);

  int len1 = sprintf(
      buff, "|int: %d; uint: %u; char: %c; string: %s; float: %f; %%: %%|", -10,
      320, 'a', "helloo", -1789.111111f);
  int len2 = s21_sprintf(
      buff1, "|int: %d; uint: %u; char: %c; string: %s; float: %f; %%: %%|",
      -10, 320, 'a', "helloo", -1789.111111f);
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n", len2);
  len1 = sprintf(
      buff,
      "|int: %ld; uint: %lu; char: %2c; string: %3.2s; float: %+.4f; %%: %%|",
      -10l, 320l, 'a', "helloo", 1789.111111f);
  len2 = s21_sprintf(
      buff1,
      "|int: %ld; uint: %lu; char: %2c; string: %3.2s; float: %+.4f; %%: %%|",
      -10l, 320l, 'a', "helloo", 1789.111111f);
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n", len2);
  len1 = sprintf(
      buff,
      "|int: %2.4hd; uint: %-3hu; char: %2c; string: %3.2s; float: %+.4f; "
      "%%: %%|",
      100, 0, 'a', "helloo", 19.12f);
  len2 =
      s21_sprintf(buff1,
                  "|int: %2.4hd; uint: %-3hu; char: %2c; string: %3.2s; float: "
                  "%+.4f; %%: %%|",
                  100, 0, 'a', "helloo", 19.12f);
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n", len2);

  free(buff1);
  free(buff);
}
END_TEST

START_TEST(test_s21_string_sprintf_multi_2) {
  char *buff = malloc(200);
  char *buff1 = malloc(200);
  int len1 = sprintf(
      buff,
      "|int: %2.4hd; uint: %-3hu; char: %2c; string: %10s; float: % .8f; "
      "%%: %%|",
      0, 0, 'a', "sigbus", -789.123f);
  int len2 = s21_sprintf(
      buff1,
      "|int: %2.4hd; uint: %-3hu; char: %2c; string: %10s; float: % .8f; "
      "%%: %%|",
      0, 0, 'a', "sigbus", -789.123f);
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n", len2);
  len1 = sprintf(
      buff,
      "|int: %2.4hd; uint: %-3hu; char: %2c; string: %-.10s; float: %+.4f; "
      "%%: %%|",
      -1, 0, 'a', "segfault", 1789.111111f);
  len2 = s21_sprintf(
      buff1,
      "|int: %2.4hd; uint: %-3hu; char: %2c; string: %-.10s; float: "
      "%+.4f; %%: %%|",
      -1, 0, 'a', "segfault", 1789.111111f);
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n", len2);
  len1 =
      sprintf(buff,
              "|int: %+4.1hd; uint: %-3hu; char: %-4c; string: %3.2s; float: "
              "%+.14f; %%: %%|",
              0, 0, '_', "", 17892.123321f);
  len2 = s21_sprintf(
      buff1,
      "|int: %+4.1hd; uint: %-3hu; char: %-4c; string: %3.2s; float: "
      "%+.14f; %%: %%|",
      0, 0, '_', "", 17892.123321f);
  ck_assert_int_eq(len1, len2);
  ck_assert_str_eq(buff, buff1);
  printf("\033[0;32m[PASS]\033[0;0m\ns21_sprintf = %s\nsprintf =     %s\n",
         buff, buff1);
  printf("returned length = %d coincided\n", len2);
  free(buff1);
  free(buff);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("test_s21_string");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_string_memchr);
  tcase_add_test(tc_core, test_s21_string_memcmp);
  tcase_add_test(tc_core, test_s21_string_memcpy);
  tcase_add_test(tc_core, test_s21_string_memset);
  tcase_add_test(tc_core, test_s21_string_strncat);
  tcase_add_test(tc_core, test_s21_string_strchr);
  tcase_add_test(tc_core, test_s21_string_strncmp);
  tcase_add_test(tc_core, test_s21_string_strncpy);
  tcase_add_test(tc_core, test_s21_string_strcspn);
  tcase_add_test(tc_core, test_s21_string_strerror);
  tcase_add_test(tc_core, test_s21_string_strlen);
  tcase_add_test(tc_core, test_s21_string_strpbrk);
  tcase_add_test(tc_core, test_s21_string_strrchr);
  tcase_add_test(tc_core, test_s21_string_strstr);
  tcase_add_test(tc_core, test_s21_string_strtok);
  tcase_add_test(tc_core, test_s21_string_to_upper);
  tcase_add_test(tc_core, test_s21_string_to_lower);
  tcase_add_test(tc_core, test_s21_string_insert);
  tcase_add_test(tc_core, test_s21_string_trim);
  tcase_add_test(tc_core, test_s21_string_sprintf_c);
  tcase_add_test(tc_core, test_s21_string_sprintf_d);
  tcase_add_test(tc_core, test_s21_string_sprintf_f);
  tcase_add_test(tc_core, test_s21_string_sprintf_s);
  tcase_add_test(tc_core, test_s21_string_sprintf_u);
  tcase_add_test(tc_core, test_s21_string_sprintf_multi_1);
  tcase_add_test(tc_core, test_s21_string_sprintf_multi_2);
  suite_add_tcase(s, tc_core);
  return s;
}

int main() {
  Suite *s = s21_string_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
  return 0;
}
