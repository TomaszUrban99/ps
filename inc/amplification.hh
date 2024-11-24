#ifndef AMPLIFICATION_HH
#define AMPLIFICATION_HH

#include <vector>

class Amplification {
    double _gain; // Współczynnik wzmocnienia

public:
    // Konstruktor z wartością wzmocnienia
    Amplification(double gain);

    // Metoda wzmacniająca sygnał audio
    bool processFile(std::vector<double> &audioSignal);
};

#endif