#pragma once

class Analyser{
public:
    Analyser();
    ~Analyser();
   
    void analyseData(double incomingData);
    double outputData();
    void wrap(int n_dataSize);

private:

    double Average;
    double incomingData;
    double oldValue;
    int dataSize;
    int n_dataSize;
    
};
