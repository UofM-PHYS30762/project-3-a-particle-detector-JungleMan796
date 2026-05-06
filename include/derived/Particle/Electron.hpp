// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Electron (derived) class.

#ifndef ELECTRON_HPP
#define ELECTRON_HPP

#include "base/Particle.hpp"

#include <iostream>
#include <string>
#include <memory>

class Electron : public Particle
{
    private:
    // No Electron distinct data members yet.

    public:
    // Defualt constructor.
    Electron();

    // Parameterised constructor.
    Electron(double E, double px, double py, double pz, bool is_anti);

    // Destructor.
    ~Electron();

    // Print function for characteristics common to Electrons.
    void print_info() const override;

    // Interacts with SubDetectors.
    bool interacts_with_hadron_calorimeter() const override;
    bool interacts_with_em_calorimeter() const override;
    bool interacts_with_muonchamber() const override;
};

#endif  