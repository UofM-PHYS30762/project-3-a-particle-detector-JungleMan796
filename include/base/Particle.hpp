// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Particle (base) class.

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "core/FourMomentum.hpp"

#include <iostream>
#include <string>
#include <memory>

class Particle
{
    protected:
    std::unique_ptr <FourMomentum> four_momentum;

    double rest_mass; // Rest mass of the Lepton [units: MeV - using natural units].
    // Will be initilaised as a constant in the constructor of the derived classes, as the rest_mass is a fixed property of each.
    // Therefore no setter as it is constant.

    bool is_anti;

    public:
    // Defualt constructor.
    Particle();

    // Parameterised constructor.
    Particle(double E, double px, double py, double pz, double rest_mass, bool is_anti);

    // Destructor.
    virtual ~Particle();

    // Copy Constructor.
    Particle(const Particle& other);

    // Copy Assignment Operator.
    Particle& operator=(const Particle& other);

    // Move Constructor.
    Particle(Particle&& other) noexcept;

    // Move Assignment Operator.
    Particle& operator=(Particle&& other) noexcept;

    // Getters.
    const FourMomentum& get_four_momentum() const;

    double get_rest_mass() const;

    bool get_is_anti() const;

    // Setters.
    void set_four_momentum(const FourMomentum& new_four_momentum);
    void set_four_momentum(double E, double px, double py, double pz);
    void set_is_anti(bool is_anti);

    // Print function for characteristics common to all Particles.
    virtual void print_info() const = 0;

    // Interacts with subdetectors, will be overridden in derived classes.
    virtual bool interacts_with_calorimeter() const = 0;

    // Friend functions.
    friend FourMomentum sum_four_momenta(const Particle& particle1, const Particle& particle2);
    friend double dot_product(const Particle& particle1, const Particle& particle2);
};

#endif