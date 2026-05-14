// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Hadron (abstract base intermediate) class.

#ifndef HADRON_HPP
#define HADRON_HPP

#include "base/Particle.hpp"

#include <iostream>
#include <string>
#include <memory>

class Hadron : public Particle
{
    private:
    // No distinct data members for Hadron yet.

    public:
    // Defualt constructor.
    Hadron();

    // Parameterised constructor.
    Hadron(double E, double px, double py, double pz, double rest_mass, bool is_anti, int charge_mag);

    // Destructor.
    virtual ~Hadron() override = 0;

    // Copy Constructor.
    Hadron(const Hadron& other) = default;

    // Copy Assignment Operator.
    Hadron& operator=(const Hadron& other) = default;

    // Move Constructor.
    Hadron(Hadron&& other) noexcept = default;

    // Move Assignment Operator.
    Hadron& operator=(Hadron&& other) noexcept = default;

    // // Print function for characteristics common to Hadron.
    // void print_info() const override;

    // Interacts with SubDetectors.
    bool interacts_with_hadron_calorimeter() const override;
    bool interacts_with_em_calorimeter() const override;
    bool interacts_with_muonchamber() const override;
};

#endif