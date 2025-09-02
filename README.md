# Signal Processors (Procesory Sygnałowe)

This repository contains source code developed as a final project for a university course.  
The project focuses on implementing basic audio signal processing effects.

## Implemented Effects
- **Low-pass filter**
- **High-pass filter**
- **Signal fading**
- **Amplification**
- **Playback speed adjustment**
## Effects Description

1. Low-pass filter. In the project, a Butterworth filter will be used for low-pass filtering. The operation of a low-pass filter consists of passing components with frequencies lower than the cutoff frequency. The cutoff frequency will be given as a parameter of the effect. An additional parameter will be the filter order. First, the filter will be designed using the \texttt{liquid\_iirdes()} function from the liquid-dsp library. The calculated coefficients will then be applied to a first-order IIR filter structure. Next, the filter will be used to process the audio signal given as a vector of \texttt{double} values.
2. High-pass filter. In the project, a Butterworth filter will be used for high-pass filtering. The operation of a high-pass filter consists of passing components with frequencies higher than the cutoff frequency. The cutoff frequency will be given as a parameter of the effect. An additional parameter will be the filter order. First, the filter will be designed using the \texttt{liquid\_iirdes()} function from the liquid-dsp library. The calculated coefficients will then be applied to a first-order IIR filter structure. Next, the filter will be used to process the audio signal given as a vector of \texttt{double} values.
3. Signal fading – consists of gradually decreasing the amplitude of the sound as the music plays. No parameters.
4. Amplification – consists of multiplying the sound amplitude by a given value. The parameter is a multiplier by which the amplitude of the sound will be increased.
5. Speed change – consists of increasing or decreasing the frequency of the sound by a given value. The parameter will be a multiplier by which the playback speed is changed.

## Technologies and Libraries

The project will be written in C++. For this technology, free libraries are available that allow faster project implementation.

The following libraries will be used in the project:

1. LIQUID-DSP - a library implementing functions related to digital signal processing. It enables, among others, filter design,
2. AUDIOFILE – a template library that enables reading files in .wav format

## Architecture

The software will be created according to the principles of object-oriented programming. Each effect will be represented by one class. Each class will contain attributes defining the parameters of the given effect. For example, for a low-pass filter, such parameters will be the cutoff frequency and the filter order. Executing a given effect will be associated with calling an appropriate method, with a vector of audio samples as the argument.

The audio to be processed will be loaded from a .wav file using the AudioFile library. Based on the program’s input arguments, the selected effect will be applied to the loaded sequence of samples.

After processing, the sequence of samples will be saved to an output file (also specified as an input argument). The AudioFile library will be used for this purpose.

## Program User Manual

### Description

The program allows processing of audio files in WAV format. It supports operations such as:

1. Amplification (volume change),
2. Speed change (speeding up or slowing down playback),
3. Filtering (applying audio filters such as low-pass and high-pass),
4. Fading (signal fading).

It also allows saving the processed signal to an output file.

### Running the program

The program is run from the command line, with the following syntax:

'audio_processor [options] <input_file.wav>'

Where:

1. '<input\_file.wav>' is a required argument specifying the WAV file to process,
2. Options are described below.

### Options

| Option | Description | Example Usage |
| ----------- | ----------- | ------------------------------ |
| -f, --frequency | Specifies the cutoff frequency for filters (only for filters) | audio\_processor -f 1000 input.wav |
| -o, --order | Specifies the filter order | audio\_processor -o 4 -f 1000 -t lowpass input.wav |
| -t, --type    | Specifies filter type: 'lowpass' or 'highpass' | audio\_processor -t lowpass -f 1000 input.wav |
| -d, --destination | Specifies the path to the output file (default: default\_output.wav) | audio\_processor -d output.wav input.wav |
| -a, --amplify     | Enables amplification (volume change). A value for amplification can be given. | audio\_processor -a 1.5 input.wav |
| -p, --speed-change | Changes playback speed (acceleration or slowdown factor) | audio\_processor -p 1.2 input.wav |
| -w, --what   | Enables fading effect (signal fading). | audio\_processor -w input.wav |
| -c, --clean | Performs filtering on the sound (cleaning) | audio\_processor -c -f 1000 -t lowpass input.wav |

### Examples

#### Amplification

To increase the volume of an audio file by 1.5 times, use the '-a' option:
'audio_processor -a 1.5 input.wav'

By default, the result will be saved to default_output.wav}.

#### Low-pass filtering

Applying a low-pass filter with a cutoff frequency of 1000 Hz:
'audio_processor -f 1000 -t lowpass input.wav'

The result will be saved to the default file 'default_output.wav'.

#### Speed change

Changing playback speed: To speed up the sound 1.2 times:
'audio_processor -p 1.2 input.wav'

#### High-pass filtering

Applying a high-pass filter with a cutoff frequency of 500 Hz:
'audio_processor -f 500 -t highpass input.wav'

#### Saving to a specific output file
'audio_processor -d output.wav input.wav'

#### Fading
Fading effect: To apply the fading effect:
'audio_processor -w input.wav'

### Notes

1. Positional arguments: The program requires one positional argument — the path to the input WAV file. This is mandatory.
2. Missing arguments: If you do not provide the required options, the program will return an error and display an appropriate message.
3. Options requiring arguments: Some options (e.g. -f, -o, -a, -p) require a value after the option. Missing such values will cause an error.

The program allows easy manipulation of WAV audio files, offering a wide range of operations such as speed change, amplification, filtering, and more. Just run the program with the appropriate options to achieve the desired effect.

\end{document}
