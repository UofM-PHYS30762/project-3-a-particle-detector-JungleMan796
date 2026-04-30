// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the EMCalorimeter (ElectroMagneticCalorimeter) (derived) class.

#ifndef EMCALORIMETER_HPP
#define EMCALORIMETER_HPP

#include "derived/SubDetector/Calorimeter.hpp"

#include <iostream>
#include <string>
#include <memory>

class EMCalorimeter : public Calorimeter
{
    protected:
    // Function to check if a Particle interacts with the EMCalorimeter.
    // Used in the detect function, to reduce code repetition.
    bool particle_interacts(const Particle& particle) const override;

    public:
    // Defualt Constructor.
    EMCalorimeter();

    // Parameterised Constructor.
    EMCalorimeter(std::string sd_name, bool status);

    // Destructor.
    ~EMCalorimeter();

    // No distinct print_info or detect function for EMCalorimeter.
};

#endif