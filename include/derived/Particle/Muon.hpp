// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Muon (derived) class.

#ifndef MUON_HPP
#define MUON_HPP

#include "base/Particle.hpp"

#include <iostream>
#include <string>
#include <memory>

class Muon : public Particle
{
    private:
    // No distinct data members for Muon yet.

    public:
    // Defualt constructor.
    Muon();

    // Parameterised constructor.
    Muon(double E, double px, double py, double pz, bool is_anti);

    // Destructor.
    ~Muon();

    // Print function for characteristics common to Muons.
    void print_info() const override;

    // Interacts with SubDetectors.
    bool interacts_with_hadron_calorimeter() const override;
    bool interacts_with_em_calorimeter() const override;
    bool interacts_with_muonchamber() const override;
};

#endif