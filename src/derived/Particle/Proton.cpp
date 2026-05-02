// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the Proton (derived) class.

#include "derived/Particle/Proton.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt constructor.
Proton::Proton() : Hadron(0.0, 0.0, 0.0, 0.0, 938.272, false, 1) // Calling the intermediate base class paramerterised constuctor.
// Defualt makes non-anti proton.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Proton Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
Proton::Proton(double E, double px, double py, double pz, bool is_anti)
    : Hadron(E, px, py, pz, 938.272, is_anti, 1) // Calling the intermediatebase class parameterised constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Proton Parameterised Constructor." << std::endl;
    }
}

// Destructor.
Proton::~Proton()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Proton Destructor." << std::endl;
    }
}

// Print function for characteristics common to all Photons.
void Proton::print_info() const
{
    std::cout << std::endl; // Line break.
    // Proton specific title.
    std::cout << "--- Proton properties ---" << std::endl;

    // Call the base class print function to print the common characteristics of all Particles.
    Particle::print_info();

    // Test for charge info.
    std::cout << "Charge: " << (is_anti ? (-1 * charge_mag) : (+1 * charge_mag)) << "e" << std::endl;

    // Additional characteristics common to Protons`.
    std::cout << "Additional Proton characteristics placeholder." << std::endl;
    
    std::cout << std::endl; // Line break.
}

// // Interacts with subdetectors.
// bool Pion::interacts_with_hadron_calorimeter() const
// {
//     return true; // Pions do interact with HadronCalorimeters.
// }

// bool Pion::interacts_with_em_calorimeter() const
// {
//     return false; // Pions do not interact with EMCalorimeters.
// }

// bool Pion::interacts_with_muonchamber() const
// {
//     return false; // Pions do not interact with muon chambers.
// }

// bool Pion::interacts_with_tracker() const
// {
//     if (is_charged)
//     {
//         return true; // Charged Pions interact with Trackers.
//     }
//     else
//     {
//         return false; // Neutral Pions do not interact with Trackers.
//     }
// }