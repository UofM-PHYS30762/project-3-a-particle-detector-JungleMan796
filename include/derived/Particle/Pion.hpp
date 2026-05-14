// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Pion (derived) class.

#ifndef PION_HPP
#define PION_HPP

#include "derived/Particle/Meson.hpp"

#include <iostream>
#include <string>
#include <memory>

class Pion : public Meson
{
    public:
    // Defualt constructor.
    Pion();

    // Parameterised constructor.
    Pion(double E, double px, double py, double pz, bool is_anti, bool is_charged);

    // Destructor.
    ~Pion() override;

    // Copy Constructor.
    Pion(const Pion& other) = default;

    // Copy Assignment Operator.
    Pion& operator=(const Pion& other) = default;

    // Move Constructor.
    Pion(Pion&& other) noexcept = default;

    // Move Assignment Operator.
    Pion& operator=(Pion&& other) noexcept = default;

    // Print function for characteristics common to Pion.
    void print_info() const override;
};

#endif