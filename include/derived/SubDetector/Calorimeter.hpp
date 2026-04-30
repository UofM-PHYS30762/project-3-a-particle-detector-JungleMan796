// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the Calorimeter (abstract base intermediate) class.

#ifndef CALORIMETER_HPP
#define CALORIMETER_HPP

#include "base/SubDetector.hpp"

#include <iostream>
#include <string>
#include <memory>

class Calorimeter : public SubDetector
{
    protected:
    // Pure virtual function to check if a Particle interacts with the Calorimeter, will be overridden in derived classes.
    // Used in the detect function.
    virtual bool particle_interacts(const Particle& particle) const = 0;

    public:
    // Defualt Constructor.
    Calorimeter();

    // Parameterised Constructor.
    Calorimeter(std::string sd_name, bool status);

    // Destructor.
    ~Calorimeter();

    // Print function for characteristics common to Calorimeters.
    void print_info() const override;

    // Function for Calorimeter detection of Particle class.
    void detect(const Particle& particle) const override;
};

#endif