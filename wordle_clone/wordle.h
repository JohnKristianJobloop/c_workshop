#ifndef WORDLE_H

#include <stdio.h>

#define WORDLE_H
#define WORD_LENGTH 5
#define RECORD_OF_WORD_LENGTH 6
#define MAX_AMOUNT_OF_TRIES 6



typedef enum {
    RESULT_RED,
    RESULT_GREEN,
    RESULT_YELLOW
} ScanWordResult;

typedef ScanWordResult ScanWordResults[WORD_LENGTH];

typedef char* string;



long get_file_size(FILE* file);

long get_offsett_marking_random_word(long fileLen);

void read_random_word_from_file(FILE* file, long offsett, char* buffer);

void read_word_from_user(string buffer, int len);

void check_word(string userGuess, string correctWord, ScanWordResults results, int len);

int has_won(ScanWordResults results);

void get_color_from_result(ScanWordResult result);
#endif