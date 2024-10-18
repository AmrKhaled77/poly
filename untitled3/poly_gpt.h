#ifndef POLYNOMIALWITHCHATGPT_H
#define POLYNOMIALWITHCHATGPT_H

#include <iostream>
#include <vector>

class PolynomialWithChatGPT
{
private:
    std::vector<double> coeffs; // Store coefficients of the polynomial

public:
    // Constructors
    PolynomialWithChatGPT();
    PolynomialWithChatGPT(const std::vector<double> &coefficients);
    PolynomialWithChatGPT(const PolynomialWithChatGPT &other);

    // Destructor
    ~PolynomialWithChatGPT();

    // Assignment operator
    PolynomialWithChatGPT &operator=(const PolynomialWithChatGPT &other);

    // Arithmetic operators
    PolynomialWithChatGPT operator+(const PolynomialWithChatGPT &other) const;
    PolynomialWithChatGPT operator-(const PolynomialWithChatGPT &other) const;
    PolynomialWithChatGPT operator*(const PolynomialWithChatGPT &other) const;

    // Equality operator
    bool operator==(const PolynomialWithChatGPT &other) const;

    // Output operator
    friend std::ostream &operator<<(std::ostream &out, const PolynomialWithChatGPT &poly);

    // Utility functions
    int degree() const;
    double evaluate(double x) const;
    PolynomialWithChatGPT compose(const PolynomialWithChatGPT &q) const;
    PolynomialWithChatGPT derivative() const;
    PolynomialWithChatGPT integral() const;
    double integral(double x1, double x2) const;
    double getRoot(double guess = 1, double tolerance = 1e-6, int maxIter = 100);

    // Getters and Setters
    void setCoefficients(const std::vector<double> &coefficients);
    double getCoefficient(int degree) const;
};

#endif // POLYNOMIALWITHCHATGPT_H
