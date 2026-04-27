// test_detector_system.cpp is for me to test the class DetectorSystem.
// Purely for testing purposes, not for final project.
// Callum Williamson.
// Student ID: 11399397.

#include <iostream>
#include <string>
#include <vector>

#include "core/DetectorSystem.hpp"

#include "derived/Particle/Electron.hpp"
#include "derived/Particle/Muon.hpp"

#include "derived/SubDetector/Calorimeter.hpp"
#include "derived/SubDetector/MuonChamber.hpp"
#include "derived/SubDetector/Tracker.hpp"

int main()
{
    std::cout << "Testing DetectorSystem class." << std::endl;
    std::cout << std::endl;

    // Test defualt constructor.
    DetectorSystem det_sys_1;
    det_sys_1.print_configuration();

    // Test setter and getter for sys_name.
    det_sys_1.set_sys_name("Detector System 1");
    std::cout << "DetectorSystem name: " << det_sys_1.get_sys_name() << std::endl;
    
    // Test parameterised constructor with no initial SubDetectors vector.
    DetectorSystem det_sys_2("Detector System 2");
    det_sys_2.print_configuration();

    // Testing add_sub_detector.
    det_sys_2.add_sub_detector(std::make_unique<Calorimeter>("Calorimeter 1", true)); // Testing adding direct.

    det_sys_2.print_configuration();

    std::unique_ptr<SubDetector> muon_chamber_1 = std::make_unique<MuonChamber>("Muon Chamber 1", true);

    det_sys_2.add_sub_detector(std::move(muon_chamber_1)); // Testing adding with move semantics.
    det_sys_2.print_configuration();

    return 0;
}