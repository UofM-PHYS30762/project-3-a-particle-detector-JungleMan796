// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the Muon (derived) class.

#ifndef MUON_HPP
#define MUON_HPP

#include "base/Particle.hpp"

#include <iostream>
#include <string>
#include <memory>

class Muon : public Particle
{
    private:
    int muon_chamber_hits; // Number of hits from this Muon in the chamber.

    public:
    // Defualt constructor.
    Muon();

    // Parameterised constructor.
    Muon(double E, double px, double py, double pz, bool is_anti, int muon_chamber_hits);

    // Destructor.
    ~Muon();

    // Validation of muon chamber hits.
    void validate_muon_chamber_hits(int muon_chamber_hits) const;

    // Getters.
    int get_muon_chamber_hits() const;

    // Setters.
    void set_muon_chamber_hits(int new_muon_chamber_hits);

    // Print function for characteristics common to Muons.
    void print_info() const override;

    // Interacts with SubDetectors.
    bool interacts_with_hadron_calorimeter() const override;
    bool interacts_with_em_calorimeter() const override;
    bool interacts_with_muonchamber() const override;
    bool interacts_with_tracker() const override;
};

#endif