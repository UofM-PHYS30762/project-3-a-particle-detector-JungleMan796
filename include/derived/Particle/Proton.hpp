// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Proton (derived) class.

#ifndef PROTON_HPP
#define PROTON_HPP

#include "derived/Particle/Hadron.hpp"

#include <iostream>
#include <string>
#include <memory>

class Proton : public Hadron
{
    public:
    // Defualt constructor.
    Proton();

    // Parameterised constructor.
    Proton(double E, double px, double py, double pz, bool is_anti);

    // Destructor.
    ~Proton();

    // Print function for characteristics common to Proton.
    void print_info() const override;

    // // Interacts with SubDetectors.
    // bool interacts_with_hadron_calorimeter() const override;
    // bool interacts_with_em_calorimeter() const override;
    // bool interacts_with_muonchamber() const override;
    // bool interacts_with_tracker() const override;
};

#endif