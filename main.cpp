// main.cpp for the final project - particle detector.
// Callum Williamson.
// Student ID: 11399397.

// General includes.

#include <iostream>
#include <string>
#include <vector>

// Header includes.
#include "core/DetectorSystem.hpp"

#include "derived/Particle/Electron.hpp"
#include "derived/Particle/Muon.hpp"
#include "derived/Particle/Photon.hpp"
#include "derived/Particle/Pion.hpp"
#include "derived/Particle/Kaon.hpp"
#include "derived/Particle/Proton.hpp"
#include "derived/Particle/Neutron.hpp"

#include "derived/SubDetector/HadronCalorimeter.hpp"
#include "derived/SubDetector/EMCalorimeter.hpp"
#include "derived/SubDetector/MuonChamber.hpp"
#include "derived/SubDetector/Tracker.hpp"

int main()
{
    // Demonstration of minimum functionality.
    std::cout << "--- Demonstration of minimum fucntionality in main.cpp ---" << std::endl;
    std::cout << std::endl; // Line break.
    std::cout << "Creating the CMS DetectorSystem with all the SubDetector components." << std::endl;
    std::cout << std::endl; // Line break.
    // As DSMessages are currently on you will see the print statements of the addtion of the SubDetectors.
    
    // Creation of arbitrary detector (DetectorSystem) with sub-detector (SubDetector) components.
    DetectorSystem det_sys_CMS("CMS Detector System"); // Will construct CMS detector with all components (SubDetectors).

    // CMS SubDetectors will be added below in correct physical order.  
    det_sys_CMS.add_sub_detector(std::make_unique<Tracker>("Silicon Tracker", true));
    det_sys_CMS.add_sub_detector(std::make_unique<EMCalorimeter>("Crystal Electromagnetic Calorimeter", true));
    det_sys_CMS.add_sub_detector(std::make_unique<HadronCalorimeter>("Hadron Calorimeter", true));
    det_sys_CMS.add_sub_detector(std::make_unique<MuonChamber>("Muon Chamber", false)); // MuonChamber is off for testing purposes.

    return 0;
}