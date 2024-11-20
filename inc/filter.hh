#ifndef FILTER_HH
#define FILTER_HH

#include <fftw3.h>
#include <cmath>
#include </home/tomasz/opt/AudioFile-master/AudioFile.h>

class filter {

    AudioFile<double> _fileHandle;
    double _boundary;

    public:

    bool load_file(std::string pathToWavFile);

    bool process_file( int freqBoundary );

    bool outputFile(std::string pathToWAVOutputFile);

};

#endif