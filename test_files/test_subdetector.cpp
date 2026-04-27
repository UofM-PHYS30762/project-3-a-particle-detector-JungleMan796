// test_subdetector.cpp is for me to test the class SubDetector and how Particle can be passed through.
// Purely for testing purposes, not for final project.
// Callum Williamson.
// Student ID: 11399397.

#include <iostream>
#include <string>
#include <vector>

#include "derived/Particle/Electron.hpp"
#include "derived/Particle/Muon.hpp"
#include "derived/Particle/Photon.hpp"

#include "derived/SubDetector/Calorimeter.hpp"
#include "derived/SubDetector/MuonChamber.hpp"
#include "derived/SubDetector/Tracker.hpp"


int main()
{
    std::cout << "Testing SubDetector class." << std::endl;

    Electron e1(10.0, 1.0, 2.0, 3.0, false, 0.0);
    e1.print_info();

    Muon m1(20.0, 4.0, 5.0, 6.0, false, 0.0);
    m1.print_info();

    Calorimeter calor1("Calorimeter 1", true);
    calor1.print_info();

    Calorimeter calor2("Calorimeter 2", false); // status off to test the status check in the detect function.
    calor2.print_info();

    calor1.detect(e1);
    calor2.detect(e1);

    calor1.detect(m1); // Testing detection of a Muon in the calorimeter, should not interact.

    MuonChamber muonchamber1("Muon Chamber 1", true);
    muonchamber1.print_info();

    muonchamber1.detect(e1); // Testing detection of an Electron in the muon chamber, should not interact.
    muonchamber1.detect(m1); // Testing detection of a Muon in the muon chamber, should interact and print energy measurement.

    Tracker tracker1("Tracker 1", true);
    tracker1.print_info();

    tracker1.detect(e1); // Testing detection of an Electron in the tracker, should interact and print energy measurement.
    tracker1.detect(m1); // Testing detection of a Muon in the tracker, should interact and print energy measurement.

    // Test Photon interactions.
    Photon p1(15.0, 7.0, 8.0, 9.0, false);
    p1.print_info();

    calor1.detect(p1);
    muonchamber1.detect(p1);
    tracker1.detect(p1);

    return 0;
}