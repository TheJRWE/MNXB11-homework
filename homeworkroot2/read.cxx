#include "TFile.h"
#include "TTree.h"
#include "HWroot2.h"
#include <iostream>
#include "TH2D.h"
#include "TCanvas.h"
#include "TStyle.h"

void read() {
    TFile* file = TFile::Open("tree_file.root", "READ");
    TTree* tree = dynamic_cast<TTree*>(file->Get("tree"));

    HWroot2* myObj = new HWroot2();

    tree->SetBranchAddress("HWroot2Obj1", &myObj);

    Int_t N = tree->GetEntries();

    for (Int_t i = 0; i < N; i++) {
        tree->GetEntry(i);
        std::cout << "Event " << i << ": px = " << myObj->GetPx() << ", py = " << myObj->GetPy() << ", pz = " << myObj->GetPz() << std::endl;
    }

    file->Close();

    delete myObj;
}

void fillTH2AndDraw() {
    TFile* file = TFile::Open("tree_file.root", "Read");
    TTree* tree = dynamic_cast<TTree*>(file->Get("tree"));

    TH2D* hist = new TH2D("hist", "TH2 Histogram of px vs py", 100, -1.0, 1.0, 100, -1.0, 1.0);

    HWroot2* myObj = new HWroot2(); 

    tree->SetBranchAddress("HWroot2Obj1", &myObj);

    Int_t N = tree->GetEntries();

    for (Int_t i = 0; i < N; i++) {
        myObj = new HWroot2();
        tree->GetEntry(i);
        Double_t px = myObj->GetPx();
        Double_t py = myObj->GetPy();
        hist->Fill(px, py);
        delete myObj; 
    }

    TCanvas* canvas = new TCanvas("canvas", "TH2 Histogram", 800, 600);

    gStyle->SetPalette(1);
    hist->Draw("COLZ");

    file->Close();

    delete myObj;
}