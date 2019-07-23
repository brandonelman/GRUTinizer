#ifndef TS800SIM_H
#define TS800SIM_H

#include <TObject.h>
#include <TMath.h>

#include <TClonesArray.h>

#include "TDetector.h"
#include "TS800SimHit.h"
#include "TGEBEvent.h"
#include "TVector3.h"

class TS800Sim : public TDetector {

  //NOTE: ATA and BTA from the S800 simulation are in mrad, which is different
  //than the ATA/BTA from the real S800 data which is in rad.
public:
  TS800Sim();
  ~TS800Sim();

  virtual void Copy(TObject& obj) const;
  virtual void Print(Option_t *opt = "") const;
  virtual void Clear(Option_t *opt = "");
  virtual size_t Size() const { return s800sim_hits.size(); }
 
  virtual void          InsertHit(const TDetectorHit& hit);
  virtual TDetectorHit& GetHit(int i)            { return s800sim_hits.at(i); }


  TVector3 Track(double sata=0.000,double sbta=0.000) const; 
  float AdjustedBeta(float beta) const;
  float Azita(float ata, float bta) const;
  const TS800SimHit& GetS800SimHit(int i) const { return s800sim_hits.at(i); }
  void PrintHit(int i){ s800sim_hits.at(i).Print(); }

 private:
  virtual int BuildHits(std::vector<TRawEvent>& raw_data);
  void BuildFrom(TGEBEvent &event);

  std::vector<TS800SimHit> s800sim_hits;

  ClassDef(TS800Sim,1);
};





#endif
