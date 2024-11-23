#ifndef FADING_HH
#define FADING_HH

#include <string>
#include <complex>
#include <liquid/liquid.h>
#include </home/tomasz/opt/AudioFile-master/AudioFile.h>

class fading {

    double _a;

    void count_coefficient( int numberOfSamples );

    public:

    bool processFile(std::vector<double> &audioSignal);

};

#endif