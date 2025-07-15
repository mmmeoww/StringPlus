#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

typedef struct flags {
  int length_h;
  int length_l;

  int flag_minus;
  int flag_plus;
  int flag_space;

  int acc;
  int width;
} flag;

char *string_int(long int num, flag flags);
char *string_uint(unsigned long int num);
char *string_float(double num, flag flags);
void process_int(long int num, char *str, int *len, flag flags);
void process_uint(unsigned long int num, char *str, int *len, flag flags);
void process_float(double num, char *str, int *len, flag flags);
void process_char(char c, char *str, int *len, flag flags);
void process_string(const char *strNew, char *str, int *len, flag flags);
int is_specifer(char c);
int is_digit(char c);
int power(int num, int pow);
int find_width_acc(const char *format, s21_size_t *i);
char *add_zeros(char *str, flag flags);
void find_flags(flag *flags, const char *format, s21_size_t *i);

int s21_sprintf(char *str, const char *format, ...) {
  int len = 0;
  va_list args;
  va_start(args, format);
  for (s21_size_t i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%' && format[i + 1] != '\0') {
      flag flags = {0};
      find_flags(&flags, format, &i);
      switch (format[i]) {
        case 'c':
          process_char(va_arg(args, int), str, &len, flags);
          break;
        case 'd':
          process_int(va_arg(args, long int), str, &len, flags);
          break;
        case 'f':
          process_float(va_arg(args, double), str, &len, flags);
          break;
        case 's':
          process_string(va_arg(args, const char *), str, &len, flags);
          break;
        case 'u':
          process_uint(va_arg(args, long unsigned int), str, &len, flags);
          break;
        case '%':
          process_char('%', str, &len, flags);
          break;
        default:
          break;
      }
    } else {
      str[len] = format[i];
    }
    len++;
  }
  str[len] = '\0';
  va_end(args);
  return len;
}

char *string_int(long int num, flag flags) {
  char *str_int = malloc(1);
  int num_temp = num;
  num = (num < 0) ? -num : num;
  int i = 0;
  if (num == 0) {
    str_int = realloc(str_int, i + 1);
    str_int[i++] = num % 10 + 48;
  }
  while (num > 0) {
    str_int = realloc(str_int, i + 1);
    str_int[i++] = num % 10 + 48;
    num /= 10;
  }
  if (flags.flag_space && num_temp >= 0) {
    str_int = realloc(str_int, i + 1);
    str_int[i++] = ' ';
  } else if (flags.flag_plus && num_temp >= 0) {
    str_int = realloc(str_int, i + 1);
    str_int[i++] = '+';
  } else if (num_temp < 0) {
    str_int = realloc(str_int, i + 1);
    str_int[i++] = '-';
  }
  str_int = realloc(str_int, i + 1);
  str_int[i] = '\0';
  for (int j = 0, k = i - 1; j < k; j++, k--) {
    char temp = str_int[j];
    str_int[j] = str_int[k];
    str_int[k] = temp;
  }
  return str_int;
}

char *string_uint(unsigned long int num) {
  char *str_uint = malloc(1);
  int i = 0;
  if (num == 0) {
    str_uint = realloc(str_uint, i + 1);
    str_uint[i++] = num % 10 + 48;
  }
  while (num > 0) {
    str_uint = realloc(str_uint, i + 1);
    str_uint[i++] = num % 10 + 48;
    num /= 10;
  }
  str_uint = realloc(str_uint, i + 1);
  str_uint[i] = '\0';
  for (int j = 0, k = i - 1; j < k; j++, k--) {
    char temp = str_uint[j];
    str_uint[j] = str_uint[k];
    str_uint[k] = temp;
  }
  return str_uint;
}

char *string_float(double num, flag flags) {
  int acc = (flags.acc) ? flags.acc : 6;
  char *str_float = malloc(1);
  int i = 0, sign = 0;
  if (num < 0) {
    str_float = realloc(str_float, ++i + 1);
    str_float[0] = '-';
    num = -num;
    sign = 1;
  } else if (flags.flag_space) {
    str_float = realloc(str_float, ++i + 1);
    str_float[0] = ' ';
    flags.flag_plus++;
    sign = 1;
  } else if (flags.flag_plus) {
    str_float = realloc(str_float, ++i + 1);
    str_float[0] = '+';
    sign = 1;
  }
  long long unsigned int num_exponent = num;
  while (num_exponent > 0) {
    str_float = realloc(str_float, i + 1);
    str_float[i++] = (num_exponent % 10) + 48;
    num_exponent /= 10;
  }
  for (int j = sign, k = i - 1; j < k; j++, k--) {
    char temp = str_float[j];
    str_float[j] = str_float[k];
    str_float[k] = temp;
  }
  if (num >= 0 && num < 1) {
    str_float = realloc(str_float, i + 1);
    str_float[i++] = '0';
  }
  float num_decimal = num;
  str_float = realloc(str_float, i + 1);
  str_float[i++] = '.';
  num_decimal -= (int)num;
  for (int j = 0; j < acc; j++) {
    num_decimal *= 10;
    int digit = (j == acc - 1) ? num_decimal + 0.5 : num_decimal;
    str_float = realloc(str_float, i + 1);
    str_float[i++] = digit + 48;
    num_decimal -= (int)num_decimal;
  }
  str_float = realloc(str_float, i + 1);
  str_float[i] = '\0';
  return str_float;
}

void process_int(long int num, char *str, int *len, flag flags) {
  if (flags.length_h) {
    num = (short int)num;
  }
  if (!flags.length_l) {
    num = (int)num;
  }
  char *str_int = string_int(num, flags);
  if ((int)s21_strlen(str_int) < flags.acc) {
    str_int = add_zeros(str_int, flags);
  }
  int len_num = s21_strlen(str_int);
  if (flags.width > len_num && !flags.flag_minus) {
    for (int l = 0; l < flags.width - len_num; l++) {
      str[(*len)++] = ' ';
    }
  }
  for (int i = 0; i < len_num; i++) {
    str[(*len)++] = str_int[i];
  }
  if (flags.width > len_num && flags.flag_minus) {
    for (int l = len_num; l < flags.width; l++) {
      str[(*len)++] = ' ';
    }
  }
  (*len)--;
  free(str_int);
}

void process_uint(unsigned long int num, char *str, int *len, flag flags) {
  if (flags.length_h) {
    num = (short unsigned int)num;
  }
  if (!flags.length_l) {
    num = (unsigned int)num;
  }
  char *str_uint = string_uint(num);
  int len_num = s21_strlen(str_uint);
  if (flags.width > len_num && !flags.flag_minus) {
    for (int l = 0; l < flags.width - len_num; l++) {
      str[(*len)++] = ' ';
    }
  }
  for (int i = 0; i < len_num; i++) {
    str[(*len)++] = str_uint[i];
  }
  if (flags.width > len_num && flags.flag_minus) {
    for (int l = len_num; l < flags.width; l++) {
      str[(*len)++] = ' ';
    }
  }
  (*len)--;
  free(str_uint);
}

void process_float(double num, char *str, int *len, flag flags) {
  char *str_float = string_float(num, flags);
  int len_num = s21_strlen(str_float);
  if (flags.width > len_num && !flags.flag_minus) {
    for (int l = 0; l < flags.width - len_num; l++) {
      str[(*len)++] = ' ';
    }
  }
  for (int i = 0; i < len_num; i++) {
    str[(*len)++] = str_float[i];
  }
  if (flags.width > len_num && flags.flag_minus) {
    for (int l = len_num; l < flags.width; l++) {
      str[(*len)++] = ' ';
    }
  }
  (*len)--;
  free(str_float);
}

void process_char(char c, char *str, int *len, flag flags) {
  if (flags.width > 1) {
    if (flags.flag_minus) {
      str[(*len)++] = c;
      for (int i = 0; i < flags.width - 1; i++) {
        str[(*len)++] = ' ';
      }
    } else {
      for (int i = 1; i < flags.width; i++) {
        str[(*len)++] = ' ';
      }
      str[(*len)++] = c;
    }
    (*len)--;
  } else {
    str[*len] = c;
  }
}

void process_string(const char *strNew, char *str, int *len, flag flags) {
  int len_new = s21_strlen(strNew);
  if (flags.acc && flags.acc <= len_new) {
    len_new = flags.acc;
  }
  if (flags.width > len_new && !flags.flag_minus) {
    for (int l = 0; l < flags.width - len_new; l++) {
      str[(*len)++] = ' ';
    }
  }
  for (int i = 0; i < len_new; i++) {
    str[(*len)++] = strNew[i];
  }
  if (flags.width > len_new && flags.flag_minus) {
    for (int l = len_new; l < flags.width; l++) {
      str[(*len)++] = ' ';
    }
  }
  (*len)--;
}

int is_specifer(char c) {
  int res = 0;
  if (c == 'c' || c == 'd' || c == 'f' || c == 's' || c == 'u' || c == '%') {
    res = 1;
  }
  return res;
}

int is_digit(char c) {
  int res = 0;
  if (c > 47 && c < 58) {
    res = 1;
  }
  return res;
}

int power(int num, int pow) {
  int num_temp = num;
  num = 1;
  while (pow > 0) {
    num *= num_temp;
    pow--;
  }
  return num;
}

int find_width_acc(const char *format, s21_size_t *i) {
  int res = 0;
  int width_start = *i;
  while (is_digit(format[*i])) {
    (*i)++;
  }
  int width_end = *i;
  int n = 0;
  for (int j = width_end - 1; j >= width_start; j--) {
    res += (format[j] - 48) * power(10, n);
    n++;
  }
  (*i)--;
  return res;
}

char *add_zeros(char *str, flag flags) {
  int len = s21_strlen(str);
  char *str_new = malloc(1);
  int sign = (str[0] == '-' || str[0] == '+' || str[0] == ' ') ? 1 : 0;
  if (sign) {
    str_new[0] = str[0];
  }
  int new_len = sign;
  if (len < flags.acc) {
    int j = 0;
    for (j = 0; j < flags.acc - len + sign; j++) {
      str_new = realloc(str_new, ++new_len);
      str_new[j + sign] = '0';
    }
    for (int i = 0; i < len - sign; i++) {
      str_new = realloc(str_new, ++new_len);
      str_new[i + j + sign] = str[i + sign];
      if (i == len - sign - 1) {
        str_new = realloc(str_new, ++new_len);
        str_new[i + j + 1 + sign] = '\0';
      }
    }
  }
  free(str);
  return str_new;
}

void find_flags(flag *flags, const char *format, s21_size_t *i) {
  (*i)++;
  while (!is_specifer(format[*i]) && format[*i] != '\0') {
    if (format[*i] == '-') {
      flags->flag_minus = 1;
    } else if (format[*i] == '+') {
      flags->flag_plus = 1;
    } else if (format[*i] == ' ') {
      flags->flag_space = 1;
    } else if (format[*i] == 'h') {
      flags->length_h = 1;
    } else if (format[*i] == 'l') {
      flags->length_l = 1;
    } else if (is_digit(format[*i]) && !flags->width && !flags->acc) {
      flags->width = find_width_acc(format, i);
    } else if (format[*i] == '.' && !flags->acc && is_digit(format[*i + 1])) {
      (*i)++;
      flags->acc = find_width_acc(format, i);
    }
    (*i)++;
  }
}
