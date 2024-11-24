#ifndef SPEEDCHANGE_HH
#define SPEEDCHANGE_HH

#include <vector>

class SpeedChange {
    double _speedFactor; // Współczynnik zmiany prędkości

public:
    SpeedChange(double speedFactor);

    bool processFile(std::vector<double> &audioSignal);
};

#endif