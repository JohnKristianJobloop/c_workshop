#ifndef WORDLE_H
#define WORDLE_H
#define WORD_LENGTH 5
#define RECORD_OF_WORD_LENGTH 6
#define MAX_AMOUNT_OF_TRIES 6

#define RESULT_RED 'R'
#define RESULT_YELLOW 'Y'
#define RESULT_GREEN 'G'

typedef char Result;

typedef Result ScanWordResult[WORD_LENGTH];


#endif