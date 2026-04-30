// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the HadronCalorimter (derived) class.

#include "derived/SubDetector/HadronCalorimeter.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Function to check if a Particle interacts with the HadronCalorimeter.
// Used in the detect function, to reduce code repetition.
bool HadronCalorimeter::particle_interacts(const Particle& particle) const
{
    return particle.interacts_with_hadron_calorimeter();
}

// Defualt Constructor.
HadronCalorimeter::HadronCalorimeter() : Calorimeter() // Calling intermediate base class defualt constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling HadronCalorimeter Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
HadronCalorimeter::HadronCalorimeter(std::string sd_name, bool status)
    : Calorimeter(sd_name, status) // Calling intermediate base class parameterised constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling HadronCalorimeter Parameterised Constructor." << std::endl;
    }
}

// Destructor
HadronCalorimeter::~HadronCalorimeter()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling HadronCalorimeter Destructor." << std::endl;
    }
}