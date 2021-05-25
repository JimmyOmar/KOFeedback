// Analyse datastream and get average
#include "analyser.h"

Analyser::Analyser(){
    oldValue = 0;
    dataSize = 0;
}

Analyser::~Analyser(){}

void Analyser::analyseData(double incomingData){
    dataSize++;
    oldValue += incomingData; // Add new value to old value
    Average = oldValue / dataSize; // Divide sum of data with amount of data = average
//    wrap(dataSize);
}

double Analyser::outputData(){
    return Average;
}

void Analyser::wrap(int n_dataSize){
    if(n_dataSize == 4000){
        dataSize = 0;
    }
}
