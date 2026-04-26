// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Electron (derived) class.

#ifndef ELECTRON_HPP
#define ELECTRON_HPP

#include "base/Particle.hpp"

#include <iostream>
#include <string>
#include <memory>

class Electron : public Particle
{
    private:
    double shower_depth; // Shower depth of the electron in a detector [cm].

    public:
    // Defualt constructor.
    Electron();

    // Parameterised constructor.
    Electron(double E, double px, double py, double pz, bool is_anti, double shower_depth);

    // Destructor.
    ~Electron();

    // Validation of shower depth.
    void validate_shower_depth(double shower_depth) const;

    // Getters.
    double get_shower_depth() const;

    // Setters.
    void set_shower_depth(double new_shower_depth);

    // Print function for characteristics common to Electrons.
    void print_info() const override;

    // Interacts with SubDetectors.
    bool interacts_with_calorimeter() const override;
};

#endif  