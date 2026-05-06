// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the Tracker (derived) class.

#include "derived/SubDetector/Tracker.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt Constructor.
Tracker::Tracker() : SubDetector() // Calling base class defualt constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Tracker Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
Tracker::Tracker(std::string sd_name, bool status)
    : SubDetector(sd_name, status) // Calling base class parameterised constructor.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Tracker Parameterised Constructor." << std::endl;
    }
}

// Destructor
Tracker::~Tracker()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Tracker Destructor." << std::endl;
    }
}

// Print function for characteristics common to all Trackers.
void Tracker::print_info() const
{
    std::cout << std::endl; // Line break.
    // Tracker specific title.
    std::cout << "--- Tracker (" << sd_name << ") properties ---" << std::endl;

    // Call the base class print function to print the common characteristics of all SubDetectors.
    SubDetector::print_info();

    // Additional characteristics common to Trackers.
    std::cout << "Placeholder Tracker unique characteristics." << std::endl;

    std::cout << std::endl; // Line break.
}

// Function for Tracker detection of Particle class.
void Tracker::detect(Particle& particle) const
{
    // Check status of SubDetector.
    if (is_off())
    {
        return; // Exit function.
    }

    if (particle.interacts_with_tracker())
    {
        std::cout << "Tracker (" << sd_name << ") measures the energy of the particle as: " << particle.get_four_momentum().get_E() << " MeV" << std::endl;
        // Will differentiate these later.
        std::cout << "The particle's true energy is: " << particle.get_four_momentum().get_E() << " MeV" << std::endl;
        std::cout << std::endl; // Line break.
    }
    else
    {
        std::cout << "Particle does not interact with the tracker (" << sd_name << "), no energy measurement." << std::endl;
        std::cout << std::endl; // Line break.
    }
}