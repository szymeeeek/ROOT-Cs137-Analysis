#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <TH1F.h>
#include <TCanvas.h>
using namespace std;

Bool_t WidmoCs(string filename = "Cs-137.dat"){
    gSystem->Load("libstdc++");
    const Int_t nBins = 1025;

    double minChannel = 0, maxChannel = nBins;

    double m = 2.4;
    double b = 38.0;

    double energyBins[nBins + 1];
    for (int i = 0; i <= nBins; i++) {
        energyBins[i] = m * (minChannel + i) + b;
    }

    TH1F *hist = new TH1F("WidmoCs137", "Widmo Cs-137", nBins, energyBins);
    TFile *file = new TFile("WidmoCs137.root", "RECREATE");

    fstream myfile;
    myfile.open(filename, ios::in);
    string line;
    if(myfile.is_open()){
        cout<<filename<<" opened successfully"<<endl;

        Double_t counts[nBins];
        Double_t errors[nBins];

        Int_t i = 0;
        while(!myfile.eof()){
            myfile>>line;

            counts[i] = stod(line);
            errors[i] = sqrt(counts[i]);
            i++;
        }
        myfile.close();
        for(Int_t i = 0; i<nBins; i++){
            hist->SetBinContent(i, counts[i]);
            hist->SetBinError(i, errors[i]);
        }
        
        hist->Write();
    }
    else{
        cerr<<"something's not good ):"<<endl;
    }

    TCanvas *c1 = new TCanvas("c1", "Widmo Cs-137", 800, 600);
    c1->cd();
    hist->Draw();
    hist->GetXaxis()->SetTitle("energy [keV]");
    hist->GetYaxis()->SetTitle("counts [a.u.]");
    hist->GetYaxis()->SetTitleOffset(1.4);
    hist->GetXaxis()->SetTitleOffset(1.2);
    hist->SetTitle("Widmo Cs-137");
    hist->SetStats(kFALSE);
    hist->SetLineColor(kBlue);
    hist->SetMarkerStyle(20);
    hist->SetMarkerSize(0.5);
    hist->SetMarkerColor(kRed);
    hist->GetXaxis()->SetRangeUser(0, 800);

    //photopeak at 662 keV
    TLine *l1 = new TLine(662, 0, 662, 1400);
    l1->SetLineColor(26);
    l1->SetLineWidth(1);
    l1->SetLineStyle(2);
    l1->Draw("same");

    TText *label1 = new TText(600, 1420, "662 keV (photopeak)");
    label1->SetTextColor(9);
    label1->SetTextSize(0.025);
    label1->Draw();

    //Compton edge at 482 keV
    TLine *l2 = new TLine(482, 0, 482, 1400);
    l2->SetLineColor(26);
    l2->SetLineWidth(1);
    l2->SetLineStyle(2);
    l2->Draw("same");

    TText *label2 = new TText(400, 1420, "482 keV (Compton edge)");
    label2->SetTextColor(9);
    label2->SetTextSize(0.025);
    label2->Draw();

    c1->Write();
    file->Close();

    return kTRUE;
}