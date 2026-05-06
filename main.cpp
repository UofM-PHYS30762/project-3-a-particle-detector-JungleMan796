// main.cpp for the final project - particle detector.
// Callum Williamson.
// Student ID: 11399397.

// General includes.

#include <iostream>
#include <string>
#include <vector>

// Header includes.
#include "core/Debug.hpp"
#include "core/DSMessages.hpp"

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
    det_sys_CMS.add_sub_detector(std::make_unique<MuonChamber>("Muon Chamber", true));
    det_sys_CMS.print_configuration(); // Demonstration of printing entire configuration.

    // Creation of Muon to pass through det_sys_CMS to demonstrate minimum functionality.
    Muon muon_1(20.0, 2.0, 3.0, 4.0, false);
    muon_1.print_info();

    det_sys_CMS.detect(muon_1); // Pass muon_1 throught the DetectorSystem.

    // Demonstration of advanced features.
    std::cout << "--- Demonstration of advanced features in main.cpp ---" << std::endl;
    std::cout << std::endl; // Line break.

    // Example of wrapper function to alter SubDetector status.
    std::cout << "Using a wrapper function to alter the status of a contained SubDetector." << std::endl;
    std::cout << "Demonstrating how this alters the detection process." << std::endl;
    det_sys_CMS.set_sub_detector_status("Muon Chamber", false);
    det_sys_CMS.detect(muon_1); // Demonstration of how this changes the detection process.

    std::cout << "Creating another DetectorSystem to demonstrate deletion and extraction of the contained SubDetectors." << std::endl;
    DetectorSystem det_sys_2("DetectorSystem 2"); // Creating Detector System to remove and release SubDetectors.
    std::cout << std::endl; // Line break.

    det_sys_2.add_sub_detector(std::make_unique<Tracker>("Silicon Tracker 2", true));
    det_sys_2.add_sub_detector(std::make_unique<EMCalorimeter>("Crystal Electromagnetic Calorimeter 2", true));

    det_sys_2.print_configuration(); // Comment if wish to reduce bloat.

    det_sys_2.remove_sub_detector("Crystal Electromagnetic Calorimeter 2"); // Deleting this Calorimeter.
    det_sys_2.print_configuration(); // Uncomment if wish to see process clearer.

    std::unique_ptr<SubDetector> released_sub_detector = det_sys_2.release_sub_detector("Silicon Tracker 2");
    std::cout << "Example of released SubDetector detecting alone." << std::endl;
    released_sub_detector->detect(muon_1); // Example of released SubDetector acting alone.

    // Demonstration of Debug namespace, turned on and then off.
    std::cout << "Example of Debug namespace turned on when an object is created." << std::endl;
    std::cout << std::endl; // Line break.
    Debug::show_messages = true; // Turn Debug messages on.

    // Created object to show constructor messages.
    Electron electron_1(10.0, 1.0, 2.0, 3.0, false);

    Debug::show_messages = false; // Turn Debug messages off.
    std::cout << std::endl; // Line break.
    std::cout << "Debug namespace has now been turned off again." << std::endl;

    return 0;
}