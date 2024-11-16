#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <TH1F.h>
#include <TCanvas.h>
using namespace std;

Bool_t HistogramStack(){
    int nBins = 50;
    auto hs = new THStack("hs", "");

    auto h1 = new TH1F("h1","test hstack",nBins,-4,10);
    h1->FillRandom("gaus",20000);
    h1->SetFillColor(28);
    hs->Add(h1);

    auto h2 = new TH1F("h2","test hstack",nBins,-4,10);
    h2->FillRandom("expo",15000);
    h2->SetFillColor(24);
    hs->Add(h2);

    auto h3 = new TH1F("h3","test hstack",nBins,-4,10);
    h3->FillRandom("landau",10000);
    h3->SetFillColor(8);
    hs->Add(h3);

    auto h4 = new TH1F("h4","test hstack",nBins,-4,10);
    h4->FillRandom("pol1",10000);
    h4->SetFillColor(kOcean);
    hs->Add(h4);

    auto mc = new TCanvas("mc","mc",10,10,700,900);
    TText T; T.SetTextFont(42); T.SetTextAlign(21);

    mc->Divide(1,2);
    mc->cd(2); hs->Draw("lego1"); 
    T.DrawTextNDC(.5,.95,"3D view");
    mc->cd(1); hs->Draw(); h1->SetLineColor(kBlack); h2->SetLineColor(kBlack); h3->SetLineColor(kBlack); h4->SetLineColor(kBlack);
    T.DrawTextNDC(.5,.95,"Projection");

    TLegend *leg = new TLegend(0.6, 0.7, 0.9, 0.9, "The Minecraft world topology");
    leg->AddEntry(h1, "A small hill (Gauss distribution)", "f");
    leg->AddEntry(h2, "Extreme hills (Exponential)", "f");
    leg->AddEntry(h3, "Random terrain (Landau)", "f");
    leg->AddEntry(h4, "Waterfall (Pol1)", "f");
    leg->Draw();

    return kTRUE;
}