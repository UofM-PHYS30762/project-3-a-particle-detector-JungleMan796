// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the Photon (derived) class.

#include "derived/Particle/Photon.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt constructor.
Photon::Photon() : Particle(0.0, 0.0, 0.0, 0.0, 0, false) // Calling the base class paramerterised constuctor.
// Setting the rest mass for a photon as 0..
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Photon Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
Photon::Photon(double E, double px, double py, double pz, bool is_anti)
    : Particle(E, px, py, pz, 0, is_anti) // Calling the base class parameterised constructor.
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
    // Photon speccfic title.
    std::cout << "--- Photon properties ---" << std::endl;

    // Call the base class print function to print the common characteristics of all Particles.
    // Particle::print_info();
    // Commented for Photon as rest_mass is zero and anti_is is redundant.
    // Part below is the Particle::print_info() adjusted.

    // Print four momenta in (E, px, py, pz) format.
    std::cout << "Four momenta: " <<
                "(" << four_momentum->get_E() << // Using -> since four_momentum is a unique_ptr. 
                ", " << four_momentum->get_px() <<
                ", " << four_momentum->get_py() <<
                ", " << four_momentum->get_pz() <<
                ") MeV" << std::endl; // (E, px, py, pz) format.

    std::cout << "Rest mass: " << rest_mass << " MeV" << std::endl;

    // Charge reminder.
    std::cout << "Charge reminder" << std::endl;

    // Additional characteristics common to Photons.
    std::cout << "Additional Photon characteristics placeholder." << std::endl;
    
    std::cout << std::endl; // Line break.
}

// Interacts with subdetectors.
bool Photon::interacts_with_calorimeter() const
{
    return true; // Photons interact with calorimeters.
}

bool Photon::interacts_with_muonchamber() const
{
    return false; // Photons do not interact with muon chambers.
}

bool Photon::interacts_with_tracker() const
{
    return false; // Photons don't interact with trackers.
}