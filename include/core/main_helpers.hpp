// main_helpers.hpp for the main.cpp.
// Callum Williamson.
// Student ID: 11399397.

#ifndef MAIN_HELPERS
#define MAIN_HELPERS

#include "base/Particle.hpp"
#include "core/DetectorSystem.hpp"

DetectorSystem create_CMS_detector();

DetectorSystem demonstrate_minimium_functionality();

void demonstrate_wrapper_sub_detector_status(DetectorSystem& det_sys);

void print_detect_print_for_abs(DetectorSystem& det_sys, Particle& particle);

void demonstrate_particle_absorption(DetectorSystem& det_sys);

void demonstrate_remove_and_release();

void demonstrate_debug_messages();

void demonstrate_advanced_features(DetectorSystem& det_sys);

#endif