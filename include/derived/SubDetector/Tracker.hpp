// Callum Williamson.
// Student ID: 11399397.

//  Implementation file for the Tracker (derived) class.

#ifndef TRACKER_HPP
#define TRACKER_HPP

#include "base/SubDetector.hpp"

#include <iostream>
#include <string>
#include <memory>

class Tracker : public SubDetector
{
    public:
    // Defualt Constructor.
    Tracker();

    // Parameterised Constructor.
    Tracker(std::string sd_name, bool status);

    // Destructor.
    ~Tracker();

    // Print function for characteristics common to Trackers.
    void print_info() const override;

    // Function for Tracker detection of Particle class.
    void detect(Particle& particle) const override;
};

#endif