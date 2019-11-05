/**
 *  @copyright Copyright 2019 The J-PET Monte Carlo Authors. All rights reserved.
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may find a copy of the License in the LICENCE file.
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  @file PrimaryGenerator.h
 */

#ifndef PRIMARYGENERATOR_H
#define PRIMARYGENERATOR_H 1

#include <G4TransportationManager.hh>
#include <G4VPrimaryGenerator.hh>
#include "MaterialExtension.h"
#include <G4PrimaryVertex.hh>
#include <TGenPhaseSpace.h>
#include <TLorentzVector.h>
#include "SourceParams.h"
#include <G4Navigator.hh>
#include "BeamParams.h"
#include <G4Event.hh>

class PrimaryGenerator : public G4VPrimaryGenerator
{
public:
  PrimaryGenerator();
  ~PrimaryGenerator();
  void GenerateBeam(BeamParams*, G4Event*);
  void GenerateIsotope(SourceParams*, G4Event*);
  void GenerateNema(G4int, G4Event*);
  void GenerateEvtSmallChamber(G4Event* event, const G4double);
  void GenerateEvtLargeChamber(G4Event* event);
  virtual void GeneratePrimaryVertex(G4Event*) {};

private:
  //! return: vtx position, 2/3g ratio, meanlifetime;
  //! as input the maximal dimension(/2) of annihilation chamber are taken (to speed up simulatons)
  std::tuple<G4ThreeVector, G4double, G4double> GetVerticesDistribution(G4double, G4double, G4double);
  std::tuple<G4ThreeVector, MaterialExtension*> GetVerticesDistributionInFilledSphere(const G4ThreeVector center, G4double radius);
  std::tuple<G4ThreeVector, MaterialExtension*> GetVerticesDistributionAlongStepVector(const G4ThreeVector center, const G4ThreeVector direction);
  G4PrimaryVertex* GenerateTwoGammaVertex(const G4ThreeVector vtxPosition, const G4double T0, const G4double lifetime2g);
  G4PrimaryVertex* GenerateThreeGammaVertex(const G4ThreeVector vtxPosition, const G4double T0, const G4double lifetime3g);
  G4PrimaryVertex* GeneratePromptGammaVertex(const G4ThreeVector vtxPosition, const G4double T0, const G4double lifetimePrompt, const G4double energy);
  G4ThreeVector VertexUniformInCylinder(G4double, G4double);
  G4double calculate_mQED(Double_t mass_e, Double_t w1, Double_t w2, Double_t w3);
  const G4ThreeVector  GetRandomPointInFilledSphere(G4double radius);
  const G4ThreeVector  GetRandomPointOnSphere(G4double radius);
  G4Navigator* theNavigator =  G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking();
};

#endif
