// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the Pion (derived) class.

#include "derived/Particle/Pion.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt constructor.
Pion::Pion() : Meson(0.0, 0.0, 0.0, 0.0, false, false, 134.98, 139.57) // Calling the intermediate base class paramerterised constuctor.
// Defualt makes a neutral pion(rest_mass = 134.98 MeV) with zero four momentum.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Pion Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
Pion::Pion(double E, double px, double py, double pz, bool is_anti, bool is_charged)
    : Meson(E, px, py, pz, is_anti, is_charged, 134.98, 139.57) // Calling the intermediatebase class parameterised constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Pion Parameterised Constructor." << std::endl;
    }
}

// Destructor.
Pion::~Pion()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Pion Destructor." << std::endl;
    }
}

// Print function for characteristics common to all Pions.
void Pion::print_info() const
{
    std::cout << std::endl; // Line break.
    // Pion specific title.
    std::cout << "--- Pion properties ---" << std::endl;

    // Call the intermediate base class (Meson) print function, to print the characteristics common to all Mesons.
    Meson::print_info();

    if (!is_charged) // This will differ for Kaons for example.
    {
        std::cout << "Note: Neutral Pions are their own anti-particles." << std::endl;
    }

    // Additional characteristics common to Pions.
    std::cout << "Additional Pion characteristics placeholder." << std::endl;
    
    std::cout << std::endl; // Line break.
}