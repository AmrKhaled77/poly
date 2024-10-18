#ifndef POLYNOMIALWITHCOPIOLT_H
#define POLYNOMIALWITHCOPIOLT_H

#include <iostream>
#include <vector>

class PolynomialWithCopilot
{
private:
    std::vector<double> coeffs;

public:
    // Constructors
    PolynomialWithCopilot();
    PolynomialWithCopilot(const std::vector<double> coefficients);
    PolynomialWithCopilot(const PolynomialWithCopilot &other);

    // Destructor
    ~PolynomialWithCopilot();

    // Assignment operator
    PolynomialWithCopilot &operator=(const PolynomialWithCopilot &other);

    // Arithmetic operators
    PolynomialWithCopilot operator+(const PolynomialWithCopilot &other) const;
    PolynomialWithCopilot operator-(const PolynomialWithCopilot &other) const;
    PolynomialWithCopilot operator*(const PolynomialWithCopilot &other) const;

    // Equality operator
    bool operator==(const PolynomialWithCopilot &other) const;

    // Output operator
    friend std::ostream &operator<<(std::ostream &out, const PolynomialWithCopilot &poly);

    // Utility functions
    int degree() const;
    double evaluate(double x) const;
    PolynomialWithCopilot compose(const PolynomialWithCopilot &q) const;
    PolynomialWithCopilot derivative() const;
    PolynomialWithCopilot integral() const;
    double integral(double x1, double x2) const;
    double getRoot(double guess = 1, double tolerance = 1e-6, int maxIter = 100);

    // Getters and Setters
    void setCoefficients(const std::vector<double> &coefficients);
    double getCoefficient(int degree) const;
};

#endif // POLYNOMIALWITHCOPIOLT_H
