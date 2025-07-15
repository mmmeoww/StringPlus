CC =gcc
FLAGS=-Wall -Werror -Wextra -std=c11
SOURCE=$(wildcard s21_*.c)
OBJECTS=$(patsubst %.c, %.o, $(SOURCE))
COVERAGE=-fprofile-arcs -ftest-coverage

SYSTEM := $(shell uname -s)
ifeq ($(SYSTEM),Linux)
    LFLAGS = -lcheck -lsubunit -lm -lrt -lpthread -L. -l:s21_string.a
endif
ifeq ($(SYSTEM),Darwin)
	LFLAGS = -lcheck -lm -lpthread s21_string.a
endif

all: s21_string.a

gcov_report: clean
	$(CC) $(FLAGS) $(COVERAGE) -c s21_string.h $(SOURCE)
	ar -rcs s21_string.a $(OBJECTS)
	$(CC) $(FLAGS) $(COVERAGE) -c test.c -o test.o
	$(CC) $(FLAGS) $(COVERAGE) test.o -o test $(LFLAGS)
	chmod +x test
	./test
	mkdir gcov_report
	gcov test.c $(SOURCE)
	lcov -c -d ./ --output-file ./coverage.info
	genhtml ./coverage.info --output-directory ./gcov_report/

test: test.o s21_string.a
	$(CC) $(FLAGS) test.o -o test $(LFLAGS)
	chmod +x test
	./test

test.o: test.c s21_string.h
	$(CC) $(FLAGS) -c test.c -o test.o

s21_string.a: $(OBJECTS)
	ar -rcs s21_string.a $(OBJECTS)

$(OBJECTS): $(SOURCE)
	$(CC) $(FLAGS) -c s21_string.h $(SOURCE)

clean:
	rm -rf s21_string.a test *.o *.gcda *.gcno *.gcov *.gch ./gcov_report *.html *.css *.info
