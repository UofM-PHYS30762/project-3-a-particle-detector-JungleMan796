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
Also whether I have a paid GenAI subscriptions: I have ChatGPT plus. 
Much of the foundation of this project was built from the assignments 4 & 5, hence I will include the declaration of AI from these assignments that are relevant, and then where I used it standalone for this project.
### Assignment 4
- ChatGPT 5.2 helped me to understand the rule of 5 and why we use the copy and move constructors and assignment operators.
- ChatGPT 5.2 suggested passing a string with a reference ```std::string&``` to avoid making an unnecessary copy.
- ChatGPT 5.2 helped with the Particle parameterised constructor validation of type, using ```validate_E()``` and ```this->type = type```.
### Assignment 5
- Using ChatGPT 5.2 to help understand the nuances of smart pointers.
- When going through this for the Particle getter I changed the return line to ```return *four_momentum``` so to not return an address but an actual FourMomentum object. While doing so ChatGPT suggested that my FourMomentum getter should return ```const FourMomentum&``` so that it does not make an unecessary copy and does not let any modification happen. This seems wise so I included this.
- When building the ```Electron``` derived class I realised the ```Lepton``` class destructor was being called. ChatGPT 5.2 and the pre lecture 8 slides helped to understand why we need the base class to have a virtual destructor.
- ChatGPT 5.2 suggested header guards so that no .hpp file gets defined twice.
- ChatGPT 5.2 suggested ```is_anti ? +1 : -1``` for printing the charge of the ```ChargeLepton``` branch of the hierarchy, I adopted this.
- Needing a better file system I wanted folders to intuitively match the hierarchy structure. This I did but ChatGPT 5.2 suggested using C++ standards ```inlcude``` for the header files and ```src``` for the implementation files.
### Project

Below will explain how it is used in this assignment.

## Report
This report includes my design considerations and process and a description of the software built.
The report can be found in the file "" with its commit history being found in the file "project_particle_detector.tex". It includes design considerations and a description of the software.
