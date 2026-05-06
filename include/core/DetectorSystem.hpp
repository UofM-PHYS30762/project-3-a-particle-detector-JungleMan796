// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the DetectorSystem class.

#ifndef DETECTORSYSTEM_HPP
#define DETECTORSYSTEM_HPP

#include "base/SubDetector.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class DetectorSystem
{
    private:
    std::string sys_name; // Name of the detector system.
    std::vector<std::unique_ptr<SubDetector>> sub_detectors; // Vector of unique pointers to SubDetectors.

    public:
    // Default constructor.
    DetectorSystem();

    // Parameterised constructor.
    DetectorSystem(const std::string& sys_name);

    // Parameterised constructor with SubDetector vector.
    DetectorSystem(const std::string& sys_name, std::vector<std::unique_ptr<SubDetector>> sub_detectors);

    // Destructor.
    ~DetectorSystem();

    // Deleted copy constructor and copy assignment operator to prevent copying of unique pointers.
    DetectorSystem(const DetectorSystem& other) = delete;
    DetectorSystem& operator=(const DetectorSystem& other) = delete;

    // Move constructor, defualt is sufficient for unique_ptr.
    DetectorSystem(DetectorSystem&& other) noexcept = default;

    // Move assignment operator, defualt is sufficient for unique_ptr.
    DetectorSystem& operator=(DetectorSystem&& other) noexcept= default;

    // Getters.
    std::string get_sys_name() const;

    // Returns non owning pointer to SubDetector, or nullptr if not found.
    SubDetector* get_sub_detector(const std::string& sub_detector_name);

    // Setters.
    void set_sys_name(const std::string& new_sys_name);

    void set_sub_detector_status(const std::string& sub_detector_name, bool new_status);

    // Add a SubDetector to the DetectorSystem.
    void add_sub_detector(std::unique_ptr<SubDetector> sub_detector);

    // Remove a SubDetector from the DetectorSystem by name and destroy it.
    void remove_sub_detector(const std::string& rem_sub_detector_name);

    // Release a SubDetector from the DetectorSystem by name and return a unique pointer to it.
    std::unique_ptr<SubDetector> release_sub_detector(const std::string& rel_sub_detector_name);

    // Print DetectorSystem configuration.
    void print_configuration() const;

    // Pass a particle through the DetectorSystem, calling detect on each SubDetector.
    void detect(Particle& particle) const;
};

#endif