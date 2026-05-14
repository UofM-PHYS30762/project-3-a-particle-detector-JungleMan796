// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Meson (intermediate base) class.

#ifndef MESON_HPP
#define MESON_HPP

#include "derived/Particle/Hadron.hpp"

#include <iostream>
#include <string>
#include <memory>

class Meson : public Hadron
{
    protected:    
    bool is_charged;

    public:
    // Defualt constructor.
    Meson();

    // Parameterised constructor.
    Meson(double E, double px, double py, double pz, bool is_anti,
        bool is_charged, double neutral_rest_mass, double charged_rest_mass);

    // Destructor.
    virtual ~Meson() override = 0;

    // Copy Constructor.
    Meson(const Meson& other) = default;

    // Copy Assignment Operator.
    Meson& operator=(const Meson& other) = default;

    // Move Constructor.
    Meson(Meson&& other) noexcept = default;

    // Move Assignment Operator.
    Meson& operator=(Meson&& other) noexcept = default;

    // Print function for characteristics common to Meson.
    void print_info() const override;
};

#endif