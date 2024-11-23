#include "commandLineParser.hh"

CommandLineParser::CommandLineParser(int argc, char** argv) {
        parse(argc, argv);
}

bool CommandLineParser::isHelpRequested() const {
        return (args_.count("help") > 0 || args_.count("h") > 0);
    }

std::string CommandLineParser::getOption(const std::string& option) const {
        if (args_.count(option) > 0) {
            return args_.at(option);
        } else {
            return "";
        }
    }

void CommandLineParser::printHelp() const {
        std::cout << "Usage: program [options] <input.wav>\n";
        std::cout << "Options:\n";
        std::cout << "  -h, --help          Show this help message\n";
        std::cout << "  -f, --frequency <cutoff>   Set the cutoff frequency for the filter (e.g., 500 Hz)\n";
        std::cout << "  -o, --order <order>       Set the filter order (e.g., 4)\n";
        std::cout << "  -t, --type <type>         Set the filter type (lowpass or highpass)\n";
        std::cout << "  <input.wav>              The input WAV file to be processed\n";
}

bool CommandLineParser::isValidFilterType(const std::string& type) const {
        return (type == "lowpass" || type == "highpass");
    }

bool CommandLineParser::isValidOutput(const std::string& path) const {
    if (path.substr(path.size()-1,4).compare("*.wav")==0)
    return true;
    else
    return false;
}

void CommandLineParser::parse(int argc, char** argv) {
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];

            // Handle flag options like -h, --help
            if (arg == "-h" || arg == "--help") {
                args_["help"] = "";
            }
            // Handle cutoff frequency (-f)
            else if (arg == "-f" || arg == "--frequency") {
                if (i + 1 < argc) {
                    args_["frequency"] = argv[++i];
                } else {
                    throw std::invalid_argument("Error: Option -f requires a cutoff frequency.");
                }
            }
            // Handle filter order (-o)
            else if (arg == "-o" || arg == "--order") {
                if (i + 1 < argc) {
                    args_["order"] = argv[++i];
                } else {
                    throw std::invalid_argument("Error: Option -o requires a filter order.");
                }
            }
            // Handle filter type (-t)
            else if (arg == "-t" || arg == "--type") {
                if (i + 1 < argc) {
                    std::string type = argv[++i];
                    if (!isValidFilterType(type)) {
                        throw std::invalid_argument("Error: Invalid filter type. Use 'lowpass' or 'highpass'.");
                    }
                    args_["type"] = type;
                } else {
                    throw std::invalid_argument("Error: Option -t requires a filter type ('lowpass' or 'highpass').");
                }
            }

            else if ( arg == "-d" || arg == "--destination" ){
                if ( i + 1 < argc ){
                         std::string type = argv[++i];
                    if (!isValidOutput(type)) {
                        args_["output"] = type;
                    }
                    else{
                    args_["output"] = "default_output.wav";
                    }
                } else {
                    throw std::invalid_argument("Error: Option -d requires output .wav file");
                }
            }
            else if ( arg == "-w" || arg == "--what" ){
                args_["operation"] = "fading";
            }
            else if ( arg == "-c" || arg == "--clean" ){
                args_["operation"] = "filter";
            }
            // Positional argument (input WAV file)
            else {
                positionalArguments_.push_back(arg);
            }
        }

        // Check if we have a positional argument (input file)
        if (positionalArguments_.empty()) {
            throw std::invalid_argument("Error: Missing input WAV file.");
        }
    }