#include <Riostream.h>
#include <fstream>
#include <string>
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>

using namespace std;

void aribho_tree(){
    //carico il file .dat in input
    ifstream in("bkg_30/data.dat");

    //creo il TFile
    TFile *f = new TFile("bkg_30/tdata.root", "RECREATE");
    //creo il TTree
    TTree *tree = new TTree("tree", "hit sui chip");


    //inizializzo le variabili relative ai branch del tree
    int event, chip, x, y;
    //ora creo un collegamento branch <--> variabile
    tree->Branch("event", &event, "event/I");
    tree->Branch("chip", &chip, "chip/I");
    tree->Branch("x", &x, "x/I");
    tree->Branch("y", &y, "y/I");

    //leggo il file in input e salvo i dati nel TTree
    while (in >> event >> chip >> x >> y){
        tree->Fill();
    }

    tree->Write();
    f->Close();

}
