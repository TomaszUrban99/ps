#ifndef FILTER_HH
#define FILTER_HH

#include <vector>
#include <fftw3.h>
#include <cmath>
#include <liquid/liquid.h>
#include <memory>

#include </home/tomasz/opt/AudioFile-master/AudioFile.h>

enum filter_type { butterworth, lowpass, highpass };

class filter {

    double _boundary;
    int _order;
    double _sample_rate;

    enum filter_type _type;

    iirfilt_crcf _filterObj;

    float *_A;
    float *_B;

    public:

    filter ( double boundary, int order,  enum filter_type _type, double sample_rate );

    ~filter();

    bool butterworth_filter ( std::vector<double> &inputSequence );

};

#endif