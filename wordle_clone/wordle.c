#include <stdlib.h>
#include <time.h>
#include "wordle.h"
#include "ansi_color_codes.h"
#include <string.h>

long get_file_size(FILE* file){
    long currentPosition = ftell(file);
    fseek(file, 0L, SEEK_END);
    long size = ftell(file);
    fseek(file, currentPosition, SEEK_SET);
    return size;
}

long get_offsett_marking_random_word(long fileLen){
    long recordAmount = fileLen / (long)RECORD_OF_WORD_LENGTH;
    return (long)((rand() % recordAmount) * RECORD_OF_WORD_LENGTH);
}

void read_random_word_from_file(FILE* file, long offsett, char* buffer){
    fseek(file, offsett, SEEK_SET);
    fread(buffer, sizeof(char), WORD_LENGTH, file);
    buffer[WORD_LENGTH] = '\0';
}

void read_word_from_user(string buffer, int len){
    do{
        if (!fgets(buffer, len, stdin)){
            return;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
    }while(buffer[0] == '\0');
}

void check_word(string userWord, string correctWord, ScanWordResults results, int len){
    int charCount[26] = {0};

    for (int i = 0; i < len; i++){
        char correct = correctWord[i];
        ScanWordResult result = correct == userWord[i] ? RESULT_GREEN : RESULT_RED;
        if (result == RESULT_GREEN) results[i] = result;
        else {
            results[i] = 0;
            if (correct >= 'a' && correct <= 'z') charCount[correct-'a']++;
            else if (correct >= 'A' && correct <= 'Z') charCount[correct-'A']++;
        }
    }

    for (int i = 0; i < len; i++){
        if (results[i] == RESULT_GREEN) continue;
        char guess = userWord[i];
        int idx = -1;
        if (guess >= 'a' && guess <= 'z') idx = guess-'a';
        else if (guess >= 'A' && guess <= 'Z') idx = guess-'A';
        if (idx >= 0 && charCount[idx] > 0){
            results[i] = RESULT_YELLOW;
            charCount[idx]--;
        } else results[i] = RESULT_RED;
    }
}

void get_color_from_result(ScanWordResult result){
    switch (result)
    {
    case RESULT_GREEN:
        printf(GRN);
        break;
    case RESULT_RED:
        printf(RED);
        break;
    case RESULT_YELLOW:
        printf(YEL);
        break;
    default:
        printf(reset);
        break;
    }
}

int has_won(ScanWordResults results){
    for(int i = 0; i < WORD_LENGTH; i++){
        if (results[i] != RESULT_GREEN) return 1;
    }
    return 0;
}

int main(){
    srand((unsigned) time(NULL));
    FILE* file = fopen("./wl.txt", "rb");
    if (!file){
        perror("fopen failed to open");
        return 1;
    }
    long fileSize = get_file_size(file);

    long wordOffset = get_offsett_marking_random_word(fileSize);

    char* buffer = malloc(RECORD_OF_WORD_LENGTH * sizeof(char));
    read_random_word_from_file(file, wordOffset, buffer);

    char* userGuess = malloc(RECORD_OF_WORD_LENGTH * sizeof(char));
    int tries = 0;
    ScanWordResults results;


    while(tries < MAX_AMOUNT_OF_TRIES ){
        read_word_from_user(userGuess, RECORD_OF_WORD_LENGTH);
        check_word(userGuess, buffer, results, WORD_LENGTH);
        for (int i = 0; i < WORD_LENGTH; i++){
            get_color_from_result(results[i]);
            printf("%c", userGuess[i]);
        }
        printf(reset);
        printf("\n");
        if (has_won(results) == 0){
            printf("You win the game!\n");
            break;
        }
        tries++;
    }
    

    free(buffer);
    free(userGuess);
    return 0;
}