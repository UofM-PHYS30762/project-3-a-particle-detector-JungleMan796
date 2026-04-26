// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the MuonChamber (derived) class.

#ifndef MUONCHAMBER_HPP
#define MUONCHAMBER_HPP

#include "base/SubDetector.hpp"

#include <iostream>
#include <string>
#include <memory>

class MuonChamber : public SubDetector
{
    public:
    // Defualt Constructor.
    MuonChamber();

    // Parameterised Constructor.
    MuonChamber(std::string sd_name, bool status);

    // Destructor.
    ~MuonChamber();

    // Print function for characteristics common to MuonChambers.
    void print_info() const override;

    // Function for MuonChamber detection of Particle class.
    void detect(const Particle& particle) const override;
};

#endif