// Callum Williamson.
// Student ID: 11399397.

// Header, file interface for the FourMomentum class.

#ifndef FOURMOMENTUM_HPP
#define FOURMOMENTUM_HPP

#include <iostream>
#include <string>
#include <vector>

class FourMomentum
{
    private:
    // Components of four momentum [units: MeV - using natural units].
    // Implemented as a pointer to a dynamically allocated std::vector.
    std::vector<double>* components; // (E, px, py, pz).

    // Validation of energy function.
    void validate_E(double E) const;

    public:
    // Defualt constructor.
    FourMomentum();

    // Parameterised constructor.
    FourMomentum(double E, double px, double py, double pz);

    // Destructor.
    ~FourMomentum();

    // Copy Constructor (deep copy).
    FourMomentum(const FourMomentum& other);

    // Copy Assignment Operator.
    FourMomentum& operator=(const FourMomentum& other);

    // Move Constructor.
    FourMomentum(FourMomentum&& other) noexcept;

    // Move Assignment Operator.
    FourMomentum& operator=(FourMomentum&& other) noexcept;

    // Getters.
    double get_E() const;
    double get_px() const;
    double get_py() const;
    double get_pz() const;

    // Setters.
    void set_E(double E);
    void set_px(double px);
    void set_py(double py);
    void set_pz(double pz);
};

#endif