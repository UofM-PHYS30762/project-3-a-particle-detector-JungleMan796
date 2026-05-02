// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the Meson (intermediate base) class.

#include "derived/Particle/Meson.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt constructor.
Meson::Meson() : Hadron(0.0, 0.0, 0.0, 0.0, 0.0, false, 0), // Calling the intermediate base class paramerterised constuctor.
    is_charged(false)
// Defualt makes a neutral meson with zero FourMomentum and zero rest_mass.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Meson Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
Meson::Meson(double E, double px, double py, double pz, bool is_anti,
    bool is_charged, double neutral_rest_mass, double charged_rest_mass)
    // Calling the intermediatebase class parameterised constructor.
    : Hadron(E, px, py, pz, is_charged ? charged_rest_mass : neutral_rest_mass, is_anti, is_charged ? 1 : 0),
    is_charged(is_charged)
    // rest_mass is set based on if charged or neutral, so is the charge_mag.
    // charge_mag for mesons is always 1 or 0.
    // neutral and charged rest masses are not stored as data members as they're not needed after initialisation.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Meson Parameterised Constructor." << std::endl;
    }
}

// Destructor.
Meson::~Meson()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Meson Destructor." << std::endl;
    }
}

// Print function for characteristics common to all Mesons.
void Meson::print_info() const
{
    // std::cout << std::endl; // Line break.
    // // Meson specific title.
    // std::cout << "--- Meson properties ---" << std::endl;

    // Call the base class print function to print the common characteristics of all Particles.
    Particle::print_info();

    // Print charge information.
    if (is_charged)
    {
        std::cout << "Charge: " << (is_anti ? "-1" : "+1") << "e" << std::endl;
        // The negative Meson is considered the anti-particle.
    }
    else
    {
        std::cout << "Charge: 0e (Neutral Meson)" << std::endl;
    }

    // Additional characteristics common to Mesons.
    std::cout << "Additional Meson characteristics placeholder." << std::endl;
}