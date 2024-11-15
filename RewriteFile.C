#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <TH1F.h>
#include <TCanvas.h>
using namespace std;

Bool_t RewriteFile(string filename0 = "Cs-137.dat", string filename = "Cs-137.bin"){
    fstream myfile;
    myfile.open(filename, ios::binary | ios::out);

    fstream myfile0;
    myfile0.open(filename0, ios::in);

    string line;
    while(!myfile0.eof()){
        myfile0>>line;
        Double_t value = stod(line);
        myfile.write((char*)&value, sizeof(Double_t));
    }

    return kTRUE;
}