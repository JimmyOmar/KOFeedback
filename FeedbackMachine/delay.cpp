/*
    A single Delay Line object
    in essence a circular buffer, with two "heads"
One of these heads writes to the buffer, and the other reads from the bufffer
The Distance between these two heads is the delay time. 
*/

#include <iostream>
#include "delay.h"
#include <cstring>

Delay::Delay(uint size) :  buffersize(size), writeHead(0), readHead(0)
{
    allocateBuffer();
}

Delay::~Delay(){
   releaseBuffer(); 
}

void Delay::resetBufferSize(uint size){
    buffersize = size;
    
    releaseBuffer();
    allocateBuffer();
}

void Delay::allocateBuffer(){
    //sets all samples to 0
    buffer = (float*)malloc(buffersize * sizeof(float));
    memset(buffer, 0, buffersize * sizeof(float));
}

void Delay::releaseBuffer(){
    //frees the data allocated with memset
//TODO what is memset? Is it like mutex?
    free(buffer);
}

void Delay::setDelayTime(uint delayTime){
    delayTimeSamples = delayTime;
    readHead = writeHead - delayTimeSamples + buffersize;
    wrap(readHead);
}

uint Delay::getDelayTime(){
    return delayTimeSamples;
}