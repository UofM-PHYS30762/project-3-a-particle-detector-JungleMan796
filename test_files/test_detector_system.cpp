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
#include "derived/Particle/Photon.hpp"

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
    
    // Testing remove_sub_detector.
    det_sys_2.remove_sub_detector("Calorimeter 1");
    det_sys_2.print_configuration();

    det_sys_2.remove_sub_detector("Non-Existent SubDetector"); // Testing error handling for non-existent SubDetector.
    det_sys_2.print_configuration();

    // Testing release_sub_detector.
    std::unique_ptr<SubDetector> released_sub_detector_1 = det_sys_2.release_sub_detector("Muon Chamber 1");
    det_sys_2.print_configuration();

    released_sub_detector_1->print_info(); // Testing that the released SubDetector is still usable.

    std::unique_ptr<SubDetector> released_sub_detector_2 = det_sys_2.release_sub_detector("Non-Existent SubDetector"); // Testing error handling for non-existent SubDetector.
    det_sys_2.print_configuration();

    if (released_sub_detector_2)
    {
        released_sub_detector_2->print_info(); // Testing that the released SubDetector is still usable, should be nullptr.
    }
    else
    {
        std::cout << "Released SubDetector is null." << std::endl;
    }

    // Test parameterised constructor with initial SubDetectors vector.
    std::vector<std::unique_ptr<SubDetector>> param_sub_detectors;
    param_sub_detectors.push_back(std::make_unique<Tracker>("Tracker 1", false));
    param_sub_detectors.push_back(std::make_unique<Calorimeter>("Calorimeter 2", true));
    param_sub_detectors.push_back(std::make_unique<MuonChamber>("Muon Chamber 2", false));
    param_sub_detectors.push_back(std::make_unique<Tracker>("Tracker 2", true));

    DetectorSystem det_sys_3("Detector System 3", std::move(param_sub_detectors));
    det_sys_3.print_configuration();

    // Test detect function with a particle.
    Electron electron_1(10.0, 1.0, 2.0, 3.0, false, 0.0);
    det_sys_3.detect(electron_1);

    // Test detect function with another particle.
    Muon muon_1(20.0, 4.0, 5.0, 6.0, false, 0.0);
    det_sys_3.detect(muon_1);

    // Test detect with Photon.
    Photon photon_1(15.0, 7.0, 8.0, 9.0, false);
    det_sys_3.detect(photon_1);

    // Test set_sub_detector_status.
    det_sys_3.set_sub_detector_status("Tracker 1", true);
    det_sys_3.set_sub_detector_status("Non-Existent SubDetector", true); // Testing error handling for non-existent SubDetector.

    det_sys_3.detect(electron_1); // Testing that Tracker 1 is now on for detection.

    return 0;
}