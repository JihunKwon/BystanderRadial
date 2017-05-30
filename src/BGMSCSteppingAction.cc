#include "BGMSCSteppingAction.hh"

#include "G4Track.hh"
#include "G4TrackStatus.hh"
#include "G4CsvAnalysisManager.hh"
#include "G4ThreeVector.hh"
#include "G4VProcess.hh"
#include "cmath"
#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

#include "G4CsvAnalysisManager.hh"

#define RADIAL_BINS 10000
#define MAX_R 0.01 //mm = 10um

BGMSCSteppingAction::BGMSCSteppingAction()
{
    i = 0;
    j = 0;
    Edep = 0;
    Edepout = 0;
    SelfAbsE = 0;
    SelfAbsG = 0;

    for (int i = 0; i < RADIAL_BINS; i++)
    {
        RadialFlux1[i] = 0;
        RadialFlux2[i] = 0;
        RadialFlux3[i] = 0;
        RadialFlux4[i] = 0;
        RadialFlux5[i] = 0;
        RadialFlux6[i] = 0;
        RadialFlux7[i] = 0;
        RadialFlux8[i] = 0;
        RadialFlux9[i] = 0;
        RadialFlux10[i] = 0;
    }
}

BGMSCSteppingAction::~BGMSCSteppingAction()
{
    FILE* fp1 = fopen("RadialFlux1.txt", "wt");
    FILE* fp2 = fopen("RadialFlux2.txt", "wt");
    FILE* fp3 = fopen("RadialFlux3.txt", "wt");
    FILE* fp4 = fopen("RadialFlux4.txt", "wt");
    FILE* fp5 = fopen("RadialFlux5.txt", "wt");
    FILE* fp6 = fopen("RadialFlux6.txt", "wt");
    FILE* fp7 = fopen("RadialFlux7.txt", "wt");
    FILE* fp8 = fopen("RadialFlux8.txt", "wt");
    FILE* fp9 = fopen("RadialFlux9.txt", "wt");
    FILE* fp10 = fopen("RadialFlux10.txt", "wt");



    fprintf(fp1, "#Distance [mm], Count\n");
    for (int i = 1; i <= RADIAL_BINS; i++) {
        fprintf(fp1, "%f %d\n", i/(G4double)RADIAL_BINS*MAX_R*1, RadialFlux1[i]);
    }
    fclose(fp1);

    fprintf(fp2, "#Distance [mm], Count\n");
    for (int i = 1; i <= RADIAL_BINS; i++) {
        fprintf(fp2, "%f %d\n", i/(G4double)RADIAL_BINS*MAX_R*1, RadialFlux2[i]);
    }
    fclose(fp2);

    fprintf(fp3, "#Distance [mm], Count\n");
    for (int i = 1; i <= RADIAL_BINS; i++) {
        fprintf(fp3, "%f %d\n", i/(G4double)RADIAL_BINS*MAX_R*1, RadialFlux3[i]);
    }
    fclose(fp3);

    fprintf(fp4, "#Distance [mm], Count\n");
    for (int i = 1; i <= RADIAL_BINS; i++) {
        fprintf(fp4, "%f %d\n", i/(G4double)RADIAL_BINS*MAX_R*1, RadialFlux4[i]);
    }
    fclose(fp4);

    fprintf(fp5, "#Distance [mm], Count\n");
    for (int i = 1; i <= RADIAL_BINS; i++) {
        fprintf(fp5, "%f %d\n", i/(G4double)RADIAL_BINS*MAX_R*1, RadialFlux5[i]);
    }
    fclose(fp5);

    fprintf(fp6, "#Distance [mm], Count\n");
    for (int i = 1; i <= RADIAL_BINS; i++) {
        fprintf(fp6, "%f %d\n", i/(G4double)RADIAL_BINS*MAX_R*1, RadialFlux6[i]);
    }
    fclose(fp6);

    fprintf(fp7, "#Distance [mm], Count\n");
    for (int i = 1; i <= RADIAL_BINS; i++) {
        fprintf(fp7, "%f %d\n", i/(G4double)RADIAL_BINS*MAX_R*1, RadialFlux7[i]);
    }
    fclose(fp7);

    fprintf(fp8, "#Distance [mm], Count\n");
    for (int i = 1; i <= RADIAL_BINS; i++) {
        fprintf(fp8, "%f %d\n", i/(G4double)RADIAL_BINS*MAX_R*1, RadialFlux8[i]);
    }
    fclose(fp8);

    fprintf(fp9, "#Distance [mm], Count\n");
    for (int i = 1; i <= RADIAL_BINS; i++) {
        fprintf(fp9, "%f %d\n", i/(G4double)RADIAL_BINS*MAX_R*1, RadialFlux9[i]);
    }
    fclose(fp9);

    fprintf(fp10, "#Distance [mm], Count\n");
    for (int i = 1; i <= RADIAL_BINS; i++) {
        fprintf(fp10, "%f %d\n", i/(G4double)RADIAL_BINS*MAX_R*1, RadialFlux10[i]);
    }
    fclose(fp10);

    ifstream InputFile1("RadialFlux1.txt");
    ifstream InputFile2("RadialFlux2.txt");
    ifstream InputFile3("RadialFlux3.txt");
    ifstream InputFile4("RadialFlux4.txt");
    ifstream InputFile5("RadialFlux5.txt");
    ifstream InputFile6("RadialFlux6.txt");
    ifstream InputFile7("RadialFlux7.txt");
    ifstream InputFile8("RadialFlux8.txt");
    ifstream InputFile9("RadialFlux9.txt");
    ifstream InputFile10("RadialFlux10.txt");

    ofstream OutputFile("RadialFlux_All_FlatPanel.csv");
    OutputFile << "#1Distance [nm], 100nm, 200nm, 300nm, 400nm, 500nm\n";

    string Header = "";

    while( Header != "Count") {
        InputFile1 >> Header;
        InputFile2 >> Header;
        InputFile3 >> Header;
        InputFile4 >> Header;
        InputFile5 >> Header;
        InputFile6 >> Header;
        InputFile7 >> Header;
        InputFile8 >> Header;
        InputFile9 >> Header;
        InputFile10 >> Header;
    }

    double x;
    int C1[RADIAL_BINS],C3[RADIAL_BINS],C5[RADIAL_BINS],C7[RADIAL_BINS],C9[RADIAL_BINS];
    int C2[RADIAL_BINS],C4[RADIAL_BINS],C6[RADIAL_BINS],C8[RADIAL_BINS],C10[RADIAL_BINS];
    for (int a=0; a<RADIAL_BINS; a++){
        InputFile1 >> x >> C1[a];
        InputFile2 >> x >> C2[a];
        InputFile3 >> x >> C3[a];
        InputFile4 >> x >> C4[a];
        InputFile5 >> x >> C5[a];
        InputFile6 >> x >> C6[a];
        InputFile7 >> x >> C7[a];
        InputFile8 >> x >> C8[a];
        InputFile9 >> x >> C9[a];
        InputFile10 >> x >> C10[a];

        OutputFile<<(x)*1000000<<", "<<C1[a]<<", "<<C2[a]<<", "<<C3[a]<<", "<<C4[a]<<", "<<C5[a]<<", "
                  <<C6[a]<<", "<<C7[a]<<", "<<C8[a]<<", "<<C9[a]<<", "<<C10[a]<<"\n";
    }

    ofstream OutputFileFlux("Flux_FlatPanel.csv");
    OutputFileFlux << Flux1 << ", " << Flux2 << ", " << Flux3 << ", " << Flux4 << ", " << Flux5 << ", " <<
                      Flux6 << ", " << Flux7 << ", " << Flux8 << ", " << Flux9 << ", " << Flux10 << "\n";
}

void BGMSCSteppingAction::UserSteppingAction(const G4Step* aStep)
{
    G4CsvAnalysisManager* analysisManager = G4CsvAnalysisManager::Instance();

    if (aStep->GetPostStepPoint()->GetMaterial())
    {
        if ((aStep->GetPostStepPoint()->GetMaterial()->GetName() == "G4_Au") &&
                (aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName() == "eIoni"))
            i = i+1;

        if (aStep->GetPostStepPoint()->GetMaterial()->GetName() == "G4_WATER")
        {
            Edep = Edep + aStep->GetTotalEnergyDeposit();

            if ((aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "e-") &&
                    (aStep->GetTrack()->GetParentID() != 0))
            {
                Edepout = Edepout + aStep->GetTotalEnergyDeposit();
            }
        }

        if (aStep->GetPostStepPoint()->GetMaterial()->GetName() == "G4_Au")
        {
            if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "e-")
                SelfAbsE = SelfAbsE + aStep->GetTotalEnergyDeposit();
            if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "gamma")
                SelfAbsG = SelfAbsG + aStep->GetTotalEnergyDeposit();
        }
    }

    if (aStep->GetTrack()->GetVolume()->GetName() == "NanoTubsPhys1") {
        if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "e-") {
            if (aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary) {
                G4double eEnergy = aStep->GetPostStepPoint()->GetKineticEnergy()/keV;
                analysisManager->FillH1(0, eEnergy);

                G4double x = aStep->GetPreStepPoint()->GetPosition().x();
                G4double y = aStep->GetPreStepPoint()->GetPosition().y();
                G4double r = sqrt(x*x + y*y)/mm;

                for (G4int i=0; i<RADIAL_BINS; i++) {
                    if((i*RADIAL_BINS/MAX_R*0.000000000001 <= r ) && (r < (i+1)*RADIAL_BINS/MAX_R*0.000000000001 ))
                    {
                        RadialFlux1[i]++;
                        break;
                    }
                }
                if(r<0.000005) { //5nm
                    Flux1++;
                }
            }
        }
    }

    if (aStep->GetTrack()->GetVolume()->GetName() == "NanoTubsPhys2") {
        if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "e-") {
            if (aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary) {
                G4double eEnergy = aStep->GetPostStepPoint()->GetKineticEnergy()/keV;
                analysisManager->FillH1(0, eEnergy);

                G4double x = aStep->GetPreStepPoint()->GetPosition().x();
                G4double y = aStep->GetPreStepPoint()->GetPosition().y();
                G4double r = sqrt(x*x + y*y)/mm;

                for (G4int i=0; i<RADIAL_BINS; i++) {
                    if((i*RADIAL_BINS/MAX_R*0.000000000001 <= r ) && (r < (i+1)*RADIAL_BINS/MAX_R*0.000000000001 ))
                    {
                        RadialFlux2[i]++;
                        break;
                    }
                }
                if(r<0.000005) { //5nm
                    Flux2++;
                }
            }
        }
    }

    if (aStep->GetTrack()->GetVolume()->GetName() == "NanoTubsPhys3") {
        if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "e-") {
            if (aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary) {
                G4double eEnergy = aStep->GetPostStepPoint()->GetKineticEnergy()/keV;
                analysisManager->FillH1(0, eEnergy);

                G4double x = aStep->GetPreStepPoint()->GetPosition().x();
                G4double y = aStep->GetPreStepPoint()->GetPosition().y();
                G4double r = sqrt(x*x + y*y)/mm;

                for (G4int i=0; i<RADIAL_BINS; i++) {
                    if((i*RADIAL_BINS/MAX_R*0.000000000001 <= r ) && (r < (i+1)*RADIAL_BINS/MAX_R*0.000000000001 ))
                    {
                        RadialFlux3[i]++;
                        break;
                    }
                }
                if(r<0.000005) { //5nm
                    Flux3++;
                }
            }
        }
    }

    if (aStep->GetTrack()->GetVolume()->GetName() == "NanoTubsPhys4") {
        if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "e-") {
            if (aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary) {
                G4double eEnergy = aStep->GetPostStepPoint()->GetKineticEnergy()/keV;
                analysisManager->FillH1(0, eEnergy);

                G4double x = aStep->GetPreStepPoint()->GetPosition().x();
                G4double y = aStep->GetPreStepPoint()->GetPosition().y();
                G4double r = sqrt(x*x + y*y)/mm;

                for (G4int i=0; i<RADIAL_BINS; i++) {
                    if((i*RADIAL_BINS/MAX_R*0.000000000001 <= r ) && (r < (i+1)*RADIAL_BINS/MAX_R*0.000000000001 ))
                    {
                        RadialFlux4[i]++;
                        break;
                    }
                }
                if(r<0.000005) { //5nm
                    Flux4++;
                }
            }
        }
    }

    if (aStep->GetTrack()->GetVolume()->GetName() == "NanoTubsPhys5") {
        if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "e-") {
            if (aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary) {
                G4double eEnergy = aStep->GetPostStepPoint()->GetKineticEnergy()/keV;
                analysisManager->FillH1(0, eEnergy);

                G4double x = aStep->GetPreStepPoint()->GetPosition().x();
                G4double y = aStep->GetPreStepPoint()->GetPosition().y();
                G4double r = sqrt(x*x + y*y)/mm;

                for (G4int i=0; i<RADIAL_BINS; i++) {
                    if((i*RADIAL_BINS/MAX_R*0.000000000001 <= r ) && (r < (i+1)*RADIAL_BINS/MAX_R*0.000000000001 ))
                    {
                        RadialFlux5[i]++;
                        break;
                    }
                }
                if(r<0.000005) { //5nm
                    Flux5++;
                }
            }
        }
    }

    if (aStep->GetTrack()->GetVolume()->GetName() == "NanoTubsPhys6") {
        if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "e-") {
            if (aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary) {
                G4double eEnergy = aStep->GetPostStepPoint()->GetKineticEnergy()/keV;
                analysisManager->FillH1(0, eEnergy);

                G4double x = aStep->GetPreStepPoint()->GetPosition().x();
                G4double y = aStep->GetPreStepPoint()->GetPosition().y();
                G4double r = sqrt(x*x + y*y)/mm;

                for (G4int i=0; i<RADIAL_BINS; i++) {
                    if((i*RADIAL_BINS/MAX_R*0.000000000001 <= r ) && (r < (i+1)*RADIAL_BINS/MAX_R*0.000000000001 ))
                    {
                        RadialFlux6[i]++;
                        break;
                    }
                }
                if(r<0.000005) { //5nm
                    Flux6++;
                }
            }
        }
    }

    if (aStep->GetTrack()->GetVolume()->GetName() == "NanoTubsPhys7") {
        if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "e-") {
            if (aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary) {
                G4double eEnergy = aStep->GetPostStepPoint()->GetKineticEnergy()/keV;
                analysisManager->FillH1(0, eEnergy);

                G4double x = aStep->GetPreStepPoint()->GetPosition().x();
                G4double y = aStep->GetPreStepPoint()->GetPosition().y();
                G4double r = sqrt(x*x + y*y)/mm;

                for (G4int i=0; i<RADIAL_BINS; i++) {
                    if((i*RADIAL_BINS/MAX_R*0.000000000001 <= r ) && (r < (i+1)*RADIAL_BINS/MAX_R*0.000000000001 ))
                    {
                        RadialFlux7[i]++;
                        break;
                    }
                }
                if(r<0.000005) { //5nm
                    Flux7++;
                }
            }
        }
    }

    if (aStep->GetTrack()->GetVolume()->GetName() == "NanoTubsPhys8") {
        if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "e-") {
            if (aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary) {
                G4double eEnergy = aStep->GetPostStepPoint()->GetKineticEnergy()/keV;
                analysisManager->FillH1(0, eEnergy);

                G4double x = aStep->GetPreStepPoint()->GetPosition().x();
                G4double y = aStep->GetPreStepPoint()->GetPosition().y();
                G4double r = sqrt(x*x + y*y)/mm;

                for (G4int i=0; i<RADIAL_BINS; i++) {
                    if((i*RADIAL_BINS/MAX_R*0.000000000001 <= r ) && (r < (i+1)*RADIAL_BINS/MAX_R*0.000000000001 ))
                    {
                        RadialFlux8[i]++;
                        break;
                    }
                }
                if(r<0.000005) { //5nm
                    Flux8++;
                }
            }
        }
    }

    if (aStep->GetTrack()->GetVolume()->GetName() == "NanoTubsPhys9") {
        if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "e-") {
            if (aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary) {
                G4double eEnergy = aStep->GetPostStepPoint()->GetKineticEnergy()/keV;
                analysisManager->FillH1(0, eEnergy);

                G4double x = aStep->GetPreStepPoint()->GetPosition().x();
                G4double y = aStep->GetPreStepPoint()->GetPosition().y();
                G4double r = sqrt(x*x + y*y)/mm;

                for (G4int i=0; i<RADIAL_BINS; i++) {
                    if((i*RADIAL_BINS/MAX_R*0.000000000001 <= r ) && (r < (i+1)*RADIAL_BINS/MAX_R*0.000000000001 ))
                    {
                        RadialFlux9[i]++;
                        break;
                    }
                }
                if(r<0.000005) { //5nm
                    Flux9++;
                }
            }
        }
    }

    if (aStep->GetTrack()->GetVolume()->GetName() == "NanoTubsPhys10") {
        if (aStep->GetTrack()->GetParticleDefinition()->GetParticleName() == "e-") {
            if (aStep->GetPreStepPoint()->GetStepStatus() == fGeomBoundary) {
                G4double eEnergy = aStep->GetPostStepPoint()->GetKineticEnergy()/keV;
                analysisManager->FillH1(0, eEnergy);

                G4double x = aStep->GetPreStepPoint()->GetPosition().x();
                G4double y = aStep->GetPreStepPoint()->GetPosition().y();
                G4double r = sqrt(x*x + y*y)/mm;

                for (G4int i=0; i<RADIAL_BINS; i++) {
                    if((i*RADIAL_BINS/MAX_R*0.000000000001 <= r ) && (r < (i+1)*RADIAL_BINS/MAX_R*0.000000000001 ))
                    {
                        RadialFlux10[i]++;
                        break;
                    }
                }
                if(r<0.000005) { //5nm
                    Flux10++;
                }
            }
        }
    }
}
