#ifndef FILTER_HH
#define FILTER_HH

#include <fftw3.h>
#include </home/tomasz/opt/AudioFile-master/AudioFile.h>

class filter {

    AudioFile<double> _fileHandle;
    double _boundary;

    public:

    bool process_file();

};

#endif