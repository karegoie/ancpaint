#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <filesystem>
#include <math.h>
#include <seqan3/io/sequence_file/all.hpp>
#include "../fCWT/src/fcwt/fcwt.h"
#include "../include/ancpaint.h"

//
// Created by hyunsu on 2023-05-30.
//

//using namespace seqan3::literals;

int reader::filename_converter() {
    //TODO: add
    return 0;
}

int reader::pair_reader() {
    std::ifstream file("pair.txt");
    if(file.is_open()) {
        std::string line;
        std::vector<std::pair<std::string, std::string>> pairs;

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string pair1, pair2;

            std::getline(iss, pair1, '\t');
            std::getline(iss, pair2, '\t');

            pairs.emplace_back(pair1, pair2);
        }
    }
    return 0;
}

int reader::bed_reader() {
    std::ifstream file("anno.bed");
    if (file.is_open()) {
        std::string line;
        std::vector<std::vector<std::string>> anno;

        while (std::getline(file, line)) {
            std::vector<std::string> row;
            std::istringstream iss(line);
            std::string value;

            while (std::getline(iss, value, '\t')) {
                row.emplace_back(value);
            }
            anno.emplace_back(row);
        }
    }
    return 0;
}

int reader::fasta_reader() {
    std::filesystem::path current_path = std::filesystem::current_path() / "seq.fa";
    seqan3::sequence_file_input fin{current_path};

    std::map<std::string,std::vector<seqan3::dna5>> genome;
    for (auto& [seq, id, qual]: fin) {
        genome.insert(std::make_pair(id, seq));
    }
    return 0;
}


int repeat_annotator::seq2voss(seqan3::dna5_vector& sequence) {
    std::vector<std::array<bool, 4>> one_hot_encoded;
    for (auto const& nucleotide : sequence)
    {
        std::array<bool, 4> encoded{};

        switch (nucleotide.to_char())
        {
            case 'A':
                encoded[0] = true;
                break;
            case 'T':
                encoded[1] = true;
                break;
            case 'G':
                encoded[2] = true;
                break;
            case 'C':
                encoded[3] = true;
                break;
            default:
                encoded[0] = true;
                break;
        }
        one_hot_encoded.push_back(encoded);
    }
    return 0;
}

int voss2cwt() {

    int n = 100000; //signal length
    const int fs = 1000; //sampling frequency
    float twopi = 2.0*3.1415;

    //3000 frequencies spread logartihmically between 1 and 32 Hz
    const float f0 = 1;
    const float f1 = 32;
    const int fn = 3000;

    //Define number of threads for multithreaded use
    const int nthreads = 8;

    //input: n real numbers
    std::vector<float> sig(n);

    //output: n x scales
    std::vector<complex<float>> tfm(n*fn);

    //initialize with 1 Hz cosine wave
    for(auto& el : sig) {
        el = cos(twopi*((float)(&el - &sig[0])/(float)fs));
    }

    //Create a wavelet object
    Wavelet *wavelet;

    //Initialize a Morlet wavelet having sigma=2.0;
    Morlet morl(2.0f);
    wavelet = &morl;

    //Create the continuous wavelet transform object
    //constructor(wavelet, nthreads, optplan)
    //
    //Arguments
    //wavelet   - pointer to wavelet object
    //nthreads  - number of threads to use
    //optplan   - use FFTW optimization plans if true
    //normalization - take extra time to normalize time-frequency matrix
    FCWT fcwt(wavelet, nthreads, true, false);

    //Generate frequencies
    //constructor(wavelet, dist, fs, f0, f1, fn)
    //
    //Arguments
    //wavelet   - pointer to wavelet object
    //dist      - FCWT_LOGSCALES | FCWT_LINFREQS for logarithmic or linear distribution frequency range
    //fs        - sample frequency
    //f0        - beginning of frequency range
    //f1        - end of frequency range
    //fn        - number of wavelets to generate across frequency range
    Scales scs(wavelet, FCWT_LINFREQS, fs, f0, f1, fn);

    //Perform a CWT
    //cwt(input, length, output, scales)
    //
    //Arguments:
    //input     - floating pointer to input array
    //length    - integer signal length
    //output    - floating pointer to output array
    //scales    - pointer to scales object
    fcwt.cwt(&sig[0], n, &tfm[0], &scs);

    return 0;
}
