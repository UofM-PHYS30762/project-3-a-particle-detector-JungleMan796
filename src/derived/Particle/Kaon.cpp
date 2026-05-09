// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the Kaon (derived) class.

#include "derived/Particle/Kaon.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt constructor.
Kaon::Kaon() : Meson(0.0, 0.0, 0.0, 0.0, false, false, 497.648, 493.677) // Calling the intermediate base class paramerterised constuctor.
// Defualt makes a neutral normal matter Kaon (rest_mass = 493.677 MeV) with zero four momentum.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Kaon Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
Kaon::Kaon(double E, double px, double py, double pz, bool is_anti, bool is_charged)
    : Meson(E, px, py, pz, is_anti, is_charged, 497.648, 493.677) // Calling the intermediatebase class parameterised constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Kaon Parameterised Constructor." << std::endl;
    }
}

// Destructor.
Kaon::~Kaon()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Kaon Destructor." << std::endl;
    }
}

// Print function for characteristics common to all Kaons.
void Kaon::print_info() const
{
    std::cout << std::endl; // Line break.
    // Kaon specific title.
    std::cout << "--- Kaon properties ---" << std::endl;

    // Call the intermediate base class (Meson) print function, to print the characteristics common to all Mesons.
    Meson::print_info();

    if (!is_charged) // This will differ for Pions for example.
    {
        std::cout << "Note: Neutral Kaons possess distinct anti-particles." << std::endl;
    }
    
    std::cout << std::endl; // Line break.
}