#include "amplification.hh"

Amplification::Amplification(double gain) : _gain(gain) {}

bool Amplification::processFile(std::vector<double> &audioSignal) {
    for (int i = 0; i < audioSignal.size(); ++i) {
        audioSignal[i] *= _gain;
    }
    return true;
}