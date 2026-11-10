/*
    LFNS2 2026: Group 4
    First code for reading the .dat files, saving the data inside a TTree
    Info in the readme.md file 
*/

#include <Riostream.h>
#include <fstream>
#include <string>
#include <TFile.h>
#include <TNtuple.h>
#include <TTree.h>
#include <TBranch.h>
#include "Point.h"

using namespace std;

void tree(const string& infile = "provadata.dat"){

    TFile hfile("htree.root","RECREATE"); //file on which the Tree is saved
    TTree *tree = new TTree("T","TTree con 2 branches"); 
    TClonesArray *hits = new TClonesArray("Point",100);

    //static Point spoint;
    tree->Branch("Hits",&hits); 
    /* Prima prova: commentando i branch sotto, riempiendo solo "hits" 
    */
    //tree->Branch("ChipNumber",spoint.getChip());
    //tree->Branch("StaveNumber",spoint.getStave());


    ifstream in(infile); //open input file
    if(!in){
        cout << "Error: opening input file" << endl;
        return;
    }
    

    int eventNumber = 0;
    int ev_id, chip_id, hit_x, hit_y;
    int j=0;

    while (in >> ev_id >> chip_id >> hit_x >> hit_y){
        if(eventNumber =! ev_id){
            tree->Fill(); //fill the ttree with the TClonesArray previously filled
            hits->Clear(); 
            j=0;
            eventNumber = ev_id;
        }
        new(hits[j])Punto(chip_id, hit_x, hit_y);
        j++;

    }
}