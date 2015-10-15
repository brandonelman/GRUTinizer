#include "TRuntimeObjects.h"

#include "TH1.h"
#include "TH2.h"

TRuntimeObjects::TRuntimeObjects(TList* detectors, TList* objects)
  : detectors(detectors), objects(objects) { }

void TRuntimeObjects::FillHistogram(std::string name,
                                    int bins, double low, double high, double value){
  TH1* hist = (TH1*) GetObjects().FindObject(name.c_str());
  if(hist){
    hist->Fill(value);
  } else {
    TH1* newHist = new TH1I(name.c_str(),name.c_str(),bins,low,high);
    newHist->Fill(value);
    GetObjects().Add(newHist);
  }
}

void TRuntimeObjects::FillHistogram(std::string name,
                                    int Xbins, double Xlow, double Xhigh, double Xvalue,
                                    int Ybins, double Ylow, double Yhigh, double Yvalue){
  TH2* hist = (TH2*) GetObjects().FindObject(name.c_str());
  if(hist){
    hist->Fill(Xvalue, Yvalue);
  } else {
    TH2* newHist = new TH2I(name.c_str(),name.c_str(),
                            Xbins, Xlow, Xhigh,
                            Ybins, Ylow, Yhigh);
    newHist->Fill(Xvalue, Yvalue);
    GetObjects().Add(newHist);
  }
}

TList& TRuntimeObjects::GetDetectors() {
  return *detectors;
}

TList& TRuntimeObjects::GetObjects() {
  return *objects;
}