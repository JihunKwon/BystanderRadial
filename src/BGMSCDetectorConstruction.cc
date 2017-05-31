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

#define height 5 // Half of diameter!!
#define distance 0 //Distance between SourceGNP and BystanderGNP
#define WORLD 6.3
#define BOX 10

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
    G4Box* world = new G4Box("World", WORLD*um, WORLD*um, WORLD*um);   //halfx=0.05um
    G4LogicalVolume *worldLogic = new G4LogicalVolume(world, water, "WorldLogic");
    G4VPhysicalVolume *worldPhys = new G4PVPlacement(0, G4ThreeVector(), worldLogic, "WorldPhys", 0, false, 0);
    worldLogic->SetVisAttributes(visAttributes);

    // NanoBox1
    G4Box* nanoBox1 = new G4Box("NanoBox1", BOX*nm, BOX*nm, height*nm);
    G4LogicalVolume *nanoBoxLogic1 = new G4LogicalVolume(nanoBox1, water, "NanoBoxLogic1");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+10)*nm), nanoBoxLogic1, "NanoBoxPhys1", worldLogic, 0, 0);
    nanoBoxLogic1->SetVisAttributes((visAttributes));
    // NanoBox2
    G4Box* nanoBox2 = new G4Box("NanoBox2", BOX*nm, BOX*nm, height*nm);
    G4LogicalVolume *nanoBoxLogic2 = new G4LogicalVolume(nanoBox2, water, "NanoBoxLogic2");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+20)*nm), nanoBoxLogic2, "NanoBoxPhys2", worldLogic, 0, 0);
    nanoBoxLogic2->SetVisAttributes((visAttributes));
    // NanoBox3
    G4Box* nanoBox3 = new G4Box("NanoBox3", BOX*nm, BOX*nm, height*nm);
    G4LogicalVolume *nanoBoxLogic3 = new G4LogicalVolume(nanoBox3, water, "NanoBoxLogic3");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+30)*nm), nanoBoxLogic3, "NanoBoxPhys3", worldLogic, 0, 0);
    nanoBoxLogic3->SetVisAttributes((visAttributes));
    // NanoBox4
    G4Box* nanoBox4 = new G4Box("NanoBox4", BOX*nm, BOX*nm, height*nm);
    G4LogicalVolume *nanoBoxLogic4 = new G4LogicalVolume(nanoBox4, water, "NanoBoxLogic4");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+40)*nm), nanoBoxLogic4, "NanoBoxPhys4", worldLogic, 0, 0);
    nanoBoxLogic4->SetVisAttributes((visAttributes));
    // NanoBox5
    G4Box* nanoBox5 = new G4Box("NanoBox5", BOX*nm, BOX*nm, height*nm);
    G4LogicalVolume *nanoBoxLogic5 = new G4LogicalVolume(nanoBox5, water, "NanoBoxLogic5");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+50)*nm), nanoBoxLogic5, "NanoBoxPhys5", worldLogic, 0, 0);
    nanoBoxLogic5->SetVisAttributes((visAttributes));
    // NanoBox6
    G4Box* nanoBox6 = new G4Box("NanoBox6", BOX*nm, BOX*nm, height*nm);
    G4LogicalVolume *nanoBoxLogic6 = new G4LogicalVolume(nanoBox6, water, "NanoBoxLogic6");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+60)*nm), nanoBoxLogic6, "NanoBoxPhys6", worldLogic, 0, 0);
    nanoBoxLogic6->SetVisAttributes((visAttributes));
    // NanoBox7
    G4Box* nanoBox7 = new G4Box("NanoBox7", BOX*nm, BOX*nm, height*nm);
    G4LogicalVolume *nanoBoxLogic7 = new G4LogicalVolume(nanoBox7, water, "NanoBoxLogic7");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+70)*nm), nanoBoxLogic7, "NanoBoxPhys7", worldLogic, 0, 0);
    nanoBoxLogic7->SetVisAttributes((visAttributes));
    // NanoBox8
    G4Box* nanoBox8 = new G4Box("NanoBox8", BOX*nm, BOX*nm, height*nm);
    G4LogicalVolume *nanoBoxLogic8 = new G4LogicalVolume(nanoBox8, water, "NanoBoxLogic8");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+80)*nm), nanoBoxLogic8, "NanoBoxPhys8", worldLogic, 0, 0);
    nanoBoxLogic8->SetVisAttributes((visAttributes));
    // NanoBox9
    G4Box* nanoBox9 = new G4Box("NanoBox9", BOX*nm, BOX*nm, height*nm);
    G4LogicalVolume *nanoBoxLogic9 = new G4LogicalVolume(nanoBox9, water, "NanoBoxLogic9");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+90)*nm), nanoBoxLogic9, "NanoBoxPhys9", worldLogic, 0, 0);
    nanoBoxLogic9->SetVisAttributes((visAttributes));
    // NanoBox10
    G4Box* nanoBox10 = new G4Box("NanoBox10", BOX*nm, BOX*nm, height*nm);
    G4LogicalVolume *nanoBoxLogic10 = new G4LogicalVolume(nanoBox10, water, "NanoBoxLogic10");
    new G4PVPlacement(0, G4ThreeVector(0, 0, (distance+100)*nm), nanoBoxLogic10, "NanoBoxPhys10", worldLogic, 0, 0);
    nanoBoxLogic10->SetVisAttributes((visAttributes));

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
