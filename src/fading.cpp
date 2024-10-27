#include "fading.hh"

    void fading::count_coefficient(){
        _a = 1 / (double) _fileHandle.getNumSamplesPerChannel();
    }

    bool fading::loadFile(std::string pathToWAVFile){
        
        if(!_fileHandle.load(pathToWAVFile)){
            std::cerr<<"Failed to load WAV file"<<std::endl;
            return false;
        }
        else{
            std::cout << "File " << pathToWAVFile << ": succesfully loaded" << std::endl;
            return true;
        }
    }

    bool fading::processFile(){

        count_coefficient();

        std::cout << _a << std::endl;
        
        for ( int i = 0; i < _fileHandle.getNumSamplesPerChannel(); ++i ){
            _fileHandle.samples[0][i] = _fileHandle.samples[0][i] * i * _a;
        }

        return true;
    }

    bool fading::outputFile(std::string pathToWAVOutputFile){
        _fileHandle.save(pathToWAVOutputFile,AudioFileFormat::Wave);
        return true;
    }