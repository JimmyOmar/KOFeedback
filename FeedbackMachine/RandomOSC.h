#pragma once

class RandomOSC{
public:
    RandomOSC();
    ~RandomOSC();
    void rOsc();
    double interpOsc(int lengthInSamples);
    double outputRandom();
private:
    int randomInt;
    double level;
    double multiplier;
    double endLevel = 0.01;
    double startLevel;
    int lengthInSamples;
    double amp = 1;
};
