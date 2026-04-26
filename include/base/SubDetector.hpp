// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the SubDetector (base) class.

#ifndef SUBDETECTOR_HPP
#define SUBDETECTOR_HPP

#include "base/Particle.hpp"

#include <iostream>
#include <string>
#include <memory>

class SubDetector
{
    protected:
    std::string sd_name; // Name of SubDetector (sd).

    bool status; // true = on, false = off

    public:
    //Defualt constructor.
    SubDetector();

    // Parameterised constructor.
    SubDetector(const std::string sd_name, bool status);

    // Destructor.
    virtual ~SubDetector();

    // Getters.
    std::string get_sd_name() const;

    bool get_status() const;

    // Setters.
    void set_sd_name(const std::string& new_sd_name);

    void set_status(bool new_status);

    // Pure virtual, print charactertistics common to all SubDetectors.
    virtual void print_info() const = 0;

    // Pure abstract function for detection of Particle class.
    virtual void detect(const Particle& particle) const = 0;
};

#endif