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
 *  @file PrimaryGeneratorActionMessenger.h
 */

#ifndef PRIMARYGENERATORACTIONMESSENGER_H
#define PRIMARYGENERATORACTIONMESSENGER_H 1

#include <G4UIcmdWithADoubleAndUnit.hh>
#include <G4UIcmdWith3VectorAndUnit.hh>
#include <G4UIcmdWithoutParameter.hh>
#include <G4UIcmdWithAnInteger.hh>
#include <G4UIcmdWith3Vector.hh>
#include <G4UIcmdWithAString.hh>
#include <G4SystemOfUnits.hh>
#include <G4UIdirectory.hh>
#include <G4UImessenger.hh>
#include <globals.hh>

class PrimaryGeneratorAction;

class PrimaryGeneratorActionMessenger: public G4UImessenger
{
public:
  PrimaryGeneratorActionMessenger(PrimaryGeneratorAction* primGeneratorAction);
  ~PrimaryGeneratorActionMessenger();
  void SetNewValue(G4UIcommand*, G4String);

private:
  void ChangeToBeam();
  void ChangeToRun();
  void ChangeToIsotope();
  bool CheckIfRun();
  PrimaryGeneratorAction* fPrimGen = nullptr;
  G4UIdirectory* fDirectory = nullptr;
  G4UIdirectory* fDirectoryRun = nullptr;
  G4UIcmdWithAString* fSourceType = nullptr;
  G4UIcmdWithADoubleAndUnit* fGammaBeamSetEnergy = nullptr;
  G4UIcmdWith3VectorAndUnit* fGammaBeamSetPosition = nullptr;
  G4UIcmdWith3VectorAndUnit* fGammaBeamSetMomentum = nullptr;
  G4UIcmdWithAString* fIsotopeSetShape = nullptr;
  G4UIcmdWithAnInteger* fIsotopeSetGenGammas = nullptr;
  G4UIcmdWithADoubleAndUnit* fIsotopeSetShapeDimCylinderRadius = nullptr;
  G4UIcmdWithADoubleAndUnit* fIsotopeSetShapeDimCylinderZ = nullptr;
  G4UIcmdWith3VectorAndUnit* fIsotopeSetCenter = nullptr;
  G4UIcmdWithAnInteger* fNemaPosition = nullptr;
  G4UIcmdWith3VectorAndUnit* fSetChamberCenter = nullptr;
  G4UIcmdWithADoubleAndUnit* fSetChamberEffectivePositronRadius = nullptr;

};

#endif
