// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Photon (derived) class.

#ifndef PHOTON_HPP
#define PHOTON_HPP

#include "base/Particle.hpp"

#include <iostream>
#include <string>
#include <memory>

class Photon : public Particle
{
    // private:
    // No distinct data members for Photon yet.

    public:
    // Defualt constructor.
    Photon();

    // Parameterised constructor.
    Photon(double E, double px, double py, double pz, bool is_anti);

    // Destructor.
    ~Photon();

    // Print function for characteristics common to Photons.
    void print_info() const override;

    // Interacts with SubDetectors.
    bool interacts_with_hadron_calorimeter() const override;
    bool interacts_with_em_calorimeter() const override;
    bool interacts_with_muonchamber() const override;
};

#endif