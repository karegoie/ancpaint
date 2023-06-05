#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <filesystem>
#include <ranges>

#include <seqan3/io/sequence_file/all.hpp>

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

//TODO: write it
int msa::pairwise_aligner(std::map<std::string, std::vector<seqan3::dna5>> pair1, std::map<std::string, std::vector<seqan3::dna5>> pair2,
                          std::map<std::string, std::vector<seqan3::dna5>> ancestor) {
    for (auto i = pair1.begin(); i != pair1.end(); i++) {
        continue;
    }

    return 0;
}
