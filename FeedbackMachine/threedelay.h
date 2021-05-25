#pragma once
#include "delay.h"
#include "analyser.h"
#include "circBuffer.h"

class Threedelay{
    public:
        Threedelay(uint bufferSize);
        ~Threedelay();

        void takeInput(double input);
        double pushOutput();

        void tick();


        void setDelayTimes(uint dtime_1, uint dtime_2, uint dtime_3);        
        uint getDelayTime_1();
        uint getDelayTime_2();
        uint getDelayTime_3();

        void setFeedbackAmount(double feedbackAmount);
        double getFeedbackAmount();

        void anal(double a_input);

    private:
    //preparing delay objects
        CircBuffer* delay_1;
        CircBuffer* delay_2;
        CircBuffer* delay_3;
        Analyser* analyser;

        double input;
        double INPUT;
        double feedbackAmount;
        double output;

        uint dtime_1;
        uint dtime_2;
        uint dtime_3;
        uint bufferSize;

        double valium;
        double amp = 0.1;
        double glideTime = 20;
        double multiplier;
       
        
        

};