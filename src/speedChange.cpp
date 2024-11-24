#include "speedChange.hh"

SpeedChange::SpeedChange(double speedFactor) : _speedFactor(speedFactor) {}

bool SpeedChange::processFile(std::vector<double> &audioSignal) {
    if (_speedFactor <= 0) {
        return false; // Niedodatnie współczynniek nie ma sensu
    }

    std::vector<double> modifiedSignal;

    double step = _speedFactor;

    for (std::size_t i = 0; i < audioSignal.size(); i += static_cast<std::size_t>(step)) {
        modifiedSignal.push_back(audioSignal[i]);
    }

    audioSignal = std::move(modifiedSignal);

    return true;
}