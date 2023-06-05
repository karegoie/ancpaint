//
// Created by user on 2023-05-30.
//

#ifndef ANCPAINT_ANCPAINT_H
#define ANCPAINT_ANCPAINT_H

#include <iostream>

namespace reader {
    static int filename_converter();
    static int pair_reader();
    static int fasta_reader();
    static int bed_reader();
};


namespace repeat_annotator {
    static int seq2voss(seqan3::dna5_vector& sequence);
    static int voss2cwt
}

#endif //ANCPAINT_ANCPAINT_H
