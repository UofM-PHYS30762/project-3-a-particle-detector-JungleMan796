// main_helpers.cpp for the main.cpp.
// Callum Williamson.
// Student ID: 11399397.

// General includes.

#include <iostream>
#include <string>
#include <vector>

// Header includes.
#include "core/main_helpers.hpp"

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

DetectorSystem create_CMS_detector()
{
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

    return det_sys_CMS;
}

DetectorSystem demonstrate_minimium_functionality()
{
    // Demonstration of minimum functionality.
    std::cout << "--- Demonstration of minimum functionality in main.cpp ---" << std::endl;
    std::cout << std::endl; // Line break.
    DetectorSystem det_sys_CMS = create_CMS_detector();
    
    det_sys_CMS.print_configuration(); // Demonstration of printing entire configuration.

    // Creation of Muon to pass through det_sys_CMS to demonstrate minimum functionality.
    Muon muon_1(130.0, 2.0, 3.0, 4.0, false);
    muon_1.print_info();

    det_sys_CMS.detect(muon_1); // Pass muon_1 through the DetectorSystem.

    return det_sys_CMS; // Returns the det_sys_CMS so that it doesn't need to be reconstructed.
}

void demonstrate_wrapper_sub_detector_status(DetectorSystem& det_sys)
{
    // Made for det_sys = det_sys_CMS

    // Example of wrapper function to alter SubDetector status.
    std::cout << "Demonstrating the use of a wrapper function to alter the status of a contained SubDetector." << std::endl;
    std::cout << "Demonstrating how this alters the detection process." << std::endl;

    Muon muon_2(130.0, 2.0, 3.0, 4.0, false); // Making new Muon to do this so I another doesn't need to be passed.

    det_sys.set_sub_detector_status("Muon Chamber", false);
    det_sys.detect(muon_2); // Demonstration of how this changes the detection process.
    det_sys.set_sub_detector_status("Muon Chamber", true); // Turning the MuonChamber back on.
}

void print_detect_print_for_abs(DetectorSystem& det_sys, Particle& particle)
{
    particle.print_info();
    det_sys.detect(particle);
    particle.print_info();
}

void demonstrate_particle_absorption(DetectorSystem& det_sys)
{
    // Made for det_sys = det_sys_CMS

    // Demonstration of Calorimeters absorbing particles, returning the Particles with no 3-momenta and their rest_mass energy.
    std::cout << "Demonstrating with Calorimeter interacting Particles that they are absorbed." << std::endl;
    std::cout << std::endl; // Line break.

    // Demonstration of an anti-electron.
    std::cout << "Demonstrating with a Positron (anti-Electron)." << std::endl;
    Electron electron_1(10.0, 1.0, 2.0, 3.0, true);

    print_detect_print_for_abs(det_sys, electron_1);

    // Demonstration of a Hadron - Neutral Pion.
    std::cout << "Demonstrating with a Neutral Pion." << std::endl;
    Pion pion_1(500.0, 4.0, 5.0, 6.0, false, false);

    print_detect_print_for_abs(det_sys, pion_1);

    // Demonstration of a Photon.
    std::cout << "Demonstrating with a Photon." << std::endl;
    Photon photon_1(50.0, 50.0, 0.0, 0.0, false);

    print_detect_print_for_abs(det_sys, photon_1);
}

void demonstrate_remove_and_release()
{
    std::cout << "Creating another DetectorSystem to demonstrate deletion and extraction of the contained SubDetectors." << std::endl;
    std::cout << "After a deletion or extraction the DetectorSystem configuration will be printed to show the change." << std::endl;
    DetectorSystem det_sys_2("DetectorSystem 2"); // Creating Detector System to remove and release SubDetectors.
    std::cout << std::endl; // Line break.

    det_sys_2.add_sub_detector(std::make_unique<Tracker>("Silicon Tracker 2", true));
    det_sys_2.add_sub_detector(std::make_unique<EMCalorimeter>("Crystal Electromagnetic Calorimeter 2", true));

    det_sys_2.print_configuration(); // Comment if wish to reduce bloat.

    det_sys_2.remove_sub_detector("Crystal Electromagnetic Calorimeter 2"); // Deleting this Calorimeter.
    det_sys_2.print_configuration(); // Uncomment if wish to see process clearer.

    std::unique_ptr<SubDetector> released_sub_detector = det_sys_2.release_sub_detector("Silicon Tracker 2");
    std::cout << "Example of released SubDetector detecting a Charged Kaon alone." << std::endl;

    Kaon kaon_1(600.0, 3.0, 4.0, 5.0, false, true);

    released_sub_detector->detect(kaon_1); // Example of released SubDetector acting alone.
}

void demonstrate_debug_messages()
{
    // Demonstration of Debug namespace, turned on and then off.
    std::cout << "Example of Debug namespace turned on when an object (Neutron) is created." << std::endl;
    std::cout << std::endl; // Line break.
    Debug::show_messages = true; // Turn Debug messages on.

    // Created object to show constructor messages.
    Neutron neutron_1(1000, 1.0, 2.0, 3.0, false);

    Debug::show_messages = false; // Turn Debug messages off.
    std::cout << std::endl; // Line break.
    std::cout << "Debug namespace has now been turned off again." << std::endl;
}

void demonstrate_advanced_features(DetectorSystem& det_sys)
{
    // Demonstration of advanced features.
    std::cout << "--- Demonstration of advanced features in main.cpp ---" << std::endl;
    std::cout << std::endl; // Line break.

    // All functions demsonstrating advanced features called.
    demonstrate_wrapper_sub_detector_status(det_sys);
    demonstrate_particle_absorption(det_sys);
    demonstrate_remove_and_release();
    demonstrate_debug_messages();

}