// Callum Williamson.
// Student ID: 11399397.

// File implementation for the FourMomentum class.

#include "core/FourMomentum.hpp"
#include "core/Debug.hpp"

#include <iostream>
#include <string>
#include <vector>

// Validation of energy function.
void FourMomentum::validate_E(double E) const
{
    if (E < 0.0)
    {
        std::cerr << "Invalid FourMomentum energy E: '" << E << "' MeV" << std::endl;
        std::cerr << "Please enter a non-negative energy." << std::endl;
        std::cerr << "Exiting program." << std::endl;
        std::exit(1); // Exit
    }
}

// Defualt Constructor.
FourMomentum::FourMomentum()
{
    components = new std::vector<double>;
    components->push_back(0.0); // E.
    components->push_back(0.0); // px
    components->push_back(0.0); // py
    components->push_back(0.0); // pz

    if (Debug::show_messages)
    {
        std::cout << "Calling FourMomentum Defualt Constructor." << std::endl;
    }
}

//Parameterised Constructor.
FourMomentum::FourMomentum(double E, double px, double py, double pz)
{
    validate_E(E); // Validation of E.

    components = new std::vector<double>;
    components->push_back(E);
    components->push_back(px);
    components->push_back(py);
    components->push_back(pz);

    if (Debug::show_messages)
    {
        std::cout << "Calling FourMomentum Parameterised Constructor." << std::endl;
    }
}

// Destructor.
FourMomentum::~FourMomentum()
{
    if (Debug::show_messages)
    {
        std::cout << "Calling FourMomentum Destructor." << std::endl;
    }
    delete components;
}

// Copy Constructor (deep copy).
FourMomentum::FourMomentum(const FourMomentum& other)
{
    // e.g FourMomentum b = a.
    // other refers to a.

    if (Debug::show_messages)
    {
        std::cout << "Calling FourMomentum Copy Constructor." << std::endl;
    }
    // Copies components of other (FourMomentum object) and constructs new object.
    // Does not copy the address of the other.
    components = new std::vector<double>(*other.components);
}

// Copy Assignment Operator.
FourMomentum& FourMomentum::operator=(const FourMomentum& other)
{
    // e.g b = a. 
    // this refers to b.
    // other refers to a. 

    if (Debug::show_messages)
    {
        std::cout << "Calling FourMomentum Copy Assignment Operator." << std::endl;
    }

    // Checks you don't do b = b. Then you may delete your memory and try to copy from it. 
    if (this != &other)
    {
        delete components; // Delete b's prior components, therefore no memory leak.
        components = new std::vector<double>(*other.components);
    }

    return *this;
}

// Move Constructor (constructing from temporary/disposible object).
FourMomentum::FourMomentum(FourMomentum&& other) noexcept // && means other is an rvalue reference, can strip from.
{
    if (Debug::show_messages)
    {
        std::cout << "Calling FourMomentum Move Constructor." << std::endl;
    }
    components = other.components;
    other.components = nullptr; // other has been stripped but safely for destructor.
}

// Move Assignment Operator.
FourMomentum& FourMomentum::operator=(FourMomentum&& other) noexcept
{
    if (Debug::show_messages)
    {
        std::cout << "Calling FourMomentum Move Assignment Operator" << std::endl;
    }

    if (this != &other)
    {
        delete components; // this previous components are deleted.
        components = other.components;
        other.components = nullptr; // other has been stripped but safely for destructor.
    }

    return *this;
}

// Getters.
double FourMomentum::get_E() const
{
    return (*components)[0];
}

double FourMomentum::get_px() const
{
    return (*components)[1];
}

double FourMomentum::get_py() const
{
    return (*components)[2];
}

double FourMomentum::get_pz() const
{
    return (*components)[3];
}

// Setters.
void FourMomentum::set_E(double E)
{
    validate_E(E); // Validation of E.
    (*components)[0] = E;
}

void FourMomentum::set_px(double px)
{
    (*components)[1] = px;
}

void FourMomentum::set_py(double py)
{
    (*components)[2] = py;
}

void FourMomentum::set_pz(double pz)
{
    (*components)[3] = pz;
}