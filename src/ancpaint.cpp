#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>

#include <seqan3/io/sequence_file/input.hpp>

#include "../include/ancpaint.h"

//
// Created by user on 2023-05-30.
//

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
        std::vector<std::vector<std::string>> genome;

        while (std::getline(file, line)) {
            std::vector<std::string> row;
            std::istringstream iss(line);
            std::string value;

            while (std::getline(iss, value, '\t')) {
                row.emplace_back(value);
            }
            genome.emplace_back(row);
        }
    }
    return 0;
}

int reader::fasta_reader() {
    std::string file_name = "seq.fa";
    seqan3::sequence_file_input file_in{file_name};
    for (auto& [seq, id, qual]: file_in) {

    }
    return 0;
}