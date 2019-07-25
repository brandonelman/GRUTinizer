#ifndef GMODIFIEDGAUS_H
#define GMODIFIEDGAUS_H

#include <TF1.h>

#include <string>
#include <algorithm>

class GModifiedGaus : public TF1 {
  public:
    GModifiedGaus(Double_t sigma1,Double_t sigma2, Double_t centroid, 
                  Double_t xlow,Double_t xhigh,Option_t *opt="gsc");
    
    GModifiedGaus(const GModifiedGaus&);
    GModifiedGaus();
    virtual ~GModifiedGaus();

    void Copy(TObject&) const;
    void Print(Option_t *opt="") const;
    void Clear(Option_t *opt="");

    void InitNames();
    bool InitParams(TH1* fithist = 0,double sigma1=0,double sigma2=0);
    bool Fit(TH1*,double c1,double c2,Option_t *opt="");
    void DrawResiduals(TH1*) const;

    TF1  *Background(Option_t *opt="TF1") { return &fBGFit; }

    Double_t GetSigma1() const     { return GetParameter("sigma1"); }
    Double_t GetSigma1Err() const  { return GetParError(GetParNumber("sigma1")); }

    Double_t GetSigma2() const     { return GetParameter("sigma2"); }
    Double_t GetSigma2Err() const  { return GetParError(GetParNumber("sigma2")); }
    
    Double_t GetAreaTotal() const         { return fAreaTotal; }
    Double_t GetAreaTotalErr() const      { return fDAreaTotal; }
    
    Double_t GetSumTotal() const          { return fSumTotal; }
    Double_t GetSumTotalErr() const       { return fDSumTotal; }
    
    Double_t GetFWHM() const         { return GetParameter("sigma1")*2.3548;}
    Double_t GetFWHMErr() const      { return GetParError(GetParNumber("sigma1"))*2.3548;}




  protected:
    void SetAreaTotal(Double_t a) { fAreaTotal = a; }
    void SetAreaTotalErr(Double_t d_a) { fDAreaTotal = d_a; }
    void SetSumTotal(Double_t a)       { fSumTotal = a; }
    void SetSumTotalErr(Double_t d_a)  { fDSumTotal = d_a; }
    void SetAreaTotal(Double_t a, Double_t dA) { SetAreaTotal(a); SetAreaTotalErr(dA);}
    void SetChi2(Double_t chi2)   { fChi2 = chi2; }
    void SetNdf(Double_t Ndf)     { fNdf  = Ndf; }

  private:
    double fAreaTotal;
    double fDAreaTotal;
    double fArea1;
    double fDArea1;
    double fArea2;
    double fDArea2;
    
    double fChi2;
    double fNdf;

    double fSumTotal;
    double fDSumTotal;
    double fSum1;
    double fDSum1;
    double fSum2;
    double fDSum2;


    Bool_t IsInitialized() const { return init_flag; }
    void SetInitialized(Bool_t flag = true) {init_flag = flag;}
    bool init_flag;

    TF1 fBGHist;
    TF1 fBGFit;
    TF1 fGaus1;
    TF1 fGaus2;


  ClassDef(GModifiedGaus,4)
};


#endif
