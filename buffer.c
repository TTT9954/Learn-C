#include <stdint.h>

typedef uint8_t Buff_ReturnType;

typedef struct Buffer
{
    uint8_t* data;
    uint16_t length;
    struct Buffer* link;
} Buffer;

Buffer* newBuffer(void)
{
    Buffer* _newBuff = (Buffer*)malloc(sizeof(Buffer));
    if (_newBuff != BUFF_NULL)
    {
        _newBuff->data = BUFF_NULL;
        _newBuff->length = 0;
        _newBuff->link = BUFF_NULL;
    }
    return _newBuff;
}

Buff_ReturnType Buffer_AddData(Buffer* buff, uint8_t* u8DataPtr, uint16_t length)
{
    Buffer* _buff = buff;
    Buffer* head_buff = buff;

    static uint8_t state = BUFF_UNLOCK;
    while(state == BUFF_LOCK){}
    state = BUFF_LOCK;
    
    while (_buff != BUFF_NULL)
    {
        if (_buff->length != 0 && _buff->data != BUFF_NULL)
        {
            head_buff = _buff;
            _buff = _buff->link;
        }
        else
        {
            _buff->data = (uint8_t*)malloc(length);
            if (_buff->data == BUFF_NULL)
            {
                state = BUFF_UNLOCK;
                return BUFF_NOT_OK;
            }

            for (uint16_t countByte = 0; countByte < length; countByte++)
            {
                _buff->data[countByte] = u8DataPtr[countByte];
            }

            _buff->length = length;
            state = BUFF_UNLOCK;
            return BUFF_OK;
        }
    }

    _buff = (Buffer*)malloc(sizeof(Buffer));
    if (_buff == BUFF_NULL)
    {
        state = BUFF_UNLOCK;
        return BUFF_NOT_OK;
    }

    _buff->data = (uint8_t*)malloc(length);
    if (_buff->data == BUFF_NULL)
    {
        free(_buff);
        state = BUFF_UNLOCK;
        return BUFF_NOT_OK;
    }

    _buff->length = 0;
    _buff->link = BUFF_NULL;
    if (head_buff != BUFF_NULL)
    {
        head_buff->link = _buff;
    }

    for (uint16_t countByte = 0; countByte < length; countByte++)
    {
        _buff->data[countByte] = u8DataPtr[countByte];
    }
    _buff->length = length;
    state = BUFF_UNLOCK;
    return BUFF_OK;
}

Buff_ReturnType Buffer_GetData(Buffer* buff, uint16_t position, uint8_t* u8DataPtr, uint16_t* length)
{
    Buffer* _buff = buff;
    uint16_t Count = Buffer_CountData(buff);

    static uint8_t state = BUFF_UNLOCK;
    while(state == BUFF_LOCK){}
    state = BUFF_LOCK;

    if (position >= Count || _buff->length == 0)
    {
        state = BUFF_UNLOCK;
        return BUFF_NOT_OK;
    }


    for (uint16_t countData = 0; countData < position; countData++)
    {
        _buff = _buff->link;
    }

    for (uint16_t countByte = 0; countByte < _buff->length; countByte++)
    {
        u8DataPtr[countByte] = _buff->data[countByte];
    }
    *length = _buff->length;
    state = BUFF_UNLOCK;
    return BUFF_OK;
}

Buff_ReturnType Buffer_GetData(Buffer* buff, uint16_t position, uint8_t* u8DataPtr, uint16_t* length)
{
    Buffer* _buff = buff;
    uint16_t Count = Buffer_CountData(buff);

    static uint8_t state = BUFF_UNLOCK;
    while(state == BUFF_LOCK){}
    state = BUFF_LOCK;

    if (position >= Count || _buff->length == 0)
    {
        state = BUFF_UNLOCK;
        return BUFF_NOT_OK;
    }


    for (uint16_t countData = 0; countData < position; countData++)
    {
        _buff = _buff->link;
    }

    for (uint16_t countByte = 0; countByte < _buff->length; countByte++)
    {
        u8DataPtr[countByte] = _buff->data[countByte];
    }
    *length = _buff->length;
    state = BUFF_UNLOCK;
    return BUFF_OK;
}

Buff_ReturnType Buffer_DeleteData(Buffer* buff, uint16_t position)
{
    Buffer* lastbuff = buff;
    Buffer* currbuff = buff;
    static uint8_t state = BUFF_UNLOCK;
    while(state == BUFF_LOCK){}
    state = BUFF_LOCK;

    uint16_t Count = Buffer_CountData(buff);

    if (position >= Count)
    {
        state = BUFF_UNLOCK;
        return BUFF_NOT_OK;
    }

    for (uint16_t countData = 0; countData < (Count - 1); countData++)
    {
        if (countData >= position)
        {
            if (currbuff->data != BUFF_NULL && countData == position)
            {
                free(currbuff->data);
                currbuff->data = NULL;
            }
            currbuff->data = currbuff->link->data;
            currbuff->length = currbuff->link->length;
        }
        lastbuff = currbuff;
        currbuff = currbuff->link;       
    }

    lastbuff->link = BUFF_NULL;
    if (Count == 1)
    {
        if (currbuff->data != BUFF_NULL)
        {
            free(currbuff->data);
        }
        currbuff->data = BUFF_NULL;
        currbuff->length = 0;
        currbuff->link = BUFF_NULL;

    }
    else
    {
        free(currbuff);
        currbuff = NULL;
    }

    state = BUFF_UNLOCK;
    return BUFF_OK;
}

Buff_ReturnType Buffer_GetData(Buffer* buff, uint16_t position, uint8_t* u8DataPtr, uint16_t* length)
{
    Buffer* _buff = buff;
    uint16_t Count = Buffer_CountData(buff);

    static uint8_t state = BUFF_UNLOCK;
    while(state == BUFF_LOCK){}
    state = BUFF_LOCK;

    if (position >= Count || _buff->length == 0)
    {
        state = BUFF_UNLOCK;
        return BUFF_NOT_OK;
    }


    for (uint16_t countData = 0; countData < position; countData++)
    {
        _buff = _buff->link;
    }

    for (uint16_t countByte = 0; countByte < _buff->length; countByte++)
    {
        u8DataPtr[countByte] = _buff->data[countByte];
    }
    *length = _buff->length;
    state = BUFF_UNLOCK;
    return BUFF_OK;
}
Buff_ReturnType Buffer_DeleteData(Buffer* buff, uint16_t position)
{
    Buffer* lastbuff = buff;
    Buffer* currbuff = buff;
    static uint8_t state = BUFF_UNLOCK;
    while(state == BUFF_LOCK){}
    state = BUFF_LOCK;

    uint16_t Count = Buffer_CountData(buff);

    if (position >= Count)
    {
        state = BUFF_UNLOCK;
        return BUFF_NOT_OK;
    }

    for (uint16_t countData = 0; countData < (Count - 1); countData++)
    {
        if (countData >= position)
        {
            if (currbuff->data != BUFF_NULL && countData == position)
            {
                free(currbuff->data);
                currbuff->data = NULL;
            }
            currbuff->data = currbuff->link->data;
            currbuff->length = currbuff->link->length;
        }
        lastbuff = currbuff;
        currbuff = currbuff->link;       
    }

    lastbuff->link = BUFF_NULL;
    if (Count == 1)
    {
        if (currbuff->data != BUFF_NULL)
        {
            free(currbuff->data);
        }
        currbuff->data = BUFF_NULL;
        currbuff->length = 0;
        currbuff->link = BUFF_NULL;

    }
    else
    {
        free(currbuff);
        currbuff = NULL;
    }

    state = BUFF_UNLOCK;
    return BUFF_OK;
}

void Buffer_Dispose(Buffer* buff)
{
    static uint8_t state = BUFF_UNLOCK;
    while(state == BUFF_LOCK){}
    state = BUFF_LOCK;
    uint16_t nbData = Buffer_CountData(buff);
    for (uint16_t countData = 0; countData < nbData; countData++)
    {
        Buffer_DeleteData(buff, 0);
    }
    free(buff);
    buff = NULL;
    state = BUFF_UNLOCK;
}