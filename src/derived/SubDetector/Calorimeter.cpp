// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the Calorimter (derived) class.

#include "derived/SubDetector/Calorimeter.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt Constructor.
Calorimeter::Calorimeter() : SubDetector() // Calling base class defualt constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Calorimeter Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
Calorimeter::Calorimeter(std::string sd_name, bool status)
    : SubDetector(sd_name, status) // Calling base class parameterised constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Calorimeter Parameterised Constructor." << std::endl;
    }
}

// Destructor
Calorimeter::~Calorimeter()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Calorimeter Destructor." << std::endl;
    }
}

// Print function for characteristics common to all Calorimeters.
void Calorimeter::print_info() const
{
    std::cout << std::endl; // Line break.
    // Calorimeter specific title.
    std::cout << "--- Calorimeter (" << sd_name << ") properties ---" << std::endl;

    // Call the base class print function to print the common characteristics of all SubDetectors.
    SubDetector::print_info();

    // Additional characteristics common to Calorimeters.
    std::cout << "Placeholder Calorimeters unique characteristics." << std::endl;

    std::cout << std::endl; // Line break.
}

// Function for Calorimeter detection of Particle class.
void Calorimeter::detect(const Particle& particle) const
{
    if (particle.interacts_with_calorimeter())
    {
        std::cout << "Calorimeter measures the energy of the particle as: " << particle.get_four_momentum().get_E() << " MeV" << std::endl;
        // Will differentiate these later.
        std::cout << "The particle's true energy is: " << particle.get_four_momentum().get_E() << " MeV" << std::endl;
    }
    else
    {
        std::cout << "Particle does not interact with the calorimeter, no energy measurement." << std::endl;
    }
}