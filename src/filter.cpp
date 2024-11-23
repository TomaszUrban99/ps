#include "filter.hh"

filter::filter ( double boundary, int order,  enum filter_type _type, double sample_rate ){
    
    this->_boundary = boundary;
    this->_order = order;
    this->_type = _type;
    this->_sample_rate = sample_rate;

    this->_A = (float*) ( malloc(sizeof(float)*(this->_order+1)));
    this->_B = (float*) ( malloc(sizeof(float)*(this->_order+1)));
  
}

filter::~filter(){

    /* Free memory alocated for filter coefficients */
    free(this->_A);
    free(this->_B);
}

bool filter::butterworth_filter ( std::vector<double> &inputSequence ){

    /* Check filter type */
    if ( this->_type == lowpass ){
    liquid_iirdes(LIQUID_IIRDES_BUTTER,
    LIQUID_IIRDES_LOWPASS,LIQUID_IIRDES_TF, this->_order,this->_boundary/this->_sample_rate,0,
    120,1, this->_B, this->_A);
    }
    else if ( this->_type == highpass ){
        liquid_iirdes(LIQUID_IIRDES_BUTTER,
    LIQUID_IIRDES_HIGHPASS,LIQUID_IIRDES_TF, this->_order,this->_boundary/this->_sample_rate,0,
    120,1, this->_B, this->_A);
    }

    std::vector<double> outputSequence(inputSequence.size(),0.0);

    for ( int i = 0; i <= this->_order; ++i ){
        outputSequence[i] = inputSequence[i];
    }

    /* Apply filter - working in time domain */
    for ( int j = this->_order; j < inputSequence.size(); ++j ){

        /* Feedforward part: related to input */
        double feed_forward_part = 0;
        for ( int i = 0; i <= this->_order; ++i ){
            
            if ( j - i  >= 0){ 
            feed_forward_part = feed_forward_part + _B[i] * inputSequence[j - i];
            }
        }

        /* Feedback part: related to output */
        double feed_back_part = 0.0;
       
        for ( int i = 1; i <= this->_order; ++i ){
            if ( j - i >= 0){
            feed_back_part = feed_back_part + _A[i] * outputSequence[j - i];
            }
        }

        outputSequence[j] = feed_forward_part - feed_back_part; 
    }

    inputSequence = std::move(outputSequence);

    return true;
}