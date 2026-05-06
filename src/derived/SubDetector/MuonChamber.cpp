// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the MuonChamber (derived) class.

#include "derived/SubDetector/MuonChamber.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt Constructor.
MuonChamber::MuonChamber() : SubDetector() // Calling base class defualt constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling MuonChamber Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
MuonChamber::MuonChamber(std::string sd_name, bool status)
    : SubDetector(sd_name, status) // Calling base class parameterised constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling MuonChamber Parameterised Constructor." << std::endl;
    }
}

// Destructor
MuonChamber::~MuonChamber()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling MuonChamber Destructor." << std::endl;
    }
}

// Print function for characteristics common to all MuonChambers.
void MuonChamber::print_info() const
{
    std::cout << std::endl; // Line break.
    // MuonChamber specific title.
    std::cout << "--- MuonChamber (" << sd_name << ") properties ---" << std::endl;

    // Call the base class print function to print the common characteristics of all SubDetectors.
    SubDetector::print_info();

    // Additional characteristics common to MuonChambers.
    std::cout << "Placeholder MuonChamber unique characteristics." << std::endl;

    std::cout << std::endl; // Line break.
}

// Function for MuonChamber detection of Particle class.
void MuonChamber::detect(Particle& particle) const
{
    // Check status of SubDetector.
    if (is_off())
    {
        return; // Exit function.
    }

    if (particle.interacts_with_muonchamber())
    {
        std::cout << "Muon Chamber (" << sd_name << ") measures the energy of the particle as: " << particle.get_four_momentum().get_E() << " MeV" << std::endl;
        // Will differentiate these later.
        std::cout << "The particle's true energy is: " << particle.get_four_momentum().get_E() << " MeV" << std::endl;
        std::cout << std::endl; // Line break.
    }
    else
    {
        std::cout << "Particle does not interact with the muon chamber (" << sd_name << "), no energy measurement." << std::endl;
        std::cout << std::endl; // Line break.
    }
}