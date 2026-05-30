#ifndef _STRUCT_3_H
#define _STRUCT_3_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX 100

typedef struct SUMMARY_BILL
{
    char date[50];
    int price;
} SUM_BILL;

extern SUM_BILL bill[MAX];

void menu1(uint8_t *exit);
void display_bill(SUM_BILL *bill, uint8_t *quantity);
void add_bill(SUM_BILL *bill, uint8_t *quantity);
void delete_bill(SUM_BILL *bill, uint8_t *quantity);
void delete_all(SUM_BILL *bill, uint8_t *quantity);

#endif