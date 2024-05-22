#ifndef ARRAY_H
#define ARRAY_H

#include "main.h"

#define MAX_LENGTH 1000

void Input(int arr[], int *size);
void Output(const int arr[], int *size);
int swap(int *a, int *b);
int Search(int a, int x);

int LinearSearch(int a[], int *size, int x);
int BinarySearch(int a[], int *size, int x);
int BinarySearch1(int a[], int *size, int x);

int Count_Freq_Appear(int a[], int *size, int x);

void BubbleSort(int a[], int *size);

void Element_Addition(int a[], int *size, int element_add, int pos);

int  Delete_Element(int *a, int *size, int element_del);

void sum_array(int arr1[], int arr2[], int *size);

void reverse_array(int a[], int *size);
#endif