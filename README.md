# Final Project - Particle Detector.

## Usage instructions.
Compilation line: ```g++ -Wall main.cpp `
src/core/*.cpp `
src/base/*.cpp `
src/derived/Particle/*.cpp `
src/derived/SubDetector/*.cpp `
-Iinclude `
-o main.exe```.
Please ensure the files in the "include" and "src" folders and "main.cpp" are in your directory.
Also please note that the files within the "test_files" are not part of the project and purely for my testing.

main.cpp demonstrates the minimum functionality and advanced features of my code design. The bullet points below indicate how you will move through the main.cpp:
- Creation of ```DetectorSystem```, ```det_sys_CMS```, emulates the CMS detector with it owning a ```Tracker```, ```MuonChamber```, ```EMCalorimeter``` and ```HadronCalorimeter```.
- Configuration of ```det_sys_CMS``` is displayed via ```print_configuration```.
- A ```Muon``` is instantiated to be passed through ```det_sys_CMS```.
- Wrapper function ```set_sub_detector_status``` is used to turn off the ```MuonChamber``` with this functionality shown by running ```det_sys_CMS::detect``` again.
- ```Calorimeter``` interacting ```Particle``` objects are created (```Electron```, neutral ```Pion``` and ```Photon```) and passed through ```det_sys_CMS``` to demonstrate the ```absorb``` functionality.
- Another ```DetectorSystem```, ```det_sys_2```, was created to demonstrate the functionality of the ```remove_sub_detector``` and ```release_sub_detector``` member functions, with the extracted ```SubDetector```, ```released_sub_detector```, shown to work independently.
- Turned ```Debug::show_messages``` on and created a ```Neutron``` object to show the messages that can be sent.  

## Declaration of AI use.
Sharing of prompts will be included if it regards "Code Generation" or "comments".
Also whether I have a paid GenAI subscriptions: I have ChatGPT plus. Below will explain how it is used in this assignment.

## Report
This report includes my design considerations and process and a description of the software built.
The report can be found in the file "" with its commit history being found in the file "project_particle_detector.tex". It includes design considerations and a description of the software.
