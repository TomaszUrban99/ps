#include "fading.hh"

    void fading::count_coefficient(int numberOfSamples){
        _a = 1 / (double) numberOfSamples;
    }

    bool fading::processFile(std::vector<double> &audioSignal){

        count_coefficient(audioSignal.size());

        for ( int i = 0; i < audioSignal.size(); ++i ){

            audioSignal[i] = audioSignal[i] * i * _a;
        }

        return true;
    }
