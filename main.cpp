// main.cpp for the final project - particle detector.
// Callum Williamson.
// Student ID: 11399397.

// General includes.

#include <iostream>
#include <string>
#include <vector>

// Header includes.
#include "core/DetectorSystem.hpp"

#include "derived/Particle/Electron.hpp"
#include "derived/Particle/Muon.hpp"
#include "derived/Particle/Photon.hpp"
#include "derived/Particle/Pion.hpp"
#include "derived/Particle/Kaon.hpp"
#include "derived/Particle/Proton.hpp"
#include "derived/Particle/Neutron.hpp"

#include "derived/SubDetector/HadronCalorimeter.hpp"
#include "derived/SubDetector/EMCalorimeter.hpp"
#include "derived/SubDetector/MuonChamber.hpp"
#include "derived/SubDetector/Tracker.hpp"

int main()
{
    // Demonstration of minimum functionality.

    // Creation of arbitrary detector (DetectorSystem) with sub-detector (SubDetector) components.
    DetectorSystem det_sys_CMS("CMS Detector System");

    return 0;
}