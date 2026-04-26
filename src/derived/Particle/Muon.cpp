// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the Muon (derived) class.

#include "derived/Particle/Muon.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt constructor.
Muon::Muon() : Particle(0.0, 0.0, 0.0, 0.0, 105.66, false), // Calling the base class paramerterised constuctor.
    muon_chamber_hits(0.0)
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Muon Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
Muon::Muon(double E, double px, double py, double pz, bool is_anti, int muon_chamber_hits)
    : Particle(E, px, py, pz, 105.66, is_anti) // Calling the base class parameterised constructor.
{
    validate_muon_chamber_hits(muon_chamber_hits);
    this->muon_chamber_hits = muon_chamber_hits;

    if (Debug::show_messages)
    {
        std::cout << "Calling Muon Parameterised Constructor." << std::endl;
    }
}

// Destructor.
Muon::~Muon()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Muon Destructor." << std::endl;
    }
}

// Validation of muon chamber hits.
void Muon::validate_muon_chamber_hits(int muon_chamber_hits) const
{
    if (muon_chamber_hits < 0.0)
    {
        std::cerr << "Invalid Muon chamber hits: '" << muon_chamber_hits << std::endl;
        std::cerr << "Please enter a non-negative number of muon chamber hits." << std::endl;
        std::cerr << "Exiting program." << std::endl;
        std::exit(1); // Exit.
    }
}

// Getters.
int Muon::get_muon_chamber_hits() const
{
    return muon_chamber_hits;
}

// Setters.
void Muon::set_muon_chamber_hits(int new_muon_chamber_hits)
{
    validate_muon_chamber_hits(new_muon_chamber_hits);
    muon_chamber_hits = new_muon_chamber_hits;
}

// Print function for characteristics common to all Muons.
void Muon::print_info() const
{
    std::cout << std::endl; // Line break.
    // Muon speccfic title.
    std::cout << "--- Muon properties ---" << std::endl;
    
    // Call ChargedLepton print function to print the common characteristics of all ChargedLeptons.
    Particle::print_info();

    // Additional characteristics common to Muons.
    std::cout << "Number of muon chamber hits: " << muon_chamber_hits << std::endl;
    
    std::cout << std::endl; // Line break.
}

// Interacts with subdetectors.
bool Muon::interacts_with_calorimeter() const
{
    return false; // Muon interact with calorimeters.
}