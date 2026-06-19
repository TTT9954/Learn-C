#include "RingBuffer.h"

RingBuffer_t RxBuffer;

void RingBuffer_Init(RingBuffer_t *dataBuffer, uint8_t *byte, uint8_t size)
{
    dataBuffer->buffer = byte;
    dataBuffer->size = size;
    dataBuffer->head = 0;
    dataBuffer->tail = 0;
    dataBuffer->fullFlag = 0;
    dataBuffer->emptyFlag = 0;
}

uint8_t IsEmptyRing(RingBuffer_t *rxbuffer)
{
   return ((!(rxbuffer->fullFlag)) && (rxbuffer->head == rxbuffer->tail));
}

int IsFullRing(RingBuffer_t *rxbuffer)
{
   return rxbuffer->fullFlag;
}

size_t GetLength(RingBuffer_t *rxbuffer)
{
   size_t len = rxbuffer->size;

   if(IsFullRing(rxbuffer)) len = rxbuffer->size;
   else
   {
      if(rxbuffer->tail >= rxbuffer->head)
      {
        len = rxbuffer->tail - rxbuffer->head;
      }
      else if(rxbuffer->tail < rxbuffer->head) 
      {
         len = rxbuffer->size + rxbuffer->tail - rxbuffer->head;
      }
      else len = 0; 
   }

   return len;
}

void Ring_Buffer_Write(RingBuffer_t *rxbuffer, int data)
{
   rxbuffer->buffer[rxbuffer->tail] = data;
    
   rxbuffer->tail = (rxbuffer->tail + 1) % (rxbuffer->size);

   rxbuffer->fullFlag = (rxbuffer->tail == rxbuffer->head);
}

uint8_t Ring_Buffer_Read(RingBuffer_t *rxbuffer, uint8_t *data)
{
    if(rxbuffer->head == rxbuffer->tail)
    {
        return 0;
    }
    *data = rxbuffer->buffer[rxbuffer->head];

    rxbuffer->head = (rxbuffer->head + 1) % (rxbuffer->size);

    return 1;
}

void DisplayRingBuffer(RingBuffer_t *rxbuffer)
{
   for(uint32_t i = 0; i < rxbuffer->size; i++)
   {
      printf("%d ", rxbuffer->buffer[i]);
   }
   printf("\n");
}