#ifndef _RINGBUFFER_H
#define _RINGBUFFER_H

#include "../inc/main.h"

#define MAX 100

typedef struct RingBuffer
{
   uint8_t head;
   uint8_t tail;
   uint8_t *buffer;
   uint8_t size;
   uint8_t fullFlag;
   uint8_t emptyFlag;
} RingBuffer_t;

extern RingBuffer_t RxBuffer;

void RingBuffer_Init(RingBuffer_t *dataBuffer, uint8_t *byte, uint8_t size);
uint8_t IsEmptyRing(RingBuffer_t *rxbuffer);
size_t GetLength(RingBuffer_t *rxbuffer);
void Ring_Buffer_Write(RingBuffer_t *rxbuffer, int data);
uint8_t Ring_Buffer_Read(RingBuffer_t *rxbuffer, uint8_t *data);

void DisplayRingBuffer(RingBuffer_t *rxbuffer);

#endif