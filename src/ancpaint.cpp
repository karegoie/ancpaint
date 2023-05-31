#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "../include/ancpaint.h"

//
// Created by user on 2023-05-30.
//
using namespace std;

int reader::pair_reader(string& first_file, string& second_file) {
    vector <pair<string, string>> gene_pair;

    string line;
    ifstream file("./pair.txt");
    if(file.is_open()){
        unsigned int oe = 0;
        while(getline(file, line, '\t')) {
            string one, two;
            if(oe % 2 == 0) {
                one = line;

            } else {
                two = line;
            }
            pair<string, string> p = make_pair(one, two);
            gene_pair.push_back(p);
            oe++;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
        return 1;
    }

    return 0;
}

int reader::bed_reader(string& first_file, string& second_file) {

    return 0;
}