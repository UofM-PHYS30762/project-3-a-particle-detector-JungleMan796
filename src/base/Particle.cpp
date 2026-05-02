// Callum Williamson.
// Student ID: 11399397.

// Implementation file for the Particle class.

#include "base/Particle.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt constructor.
Particle::Particle() : four_momentum(std::make_unique<FourMomentum>(0.0, 0.0, 0.0, 0.0)),
rest_mass(0.0),  is_anti(false), charge_mag(0)
// Setting defualt four momenta as all zeros,  rest mass as zero, is_anti as false and charge_mag as zero.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Particle Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
Particle::Particle(double E, double px, double py, double pz, double rest_mass, bool is_anti, int charge_mag)
    : four_momentum(std::make_unique<FourMomentum>(E, px, py, pz)), // Validation of E happens in the four_momentum constructor.
    rest_mass(rest_mass), // Setting rest_mass given via constructor chain from derived class.
    is_anti(is_anti), // Setting is_anti given via constructor chain from derived class.
    charge_mag(charge_mag) // Setting charge_mag given via constructor chain from derived class.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Particle Parameterised Constructor." << std::endl;
    }
}

// Destructor.
Particle::~Particle()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Particle Destructor." << std::endl;
    }
}

// Copy Constructor.
Particle::Particle(const Particle& other) 
    : four_momentum(std::make_unique<FourMomentum>(*other.four_momentum)),
    rest_mass(other.rest_mass),
    is_anti(other.is_anti),
    charge_mag(other.charge_mag)
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Particle Copy Constructor." << std::endl;
    }
}

// Copy Assignment Operator.
Particle& Particle::operator=(const Particle& other)
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Particle Copy Assignment Operator." << std::endl;
    }

    if (this != &other)
    {
        four_momentum = std::make_unique<FourMomentum>(*other.four_momentum);
        rest_mass = other.rest_mass;
        is_anti = other.is_anti;
        charge_mag = other.charge_mag;
    }

    return *this;
}

// Move Constructor.
Particle::Particle(Particle&& other) noexcept
    : four_momentum(std::move(other.four_momentum)),
    rest_mass(std::move(other.rest_mass)),
    is_anti(std::move(other.is_anti)),
    charge_mag(std::move(other.charge_mag))
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Particle Move Constructor." << std::endl;
    }
}

// Move Assignment Operator.
Particle& Particle::operator=(Particle&& other) noexcept
{
    if (Debug::show_messages)
    {
        std::cout << "Calling Particle Move Assignment Operator." << std::endl;
    }

    if (this != &other)
    {
        four_momentum = std::move(other.four_momentum);
        rest_mass = std::move(other.rest_mass);
        is_anti = std::move(other.is_anti);
        charge_mag = std::move(other.charge_mag);
    }

    return *this;
}

// Getters.
const FourMomentum& Particle::get_four_momentum() const
{
    return *four_momentum;
}

double Particle::get_rest_mass() const
{
    return rest_mass;
}

bool Particle::get_is_anti() const
{
    return is_anti;
}

int Particle::get_charge_mag() const
{
    return charge_mag;
}

// Setters.
void Particle::set_four_momentum(const FourMomentum& new_four_momentum)
{
    four_momentum = std::make_unique<FourMomentum>(new_four_momentum);
}

void Particle::set_four_momentum(double E, double px, double py, double pz) // Created other setter so you don't need to have prior FourMomentum.
{
    four_momentum = std::make_unique<FourMomentum>(E, px, py, pz);
}

void Particle::set_is_anti(bool new_is_anti)
{
    is_anti = new_is_anti;
}

// Print function for characteristics common to all Particles.
void Particle::print_info() const
{
    // Print four momenta in (E, px, py, pz) format.
    std::cout << "Four momenta: " <<
                "(" << four_momentum->get_E() << // Using -> since four_momentum is a unique_ptr. 
                ", " << four_momentum->get_px() <<
                ", " << four_momentum->get_py() <<
                ", " << four_momentum->get_pz() <<
                ") MeV" << std::endl; // (E, px, py, pz) format.

    std::cout << "Rest mass: " << rest_mass << " MeV" << std::endl;

    std::cout << "Is an anti-particle (true/false): " << std::boolalpha << is_anti << std::noboolalpha << std::endl; // Using boolalpha to print bool as true/false instead of 1/0.
}

// Friend functions.
FourMomentum sum_four_momenta(const Particle& particle1, const Particle& particle2)
{
    // Very similar to the +operator in Particle.
    // No direct access of the four_momentum member varables as that would require more friendship.
    return FourMomentum(
        particle1.four_momentum->get_E() + particle2.four_momentum->get_E(),
        particle1.four_momentum->get_px() + particle2.four_momentum->get_px(),
        particle1.four_momentum->get_py() + particle2.four_momentum->get_py(),
        particle1.four_momentum->get_pz() + particle2.four_momentum->get_pz()
    );
}

double dot_product(const Particle& particle1, const Particle& particle2)
{
    return (particle1.four_momentum->get_E() * particle2.four_momentum->get_E())
    - (particle1.four_momentum->get_px() * particle2.four_momentum->get_px())
    - (particle1.four_momentum->get_py() * particle2.four_momentum->get_py())
    - (particle1.four_momentum->get_pz() * particle2.four_momentum->get_pz());
}