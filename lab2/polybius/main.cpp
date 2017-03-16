//
// Created by karol on 3/16/17.
//

#include "Polybius.h"
#include <iostream>
#include <fstream>
#include <cstring>

using std::string;
using std::cout;
using std::endl;

int main(int argc, const char *argv[]){
    if(argc == 4){
        std::ifstream inputfile(argv[1]);
        std::ofstream outputfile(argv[2]);
        char line[256];

        if(!inputfile) {
            cout << "Nie mozna otworzyc pliku" << endl;
            return -1;
        }
        if(!outputfile) {
            cout << "Nie mozna otworzyc pliku" << endl;
            return -1;
        }

        if(!std::strcmp(argv[3],"1")){
            while(!inputfile.eof()){
                inputfile.getline(line,256);
                string linestr = line;
                outputfile << PolybiusCrypt(linestr) << endl;
            }
        }
        else if(!std::strcmp(argv[3],"0")){
            while(!inputfile.eof()){
                inputfile.getline(line,256);
                string linestr = line;
                outputfile << PolybiusDecrypt(linestr) << endl;
            }
        }
        else
            cout << "Nie podano prawidlowych argumentowxd" << endl;
        inputfile.close();
        outputfile.close();
    }
    else
        cout << "Nie podano prawidlowych argumentow" << endl;
    return 0;
}