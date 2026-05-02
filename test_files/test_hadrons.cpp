// test_hadrons.cpp is for me to test the class Hadron and its derived classes..
// Purely for testing purposes.
// Callum Williamson.
// Student ID: 11399397.

#include <iostream>
#include <string>
#include <vector>

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
    std::cout << "Testing Hadron derived classes." << std::endl;
    std::cout << std::endl;

    // Test default constructor Pion.
    Pion pion_1;
    pion_1.print_info();

    // Test parameterised constructor Pion, charged Pion.
    Pion pion_2(10.0, 1.0, 2.0, 3.0, false, true);
    pion_2.print_info();

    pion_2.set_is_anti(true); // Make it an anti-pion to see if charge changes.
    pion_2.print_info();

    Pion pion_3(15.0, 4.0, 5.0, 6.0, false, false); // Testing parameterised constructor for neutral Pion.
    pion_3.print_info(); // Anti is redundant :(.

    pion_3.set_is_anti(true);
    pion_3.print_info();

    // Test parameterized constructor.
    DetectorSystem det_sys_CMS("CMS Detector System");

    // Add SubDetectors to the CMS DetectorSystem.
    det_sys_CMS.add_sub_detector(std::make_unique<Tracker>("Silicon Tracker", true));
    det_sys_CMS.add_sub_detector(std::make_unique<EMCalorimeter>("Crystal Electromagnetic Calorimeter", true));
    det_sys_CMS.add_sub_detector(std::make_unique<HadronCalorimeter>("Hadron Calorimeter", true));
    det_sys_CMS.add_sub_detector(std::make_unique<EMCalorimeter>("Forward Calorimeter", true));
    det_sys_CMS.add_sub_detector(std::make_unique<MuonChamber>("Muon Chamber", true));

    det_sys_CMS.detect(pion_3);
    det_sys_CMS.detect(pion_2);

    // Test Kaons.
    Kaon kaon_1;
    kaon_1.print_info();

    Kaon kaon_2(20.0, 4.0, 5.0, 6.0, false, true);
    kaon_2.print_info();
    kaon_2.set_is_anti(true);
    kaon_2.print_info();

    Kaon kaon_3(25.0, 7.0, 8.0, 9.0, true, false);
    kaon_3.print_info();

    det_sys_CMS.detect(kaon_2);
    det_sys_CMS.detect(kaon_3);

    // Test default constructor Proton.
    Proton proton_1;
    proton_1.print_info();
    proton_1.set_is_anti(true);
    proton_1.print_info();

    Proton proton_2(20.0, 4.0, 5.0, 6.0, false);
    proton_2.print_info();

    det_sys_CMS.detect(proton_1);

    // Testing Neutrons.
    Neutron neutron_1;
    neutron_1.print_info();
    neutron_1.set_is_anti(true);
    neutron_1.print_info();

    Neutron neutron_2(30.0, 7.0, 8.0, 9.0, false);
    neutron_2.print_info();

    det_sys_CMS.detect(neutron_1);
    
    return 0;
}