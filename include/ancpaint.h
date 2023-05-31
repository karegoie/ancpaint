//
// Created by user on 2023-05-30.
//

#ifndef ANCPAINT_ANCPAINT_H
#define ANCPAINT_ANCPAINT_H

#include <iostream>

class reader {
public:
    static int filename_converter();
    static int pair_reader();
    static int fasta_reader();
    static int bed_reader();
};

class utils {
public:
    int distance_measure;
    int who_is_first;
    int generate_report;
    int cross_correlation;
};

class signal {
public:
    static int seq2voss();
    static int voss2signal;
    static int cwt;
};



#endif //ANCPAINT_ANCPAINT_H
