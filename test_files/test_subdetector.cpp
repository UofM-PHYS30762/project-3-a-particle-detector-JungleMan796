// test_subdetector.cpp is for me to test the class SubDetector and how Particle can be passed through.
// Purely for testing purposes, not for final project.
// Callum Williamson.
// Student ID: 11399397.

#include <iostream>
#include <string>
#include <vector>

#include "derived/Particle/Electron.hpp"
#include "derived/Particle/Muon.hpp"

#include "derived/SubDetector/Calorimeter.hpp"
#include "derived/SubDetector/MuonChamber.hpp"


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

    return 0;
}