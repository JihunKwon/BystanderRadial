#include "BGMSCPrimaryGeneratorAction.hh"

#include "G4Proton.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"

#include <G4SingleParticleSource.hh>

#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"

#define radius 5 // Half of diameter!!

using namespace CLHEP;

BGMSCPrimaryGeneratorAction::BGMSCPrimaryGeneratorAction()
{
        //Psudo Gamma
        CircleSourceG = new G4SingleParticleSource;
        CircleSourceG->SetParticleDefinition(G4Electron::Definition());//G4Gamma G4Electron
        this->setEnergyToGamma();

//        G4SPSEneDistribution* energyG = CircleSourceG->GetEneDist();
//        energyG->SetMonoEnergy(10*keV);

        G4SPSPosDistribution* positionG = CircleSourceG->GetPosDist();
        positionG->SetPosDisType("Plane");
        positionG->SetPosDisShape("Circle");
        positionG->SetRadius(radius*nm);
        positionG->SetCentreCoords(G4ThreeVector(0*m, 0*m,  -radius*nm));

        G4SPSAngDistribution* angularG = CircleSourceG->GetAngDist();
        angularG->SetParticleMomentumDirection(G4ThreeVector(0.0,0.0,1.0));
        angularG->DefineAngRefAxes("angref1", G4ThreeVector(-1.0,0.0,0.0));
        CircleSourceG->SetNumberOfParticles(1);

}

BGMSCPrimaryGeneratorAction::~BGMSCPrimaryGeneratorAction()
{
    //delete CircleSource;
    delete CircleSourceG;
    //delete fParticleGun;
}

void BGMSCPrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{
    //CircleSource->SetNumberOfParticles(3);

        // CircleSource->GeneratePrimaryVertex(event);   //Changed
       CircleSourceG->GeneratePrimaryVertex(event);
        //fParticleGun->GeneratePrimaryVertex(event);

}

G4SPSEneDistribution* BGMSCPrimaryGeneratorAction::setEnergyToGamma() {
    G4SPSEneDistribution* eneDistG = CircleSourceG->GetEneDist();
    eneDistG->SetEnergyDisType("Arb");
    //eneDistG->ArbEnergyHistoFile("Gamma_EnergyDistribution_allon_10nm_100keVX-ray_2.115_10^9.txt");
    eneDistG->ArbEnergyHistoFile("Electron_EnergyDistribution_10nm_100keVX-ray.txt");
    eneDistG->ArbInterpolate("Lin");
    return eneDistG;
}




