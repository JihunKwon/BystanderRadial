#include "BGMSCDetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4NistManager.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"
#include "G4VisAttributes.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4RunManager.hh"
#include "G4VSolid.hh"
#include "G4Sphere.hh"
#include "G4UserLimits.hh"

#define radius 5 // Half of diameter!!
#define distance 0 //Distance between SourceGNP and BystanderGNP

using namespace CLHEP;


BGMSCDetectorConstruction::BGMSCDetectorConstruction()
    :fStepLimit(NULL)
{}

//BGMSCDetectorConstruction::~BGMSCDetectorConstruction()
//{
//  delete fStepLimit;
//}

G4VPhysicalVolume* BGMSCDetectorConstruction::Construct()
{
    // Cleanup old geometry
    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();

    G4VisAttributes* visAttributes = new G4VisAttributes;
    visAttributes->SetForceWireframe(true);
    visAttributes->SetForceAuxEdgeVisible(true);

    G4NistManager* nistManager = G4NistManager::Instance();
    G4Material* Au = nistManager->FindOrBuildMaterial("G4_Au");
    G4Material* vacuum = nistManager->FindOrBuildMaterial("G4_Galactic");
    G4Material* water = nistManager->FindOrBuildMaterial("G4_WATER");

    // World
    G4Box* world = new G4Box("World", 6.3*um, 6.3*um, 6.3*um);   //halfx=0.05um
    G4LogicalVolume *worldLogic = new G4LogicalVolume(world, water, "WorldLogic");
    G4VPhysicalVolume *worldPhys = new G4PVPlacement(0, G4ThreeVector(), worldLogic, "WorldPhys", 0, false, 0);
    worldLogic->SetVisAttributes(visAttributes);

    // NanoTubs1
    G4Box* nanoTubs1 = new G4Box("NanoTubs1", 6.3*um, 6.3*um, radius*nm);
    G4LogicalVolume *nanoTubsLogic1 = new G4LogicalVolume(nanoTubs1, water, "NanoTubsLogic1");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+10)*nm), nanoTubsLogic1, "NanoTubsPhys1", worldLogic, 0, 0);
    nanoTubsLogic1->SetVisAttributes((visAttributes));
    // NanoTubs2
    G4Box* nanoTubs2 = new G4Box("NanoTubs2", 6.3*um, 6.3*um, radius*nm);
    G4LogicalVolume *nanoTubsLogic2 = new G4LogicalVolume(nanoTubs2, water, "NanoTubsLogic2");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+20)*nm), nanoTubsLogic2, "NanoTubsPhys2", worldLogic, 0, 0);
    nanoTubsLogic2->SetVisAttributes((visAttributes));
    // NanoTubs3
    G4Box* nanoTubs3 = new G4Box("NanoTubs3", 6.3*um, 6.3*um, radius*nm);
    G4LogicalVolume *nanoTubsLogic3 = new G4LogicalVolume(nanoTubs3, water, "NanoTubsLogic3");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+30)*nm), nanoTubsLogic3, "NanoTubsPhys3", worldLogic, 0, 0);
    nanoTubsLogic3->SetVisAttributes((visAttributes));
    // NanoTubs4
    G4Box* nanoTubs4 = new G4Box("NanoTubs4", 6.3*um, 6.3*um, radius*nm);
    G4LogicalVolume *nanoTubsLogic4 = new G4LogicalVolume(nanoTubs4, water, "NanoTubsLogic4");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+40)*nm), nanoTubsLogic4, "NanoTubsPhys4", worldLogic, 0, 0);
    nanoTubsLogic4->SetVisAttributes((visAttributes));
    // NanoTubs5
    G4Box* nanoTubs5 = new G4Box("NanoTubs5", 6.3*um, 6.3*um, radius*nm);
    G4LogicalVolume *nanoTubsLogic5 = new G4LogicalVolume(nanoTubs5, water, "NanoTubsLogic5");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+50)*nm), nanoTubsLogic5, "NanoTubsPhys5", worldLogic, 0, 0);
    nanoTubsLogic5->SetVisAttributes((visAttributes));
    // NanoTubs6
    G4Box* nanoTubs6 = new G4Box("NanoTubs6", 6.3*um, 6.3*um, radius*nm);
    G4LogicalVolume *nanoTubsLogic6 = new G4LogicalVolume(nanoTubs6, water, "NanoTubsLogic6");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+60)*nm), nanoTubsLogic6, "NanoTubsPhys6", worldLogic, 0, 0);
    nanoTubsLogic6->SetVisAttributes((visAttributes));
    // NanoTubs7
    G4Box* nanoTubs7 = new G4Box("NanoTubs7", 6.3*um, 6.3*um, radius*nm);
    G4LogicalVolume *nanoTubsLogic7 = new G4LogicalVolume(nanoTubs7, water, "NanoTubsLogic7");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+70)*nm), nanoTubsLogic7, "NanoTubsPhys7", worldLogic, 0, 0);
    nanoTubsLogic7->SetVisAttributes((visAttributes));
    // NanoTubs8
    G4Box* nanoTubs8 = new G4Box("NanoTubs8", 6.3*um, 6.3*um, radius*nm);
    G4LogicalVolume *nanoTubsLogic8 = new G4LogicalVolume(nanoTubs8, water, "NanoTubsLogic8");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+80)*nm), nanoTubsLogic8, "NanoTubsPhys8", worldLogic, 0, 0);
    nanoTubsLogic8->SetVisAttributes((visAttributes));
    // NanoTubs9
    G4Box* nanoTubs9 = new G4Box("NanoTubs9", 6.3*um, 6.3*um, radius*nm);
    G4LogicalVolume *nanoTubsLogic9 = new G4LogicalVolume(nanoTubs9, water, "NanoTubsLogic9");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+90)*nm), nanoTubsLogic9, "NanoTubsPhys9", worldLogic, 0, 0);
    nanoTubsLogic9->SetVisAttributes((visAttributes));
    // NanoTubs10
    G4Box* nanoTubs10 = new G4Box("NanoTubs10", 6.3*um, 6.3*um, radius*nm);
    G4LogicalVolume *nanoTubsLogic10 = new G4LogicalVolume(nanoTubs10, water, "NanoTubsLogic10");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+100)*nm), nanoTubsLogic10, "NanoTubsPhys10", worldLogic, 0, 0);
    nanoTubsLogic10->SetVisAttributes((visAttributes));

    G4double maxStep = 1*nm;
    fStepLimit = new G4UserLimits(maxStep);
    //nanoTubsLogic->SetUserLimits(fStepLimit);

    return worldPhys;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void BGMSCDetectorConstruction::SetMaxStep(G4double maxStep)
{
    if ((fStepLimit)&&(maxStep>0.)) fStepLimit->SetMaxAllowedStep(maxStep);
}
