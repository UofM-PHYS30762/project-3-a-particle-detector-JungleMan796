// Callum Williamson.
// Student ID: 11399397.

// File implementation for the DetectorSystem class.

#include "core/DetectorSystem.hpp"
#include "core/Debug.hpp"
#include "core/DSMessages.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

// Defualt constructor.
DetectorSystem::DetectorSystem() : sys_name("Unnamed Detector System") // May make this so naming is unique.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling DetectorSystem Defualt Constructor." << std::endl;
    }
}

// Parameterised constructor.
DetectorSystem::DetectorSystem(const std::string& sys_name) : sys_name(sys_name)
{
    if (Debug::show_messages)
    {
        std::cout << "Calling DetectorSystem Parameterised Constructor." << std::endl;
    }
}

// Parameterised constructor with SubDetector vector.
// Note that if there is a pre-existing vector of unique pointers to SubDetectors, must use std::move in the argument.
DetectorSystem::DetectorSystem(
    const std::string& sys_name,
    std::vector<std::unique_ptr<SubDetector>> sub_detectors
)
    : sys_name(sys_name),
    sub_detectors(std::move(sub_detectors))
{
    if (Debug::show_messages)
    {
        std::cout << "Calling DetectorSystem Parameterised Constructor with SubDetector vector." << std::endl;
    }
}

// Destructor.
DetectorSystem::~DetectorSystem()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling DetectorSystem Destructor." << std::endl;
    }
}

// Getters.
std::string DetectorSystem::get_sys_name() const
{
    return sys_name;
}

// Returns non owning pointer to SubDetector, or nullptr if not found.
SubDetector* DetectorSystem::get_sub_detector(const std::string& sub_detector_name)
{
    // Find which index the SubDetector is at in the vector, if it exists.
    std::vector<std::unique_ptr<SubDetector>>::iterator it = std::find_if(
        sub_detectors.begin(),
        sub_detectors.end(),
        [&sub_detector_name](const std::unique_ptr<SubDetector>& sub_detector)
        {
            return sub_detector->get_sd_name() == sub_detector_name;
        }
    );

    if (it == sub_detectors.end())
    {
        return nullptr;
    }

    return it->get();
}

// Setters.
void DetectorSystem::set_sys_name(const std::string& new_sys_name)
{
    sys_name = new_sys_name;
}

void DetectorSystem::set_sub_detector_status(const std::string& sub_detector_name, bool new_status)
{
    SubDetector* sub_detector = get_sub_detector(sub_detector_name);

    if (!sub_detector)
    {
        std::cerr << "Error: SubDetector (" << sub_detector_name << ") not found in DetectorSystem (" << sys_name << ")." << std::endl;    
        std::cout << std::endl;
        return;
    }
    
    sub_detector->set_status(new_status);
    if (DSMessages::show_messages)
    {
        std::cout << "Set SubDetector (" << sub_detector_name << ") status to -" << (new_status ? "on" : "off") 
        << "- in DetectorSystem (" << sys_name << ")." << std::endl;
        std::cout << std::endl;
    }
}

// Add a SubDetector to the DetectorSystem.
// If adding from pre-existing unique pointer, must use std::move in the argument.
void DetectorSystem::add_sub_detector(std::unique_ptr<SubDetector> new_sub_detector)
{
    if (!new_sub_detector)
    {
        std::cerr << "Error: Cannot add a null SubDetector to the DetectorSystem." << std::endl;
        std::cout << std::endl;
        return;
    }
    else
    {
        if (DSMessages::show_messages)
        {
            std::cout << "Added SubDetector (" << new_sub_detector->get_sd_name() << ") to DetectorSystem (" << sys_name << ")." << std::endl;
            std::cout << std::endl;
        }

        sub_detectors.push_back(std::move(new_sub_detector));
    }
}

// Remove a SubDetector from the DetectorSystem by name and destroy it.
void DetectorSystem::remove_sub_detector(const std::string& rem_sub_detector_name)
{
    // Find which index the SubDetector is at in the vector, if it exists.
    std::vector<std::unique_ptr<SubDetector>>::iterator it = std::find_if(
        sub_detectors.begin(),
        sub_detectors.end(),
        [&rem_sub_detector_name](const std::unique_ptr<SubDetector>& sub_detector)
        {
            return sub_detector->get_sd_name() == rem_sub_detector_name;
        }
    );

    if (it == sub_detectors.end())
    {
        std::cerr << "Error: SubDetector (" << rem_sub_detector_name << ") not found in DetectorSystem (" << sys_name << ")." << std::endl;
        std::cout << std::endl;
        return;
    }

    sub_detectors.erase(it);
    if (DSMessages::show_messages)
    {
        std::cout << "Removed SubDetector (" << rem_sub_detector_name << ") from DetectorSystem (" << sys_name << ")." << std::endl;
        std::cout << std::endl;
    }
}

// Release a SubDetector from the DetectorSystem by name and return a unique pointer to it.
// Transfer of ownership.
std::unique_ptr<SubDetector> DetectorSystem::release_sub_detector(const std::string& rel_sub_detector_name)
{
    // Find which index the SubDetector is at in the vector, if it exists.
    std::vector<std::unique_ptr<SubDetector>>::iterator it = std::find_if(
        sub_detectors.begin(),
        sub_detectors.end(),
        [&rel_sub_detector_name](const std::unique_ptr<SubDetector>& sub_detector)
        {
            return sub_detector->get_sd_name() == rel_sub_detector_name;
        }
    );

    if (it == sub_detectors.end())
    {
        std::cerr << "Error: SubDetector (" << rel_sub_detector_name << ") not found in DetectorSystem (" << sys_name << ")." << std::endl;
        return nullptr;
    }

    std::unique_ptr<SubDetector> rel_sub_detector = std::move(*it); // Moves ownership.
    sub_detectors.erase(it); // Erase the now empty unique pointer from the vector.
    if (DSMessages::show_messages)
    {
        std::cout << "Released SubDetector (" << rel_sub_detector_name << ") from DetectorSystem (" << sys_name << ")." << std::endl;
        std::cout << std::endl;
    }
    
    return rel_sub_detector;
}

// Print DetectorSystem configuration.
void DetectorSystem::print_configuration() const
{
    std::cout << std::endl; // Line break.
    // DetectorSystem title.
    std::cout << "--- DetectorSystem (" << sys_name << ") properties/configuration ---" << std::endl;
    std::cout << std::endl; // Line break.

    // Print sys_name. Maybe remove.
    // std::cout << "DetectorSystem name: " << sys_name << std::endl;

    // Properties section title.
    std::cout << "--- DetectorSystem properties:" << std::endl;

    // Print number of SubDetectors.
    std::cout << "Number of SubDetectors: " << sub_detectors.size() << std::endl;
    std::cout << std::endl; // Line break.

    // Configuration section title.
    std::cout << "--- Configuration:" << std::endl;

    // Print each SubDetector's information.
    for (const auto& sub_detector : sub_detectors)
    {
        sub_detector->print_info();
        // std::cout << std::endl; // Line break between SubDetectors.
    }

    std::cout << "--- End of DetectorSystem (" << sys_name << ") properties/configuration ---" << std::endl;
    std::cout << std::endl; // Line break.
}

// Pass a particle through the DetectorSystem, calling detect on each SubDetector.
void DetectorSystem::detect(const Particle& particle) const
{
    std::cout << "-- Passing particle through DetectorSystem (" << sys_name << ") ---" << std::endl;
    std::cout << std::endl; // Line break.

    for (const auto& sub_detector : sub_detectors)
    {
        sub_detector->detect(particle);
    }

    std::cout << "-- Finished passing particle through DetectorSystem (" << sys_name << ") ---" << std::endl;
    std::cout << std::endl; // Line break.
}