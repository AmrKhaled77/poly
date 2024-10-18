#include "poly_gpt.h"
#include <cmath>
#include <algorithm>

// Constructors
PolynomialWithChatGPT::PolynomialWithChatGPT() {}

PolynomialWithChatGPT::PolynomialWithChatGPT(const std::vector<double> &coefficients) : coeffs(coefficients) {}

PolynomialWithChatGPT::PolynomialWithChatGPT(const PolynomialWithChatGPT &other) : coeffs(other.coeffs) {}

// Destructor
PolynomialWithChatGPT::~PolynomialWithChatGPT() {}

// Assignment operator
PolynomialWithChatGPT &PolynomialWithChatGPT::operator=(const PolynomialWithChatGPT &other)
{
    if (this != &other)
    {
        coeffs = other.coeffs;
    }
    return *this;
}

// Arithmetic operators
PolynomialWithChatGPT PolynomialWithChatGPT::operator+(const PolynomialWithChatGPT &other) const
{
    std::vector<double> result(std::max(coeffs.size(), other.coeffs.size()), 0);
    for (size_t i = 0; i < coeffs.size(); i++)
        result[i] += coeffs[i];
    for (size_t i = 0; i < other.coeffs.size(); i++)
        result[i] += other.coeffs[i];
    return PolynomialWithChatGPT(result);
}

PolynomialWithChatGPT PolynomialWithChatGPT::operator-(const PolynomialWithChatGPT &other) const
{
    std::vector<double> result(std::max(coeffs.size(), other.coeffs.size()), 0);
    for (size_t i = 0; i < coeffs.size(); i++)
        result[i] += coeffs[i];
    for (size_t i = 0; i < other.coeffs.size(); i++)
        result[i] -= other.coeffs[i];
    return PolynomialWithChatGPT(result);
}

PolynomialWithChatGPT PolynomialWithChatGPT::operator*(const PolynomialWithChatGPT &other) const
{
    std::vector<double> result(coeffs.size() + other.coeffs.size() - 1, 0);
    for (size_t i = 0; i < coeffs.size(); i++)
    {
        for (size_t j = 0; j < other.coeffs.size(); j++)
        {
            result[i + j] += coeffs[i] * other.coeffs[j];
        }
    }
    return PolynomialWithChatGPT(result);
}

// Equality operator
bool PolynomialWithChatGPT::operator==(const PolynomialWithChatGPT &other) const
{
    return coeffs == other.coeffs;
}

// Output operator
std::ostream &operator<<(std::ostream &out, const PolynomialWithChatGPT &poly)
{
    for (int i = poly.coeffs.size() - 1; i >= 0; i--)
    {
        out << poly.coeffs[i];
        if (i != 0)
            out << "x^" << i << " + ";
    }
    return out;
}

// Utility functions
int PolynomialWithChatGPT::degree() const
{
    return coeffs.size() - 1;
}

double PolynomialWithChatGPT::evaluate(double x) const
{
    double result = 0;
    for (int i = coeffs.size() - 1; i >= 0; i--)
    {
        result = result * x + coeffs[i];
    }
    return result;
}

PolynomialWithChatGPT PolynomialWithChatGPT::compose(const PolynomialWithChatGPT &q) const
{
    PolynomialWithChatGPT result({0});
    for (int i = coeffs.size() - 1; i >= 0; i--)
    {
        result = result * q + PolynomialWithChatGPT({coeffs[i]});
    }
    return result;
}

PolynomialWithChatGPT PolynomialWithChatGPT::derivative() const
{
    std::vector<double> result;
    for (int i = 1; i < coeffs.size(); i++)
    {
        result.push_back(i * coeffs[i]);
    }
    return PolynomialWithChatGPT(result);
}

PolynomialWithChatGPT PolynomialWithChatGPT::integral() const
{
    std::vector<double> result(coeffs.size() + 1, 0);
    for (int i = 0; i < coeffs.size(); i++)
    {
        result[i + 1] = coeffs[i] / (i + 1);
    }
    return PolynomialWithChatGPT(result);
}

double PolynomialWithChatGPT::integral(double x1, double x2) const
{
    PolynomialWithChatGPT intPoly = this->integral();
    return intPoly.evaluate(x2) - intPoly.evaluate(x1);
}

double PolynomialWithChatGPT::getRoot(double guess, double tolerance, int maxIter)
{
    PolynomialWithChatGPT deriv = this->derivative();
    double x = guess;
    for (int i = 0; i < maxIter; i++)
    {
        double fx = this->evaluate(x);
        if (std::abs(fx) < tolerance)
            return x;
        double fpx = deriv.evaluate(x);
        if (fpx == 0)
            break;
        x = x - fx / fpx;
    }
    return x;
}

// Getters and Setters
void PolynomialWithChatGPT::setCoefficients(const std::vector<double> &coefficients)
{
    coeffs = coefficients;
}

double PolynomialWithChatGPT::getCoefficient(int degree) const
{
    if (degree < coeffs.size())
        return coeffs[degree];
    return 0;
}


// Function to display the menu


