// Generate random oscillator
#include <cmath>
#include "math.h"
#include <iostream>
#include "RandomOSC.h"

RandomOSC::RandomOSC(){}

RandomOSC::~RandomOSC(){}

void RandomOSC::rOsc(){
    randomInt = rand() % 100 + 2;
    level = randomInt / 100.0;
    startLevel = endLevel;
    endLevel = level;
//    std::cout << "randomInt " << randomInt << std::endl;
    std::cout << "level " << level << std::endl;
//    std::cout << "startLevel " << startLevel << std::endl;
//    std::cout << "endLevel " << endLevel << std::endl;
}

double RandomOSC::interpOsc(int lengthInSamples){
    multiplier = 1.0 + (log(endLevel) - log(startLevel)) / (lengthInSamples);
    amp *= multiplier;
    return amp;
    //       std::cout << "multiplier " << multiplier << std::endl;
}

double RandomOSC::outputRandom(){
    amp *= multiplier;
//    std::cout << "amp " << amp - 1 << std::endl;
    return amp;
}


