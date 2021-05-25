#include "threedelay.h"
#include <complex>
#include <iostream>

Threedelay::Threedelay(uint bufferSize){
    delay_1 = new CircBuffer(bufferSize);
    delay_2 = new CircBuffer(bufferSize);
    delay_3 = new CircBuffer(bufferSize); 
    delay_1->resetSize(bufferSize);
    delay_2->resetSize(bufferSize);
    delay_3->resetSize(bufferSize);
    analyser = new Analyser();  
}

Threedelay::~Threedelay(){
}

void Threedelay::tick(){
    delay_1->tick();
    delay_2->tick();
    delay_3->tick();
    amp *= multiplier;
//     std::cout << multiplier << std::endl;
}

void Threedelay::takeInput(double input){
    INPUT = input + (output * feedbackAmount);   
    delay_1->write(INPUT);
    delay_2->write(INPUT);
    delay_3->write(INPUT);
}

double Threedelay::pushOutput(){
    output = (  (   delay_1->read() +
                    delay_2->read() +
                    delay_3->read()
                     ) / 3.);
   
                
    return output;
}

void Threedelay::setDelayTimes(uint dtime_1, uint dtime_2, uint dtime_3){
    delay_1->setDistanceRW(dtime_1);
    delay_2->setDistanceRW(dtime_2);
    delay_3->setDistanceRW(dtime_3);

    delay_1->getDistanceRW();
    delay_2->getDistanceRW();
    delay_3->getDistanceRW();
}
uint Threedelay::getDelayTime_1(){
    return delay_1->getDistanceRW();
}
uint Threedelay::getDelayTime_2(){
    return delay_2->getDistanceRW();
}
uint Threedelay::getDelayTime_3(){
    return delay_3->getDistanceRW();
}

void Threedelay::setFeedbackAmount(double feedbackAmount){
    this->feedbackAmount = feedbackAmount;
}

double Threedelay::getFeedbackAmount(){
    return feedbackAmount;
}

//Pass absolute values only
void Threedelay::anal(double a_input){
    analyser->analyseData(std::abs(a_input));
    valium = analyser->outputData();
    
        if(valium >= 1){
           // multiplier = 1.0 + (log(0.00001) - log(1.0)) / (glideTime);
            setFeedbackAmount(0.0);
            getFeedbackAmount();
        }
        else{
          //  multiplier = 1.0 + (log(1.0) - log(0.0001)) / (glideTime);
            setFeedbackAmount(1.0);
            getFeedbackAmount();
        }
}