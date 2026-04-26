// Callum Williamson.
// Student ID: 11399397.

// Implementation file for the SubDetector class.

#include "base/SubDetector.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <memory>

// Defualt Constructor.
SubDetector::SubDetector() : sd_name("Defualt SubDetector name"), status(false)
{
    if (Debug::show_messages)
    {
        std::cout << "Calling SubDetector Defualt Constructor" << std::endl;
    }
}

// Parameterised Constructor.
SubDetector::SubDetector(std::string sd_name, bool status)
    :sd_name(sd_name), status(status) // Will adjust for validation.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling SubDetector Parameterised Constructor." << std::endl;
    }
}

// Destructor.
SubDetector::~SubDetector()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling SubDetector Destructor." << std::endl;
    }
}

// Getters.
std::string SubDetector::get_sd_name() const
{
    return sd_name;
}

bool SubDetector::get_status() const
{
    return status;
}

// Setters.
void SubDetector::set_sd_name(const std::string& new_sd_name)
{
    sd_name = new_sd_name; // Will adjust for validation.
}

void SubDetector::set_status(bool new_status)
{
    status = new_status;
}

// Print characteristics common to all SubDetectors.
void SubDetector::print_info() const
{
    // Print sd_name.
    std::cout << "Sub-detector name: " << sd_name << std::endl;

    // Print status.
    std::cout << "Status (0=off/1=on): " << status << std::endl;
}

// No detect defined as it is derived SubDetector specific.