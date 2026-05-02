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
    ~Pion();

    // Print function for characteristics common to Pion.
    void print_info() const override;
};

#endif