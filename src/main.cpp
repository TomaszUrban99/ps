#include <iostream>
#include </home/tomasz/opt/AudioFile-master/AudioFile.h>

int main(int argc, char **argv){

    AudioFile<double> audioFile;

    audioFile.load("/home/tomasz/Downloads/africa-toto.wav");

    audioFile.printSummary();

    return 0;
}