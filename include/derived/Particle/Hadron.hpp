// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Hadron (abstract base intermediate) class.

#ifndef HADRON_HPP
#define HADRON_HPP

#include "base/Particle.hpp"

#include <iostream>
#include <string>
#include <memory>

class Hadron : public Particle
{
    private:
    // No distinct data members for Hadron yet.

    public:
    // Defualt constructor.
    Hadron();

    // Parameterised constructor.
    Hadron(double E, double px, double py, double pz, double rest_mass, bool is_anti, int charge_mag);

    // Destructor.
    ~Hadron();

    // // Print function for characteristics common to Hadron.
    // void print_info() const override;

    // Interacts with SubDetectors.
    bool interacts_with_hadron_calorimeter() const override;
    bool interacts_with_em_calorimeter() const override;
    bool interacts_with_muonchamber() const override;
};

#endif