// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Neutron (derived) class.

#ifndef NEUTRON_HPP
#define NEUTRON_HPP

#include "derived/Particle/Hadron.hpp"

#include <iostream>
#include <string>
#include <memory>

class Neutron : public Hadron
{
    public:
    // Defualt constructor.
    Neutron();

    // Parameterised constructor.
    Neutron(double E, double px, double py, double pz, bool is_anti);

    // Destructor.
    ~Neutron() override;

    // Copy Constructor.
    Neutron(const Neutron& other) = default;

    // Copy Assignment Operator.
    Neutron& operator=(const Neutron& other) = default;

    // Move Constructor.
    Neutron(Neutron&& other) noexcept = default;

    // Move Assignment Operator.
    Neutron& operator=(Neutron&& other) noexcept = default;

    // Print function for characteristics common to Neutron.
    void print_info() const override;
};

#endif