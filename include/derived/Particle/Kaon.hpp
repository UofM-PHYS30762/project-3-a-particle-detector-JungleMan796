// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Kaon (derived) class.

#ifndef KAON_HPP
#define KAON_HPP

#include "derived/Particle/Meson.hpp"

#include <iostream>
#include <string>
#include <memory>

class Kaon : public Meson
{
    public:
    // Defualt constructor.
    Kaon();

    // Parameterised constructor.
    Kaon(double E, double px, double py, double pz, bool is_anti, bool is_charged);

    // Destructor.
    ~Kaon() override;

    // Copy Constructor.
    Kaon(const Kaon& other) = default;

    // Copy Assignment Operator.
    Kaon& operator=(const Kaon& other) = default;

    // Move Constructor.
    Kaon(Kaon&& other) noexcept = default;

    // Move Assignment Operator.
    Kaon& operator=(Kaon&& other) noexcept = default;

    // Print function for characteristics common to Kaon.
    void print_info() const override;
};

#endif