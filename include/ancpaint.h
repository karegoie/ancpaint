//
// Created by user on 2023-05-30.
//

#ifndef ANCPAINT_ANCPAINT_H
#define ANCPAINT_ANCPAINT_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class reader {
public:
    static int pair_reader(string& first_file, string& second_file);
    int bed_reader(string& first_file, string& second_file);
};

class utils {
public:
    int distance_measure;
    int who_is_first;
    int generate_report;
};




#endif //ANCPAINT_ANCPAINT_H
