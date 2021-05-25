#pragma once

typedef unsigned int uint;

class Delay{
    public:
        Delay(uint size);
        ~Delay();
    
        void resetBufferSize(uint size);
//delaytime in samples
        void setDelayTime(uint delayTime);
        uint getDelayTime();

        void allocateBuffer();
        void releaseBuffer();

//Input and Output
        inline void write(double input){ 
            buffer[writeHead] = input; 
            }
        inline double read(){ 
            return buffer[readHead]; 
            }

//tick() method
        inline void tick(){
            tickWriteHead();
            tickReadHead();
        }

    private:
//incrementing the write and read heads
        inline void tickWriteHead(){
            writeHead++;
            wrap(writeHead);
        }
        inline void tickReadHead(){
            readHead++;
            wrap(readHead);
        }
// When the write and read head reach the last element of the buffer they need to be
// redirected to the start of the buffer. This is called wrapping.
        inline void wrap(uint& head){
            if (head >= size) head -= size;
        }

//Altering buffer size


    float* buffer;
    uint buffersize;
    uint size; 
    uint writeHead;
    uint readHead;
    uint delayTime;
    uint delayTimeSamples;

};