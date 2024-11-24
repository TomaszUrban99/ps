#include <iostream>
#include </home/tomasz/opt/AudioFile-master/AudioFile.h>
#include <stdlib.h>

#include "fading.hh"
#include "filter.hh"
#include "commandLineParser.hh"
#include "speedChange.hh"
#include "amplification.hh"

int main(int argc, char **argv){

    try {
        CommandLineParser parser(argc, argv);

        // If the user requests help, print it and exit
        if (parser.isHelpRequested()) {
            parser.printHelp();
            return 0;
        }

        std::string operation = parser.getOption("operation");       
        
         // Get the input WAV file and load data
        std::string inputWavFile = parser.positionalArguments_[0];
        AudioFile<double> file;
        file.load(inputWavFile);

        if ( operation == "filter"){

        // Example: Get filter parameters
        std::string cutoff = parser.getOption("frequency");
        std::string order = parser.getOption("order");
        std::string type = parser.getOption("type");

        // Print out the filter parameters and input file
        std::cout << "Input WAV File: " << inputWavFile << std::endl;
        std::cout << "Cutoff Frequency: " << cutoff << " Hz" << std::endl;
        std::cout << "Filter Order: " << order << std::endl;
        std::cout << "Filter Type: " << type << std::endl;
        
        if ( type == "lowpass" ){
            filter butterworth(atof(cutoff.c_str()),atoi(order.c_str()),lowpass,file.getSampleRate());
            butterworth.butterworth_filter(file.samples[0]);
        }
        else {
            filter butterworth(atof(cutoff.c_str()),atoi(order.c_str()),highpass,file.getSampleRate());
            butterworth.butterworth_filter(file.samples[0]);
        }

        }
        else if ( operation == "fading"){
            fading fade;
            fade.processFile(file.samples[0]);
        }
        else if ( operation == "speed_change"){
            SpeedChange speedchange(atof(parser.getOption("speed_change").c_str()));
            speedchange.processFile(file.samples[0]);
        }
        else if ( operation == "amplify"){
            Amplification amplify(atof(parser.getOption("amplify").c_str()));
            amplify.processFile(file.samples[0]);
        }

        std::string out = parser.getOption("output");
        std::cout << out << std::endl;
        file.save(out);

    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

    // Schemat architektury, dokładniej opisać, dokładnie opisać biblioteki
    // Etap II 
    // Dopisać w dokumentacji, że wszystko będzie korzystało z konsoli, jak korzystać z niej
    // Upload dokumentów 
    // wykonać wcześniej
    // W przypadku 