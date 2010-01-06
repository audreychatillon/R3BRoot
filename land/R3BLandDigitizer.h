#ifndef R3BLANDDIGITIZER_H
#define R3BLANDDIGITISER_H 1


#include "FairTask.h"
#include <map>
#include <string>
#include "R3BLandDigiPar.h"

class TClonesArray;
class TObjectArray;
class TH1F;
class TH2F;


class R3BLandDigitizer : public FairTask
{

 public:

  /** Default constructor **/  
  R3BLandDigitizer();


  /** Destructor **/
  ~R3BLandDigitizer();


  /** Virtual method Init **/
  virtual InitStatus Init();


  /** Virtual method Exec **/
  virtual void Exec(Option_t* opt);

  virtual void Finish();
  virtual void Reset();

  protected:
  TClonesArray* fLandPoints;
  TClonesArray* fLandMCTrack; 

  // Parameter class
  R3BLandDigiPar* fLandDigiPar;

  //- Control Hitograms
  TH1F *hPMl;
  TH1F *hPMr;
  TH1F *hTotalEnergy;
  TH1F *hTotalLight;
  TH1F *hMult;
  TH1F *hParticle;
  TH1F *hPaddleEnergy;
  TH1F *hFirstEnergy;

  TH1F *hDeltaPx1;
  TH1F *hDeltaPy1;
  TH1F *hDeltaPz1;
  TH1F *hDeltaPx2;
  TH1F *hDeltaPy2;
  TH1F *hDeltaPz2;
  
  TH2F *hElossLight;

  TH1F *hNeutmult1;
  TH1F *hNeutmult2;

  TH1F *hDeltaP1;
  TH1F *hDeltaP2;

  TH1F *hDeltaX;
  TH1F *hDeltaY;
  TH1F *hDeltaZ;
  TH1F *hDeltaT;
 
  TH1F *hFirstMedia;

  Int_t npaddles;
  Int_t nplanes;

  Double_t plength; // half length of paddle
  Double_t att; // light attenuation factor [1/cm]
  Double_t mn; // mass of neutron in MeV/c**2
  Double_t c;
  
  private:
  virtual void SetParContainers();

 
  ClassDef(R3BLandDigitizer,1);
  
};

#endif