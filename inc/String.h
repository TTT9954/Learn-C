#ifndef STRING1_H
#define STRING1_H

#include <string.h>
#include <stdio.h>

int count_char(char *s);

void count_word(char s[30]);

void Delete(char s[30], int vitri);

void Add(char s[30], char k, int vitri);

void hoa_thuong(char s[30]);

void invert(char s[30]);

char *reverse(char s[]);

char *concat(char s1[], char s2[]);

int strcmp1(char s1[], char s2[]);

#endif