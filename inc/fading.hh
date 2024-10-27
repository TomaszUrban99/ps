#ifndef FADING_HH
#define FADING_HH

#include <string>
#include </home/tomasz/opt/AudioFile-master/AudioFile.h>

class fading {

    AudioFile<double> _fileHandle;

    double _a;

    void count_coefficient();

    public:

    /*!
        \brief Load data from .wav file

        \par std::string pathToWAVFile - path to .wav file

        \retval
    */
    bool loadFile(std::string pathToWAVFile);

    bool processFile();

    bool outputFile(std::string pathToWAVOutputFile);
};

#endif