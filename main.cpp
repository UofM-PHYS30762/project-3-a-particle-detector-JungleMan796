// main.cpp for the final project - particle detector.
// Callum Williamson.
// Student ID: 11399397.

#include "core/main_helpers.hpp"

int main()
{
    DetectorSystem det_sys_CMS = demonstrate_minimium_functionality();
    // Returns the CMS DetectorSytem to be used in advanced features.
    demonstrate_advanced_features(det_sys_CMS);

    return 0;
}