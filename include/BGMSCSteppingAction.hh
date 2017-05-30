#ifndef BGMSCSTEPPINGACTION_H
#define BGMSCSTEPPINGACTION_H

#include "G4UserSteppingAction.hh"

#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

#define RADIAL_BINS 10000

class PrimaryGeneratorAction;

class BGMSCSteppingAction : public G4UserSteppingAction {

public:
    BGMSCSteppingAction();
    ~BGMSCSteppingAction();

    void UserSteppingAction(const G4Step* aStep);

private:
    G4int i;
    G4int j;
    G4double Edep;
    G4double Edepout;
    G4double SelfAbsE;
    G4double SelfAbsG;

    G4int InEnergy[200];
    G4int OutEnergy[200];
    G4int RadialFlux1[RADIAL_BINS];
    G4int RadialFlux2[RADIAL_BINS];
    G4int RadialFlux3[RADIAL_BINS];
    G4int RadialFlux4[RADIAL_BINS];
    G4int RadialFlux5[RADIAL_BINS];
    G4int RadialFlux6[RADIAL_BINS];
    G4int RadialFlux7[RADIAL_BINS];
    G4int RadialFlux8[RADIAL_BINS];
    G4int RadialFlux9[RADIAL_BINS];
    G4int RadialFlux10[RADIAL_BINS];
    G4int TotalFlux;

    G4int Flux1;
    G4int Flux2;
    G4int Flux3;
    G4int Flux4;
    G4int Flux5;
    G4int Flux6;
    G4int Flux7;
    G4int Flux8;
    G4int Flux9;
    G4int Flux10;
};

#endif
