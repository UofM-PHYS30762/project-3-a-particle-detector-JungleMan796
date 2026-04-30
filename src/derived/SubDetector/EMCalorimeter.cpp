// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the EMCalorimeter (ElectroMagneticCalorimeter) (derived) class.

#include "derived/SubDetector/EMCalorimeter.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Function to check if a Particle interacts with the EMCalorimeter.
// Used in the detect function, to reduce code repetition.
bool EMCalorimeter::particle_interacts(const Particle& particle) const
{
    return particle.interacts_with_em_calorimeter();
}

// Defualt Constructor.
EMCalorimeter::EMCalorimeter() : Calorimeter() // Calling intermediate base class defualt constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling EMCalorimeter Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
EMCalorimeter::EMCalorimeter(std::string sd_name, bool status)
    : Calorimeter(sd_name, status) // Calling intermediate base class parameterised constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling EMCalorimeter Parameterised Constructor." << std::endl;
    }
}

// Destructor
EMCalorimeter::~EMCalorimeter()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling EMCalorimeter Destructor." << std::endl;
    }
}