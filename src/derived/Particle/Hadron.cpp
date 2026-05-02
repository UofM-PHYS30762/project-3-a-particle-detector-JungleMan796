// Callum Williamson.
// Student ID: 11399397.

// Implementation file for the Hadron (abstract base intermediate) class.

#include "derived/Particle/Hadron.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt constructor.
Hadron::Hadron() : Particle(0.0, 0.0, 0.0, 0.0, 0, false, 0) // Calling the base class paramerterised constuctor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Hadron Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
Hadron::Hadron(double E, double px, double py, double pz, double rest_mass, bool is_anti, int charge_mag)
    : Particle(E, px, py, pz, rest_mass, is_anti, charge_mag) // Calling the base class parameterised constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Hadron Parameterised Constructor." << std::endl;
    }
}

// Destructor.
Hadron::~Hadron()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Hadron Destructor." << std::endl;
    }
}

// // Print function for characteristics common to all Hadrons.
// void Hadron::print_info() const
// {
//     std::cout << std::endl; // Line break.
//     // Hadron speccfic title.
//     std::cout << "--- Hadron properties ---" << std::endl;

//     // Call the base class print function to print the common characteristics of all Particles.
//     Particle::print_info();

//     // Additional characteristics common to Hadrons.
//     std::cout << "Additional Hadron properties placeholder." << std::endl;
    
//     std::cout << std::endl; // Line break.
// }

// Interacts with subdetectors.
bool Hadron::interacts_with_hadron_calorimeter() const
{
    return true; // Hadrons interact with HadronCalorimeters.
}

bool Hadron::interacts_with_em_calorimeter() const
{
    return false; // Hadrons don't interact with EMCalorimeters.
}

bool Hadron::interacts_with_muonchamber() const
{
    return false; // Hadrons do not interact with MuonChamber.
}