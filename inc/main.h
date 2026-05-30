#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define max(a,b)    ((a > b) ? a : b)
#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME     40

#define YEARS   5
#define MONTHS  12

#define ROW   3
#define COL   3

#define FILE_BASE  "original.txt"
#define FILE_TEMP  "temp.txt"

void salary_cal(double hour);
int GuessNumberGame();
void PrimesArray(int n);

/* Tic tac toe game*/
void drawTable(char a[ROW][COL]);

void resetTable(char a[ROW][COL]);

int checkWin(char a[ROW][COL]);

int checkFreeSpace(char a[ROW][COL]);

int playerChoice(int *player, int *playerChoice);

void playerMove(char a[ROW][COL], int *player);

void fileExercise(FILE *file, FILE *fileTemp);


#endif