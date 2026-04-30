// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the HadronCalorimeter (derived) class.

#ifndef HADRONCALORIMETER_HPP
#define HADRONCALORIMETER_HPP

#include "derived/SubDetector/Calorimeter.hpp"

#include <iostream>
#include <string>
#include <memory>

class HadronCalorimeter : public Calorimeter
{
    protected:
    // Function to check if a Particle interacts with the HadronCalorimeter.
    // Used in the detect function, to reduce code repetition.
    bool particle_interacts(const Particle& particle) const override;

    public:
    // Defualt Constructor.
    HadronCalorimeter();

    // Parameterised Constructor.
    HadronCalorimeter(std::string sd_name, bool status);

    // Destructor.
    ~HadronCalorimeter();

    // No distinct print_info or detect function for HadronCalorimeter.
};

#endif