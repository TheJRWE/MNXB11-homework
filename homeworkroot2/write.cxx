#include "TFile.h"
#include "TTree.h"
#include "HWroot2.h"
#include "TRandom3.h"

void write() {
    TTree* tree = new TTree("myTree", "Custom Tree");

    TFile* file = new TFile("myTree.root", "Recreate");

    TRandom3* gRandom = new TRandom3(0);
    Double_t px, py, pz;
    Double_t energy;

    tree->Branch("px", &px, "px/D");
    tree->Branch("py", &py, "py/D");
    tree->Branch("pz", &pz, "pz/D");

    Int_t nEvents = 100;

    for (Int_t i = 0; i < nEvents; i++) {
        px = gRandom->Gaus(0,.02);
        py = gRandom->Gaus(0,.02);
        pz = gRandom->Gaus(0,.02);

        tree->Fill();
    }
    file->Write();
    file->Close();

    delete file;
    delete gRandom;
}

void fillTree() {
    TFile* file = new TFile("tree_file.root", "Recreate");

    TTree* tree = new TTree("tree", "Tree of HWroot2 objects");

    TRandom3 gRandom(0); 

    for (Int_t i = 0; i < 100; i++) { 
        Double_t px = gRandom.Gaus(0, 0.02);
        Double_t py = gRandom.Gaus(0, 0.02);
        Double_t pz = gRandom.Gaus(0, 0.02);

        HWroot2* obj = new HWroot2(px, py, pz);
        tree->Branch(Form("HWroot2Obj%d", i), "HWroot2", &obj);
        tree->Fill();
    }

    tree->Write();
    file->Close();
}
