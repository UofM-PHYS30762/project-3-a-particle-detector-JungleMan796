// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the Photon (derived) class.

#include "derived/Particle/Photon.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt constructor.
Photon::Photon() : Particle(0.0, 0.0, 0.0, 0.0, 0, false, 0) // Calling the base class paramerterised constuctor.
// Setting the rest mass for a photon as 0.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Photon Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
Photon::Photon(double E, double px, double py, double pz, bool is_anti)
    : Particle(E, px, py, pz, 0, is_anti, 0) // Calling the base class parameterised constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Photon Parameterised Constructor." << std::endl;
    }
}

// Destructor.
Photon::~Photon()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Photon Destructor." << std::endl;
    }
}

// Print function for characteristics common to all Photons.
void Photon::print_info() const
{
    std::cout << std::endl; // Line break.
    // Photon specific title.
    std::cout << "--- Photon properties ---" << std::endl;

    // Call the base class print function to print the common characteristics of all Particles.
    Particle::print_info();

    // Print charge info.
    std::cout << "Charge: 0e" << std::endl;

    // Additional characteristics common to Photons.
    std::cout << "Note: Photons are their own anti-particles." << std::endl;
    std::cout << "Additional Photon characteristics placeholder." << std::endl;
    
    std::cout << std::endl; // Line break.
}

// Interacts with subdetectors.
bool Photon::interacts_with_hadron_calorimeter() const
{
    return false; // Photons do not interact with HadronCalorimeters.
}

bool Photon::interacts_with_em_calorimeter() const
{
    return true; // Photons interact with EMCalorimeters.
}

bool Photon::interacts_with_muonchamber() const
{
    return false; // Photons do not interact with muon chambers.
}