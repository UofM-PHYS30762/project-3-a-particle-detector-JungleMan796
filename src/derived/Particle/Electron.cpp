// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the Electron (derived) class.

#include "derived/Particle/Electron.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt constructor.
Electron::Electron() : Particle(0.0, 0.0, 0.0, 0.0, 0.511, false, 1), // Calling the base class paramerterised constuctor.
    shower_depth(0.0)
// Setting the rest mass for an electron.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Electron Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
Electron::Electron(double E, double px, double py, double pz, bool is_anti, double shower_depth)
    : Particle(E, px, py, pz, 0.511, is_anti, 1) // Calling the base class parameterised constructor.
{
    validate_shower_depth(shower_depth);
    this->shower_depth = shower_depth;

    if (Debug::show_messages)
    {
        std::cout << "Calling Electron Parameterised Constructor." << std::endl;
    }
}

// Destructor.
Electron::~Electron()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Electron Destructor." << std::endl;
    }
}

// Validation of shower depth.
void Electron::validate_shower_depth(double shower_depth) const
{
    if (shower_depth < 0.0)
    {
        std::cerr << "Invalid Electron shower depth: '" << shower_depth << "' cm" << std::endl;
        std::cerr << "Please enter a non-negative shower depth." << std::endl;
        std::cerr << "Exiting program." << std::endl;
        std::exit(1); // Exit.
    }
}


// Getters.
double Electron::get_shower_depth() const
{
    return shower_depth;
}

// Setters.
void Electron::set_shower_depth(double new_shower_depth)
{
    validate_shower_depth(new_shower_depth);
    shower_depth = new_shower_depth;
}

// Print function for characteristics common to all Electrons.
void Electron::print_info() const
{
    std::cout << std::endl; // Line break.
    // Electron speccfic title.
    std::cout << "--- Electron properties ---" << std::endl;
    
    // // Call ChargedLepton print function to print the common characteristics of all ChargedLeptons.
    // ChargedLepton::print_info();

    // Call the base class print function to print the common characteristics of all Particles.
    Particle::print_info();

    // Print charge info.
    std::cout << "Charge: " << (is_anti ? "+1" : "-1") << std::endl;

    // Additional characteristics common to Electrons.
    std::cout << "Electron shower depth: " << shower_depth << " cm" << std::endl;
    
    std::cout << std::endl; // Line break.
}

// Interacts with subdetectors.
bool Electron::interacts_with_hadron_calorimeter() const
{
    return false; // Electrons doesn't interact with HadronCalorimeters.
}

bool Electron::interacts_with_em_calorimeter() const
{
    return true; // Electrons do interact with EMCalorimeters.
}

bool Electron::interacts_with_muonchamber() const
{
    return false; // Electrons do not interact with muon chambers.
}