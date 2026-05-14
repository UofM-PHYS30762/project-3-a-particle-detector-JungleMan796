# Final Project - Particle Detector.

## Usage instructions.
Compilation line: ```g++ -Wall main.cpp src/core/*.cpp src/base/*.cpp src/derived/Particle/*.cpp src/derived/SubDetector/*.cpp -Iinclude -o main.exe```.
Please ensure the files in the "include" and "src" folders and "main.cpp" are in your directory.
Also please note that the files within the "test_files" are not part of the project and purely for my testing, and the files within "report_assets" are needed to have figures in the synced overleaf repository.

main.cpp demonstrates the minimum functionality and advanced features of my code design. It does so by calling helper functions ```demonstrate_minimum_functionality``` and ```demonstrate_advanced_features``` to make the main.cpp succinct. These helper functions have helper functions within, defined in "main_helpers.cpp", that makes the main.cpp understandable and modular.
The bullet points below indicate how you will move through the main.cpp:
- Creation of ```DetectorSystem```, ```det_sys_CMS```, emulates the CMS detector with it owning a ```Tracker```, ```MuonChamber```, ```EMCalorimeter``` and ```HadronCalorimeter```.
- Configuration of ```det_sys_CMS``` is displayed via ```print_configuration```.
- A ```Muon``` is instantiated to be passed through ```det_sys_CMS```.
- Wrapper function ```set_sub_detector_status``` is used to turn off the ```MuonChamber``` with this functionality shown by running ```det_sys_CMS::detect``` again.
- ```Calorimeter``` interacting ```Particle``` objects are created (```Electron```, neutral ```Pion``` and ```Photon```) and passed through ```det_sys_CMS``` to demonstrate the ```absorb``` functionality.
- Another ```DetectorSystem```, ```det_sys_2```, was created to demonstrate the functionality of the ```remove_sub_detector``` and ```release_sub_detector``` member functions, with the extracted ```SubDetector```, ```released_sub_detector```, shown to work independently.
- Turned ```Debug::show_messages``` on and created a ```Neutron``` object to show the messages that can be sent.

Modification and additions to the classes can be applied simply due them being made with extensibility in mind, as discussed in the report. Some examples are:
- Can add a new ```Hadron``` by following how ```Proton``` and ```Neutron``` are derived. Construction logic may have to differ depending on the ```Hadron``` chosen. For example a Xi particle has a negative and neutral type whereas a Sigma particle would follow construction similar to ```Meson``` due to its positive, negative and neutral types.
- Could add energy thresholds to whether ```MuonChamber``` objects can detect a ```Muon```, this would be done by modifying the member function ```interacts_with_muon_chamber```. 

## Declaration of AI use.
Sharing of prompts will be included if it regards "Code Generation" or "comments", none were needed for this project.
Also whether I have a paid GenAI subscriptions: I have ChatGPT plus. 
Much of the foundation of this project was built from the assignments 4 & 5, hence I will include the declaration of AI from these assignments that are relevant, and then where I used it standalone for this project.
### Assignment 4
- ChatGPT 5.2 helped me to understand the rule of 5 and why we use the copy and move constructors and assignment operators.
- ChatGPT 5.2 suggested passing a string with a reference ```std::string&``` to avoid making an unnecessary copy.
- ChatGPT 5.2 helped with the Particle parameterised constructor validation of type, using ```validate_E()``` and ```this->type = type```.
### Assignment 5
- Using ChatGPT 5.2 to help understand the nuances of smart pointers.
- When going through this for the Particle getter I changed the return line to ```return *four_momentum``` so to not return an address but an actual FourMomentum object. While doing so ChatGPT suggested that my FourMomentum getter should return ```const FourMomentum&``` so that it does not make an unecessary copy and does not let any modification happen. This seems wise so I included this.
- When building the ```Electron``` derived class I realised the ```Lepton``` class destructor was being called. ChatGPT 5.2 and the pre lecture 8 slides helped me to understand why we need the base class to have a virtual destructor.
- ChatGPT 5.2 suggested header guards so that no .hpp file gets defined twice.
- ChatGPT 5.2 suggested ```is_anti ? +1 : -1``` for printing the charge of the ```ChargeLepton``` branch of the hierarchy, I adopted this.
- Needing a better file system I wanted folders to intuitively match the hierarchy structure. This I did but ChatGPT 5.2 suggested using C++ standards ```include``` for the header files and ```src``` for the implementation files.
### Project
- Discussed whether to store the interaction logic with member functions or in a ```vector```.
- For the ```DetectorSystem``` container ChatGPT 5.2 suggested ```std::vector<std::unique_ptr<SubDetector>>```, with ```std::unique_ptr``` making sense as discussed in the report.
- When creating the ```DetectorSystem``` member functions, ```remove_sub_detector``` and ```release_sub_detector```, ChatGPT 5.2 suggested that I use ```std::find_if()``` to search for the requested ```SubDetector``` within the container.
- When designing the ```DetectorSystem``` wrapper function ```set_sub_detector_status```, ChatGPT 5.2 indicated the use of a raw non-owning pointer to deal with the ```status``` change of the ```SubDetector``` stored in the ```DetectorSystem```. 
- ChatGPT 5.2 helped me to learn how UML diagrams work.
- Discussed the possibilities of exceptions for validation, however I did not think it added much value.
- In the report ChatGPT 5.2 helped me to create nicely formatted code snippets.
- In "main.cpp" ChatGPT 5.2 recommened helper functions to split up the long main into many managable functions that demonstrate a singular feature.
- While testing the alteration of my ```FourMomentum``` to use smart pointers instead of raw pointers, I noticed the derived Particles were not moving as expected, more just copying. I thought they would derive the copy/move semantics from Particle, which they should if they hadn't had an overriding destructor. ChatGPT 5.2 helped me to realise that this definition of a custom destructor prevented the compiler from doing the correct move operations for all the derived Particles. Hence in each intermediate base class and derived class I defualted the copy/move constructors and assignment operators, e.g for the ```Proton``` copy constructor ```Proton(const Proton& other) = default;```. This specifically stated that the compiler should use the semantics from the base ```Particle```. 
 

## Report
This report includes my key design considerations, with the results indicating how the main.cpp demonstrates the minimum and advanced functionality.
The report can be found in the file "" with its commit history being found in the file "project_particle_detector.tex".
