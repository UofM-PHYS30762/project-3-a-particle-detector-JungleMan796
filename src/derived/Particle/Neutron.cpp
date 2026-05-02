// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the Neutron (derived) class.

#include "derived/Particle/Neutron.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt constructor.
Neutron::Neutron() : Hadron(0.0, 0.0, 0.0, 0.0, 939.565, false, 0) // Calling the intermediate base class paramerterised constuctor.
// Defualt makes a non-anti neutron.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Neutron Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
Neutron::Neutron(double E, double px, double py, double pz, bool is_anti)
    : Hadron(E, px, py, pz, 939.565, is_anti, 0) // Calling the intermediatebase class parameterised constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Neutron Parameterised Constructor." << std::endl;
    }
}

// Destructor.
Neutron::~Neutron()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Neutron Destructor." << std::endl;
    }
}

// Print function for characteristics common to all Photons.
void Neutron::print_info() const
{
    std::cout << std::endl; // Line break.
    // Neutron specific title.
    std::cout << "--- Neutron properties ---" << std::endl;

    // Call the base class print function to print the common characteristics of all Particles.
    Particle::print_info();

    // Test for charge info.
    std::cout << "Charge: 0e" << std::endl;

    // Additional characteristics common to Neutrons.
    std::cout << "Additional Neutron characteristics placeholder." << std::endl;
    
    std::cout << std::endl; // Line break.
}