#include <iostream>
#include </home/tomasz/opt/AudioFile-master/AudioFile.h>
#include <fftw3.h>
#include <stdlib.h>

#include "fading.hh"
#include "filter.hh"
#include "commandLineParser.hh"

int main(int argc, char **argv){

/*    CommandLineParser parser(argc,argv);*/

    /* Object for storing data included in .WAV file */
    // AudioFile<double> file;

    /* Load WAV file */
    /*if (  ! file.load(argv[1]) ){
        std::cerr << "Failed to load file " << std::endl;
        return 1;
    }*/

    /* Create flter object */
    /*filter Filter ( 600, 4, butterworth, file.getSampleRate());
    Filter.butterworth_filter(file.samples[0]);

    file.save("/home/tomasz/Documents/example_output.wav");*/

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