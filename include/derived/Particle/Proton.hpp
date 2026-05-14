// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Proton (derived) class.

#ifndef PROTON_HPP
#define PROTON_HPP

#include "derived/Particle/Hadron.hpp"

#include <iostream>
#include <string>
#include <memory>

class Proton : public Hadron
{
    public:
    // Defualt constructor.
    Proton();

    // Parameterised constructor.
    Proton(double E, double px, double py, double pz, bool is_anti);

    // Destructor.
    ~Proton() override;

    // Copy Constructor.
    Proton(const Proton& other) = default;

    // Copy Assignment Operator.
    Proton& operator=(const Proton& other) = default;

    // Move Constructor.
    Proton(Proton&& other) noexcept = default;

    // Move Assignment Operator.
    Proton& operator=(Proton&& other) noexcept = default;

    // Print function for characteristics common to Proton.
    void print_info() const override;
};

#endif