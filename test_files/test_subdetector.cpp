// test_subdetector.cpp is for me to test the class SubDetector and how Particle can be passed through.
// Purely for testing purposes, not for final project.
// Callum Williamson.
// Student ID: 11399397.

#include <iostream>
#include <string>
#include <vector>

#include "derived/Particle/Electron.hpp"

#include "derived/SubDetector/Calorimeter.hpp"


int main()
{
    std::cout << "Testing SubDetector class." << std::endl;

    Electron e1(10.0, 1.0, 2.0, 3.0, false, 0.0);
    e1.print_info();

    Calorimeter calor1("Calorimeter 1", true);
    calor1.print_info();

    calor1.detect(e1);

    return 0;
}