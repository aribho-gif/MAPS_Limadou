/*
    LFNS2 2026: Group 4
    First code for reading the .dat files, saving the data inside a TNtuple
    Info in the readme.md file 
*/
#include <Riostream.h>
#include <fstream>
#include <string>
#include <TFile.h>
#include <TNtuple.h>

using namespace std;

void usedata(const string& infile = "bkg_30/data.dat"){
    ifstream in(infile); //open input file
    if(!in){
        cout << "Error: opening input file" << endl;
        return;
    }
    
    int countElements = 0;
    int countEvents;
    int x, y, z, w;
    
    TNtuple* ntuple = new TNtuple("ntuple", "hits", "event_count:chip_id:hit_x:hit_y");
    float ntuple_element[4];

    while (in >> x >> y >> z >> w){
        ntuple_element[0] = x;
        ntuple_element[1] = y;
        ntuple_element[2] = z;
        ntuple_element[3] = w;
        countElements++;
        countEvents = int(ntuple_element[0]) + 1;

        ntuple->Fill(ntuple_element);
    }

    in.close();

    cout << endl << "Print the ntuple" << endl;
    ntuple->Print();
    /*
    for(int i=0; i<ntuple->GetEntries(); i++){
        cout << i << ")  ";
        ntuple->GetEvent(i);
        for(int j=0; j<4; j++) cout << event_count << "    " << chip_id << "    " << hit_x << "     " << hit_y << endl;
    } */
}