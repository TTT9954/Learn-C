#ifndef STRINGSELF_H
#define STRINGSELF_H

#include "main.h"

bool isSpace(char c);

int count_char_noSpace(char *s);

int countChar_withSpace(const char s[]);

int count_word(char s[30]);

void Delete(char s[30], int vitri);

char *Add_char(char s[30], char k, int pos);

char upperChar(char c);

void invert(char s[30]);

char *reverse(char s[]);

char *concat(char s1[], char s2[]);

int StringCompare(const char s1[], const char s2[]);

int isDigit(char c);

int isAlpha(char c);

uint8_t CharToInt(char c);

uint32_t StringToInt(const char s[]);

#endif