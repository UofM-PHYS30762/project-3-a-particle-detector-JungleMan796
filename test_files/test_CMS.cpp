// test_CMS.cpp is for me to test the class DetectorSystem and build the CMS detector.
// Purely for testing purposes, will be used in the min functionality of the final project.
// Callum Williamson.
// Student ID: 11399397.

#include <iostream>
#include <string>
#include <vector>

#include "core/DetectorSystem.hpp"

#include "derived/Particle/Electron.hpp"
#include "derived/Particle/Muon.hpp"
#include "derived/Particle/Photon.hpp"

#include "derived/SubDetector/HadronCalorimeter.hpp"
#include "derived/SubDetector/EMCalorimeter.hpp"
#include "derived/SubDetector/MuonChamber.hpp"
#include "derived/SubDetector/Tracker.hpp"

int main()
{
    std::cout << "Testing DetectorSystem class by trying to create the CMS detector." << std::endl;
    std::cout << std::endl;

    // Test parameterized constructor.
    DetectorSystem det_sys_CMS("CMS Detector System");

    // Add SubDetectors to the CMS DetectorSystem.
    det_sys_CMS.add_sub_detector(std::make_unique<Tracker>("Silicon Tracker", true));
    det_sys_CMS.add_sub_detector(std::make_unique<EMCalorimeter>("Crystal Electromagnetic Calorimeter", true));
    det_sys_CMS.add_sub_detector(std::make_unique<HadronCalorimeter>("Hadron Calorimeter", true));
    det_sys_CMS.add_sub_detector(std::make_unique<EMCalorimeter>("Forward Calorimeter", true));
    det_sys_CMS.add_sub_detector(std::make_unique<MuonChamber>("Muon Chamber", true));

    // Print CMS configuration.
    det_sys_CMS.print_configuration();

    // Define particle for detection test.
    Electron electron_1(10.0, 1.0, 2.0, 3.0, false, 0.0);
    electron_1.print_info();
    electron_1.set_is_anti(true);
    electron_1.print_info();

    Muon muon_1(20.0, 4.0, 5.0, 6.0, false, 0.0);
    muon_1.print_info();
    muon_1.set_is_anti(true);
    muon_1.print_info();

    Photon photon_1(30.0, 7.0, 9.0, 11.0, false);
    photon_1.print_info();

    // Detection.
    det_sys_CMS.detect(electron_1);
    det_sys_CMS.detect(muon_1);
    det_sys_CMS.detect(photon_1);

    
    return 0;
}