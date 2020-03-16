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
 *  @file MaterialExtension.h
 */

#ifndef MATERIALEXTENSION_H
#define MATERIALEXTENSION_H 1

#include "../Info/MaterialExtensionMessenger.h"
#include "MaterialParameters.h"
#include <G4VMaterialExtension.hh>
#include <G4SystemOfUnits.hh>
#include <G4UnitsTable.hh>
#include <G4Material.hh>
#include <globals.hh>
#include <vector>

/**
 * @class MaterialExtension
 * @brief extended material keeps information about 2g/3g creation fraction
 */

class MaterialExtension : public G4Material
{
public:
  MaterialExtension(const G4String& materialType, const G4String& name, const G4Material* baseMaterial);
  ~MaterialExtension();

  G4Material* GetMaterial(){return fMaterial;};
  void Add_oPsComponent(G4double Lifetime, G4double Probability);
  void Add_directComponent(G4double Lifetime, G4double Probability);
  void Set_pPsComponent(G4double Lifetime, G4double Fraction);
  const G4double GetLifetime(double randNumber, G4String channel) const;
  
/* Changing lifetime and intensity parameters of Material to the parameters from 
 * the dummy object MaterialParameters::Temp that are currently set on it.
 * This object allows to modify its parameters by the user on the macro level
 * After every call of ChangeMaterialConstants() object MaterialParameters::Temp
   is cleared in the meesenger for further modification of different material*/
  void ChangeMaterialConstants();

  void FillIntensities() {fMaterialParameters->Set_ComponentsIntensities();};
  //! 2g direct // 2g pickoff (lifetime 3g) // 3g direct // 3g oPs (lifetime 3g)
  const std::vector<G4double> GetEventsFraction() const;

  G4bool IsTarget() const {return fTarget;};
  void AllowsAnnihilations(G4bool tf) {fTarget = tf;};
  void Print() const {;};

  G4bool IsExtended() const {return true;}

private:
  G4Material* fMaterial = nullptr;
  MaterialExtensionMessenger* fMaterialExtensionMessenger
    = MaterialExtensionMessenger::GetMaterialExtensionMessenger();
  G4bool fTarget;
  MaterialParameters *fMaterialParameters = nullptr;
};

#endif
