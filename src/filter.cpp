#include "filter.hh"

bool filter::load_file(std::string pathToWavFile){

        if(!_fileHandle.load(pathToWavFile)){
            std::cerr<<"Failed to load WAV file"<<std::endl;
            return false;
        }
        else{
            std::cout << "File " << pathToWavFile << ": succesfully loaded" << std::endl;
            return true;
        }
}

bool filter::outputFile(std::string pathToWAVOutputFile){
        _fileHandle.save(pathToWAVOutputFile,AudioFileFormat::Wave);
        return true;
}

bool filter::process_file( int freqBoundary ){
    
    fftw_complex *out_rev;
    
    fftw_plan rev_p;
    
    fftw_complex *in;
    
    fftw_complex *in_rev;
    fftw_complex *out;
    
    fftw_plan p;

    /* Input array */
    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * _fileHandle.getNumSamplesPerChannel());
    /* Output array */
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * _fileHandle.getNumSamplesPerChannel());

    
    p = fftw_plan_dft_1d(_fileHandle.getNumSamplesPerChannel(),in,out, FFTW_FORWARD, FFTW_ESTIMATE);
    rev_p = fftw_plan_dft_1d(_fileHandle.getNumSamplesPerChannel(),out,in, FFTW_BACKWARD, FFTW_ESTIMATE);
    
    for ( int i = 0; i < _fileHandle.getNumSamplesPerChannel(); ++i){
        in[i][0] = _fileHandle.samples[0][i];
        in[i][1] = 0;
    }

    fftw_execute_dft(p,in,out);

    /* Apply filter */
    double delta_freq = ((double) _fileHandle.getSampleRate()) / _fileHandle.getNumSamplesPerChannel();
    int sample_number = freqBoundary / delta_freq;

    for ( int i = sample_number; i < _fileHandle.getNumSamplesPerChannel(); ++i ){
        out[i][0] = 0;
        out[i][1] = 0;
    }

    fftw_execute_dft(rev_p,out,in);

    for ( int i = 0; i < _fileHandle.getNumSamplesPerChannel(); ++i){
        _fileHandle.samples[0][i] = in[i][0] / _fileHandle.getNumSamplesPerChannel();
    } 
   

    fftw_destroy_plan(p);
    fftw_destroy_plan(rev_p);
    fftw_free(in);
    fftw_free(out);
    
    return true;
}