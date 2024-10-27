#include <iostream>
#include </home/tomasz/opt/AudioFile-master/AudioFile.h>
#include <fftw3.h>

#include "fading.hh"

int main(int argc, char **argv){

    fading Fading;

    Fading.loadFile("/home/tomasz/Downloads/africa-toto.wav");
    Fading.processFile();
    Fading.outputFile("/home/tomasz/Documents/example_output.wav");

    //AudioFile<double> audioFile;
    //fftw_complex *in, *out;
    //fftw_plan p;

    //in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 6570432);
    //out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 6570432);

    //audioFile.load("/home/tomasz/Downloads/africa-toto.wav");
    //std::vector<std::vector<double>> samples = audioFile.samples;

    /*for ( int i = 0; i < 6570432; ++i ){
        in[0][i] = samples[0][i];
        in[1][i] = 0;
    }*/

    //p = fftw_plan_dft_1d(6570432,in,out,FFTW_FORWARD,FFTW_ESTIMATE);

    //std::cout << "Dim 1: " << samples.size();
    //std::cout << "Dim 2: " << samples[0].size();

    //audioFile.save("/home/tomasz/Documents/example_output.wav", AudioFileFormat::Wave);

    //audioFile.printSummary();

    return 0;
}