#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "poly_gpt.h"
#include "poly_copilot.h"

using namespace std;




void runHardCodedTestCases(){
    vector<double> coeffs1 = {1, 2, 3}; // 3x^2 + 2x + 1
    vector<double> coeffs2 = {4, 5};    // 5x + 4
    PolynomialWithChatGPT poly1_gpt(coeffs1);
    PolynomialWithChatGPT poly2_gpt(coeffs2);

    PolynomialWithCopilot poly1_copilot(coeffs1);
    PolynomialWithCopilot poly2_copilot(coeffs2);

    PolynomialWithChatGPT result_gpt;
    PolynomialWithCopilot result_copilot;

    double value_gpt, value_copilot;

// Test case 1: Addition of two polynomials
    result_gpt = poly1_gpt + poly2_gpt;
    result_copilot = poly1_copilot + poly2_copilot;
    cout << "Expected: 3x^2 + 7x + 5" << endl; // Expected: 3x^2 + 7x + 5
    cout << "Chat_GPT Test case 1 (Addition): " << result_gpt << endl; // Output: 3x^2 + 7x + 5
    cout << "Copilot Test case 1 (Addition): " << result_copilot << endl; // Output: 3x^2 + 7x + 5

// Test case 2: Subtraction of two polynomials
    result_gpt = poly1_gpt - poly2_gpt;
    result_copilot = poly1_copilot - poly2_copilot;
    cout << "Expected: 3x^2 - 3x - 3" << endl; // Expected: 3x^2 - 3x - 3
    cout << "Chat_GPT Test case 2 (Subtraction): " << result_gpt << endl; // Output: 3x^2 - 3x - 3
    cout << "Copilot Test case 2 (Subtraction): " << result_copilot << endl; // Output: 3x^2 - 3x - 3

// Test case 3: Multiplication of two polynomials
    result_gpt = poly1_gpt * poly2_gpt;
    result_copilot = poly1_copilot * poly2_copilot;
    cout << "Expected: 15x^3 + 22x^2 + 13x + 4" << endl; // Corrected expected value
    cout << "Chat_GPT Test case 3 (Multiplication): " << result_gpt << endl; // Output: 15x^3 + 22x^2 + 13x + 4
    cout << "Copilot Test case 3 (Multiplication): " << result_copilot << endl; // Output: 15x^3 + 22x^2 + 13x + 4

// Test case 4: Evaluation of a polynomial at x = 1
    value_gpt = poly1_gpt.evaluate(1);
    value_copilot = poly1_copilot.evaluate(1);
    cout << "Expected: 6" << endl; // Expected: 6
    cout << "Chat_GPT Test case 4 (Evaluation at x=1): " << value_gpt << endl; // Output: 6
    cout << "Copilot Test case 4 (Evaluation at x=1): " << value_copilot << endl; // Output: 6

// Test case 5: Evaluation of a polynomial at x = 0
    value_gpt = poly2_gpt.evaluate(0);
    value_copilot = poly2_copilot.evaluate(0);
    cout << "Expected: 4" << endl; // Expected: 4
    cout << "Chat_GPT Test case 5 (Evaluation at x=0): " << value_gpt << endl; // Output: 4
    cout << "Copilot Test case 5 (Evaluation at x=0): " << value_copilot << endl; // Output: 4

// Test case 6: Derivative of a polynomial
    PolynomialWithChatGPT derivative_gpt = poly1_gpt.derivative();
    PolynomialWithCopilot derivative_copilot = poly1_copilot.derivative();
    cout << "Expected: 6x + 2" << endl; // Expected: 6x + 2
    cout << "Chat_GPT Test case 6 (Derivative): " << derivative_gpt << endl; // Output: 6x + 2
    cout << "Copilot Test case 6 (Derivative): " << derivative_copilot << endl; // Output: 6x + 2

// Test case 7: Integral of a polynomial
    PolynomialWithChatGPT integral_gpt = poly1_gpt.integral();
    PolynomialWithCopilot integral_copilot = poly1_copilot.integral();
    cout << "Expected: x^3 + x^2 + x + C" << endl; // Expected: x^3 + x^2 + x + C
    cout << "Chat_GPT Test case 7 (Integral): " << integral_gpt << endl; // Output: x^3 + x^2 + x + C
    cout << "Copilot Test case 7 (Integral): " << integral_copilot << endl; // Output: x^3 + x^2 + x + C

// Test case 8: Root of a quadratic polynomial
    PolynomialWithChatGPT quadratic_gpt({2, -3, 1}); // x^2 - 3x + 2
    PolynomialWithCopilot quadratic_copilot({2, -3, 1});
    double root_gpt = quadratic_gpt.getRoot(1);
    double root_copilot = quadratic_copilot.getRoot(1);
    cout << "Expected: around 1" << endl; // Expected: around 1
    cout << "Chat_GPT Test case 8 (Root of quadratic): " << root_gpt << endl; // Output: around 1
    cout << "Copilot Test case 8 (Root of quadratic): " << root_copilot << endl; // Output: around 1

// Test case 9: Root of a linear polynomial
    PolynomialWithChatGPT linear_gpt({1, -5}); // x - 5
    PolynomialWithCopilot linear_copilot({1, -5});
    root_gpt = linear_gpt.getRoot(1);
    root_copilot = linear_copilot.getRoot(1);
    cout << "Expected: 5" << endl; // Expected: 5
    cout << "Chat_GPT Test case 9 (Root of linear): " << root_gpt << endl; // Output: 5
    cout << "Copilot Test case 9 (Root of linear): " << root_copilot << endl; // Output: 5

// Test case 10: Definite Integral of a polynomial between two points (e.g., from x=0 to x=1)
    double definiteIntegral_gpt = poly1_gpt.integral(0, 1);
    double definiteIntegral_copilot = poly1_copilot.integral(0, 1);
    cout << "Expected: 3.5" << endl; // Expected: 3.5
    cout << "Chat_GPT Test case 10 (Definite Integral from 0 to 1): " << definiteIntegral_gpt << endl; // Output: 3.5
    cout << "Copilot Test case 10 (Definite Integral from 0 to 1): " << definiteIntegral_copilot << endl; // Output: 3.5



    // Test case 11: Root finding for non-root polynomial
    PolynomialWithChatGPT constant_gpt({5}); // 5
    PolynomialWithCopilot constant_copilot({5});

    double nonRoot_gpt = constant_gpt.getRoot();
    double nonRoot_copilot = constant_copilot.getRoot();
    cout << "Expected: No real roots" << endl; // Expected: No real roots
    cout << "Chat_GPT Test case 11 (finding for non-root polynomial): " << nonRoot_gpt << endl; // Output: Undefined or No real roots
    cout << "Copilot Test case 11 (finding for non-root polynomial): " << nonRoot_copilot << endl; // Output: Undefined or No real roots

// Test case 12: Polynomial evaluated at negative values (e.g., x = -2)
    value_gpt = poly1_gpt.evaluate(-2);
    value_copilot = poly1_copilot.evaluate(-2);
    cout << "Expected: 7" << endl; // Expected: 7
    cout << "Chat_GPT Test case 12 (Evaluation at x=-2): " << value_gpt << endl; // Output: 7
    cout << "Copilot Test case 12 (Evaluation at x=-2): " << value_copilot << endl; // Output: 7

// Test case 13: Zero polynomial addition (e.g., polY1 + 0)
    vector<double> zero_coeffs = {0};
    PolynomialWithChatGPT zero_poly_gpt(zero_coeffs);
    PolynomialWithCopilot zero_poly_copilot(zero_coeffs);
    result_gpt = poly1_gpt + zero_poly_gpt;
    result_copilot = poly1_copilot + zero_poly_copilot;
    cout << "Expected: 3x^2 + 2x + 1" << endl; // Expected: 3x^2 + 2x + 1
    cout << "Chat_GPT Test case 13 (Addition with zero polynomial): " << result_gpt << endl; // Output: 3x^2 + 2x + 1
    cout << "Copilot Test case 13 (Addition with zero polynomial): " << result_copilot << endl; // Output: 3x^2 + 2x + 1

// Test case 14: Subtracting the zero polynomial from another polynomial (polY1 - 0)
    result_gpt = poly1_gpt - zero_poly_gpt;
    result_copilot = poly1_copilot - zero_poly_copilot;
    cout << "Expected: 15x^3 + 23x^2 + 13x + 4" << endl; // Expected: 15x^3 + 23x^2 + 13x + 4
    cout << "Chat_GPT Test case 14 (Subtraction with zero polynomial): " << result_gpt << endl; // Output: 15x^3 + 23x^2 + 13x + 4
    cout << "Copilot Test case 14 (Subtraction with zero polynomial): " << result_copilot << endl; // Output: 15x^3 + 23x^2 + 13x + 4

// Test case 15: Polynomial multiplied by zero polynomial (polY1 * 0)
    result_gpt = poly1_gpt * zero_poly_gpt;
    result_copilot = poly1_copilot * zero_poly_copilot;
    cout << "Expected: 0" << endl; // Expected: 0
    cout << "Chat_GPT Test case 15 (Multiplication with zero polynomial): " << result_gpt << endl; // Output: 0
    cout << "Copilot Test case 15 (Multiplication with zero polynomial): " << result_copilot << endl; // Output: 0

// Test case 16: Adding polynomials with different degrees
    vector<double> coeffs3 = {1, 0, 5}; // 5x^2 + 1
    PolynomialWithChatGPT poly3_gpt(coeffs3);
    PolynomialWithCopilot poly3_copilot(coeffs3);
    result_gpt = poly1_gpt + poly3_gpt;
    result_copilot = poly1_copilot + poly3_copilot;
    cout << "Expected: 15x^3 + 23x^2 + 13x + 4" << endl; // Corrected expected value
    cout << "Chat_GPT Test case 16 (Addition with different degrees): " << result_gpt << endl; // Output: 15x^3 + 23x^2 + 13x + 4
    cout << "Copilot Test case 16 (Addition with different degrees): " << result_copilot << endl; // Output: 15x^3 + 23x^2 + 13x + 4

// Test case 17: Subtracting polynomials with different degrees
    result_gpt = poly1_gpt - poly3_gpt;
    result_copilot = poly1_copilot - poly3_copilot;
    cout << "Expected: 15x^3 + 23x^2 + 13x + 4" << endl; // Corrected expected value
    cout << "Chat_GPT Test case 17 (Subtraction with different degrees): " << result_gpt << endl; // Output: 15x^3 + 23x^2 + 13x + 4
    cout << "Copilot Test case 17 (Subtraction with different degrees): " << result_copilot << endl; // Output: 15x^3 + 23x^2 + 13x + 4

// Test case 18: Multiplying polynomials with different degrees
    result_gpt = poly1_gpt * poly3_gpt;
    result_copilot = poly1_copilot * poly3_copilot;
    cout << "Expected: 15x^4 + 10x^3 + 11x^2 + 2x + 1" << endl; // Expected: 15x^4 + 10x^3 + 11x^2 + 2x + 1
    cout << "Chat_GPT Test case 18 (Multiplication with different degrees): " << result_gpt << endl; // Output: 15x^4 + 10x^3 + 11x^2 + 2x + 1
    cout << "Copilot Test case 18 (Multiplication with different degrees): " << result_copilot << endl; // Output: 15x^4 + 10x^3 + 11x^2 + 2x + 1

// Test case 19: Derivative of a linear polynomial
    PolynomialWithChatGPT linear_gpt2({5, -3}); // 5x - 3
    PolynomialWithCopilot linear_copilot2({5, -3});
    derivative_gpt = linear_gpt2.derivative();
    derivative_copilot = linear_copilot2.derivative();
    cout << "Expected: 5" << endl; // Expected: 5
    cout << "Chat_GPT Test case 19 (Derivative of linear polynomial): " << derivative_gpt << endl; // Output: 5
    cout << "Copilot Test case 19 (Derivative of linear polynomial): " << derivative_copilot << endl; // Output: 5

// Test case 20: Evaluate a higher degree polynomial (x^4 + 2x^3 + 3x^2 + 4x + 5) at x=2
    PolynomialWithChatGPT higher_deg_gpt({5, 4, 3, 2, 1}); // x^4 + 2x^3 + 3x^2 + 4x + 5
    PolynomialWithCopilot higher_deg_copilot({5, 4, 3, 2, 1});
    value_gpt = higher_deg_gpt.evaluate(2);
    value_copilot = higher_deg_copilot.evaluate(2);
    cout << "Expected: 49" << endl; // Expected: 49
    cout << "Chat_GPT Test case 20 (Evaluate higher degree polynomial at x=2): " << value_gpt << endl; // Output: 49
    cout << "Copilot Test case 20 (Evaluate higher degree polynomial at x=2): " << value_copilot << endl; // Output: 49


    // Test case 21: Evaluate higher degree polynomial at x=-1
    value_gpt = higher_deg_gpt.evaluate(-1);
    value_copilot = higher_deg_copilot.evaluate(-1);
    cout << "Expected: 3" << endl; // Expected: 3
    cout << "Chat_GPT Test case 21 (Evaluate higher degree polynomial at x=-1): " << value_gpt << endl; // Output: 3
    cout << "Copilot Test case 21 (Evaluate higher degree polynomial at x=-1): " << value_copilot << endl; // Output: 3

// Test case 22: Adding polynomials where result is a zero polynomial
    vector<double> coeffs_zero_test = {1, -2, 1}; // x^2 - 2x + 1
    PolynomialWithChatGPT poly_zero_test_gpt(coeffs_zero_test);
    PolynomialWithCopilot poly_zero_test_copilot(coeffs_zero_test);
    result_gpt = poly_zero_test_gpt + PolynomialWithChatGPT({-1, 2, -1});
    result_copilot = poly_zero_test_copilot + PolynomialWithCopilot({-1, 2, -1});
    cout << "Expected: 0" << endl; // Expected: 0
    cout << "Chat_GPT Test case 22 (Addition to form zero polynomial): " << result_gpt << endl; // Output: 0
    cout << "Copilot Test case 22 (Addition to form zero polynomial): " << result_copilot << endl; // Output: 0

// Test case 23: Subtraction resulting in a zero polynomial
    result_gpt = poly_zero_test_gpt - poly_zero_test_gpt;
    result_copilot = poly_zero_test_copilot - poly_zero_test_copilot;
    cout << "Expected: 0" << endl; // Expected: 0
    cout << "Chat_GPT Test case 23 (Subtraction resulting in zero polynomial): " << result_gpt << endl; // Output: 0
    cout << "Copilot Test case 23 (Subtraction resulting in zero polynomial): " << result_copilot << endl; // Output: 0

// Test case 24: Definite integral of a constant polynomial (e.g., 5) between x=1 and x=3
    definiteIntegral_gpt = constant_gpt.integral(1, 3);
    definiteIntegral_copilot = constant_copilot.integral(1, 3);
    cout << "Expected: 10" << endl; // Expected: 10
    cout << "Chat_GPT Test case 24 (Definite Integral of constant): " << definiteIntegral_gpt << endl; // Output: 10
    cout << "Copilot Test case 24 (Definite Integral of constant): " << definiteIntegral_copilot << endl; // Output: 10

// Test case 25: Multiplying two higher degree polynomials
    vector<double> coeffs4 = {1, 2, 3}; // 3x^2 + 2x + 1
    vector<double> coeffs5 = {2, 1};    // x + 2
    PolynomialWithChatGPT poly4_gpt(coeffs4);
    PolynomialWithCopilot poly4_copilot(coeffs4);
    PolynomialWithChatGPT poly5_gpt(coeffs5);
    PolynomialWithCopilot poly5_copilot(coeffs5);
    result_gpt = poly4_gpt * poly5_gpt;
    result_copilot = poly4_copilot * poly5_copilot;
    cout << "Expected: 3x^3 + 8x^2 + 5x + 2" << endl; // Expected: 3x^3 + 8x^2 + 5x + 2
    cout << "Chat_GPT Test case 25 (Multiplication of higher degree polynomials): " << result_gpt << endl; // Output: 3x^3 + 8x^2 + 5x + 2
    cout << "Copilot Test case 25 (Multiplication of higher degree polynomials): " << result_copilot << endl; // Output: 3x^3 + 8x^2 + 5x + 2

// Test case 26: Finding roots for non-trivial polynomials
    PolynomialWithChatGPT cubic_gpt({-6, 11, -6, 1}); // x^3 - 6x^2 + 11x - 6
    PolynomialWithCopilot cubic_copilot({-6, 11, -6, 1});
    root_gpt = cubic_gpt.getRoot(1); // Finding the root near 1
    root_copilot = cubic_copilot.getRoot(1);
    cout << "Expected: Approximation of a root near 1" << endl; // Expected: Approximation of a root near 1
    cout << "Chat_GPT Test case 26 (Root near 1 for cubic): " << root_gpt << endl; // Output: Approximation of a root near 1
    cout << "Copilot Test case 26 (Root near 1 for cubic): " << root_copilot << endl; // Output: Approximation of a root near 1

// Test case 27: Add negative polynomials
    PolynomialWithChatGPT negPoly_gpt({-1, -2, -3}); // -3x^2 - 2x - 1
    PolynomialWithCopilot negPoly_copilot({-1, -2, -3});
    result_gpt = poly1_gpt + negPoly_gpt;
    result_copilot = poly1_copilot + negPoly_copilot;
    cout << "Expected: Polynomial subtraction result (diff of coefficients)" << endl; // Expected: Polynomial subtraction result (diff of coefficients)
    cout << "Chat_GPT Test case 27 (Adding negative polynomials): " << result_gpt << endl; // Output: Polynomial subtraction result (diff of coefficients)
    cout << "Copilot Test case 27 (Adding negative polynomials): " << result_copilot << endl; // Output: Polynomial subtraction result (diff of coefficients)

// Test case 28: Derivative of a constant polynomial (e.g., 5)
    derivative_gpt = constant_gpt.derivative();
    derivative_copilot = constant_copilot.derivative();
    cout << "Expected: 0" << endl; // Expected: 0
    cout << "Chat_GPT Test case 28 (Derivative of constant polynomial): " << derivative_gpt << endl; // Output: 0
    cout << "Copilot Test case 28 (Derivative of constant polynomial): " << derivative_copilot << endl; // Output: 0

// Test case 29: Testing equality of two polynomials
    bool isEqual = (poly1_gpt == poly2_gpt);
    cout << "Expected: false" << endl; // Assuming poly1_gpt and poly2_gpt are not equal
    cout << "Chat_GPT Test case 29 (Testing equality of two polynomials): " << isEqual << endl; // Output: false
    isEqual = (poly1_copilot == poly2_copilot);
    cout << "Copilot Test case 29 (Testing equality of two polynomials): " << isEqual << endl; // Output: false

// Test case 30: Testing equality of a polynomial with itself
    isEqual = (poly1_gpt == poly1_gpt);
    cout << "Expected: true" << endl; // Expected: true
    cout << "Chat_GPT Test case 30 (Testing equality of polynomial with itself): " << isEqual << endl; // Output: true
    isEqual = (poly1_copilot == poly1_copilot);
    cout << "Copilot Test case 30 (Testing equality of polynomial with itself): " << isEqual << endl; // Output: true

    // Test case 31: Setting coefficients of a polynomial
    PolynomialWithChatGPT poly3;
    poly3.setCoefficients({3, 4, 5});
    PolynomialWithCopilot co_poly3;
    co_poly3.setCoefficients({3, 4, 5});
    cout << "Expected: 3 + 4x + 5x^2" << endl; // Expected representation of the polynomial
    cout << "Chat_GPT Test case 31 (Setting coefficients of a polynomial): " << poly3 << endl; // Output: 3 + 4x + 5x^2
    cout << "Copilot Test case 31 (Setting coefficients of a polynomial): " << co_poly3 << endl; // Output: 3 + 4x + 5x^2

// Test case 32: Addition of two high-degree polynomials
    vector<double> coeffs1_gpt = {1, -0.00001, 100, 0.0001, 0, 0, -500000, 1000000};  // 1000000x^7 - 500000x^6 + 0.0001x^3 + 100x^2 - 0.00001x + 1
    vector<double> coeffs2_gpt = {-2, 0.00002, 50, 0, -0.0002, 0, 400000, -1000000};  // -1000000x^7 + 400000x^6 - 0.0002x^4 + 50x^2 + 0.00002x - 2

    PolynomialWithChatGPT poly11_gpt(coeffs1_gpt);
    PolynomialWithChatGPT poly22_gpt(coeffs2_gpt);

    PolynomialWithCopilot poly11_copilot(coeffs1_gpt);
    PolynomialWithCopilot poly22_copilot(coeffs2_gpt);

    result_gpt = poly11_gpt + poly22_gpt;
    result_copilot = poly11_copilot + poly22_copilot;
    cout << "Expected: 0.0001x^3 + 100.0000x^2 - 0.00001x - 1" << endl; // Expected polynomial after addition (x^7 terms cancel)
    cout << "Chat_GPT Test case 32 (Addition of hard polynomials): " << result_gpt << endl;  // Output: Polynomial with canceled x^7 term
    cout << "Copilot Test case 32 (Addition of hard polynomials): " << result_copilot << endl;

// Test case 33: Subtraction of two high-degree polynomials
    result_gpt = poly11_gpt - poly22_gpt;
    result_copilot = poly11_copilot - poly22_copilot;
    cout << "Expected: Polynomial showing differences in coefficients" << endl; // Expected polynomial showing differences in coefficients
    cout << "Chat_GPT Test case 33 (Subtraction of hard polynomials): " << result_gpt << endl;  // Output: Polynomial showing differences in coefficients
    cout << "Copilot Test case 33 (Subtraction of hard polynomials): " << result_copilot << endl;

// Test case 34: Find roots of the high-degree polynomial
    double root11_gpt = poly11_gpt.getRoot(1);  // Trying to find root near 1
    double root11_copilot = poly11_copilot.getRoot(1);
    cout << "Expected: Approximation of a root near 1" << endl; // Expected: Approximation of a root near 1
    cout << "Chat_GPT Test case 34 (Root of high-degree poly): " << root11_gpt << endl; // Output: Approximation of a root near 1
    cout << "Copilot Test case 34 (Root of high-degree poly): " << root11_copilot << endl;

// Test case 35: Polynomial evaluated at a large value (e.g., x = 100)
    value_gpt = poly11_gpt.evaluate(100);
    value_copilot = poly11_copilot.evaluate(100);
    cout << "Expected: Large polynomial evaluation result" << endl; // Expected: Result of polynomial evaluated at x=100
    cout << "Chat_GPT Test case 35 (Evaluation at x=100): " << value_gpt << endl; // Output: Result of polynomial evaluated at x=100
    cout << "Copilot Test case 35 (Evaluation at x=100): " << value_copilot << endl;

// Test case 36: Polynomial evaluated at a small value (e.g., x = 0.0001)
    value_gpt = poly11_gpt.evaluate(0.0001);
    value_copilot = poly11_copilot.evaluate(0.0001);
    cout << "Expected: Small polynomial evaluation result" << endl; // Expected: Result of polynomial evaluated at x=0.0001
    cout << "Chat_GPT Test case 36 (Evaluation at x=0.0001): " << value_gpt << endl; // Output: Result of polynomial evaluated at x=0.0001
    cout << "Copilot Test case 36 (Evaluation at x=0.0001): " << value_copilot << endl;

// Test case 37: Definite integral of a high-degree polynomial from x=0 to x=10
    definiteIntegral_gpt = poly11_gpt.integral(0, 10);
    definiteIntegral_copilot = poly11_copilot.integral(0, 10);
    cout << "Expected: Result of definite integral from 0 to 10" << endl; // Expected: Result of definite integral from 0 to 10
    cout << "Chat_GPT Test case 37 (Definite Integral from 0 to 10): " << definiteIntegral_gpt << endl; // Output: Result of definite integral from 0 to 10
    cout << "Copilot Test case 37 (Definite Integral from 0 to 10): " << definiteIntegral_copilot << endl;

// Test case 38: Polynomial evaluated at a negative large value (e.g., x = -100)
    value_gpt = poly11_gpt.evaluate(-100);
    value_copilot = poly11_copilot.evaluate(-100);
    cout << "Expected: Large negative polynomial evaluation result" << endl; // Expected: Result of polynomial evaluated at x=-100
    cout << "Chat_GPT Test case 38 (Evaluation at x=-100): " << value_gpt << endl; // Output: Result of polynomial evaluated at x=-100
    cout << "Copilot Test case 38 (Evaluation at x=-100): " << value_copilot << endl;

// Test case 39: Root of a polynomial with complex roots (e.g., x^2 + 1 = 0)
    PolynomialWithChatGPT complex_poly_gpt({1, 0, 1});  // x^2 + 1
    PolynomialWithCopilot complex_poly_copilot({1, 0, 1});
    root_gpt = complex_poly_gpt.getRoot(1);  // Should handle gracefully or return NaN
    root_copilot = complex_poly_copilot.getRoot(1);
    cout << "Expected: NaN or appropriate indication of complex root" << endl; // Expected: NaN or appropriate indication of complex root
    cout << "Chat_GPT Test case 39 (Root of x^2 + 1): " << root_gpt << endl; // Output: NaN or appropriate indication of complex root
    cout << "Copilot Test case 39 (Root of x^2 + 1): " << root_copilot << endl;

// Test case 40: Derivative of a higher-degree polynomial
    derivative_gpt = poly11_gpt.derivative();
    derivative_copilot = poly11_copilot.derivative();
    cout << "Expected: Derivative polynomial representation" << endl; // Expected: Derivative polynomial representation
    cout << "Chat_GPT Test case 40 (Derivative of high-degree polynomial): " << derivative_gpt << endl; // Output: Derivative polynomial representation
    cout << "Copilot Test case 40 (Derivative of high-degree polynomial): " << derivative_copilot << endl; // Output: Derivative polynomial representation


// Test case 41: Definite integral of a polynomial from x=-1 to x=1
    definiteIntegral_gpt = poly1_gpt.integral(-1, 1);
    definiteIntegral_copilot = poly1_copilot.integral(-1, 1);
    cout << "Expected: Value of definite integral from -1 to 1" << endl; // Expected result of definite integral
    cout << "Chat_GPT Test case 41 (Definite Integral from -1 to 1): " << definiteIntegral_gpt << endl;
    cout << "Copilot Test case 41 (Definite Integral from -1 to 1): " << definiteIntegral_copilot << endl;

// Test case 42: Evaluation of polynomial at a large negative value
    value_gpt = poly1_gpt.evaluate(-100);
    value_copilot = poly1_copilot.evaluate(-100);
    cout << "Expected: Value of polynomial evaluated at x=-100" << endl; // Expected result of polynomial evaluated at x=-100
    cout << "Chat_GPT Test case 42 (Evaluation at x=-100): " << value_gpt << endl;
    cout << "Copilot Test case 42 (Evaluation at x=-100): " << value_copilot << endl;

// Test case 43: Addition of polynomials where one is a constant
    PolynomialWithChatGPT constant_poly_gpt({7});  // A constant polynomial 7
    PolynomialWithCopilot constant_poly_copilot({7});
    result_gpt = poly1_gpt + constant_poly_gpt;
    result_copilot = poly1_copilot + constant_poly_copilot;
    cout << "Expected: 15x^3 + 23x^2 + 13x + 11" << endl; // Expected: Result of adding a constant to the polynomial
    cout << "Chat_GPT Test case 43 (Addition with constant polynomial): " << result_gpt << endl;
    cout << "Copilot Test case 43 (Addition with constant polynomial): " << result_copilot << endl;

// Test case 44: Subtracting a constant polynomial from a higher-degree polynomial
    result_gpt = poly1_gpt - constant_poly_gpt;
    result_copilot = poly1_copilot - constant_poly_copilot;
    cout << "Expected: 15x^3 + 23x^2 + 13x - 3" << endl; // Expected: Result of subtracting a constant from the polynomial
    cout << "Chat_GPT Test case 44 (Subtraction with constant polynomial): " << result_gpt << endl;
    cout << "Copilot Test case 44 (Subtraction with constant polynomial): " << result_copilot << endl;

// Test case 45: Polynomial with fractional coefficients (e.g., 0.5x^2 + 0.25x + 0.75)
    PolynomialWithChatGPT fractional_poly_gpt({0.75, 0.25, 0.5});
    PolynomialWithCopilot fractional_poly_copilot({0.75, 0.25, 0.5});
    result_gpt = poly1_gpt + fractional_poly_gpt;
    result_copilot = poly1_copilot + fractional_poly_copilot;
    cout << "Expected: 15x^3 + 23.75x^2 + 13.25x + 4.75" << endl; // Expected: Result of adding polynomial with fractional coefficients
    cout << "Chat_GPT Test case 45 (Addition with fractional coefficients): " << result_gpt << endl;
    cout << "Copilot Test case 45 (Addition with fractional coefficients): " << result_copilot << endl;

// Test case 46: Subtraction of polynomial with fractional coefficients
    result_gpt = poly1_gpt - fractional_poly_gpt;
    result_copilot = poly1_copilot - fractional_poly_copilot;
    cout << "Expected: 15x^3 + 22.25x^2 + 12.75x + 3.25" << endl; // Expected: Result of subtracting polynomial with fractional coefficients
    cout << "Chat_GPT Test case 46 (Subtraction with fractional coefficients): " << result_gpt << endl;
    cout << "Copilot Test case 46 (Subtraction with fractional coefficients): " << result_copilot << endl;

// Test case 47: Multiplication of polynomial with fractional coefficients
    result_gpt = poly1_gpt * fractional_poly_gpt;
    result_copilot = poly1_copilot * fractional_poly_copilot;
    cout << "Expected: 15x^3 + 23.0x^2 + 13.0x + 4.5" << endl; // Expected: Result of multiplying polynomial with fractional coefficients
    cout << "Chat_GPT Test case 47 (Multiplication with fractional coefficients): " << result_gpt << endl;
    cout << "Copilot Test case 47 (Multiplication with fractional coefficients): " << result_copilot << endl;

// Test case 48: Derivative of polynomial with fractional coefficients
    derivative_gpt = fractional_poly_gpt.derivative();
    derivative_copilot = fractional_poly_copilot.derivative();
    cout << "Expected: 1.5x + 0.25" << endl; // Expected: Derivative of fractional polynomial
    cout << "Chat_GPT Test case 48 (Derivative of fractional polynomial): " << derivative_gpt << endl;
    cout << "Copilot Test case 48 (Derivative of fractional polynomial): " << derivative_copilot << endl;

// Test case 49: Evaluation of polynomial with fractional coefficients at x=1.5
    value_gpt = fractional_poly_gpt.evaluate(1.5);
    value_copilot = fractional_poly_copilot.evaluate(1.5);
    cout << "Expected: 1.6875" << endl; // Expected: Result of evaluating fractional polynomial at x=1.5
    cout << "Chat_GPT Test case 49 (Evaluation at x=1.5 for fractional polynomial): " << value_gpt << endl;
    cout << "Copilot Test case 49 (Evaluation at x=1.5 for fractional polynomial): " << value_copilot << endl;

// Test case 50: Definite integral of polynomial with fractional coefficients from x=0 to x=1
    definiteIntegral_gpt = fractional_poly_gpt.integral(0, 1);
    definiteIntegral_copilot = fractional_poly_copilot.integral(0, 1);
    cout << "Expected: 0.5" << endl; // Expected: Result of definite integral of fractional polynomial from 0 to 1
    cout << "Chat_GPT Test case 50 (Definite Integral of fractional polynomial from 0 to 1): " << definiteIntegral_gpt << endl;
    cout << "Copilot Test case 50 (Definite Integral of fractional polynomial from 0 to 1): " << definiteIntegral_copilot << endl;


// Test case 51: Evaluate a polynomial at a fractional value (e.g., x = 0.5)
    value_gpt = poly1_gpt.evaluate(0.5);
    value_copilot = poly1_copilot.evaluate(0.5);
    cout << "Expected: 2.25" << endl; // Expected: Value of polynomial at x=0.5
    cout << "Chat_GPT Test case 51 (Evaluation at x=0.5): " << value_gpt << endl;
    cout << "Copilot Test case 51 (Evaluation at x=0.5): " << value_copilot << endl;

// Test case 52: Adding a polynomial and its negative
    result_gpt = poly1_gpt + PolynomialWithChatGPT({-1, -2, -3});
    result_copilot = poly1_copilot + PolynomialWithCopilot({-1, -2, -3});
    cout << "Expected: 0" << endl; // Expected: Result of adding polynomial and its negative
    cout << "Chat_GPT Test case 52 (Adding polynomial and its negative): " << result_gpt << endl;
    cout << "Copilot Test case 52 (Adding polynomial and its negative): " << result_copilot << endl;

// Test case 53: Evaluating a polynomial at the root of a quadratic polynomial
    double root_quad = quadratic_gpt.getRoot(1); // Get root near 1
    value_gpt = poly1_gpt.evaluate(root_quad);
    value_copilot = poly1_copilot.evaluate(root_quad);
    cout << "Expected: Value at the root of the quadratic" << endl; // Expected: Value of polynomial at the root of the quadratic
    cout << "Chat_GPT Test case 53 (Evaluation at root of quadratic): " << value_gpt << endl;
    cout << "Copilot Test case 53 (Evaluation at root of quadratic): " << value_copilot << endl;

// Test case 54: Multiplication of a polynomial by 1
    result_gpt = poly1_gpt * PolynomialWithChatGPT({1});
    result_copilot = poly1_copilot * PolynomialWithCopilot({1});
    cout << "Expected: 15x^3 + 23x^2 + 13x + 4" << endl; // Expected: Result of multiplying polynomial by 1
    cout << "Chat_GPT Test case 54 (Multiplication by 1): " << result_gpt << endl;
    cout << "Copilot Test case 54 (Multiplication by 1): " << result_copilot << endl;

// Test case 55: High degree polynomial evaluation with leading coefficient 0
    vector<double> leading_zero_coeffs = {0, 2, 3}; // 3x + 2
    PolynomialWithChatGPT leading_zero_poly(leading_zero_coeffs);
    value_gpt = leading_zero_poly.evaluate(5);
    value_copilot = leading_zero_poly.evaluate(5);
    cout << "Expected: 17" << endl; // Expected: Value of 3x + 2 at x=5
    cout << "Chat_GPT Test case 55 (High degree poly with leading zero): " << value_gpt << endl;
    cout << "Copilot Test case 55 (High degree poly with leading zero): " << value_copilot << endl;

// Test case 56: Evaluate polynomial with all coefficients zero
    vector<double> all_zero_coeffs = {0, 0, 0}; // 0
    PolynomialWithChatGPT zero_poly(all_zero_coeffs);
    value_gpt = zero_poly.evaluate(10);
    value_copilot = zero_poly.evaluate(10);
    cout << "Expected: 0" << endl; // Expected: Evaluation of zero polynomial
    cout << "Chat_GPT Test case 56 (Evaluation of zero polynomial): " << value_gpt << endl;
    cout << "Copilot Test case 56 (Evaluation of zero polynomial): " << value_copilot << endl;

// Test case 57: Evaluate polynomial at a very small positive value (e.g., x = 0.00001)
    value_gpt = poly1_gpt.evaluate(0.00001);
    value_copilot = poly1_copilot.evaluate(0.00001);
    cout << "Expected: Close to 1" << endl; // Expected: Value at a very small x
    cout << "Chat_GPT Test case 57 (Evaluation at x=0.00001): " << value_gpt << endl;
    cout << "Copilot Test case 57 (Evaluation at x=0.00001): " << value_copilot << endl;

// Test case 58: Check polynomial equality after altering coefficients
    poly1_gpt.setCoefficients({1, 2, 3});
    poly1_copilot.setCoefficients({1, 2, 3});
    isEqual = (poly1_gpt == poly1_gpt);
    cout << "Expected: true" << endl; // Expected: Equality should hold
    cout << "Chat_GPT Test case 58 (Equality after altering coefficients): " << isEqual << endl;
    isEqual = (poly1_copilot == poly1_copilot);
    cout << "Copilot Test case 58 (Equality after altering coefficients): " << isEqual << endl;

// Test case 59: Evaluate polynomial at boundary of domain (e.g., x = INFINITY)
    value_gpt = poly1_gpt.evaluate(INFINITY);
    value_copilot = poly1_copilot.evaluate(INFINITY);
    cout << "Expected: Inf" << endl; // Expected: Value at infinity
    cout << "Chat_GPT Test case 59 (Evaluation at x=INFINITY): " << value_gpt << endl;
    cout << "Copilot Test case 59 (Evaluation at x=INFINITY): " << value_copilot << endl;

// Test case 60: Evaluate polynomial at boundary of domain (e.g., x = -INFINITY)
    value_gpt = poly1_gpt.evaluate(-INFINITY);
    value_copilot = poly1_copilot.evaluate(-INFINITY);
    cout << "Expected: -Inf" << endl; // Expected: Value at negative infinity
    cout << "Chat_GPT Test case 60 (Evaluation at x=-INFINITY): " << value_gpt << endl;
    cout << "Copilot Test case 60 (Evaluation at x=-INFINITY): " << value_copilot << endl;

// Test case 61: Evaluate derivative at specific point
    derivative_gpt = poly1_gpt.derivative();
    value_gpt = derivative_gpt.evaluate(1);
    derivative_copilot = poly1_copilot.derivative();
    value_copilot = derivative_copilot.evaluate(1);
    cout << "Expected: 8" << endl; // Expected: Derivative evaluated at x=1
    cout << "Chat_GPT Test case 61 (Derivative evaluation at x=1): " << value_gpt << endl;
    cout << "Copilot Test case 61 (Derivative evaluation at x=1): " << value_copilot << endl;

// Test case 62: Check if the polynomial evaluates correctly at zero
    value_gpt = poly1_gpt.evaluate(0);
    value_copilot = poly1_copilot.evaluate(0);
    cout << "Expected: 4" << endl; // Expected: Value of polynomial at x=0
    cout << "Chat_GPT Test case 62 (Evaluation at x=0): " << value_gpt << endl;
    cout << "Copilot Test case 62 (Evaluation at x=0): " << value_copilot << endl;

// Test case 63: Evaluate polynomial at a negative number (e.g., x = -3)
    value_gpt = poly1_gpt.evaluate(-3);
    value_copilot = poly1_copilot.evaluate(-3);
    cout << "Expected: Positive or negative based on coefficients" << endl; // Expected: Depends on the coefficients of the polynomial
    cout << "Chat_GPT Test case 63 (Evaluation at x=-3): " << value_gpt << endl;
    cout << "Copilot Test case 63 (Evaluation at x=-3): " << value_copilot << endl;

// Test case 64: Check multiplication with zero polynomial
    result_gpt = poly1_gpt * PolynomialWithChatGPT({0});
    result_copilot = poly1_copilot * PolynomialWithCopilot({0});
    cout << "Expected: 0" << endl; // Expected: Result of multiplying by zero polynomial
    cout << "Chat_GPT Test case 64 (Multiplication by zero polynomial): " << result_gpt << endl;
    cout << "Copilot Test case 64 (Multiplication by zero polynomial): " << result_copilot << endl;

// Test case 65: Check for polynomial equality after a series of operations
    poly1_gpt.setCoefficients({1, 2});
    poly2_gpt.setCoefficients({1, 2});
    isEqual = (poly1_gpt == poly2_gpt);
    cout << "Expected: true" << endl; // Expected: Should be true as coefficients are equal
    cout << "Chat_GPT Test case 65 (Equality after operations): " << isEqual << endl;
    isEqual = (poly1_copilot == poly2_copilot);
    cout << "Copilot Test case 65 (Equality after operations): " << isEqual << endl;

// Test case 66: Check for equality of polynomials with different representations
    poly1_gpt.setCoefficients({1, 2, 3});
    poly2_gpt.setCoefficients({1, 2, 3});
    isEqual = (poly1_gpt == poly2_gpt);
    cout << "Expected: true" << endl; // Expected: Should be true as coefficients are equal
    cout << "Chat_GPT Test case 66 (Equality with different representations): " << isEqual << endl;
    isEqual = (poly1_copilot == poly2_copilot);
    cout << "Copilot Test case 66 (Equality with different representations): " << isEqual << endl;

// Test case 67: Check for evaluation at a large number
    value_gpt = poly1_gpt.evaluate(1e6);
    value_copilot = poly1_copilot.evaluate(1e6);
    cout << "Expected: Very large number" << endl; // Expected: Value should be very large, depending on polynomial coefficients
    cout << "Chat_GPT Test case 67 (Evaluation at large number): " << value_gpt << endl;
    cout << "Copilot Test case 67 (Evaluation at large number): " << value_copilot << endl;

// Test case 68: Check if two identical polynomials are equal
    isEqual = (poly1_gpt == poly1_gpt);
    cout << "Expected: true" << endl; // Expected: Should be true as they are identical
    cout << "Chat_GPT Test case 68 (Identical polynomials): " << isEqual << endl;
    isEqual = (poly1_copilot == poly1_copilot);
    cout << "Copilot Test case 68 (Identical polynomials): " << isEqual << endl;

// Test case 69: Test polynomial subtraction
    result_gpt = poly1_gpt - poly2_gpt;
    result_copilot = poly1_copilot - poly2_copilot;
    cout << "Expected: 0" << endl; // Expected: Result of subtraction should equal zero polynomial if they are equal
    cout << "Chat_GPT Test case 69 (Subtraction): " << result_gpt << endl;
    cout << "Copilot Test case 69 (Subtraction): " << result_copilot << endl;



// Test case 70: Composing two polynomials (e.g., f(x) = x^2, g(x) = 2x + 3; f(g(x)))
    PolynomialWithChatGPT f_poly({0, 1, 0}); // Represents x^2
    PolynomialWithChatGPT g_poly({3, 2});    // Represents 2x + 3
    PolynomialWithChatGPT composed_poly_gpt = f_poly.compose(g_poly); // f(g(x))
    double value_composed_gpt = composed_poly_gpt.evaluate(1); // Evaluate at x = 1
    PolynomialWithCopilot f_poly_copilot({0, 1, 0}); // Represents x^2 for Copilot
    PolynomialWithCopilot g_poly_copilot({3, 2});    // Represents 2x + 3 for Copilot
    PolynomialWithCopilot composed_poly_copilot = f_poly_copilot.compose(g_poly_copilot); // f(g(x))
    double value_composed_copilot = composed_poly_copilot.evaluate(1); // Evaluate at x = 1
    cout << "Expected: 25" << endl; // f(g(1)) = f(5) = 5^2 = 25
    cout << "Chat_GPT Test case 70 (Composition of polynomials): " << value_composed_gpt << endl;
    cout << "Copilot Test case 70 (Composition of polynomials): " << value_composed_copilot << endl;

// Test case 71: Composing polynomials with a constant (e.g., f(x) = x + 1, g(x) = 3)
    PolynomialWithChatGPT const_poly({3}); // Represents constant polynomial 3
    PolynomialWithChatGPT f_poly2({1, 1}); // Represents x + 1
    PolynomialWithChatGPT composed_poly2_gpt = f_poly2.compose(const_poly); // f(3)
    double value_composed2_gpt = composed_poly2_gpt.evaluate(0); // Evaluate f(3)
    PolynomialWithCopilot const_poly_copilot({3}); // Represents constant polynomial 3 for Copilot
    PolynomialWithCopilot f_poly2_copilot({1, 1}); // Represents x + 1 for Copilot
    PolynomialWithCopilot composed_poly2_copilot = f_poly2_copilot.compose(const_poly_copilot); // f(3)
    double value_composed2_copilot = composed_poly2_copilot.evaluate(0); // Evaluate f(3)
    cout << "Expected: 4" << endl; // f(3) = 3 + 1 = 4
    cout << "Chat_GPT Test case 71 (Composition with constant polynomial): " << value_composed2_gpt << endl;
    cout << "Copilot Test case 71 (Composition with constant polynomial): " << value_composed2_copilot << endl;

// Test case 72: Composing polynomials where f(x) = x^3 and g(x) = x^2 + 1
    PolynomialWithChatGPT f_poly3({0, 0, 0, 1}); // Represents x^3
    PolynomialWithChatGPT g_poly2({1, 0, 1});    // Represents x^2 + 1
    PolynomialWithChatGPT composed_poly3_gpt = f_poly3.compose(g_poly2); // f(g(x))
    double value_composed3_gpt = composed_poly3_gpt.evaluate(1); // Evaluate f(g(1)) = f(2) = 2^3 = 8
    PolynomialWithCopilot f_poly3_copilot({0, 0, 0, 1}); // Represents x^3 for Copilot
    PolynomialWithCopilot g_poly2_copilot({1, 0, 1});    // Represents x^2 + 1 for Copilot
    PolynomialWithCopilot composed_poly3_copilot = f_poly3_copilot.compose(g_poly2_copilot); // f(g(x))
    double value_composed3_copilot = composed_poly3_copilot.evaluate(1); // Evaluate f(g(1)) = f(2) = 2^3 = 8
    cout << "Expected: 8" << endl;
    cout << "Chat_GPT Test case 72 (Composition of higher degree polynomials): " << value_composed3_gpt << endl;
    cout << "Copilot Test case 72 (Composition of higher degree polynomials): " << value_composed3_copilot << endl;

// Test case 73: Composition resulting in a polynomial of higher degree (e.g., f(x) = x^2, g(x) = x)
    PolynomialWithChatGPT f_poly4({0, 0, 1}); // Represents x^2
    PolynomialWithChatGPT g_poly3({0, 1});     // Represents x
    PolynomialWithChatGPT composed_poly4_gpt = f_poly4.compose(g_poly3); // f(g(x)) = (g(x))^2
    double value_composed4_gpt = composed_poly4_gpt.evaluate(2); // Evaluate f(g(2)) = f(2) = 2^2 = 4
    PolynomialWithCopilot f_poly4_copilot({0, 0, 1}); // Represents x^2 for Copilot
    PolynomialWithCopilot g_poly3_copilot({0, 1});     // Represents x for Copilot
    PolynomialWithCopilot composed_poly4_copilot = f_poly4_copilot.compose(g_poly3_copilot); // f(g(x)) = (g(x))^2
    double value_composed4_copilot = composed_poly4_copilot.evaluate(2); // Evaluate f(g(2)) = f(2) = 2^2 = 4
    cout << "Expected: 4" << endl;
    cout << "Chat_GPT Test case 73 (Composition leading to higher degree polynomial): " << value_composed4_gpt << endl;
    cout << "Copilot Test case 73 (Composition leading to higher degree polynomial): " << value_composed4_copilot << endl;

// Test case 74: Evaluate polynomial at a positive integer (e.g., x = 5)
    PolynomialWithChatGPT poly1({4, 3, 2, 1}); // Represents 4 + 3x + 2x^2 + 1x^3
    double value_at_5_gpt = poly1.evaluate(5); // Evaluate at x = 5
    double value_at_5_copilot = poly1_copilot.evaluate(5); // Evaluate at x = 5
    cout << "Expected: 4 + 15 + 50 + 125 = 194" << endl;
    cout << "Chat_GPT Test case 74 (Evaluation at x=5): " << value_at_5_gpt << endl;
    cout << "Copilot Test case 74 (Evaluation at x=5): " << value_at_5_copilot << endl;

// Test case 75: Evaluate polynomial at zero (e.g., x = 0)
    double value_at_0_gpt = poly1.evaluate(0); // Should give the constant term
    double value_at_0_copilot = poly1_copilot.evaluate(0); // Should give the constant term
    cout << "Expected: 4" << endl;
    cout << "Chat_GPT Test case 75 (Evaluation at x=0): " << value_at_0_gpt << endl;
    cout << "Copilot Test case 75 (Evaluation at x=0): " << value_at_0_copilot << endl;

// Test case 76: Evaluate polynomial at a negative integer (e.g., x = -2)
    double value_at_neg2_gpt = poly1.evaluate(-2); // Evaluate at x = -2
    double value_at_neg2_copilot = poly1_copilot.evaluate(-2); // Evaluate at x = -2
    cout << "Expected: 4 - 6 + 8 - 8 = -2" << endl;
    cout << "Chat_GPT Test case 76 (Evaluation at x=-2): " << value_at_neg2_gpt << endl;
    cout << "Copilot Test case 76 (Evaluation at x=-2): " << value_at_neg2_copilot << endl;

// Test case 77: Evaluate polynomial at a fraction (e.g., x = 0.5)
    double value_at_half_gpt = poly1.evaluate(0.5); // Evaluate at x = 0.5
    double value_at_half_copilot = poly1_copilot.evaluate(0.5); // Evaluate at x = 0.5
    cout << "Expected: 4 + 1.5 + 0.5 + 0.125 = 6.125" << endl;
    cout << "Chat_GPT Test case 77 (Evaluation at x=0.5): " << value_at_half_gpt << endl;
    cout << "Copilot Test case 77 (Evaluation at x=0.5): " << value_at_half_copilot << endl;

// Test case 78: Evaluate polynomial at a very large number (e.g., x = 1e6)
    double value_at_large_gpt = poly1.evaluate(1e6); // Evaluate at x = 1e6
    double value_at_large_copilot = poly1_copilot.evaluate(1e6); // Evaluate at x = 1e6
    cout << "Expected: Large number" << endl; // Expected: Large value
    cout << "Chat_GPT Test case 78 (Evaluation at x=1e6): " << value_at_large_gpt << endl;
    cout << "Copilot Test case 78 (Evaluation at x=1e6): " << value_at_large_copilot << endl;

// Test case 79: Evaluate polynomial at a very small positive value (e.g., x = 0.0001)
    double value_at_small_gpt = poly1.evaluate(0.0001); // Evaluate at x = 0.0001
    double value_at_small_copilot = poly1_copilot.evaluate(0.0001); // Evaluate at x = 0.0001
    cout << "Expected: 4 + 0.0003 + 0.00000002 + 0.000000000001 = Close to 4" << endl;
    cout << "Chat_GPT Test case 79 (Evaluation at x=0.0001): " << value_at_small_gpt << endl;
    cout << "Copilot Test case 79 (Evaluation at x=0.0001): " << value_at_small_copilot << endl;

// Test case 80: Evaluate polynomial at infinity (e.g., x = INFINITY)
    double value_infinity_gpt = poly1.evaluate(INFINITY); // Should give a very large number
    double value_infinity_copilot = poly1_copilot.evaluate(INFINITY); // Should give a very large number
    cout << "Expected: Inf" << endl;
    cout << "Chat_GPT Test case 80 (Evaluation at x=INFINITY): " << value_infinity_gpt << endl;
    cout << "Copilot Test case 80 (Evaluation at x=INFINITY): " << value_infinity_copilot << endl;

// Test case 81: Evaluate polynomial at negative infinity (e.g., x = -INFINITY)
    double value_neg_infinity_gpt = poly1.evaluate(-INFINITY); // Should give a very negative number
    double value_neg_infinity_copilot = poly1_copilot.evaluate(-INFINITY); // Should give a very negative number
    cout << "Expected: -Inf" << endl;
    cout << "Chat_GPT Test case 81 (Evaluation at x=-INFINITY): " << value_neg_infinity_gpt << endl;
    cout << "Copilot Test case 81 (Evaluation at x=-INFINITY): " << value_neg_infinity_copilot << endl;

// Test case 82: Definite integral of a polynomial from x=0 to x=1
    PolynomialWithChatGPT polY1({1, 2, 3}); // Represents 1 + 2x + 3x^2
    PolynomialWithCopilot polY1_copilot({1, 2, 3});
    double definiteIntegral_0_to_1_gpt = polY1.integral(0, 1); // Evaluate integral from 0 to 1
    double definiteIntegral_0_to_1_copilot = polY1_copilot.integral(0, 1); // Evaluate integral from 0 to 1
    cout << "Expected: [x + x^2 + x^3] from 0 to 1 = 1 + 1 + 1 = 3" << endl;
    cout << "Chat_GPT Test case 82 (Definite Integral from 0 to 1): " << definiteIntegral_0_to_1_gpt << endl;
    cout << "Copilot Test case 82 (Definite Integral from 0 to 1): " << definiteIntegral_0_to_1_copilot << endl;

// Test case 83: Definite integral of a polynomial from x=1 to x=2
    double definiteIntegral_1_to_2_gpt = polY1.integral(1, 2); // Evaluate integral from 1 to 2
    double definiteIntegral_1_to_2_copilot = polY1_copilot.integral(1, 2); // Evaluate integral from 1 to 2
    cout << "Expected: [x + x^2 + x^3] from 1 to 2 = (2 + 4 + 8) - (1 + 1 + 1) = 13 - 3 = 10" << endl;
    cout << "Chat_GPT Test case 83 (Definite Integral from 1 to 2): " << definiteIntegral_1_to_2_gpt << endl;
    cout << "Copilot Test case 83 (Definite Integral from 1 to 2): " << definiteIntegral_1_to_2_copilot << endl;

// Test case 84: Indefinite integral of a polynomial
    auto indefiniteIntegral_gpt = polY1.integral(); // Evaluate indefinite integral
    auto indefiniteIntegral_copilot = polY1_copilot.integral(); // Evaluate indefinite integral
    cout << "Expected: x + x^2 + x^3 + C" << endl;
    cout << "Chat_GPT Test case 84 (Indefinite Integral): " << indefiniteIntegral_gpt << endl;
    cout << "Copilot Test case 84 (Indefinite Integral): " << indefiniteIntegral_copilot << endl;

// Test case 85: Definite integral of a constant polynomial (e.g., f(x) = 5) from x=0 to x=3
    PolynomialWithChatGPT constant_poly({5}); // Represents f(x) = 5
    PolynomialWithCopilot Constant_poly_copilot({5}); // Represents f(x) = 5
    double definiteIntegral_constant_gpt = constant_poly.integral(0, 3); // Evaluate integral from 0 to 3
    double definiteIntegral_constant_copilot = constant_poly_copilot.integral(0, 3); // Evaluate integral from 0 to 3
    cout << "Expected: 5 * (3 - 0) = 15" << endl;
    cout << "Chat_GPT Test case 85 (Definite Integral of constant polynomial): " << definiteIntegral_constant_gpt << endl;
    cout << "Copilot Test case 85 (Definite Integral of constant polynomial): " << definiteIntegral_constant_copilot << endl;

// Test case 86: Definite integral of a polynomial with negative coefficients from x=-1 to x=0
    PolynomialWithChatGPT negative_poly({1, -2, -3}); // Represents 1 - 2x - 3x^2
    PolynomialWithCopilot negative_poly_copilot({1, -2, -3}); // Represents 1 - 2x - 3x^2
    double definiteIntegral_neg_gpt = negative_poly.integral(-1, 0); // Evaluate integral from -1 to 0
    double definiteIntegral_neg_copilot = negative_poly_copilot.integral(-1, 0); // Evaluate integral from -1 to 0
    cout << "Expected: [x - x^2 - x^3] from -1 to 0 = (0 - 0 - 0) - (-1 + 1 + 0) = 1" << endl;
    cout << "Chat_GPT Test case 86 (Definite Integral of negative polynomial): " << definiteIntegral_neg_gpt << endl;
    cout << "Copilot Test case 86 (Definite Integral of negative polynomial): " << definiteIntegral_neg_copilot << endl;

// Test case 87: Evaluate the integral at the boundaries (e.g., x = -INFINITY to x = INFINITY)
    double definiteIntegral_infinity_gpt = poly1.integral(-INFINITY, INFINITY); // Evaluate integral from -INFINITY to INFINITY
    double definiteIntegral_infinity_copilot = poly1_copilot.integral(-INFINITY, INFINITY); // Evaluate integral from -INFINITY to INFINITY
    cout << "Expected: Undefined for non-zero polynomial" << endl;
    cout << "Chat_GPT Test case 87 (Definite Integral from -Inf to Inf): " << definiteIntegral_infinity_gpt << endl;
    cout << "Copilot Test case 87 (Definite Integral from -Inf to Inf): " << definiteIntegral_infinity_copilot << endl;

// Test case 88: Definite integral of a polynomial with fractional coefficients from x=0 to x=1
    PolynomialWithChatGPT fractional_poly({0.5, 0.25, 0.75}); // Represents 0.5 + 0.25x + 0.75x^2
    PolynomialWithCopilot Fractional_poly_copilot({0.5, 0.25, 0.75}); // Represents 0.5 + 0.25x + 0.75x^2
    double definiteIntegral_fractional_gpt = fractional_poly.integral(0, 1); // Evaluate integral from 0 to 1
    double definiteIntegral_fractional_copilot = fractional_poly_copilot.integral(0, 1); // Evaluate integral from 0 to 1
    cout << "Expected: [0.5x + (0.25/2)x^2 + (0.75/3)x^3] from 0 to 1 = 0.5 + 0.125 + 0.25 = 0.875" << endl;
    cout << "Chat_GPT Test case 88 (Definite Integral of fractional polynomial): " << definiteIntegral_fractional_gpt << endl;
    cout << "Copilot Test case 88 (Definite Integral of fractional polynomial): " << definiteIntegral_fractional_copilot << endl;

// Test case 89: Definite integral of a higher-degree polynomial (e.g., x^4 + 2x^3 + x^2) from x=0 to x=2
    PolynomialWithChatGPT higher_degree_poly({0, 1, 2, 0, 1}); // Represents x^4 + 2x^3 + x^2
    PolynomialWithCopilot higher_degree_poly_copilot({0, 1, 2, 0, 1}); // Represents x^4 + 2x^3 + x^2
    double definiteIntegral_higher_degree_gpt = higher_degree_poly.integral(0, 2); // Evaluate integral from 0 to 2
    double definiteIntegral_higher_degree_copilot = higher_degree_poly_copilot.integral(0, 2); // Evaluate integral from 0 to 2
    cout << "Expected: [1/5x^5 + (1/2)x^4 + (1/3)x^3] from 0 to 2 = (32/5 + 16 + 8/3) = 12.0667" << endl;
    cout << "Chat_GPT Test case 89 (Definite Integral of higher-degree polynomial): " << definiteIntegral_higher_degree_gpt << endl;
    cout << "Copilot Test case 89 (Definite Integral of higher-degree polynomial): " << definiteIntegral_higher_degree_copilot << endl;


// Test case 90: Derivative of a constant polynomial (f(x) = 5)
    PolynomialWithChatGPT constant_poly_derivative({5}); // Represents f(x) = 5
    PolynomialWithCopilot constant_poly_derivative_copilot({5}); // Represents f(x) = 5
    auto derivative_constant_gpt = constant_poly_derivative.derivative(); // Derivative
    auto derivative_constant_copilot = constant_poly_derivative_copilot.derivative(); // Derivative
    cout << "Expected: 0" << endl;
    cout << "Chat_GPT Test case 90 (Derivative of constant polynomial): " << derivative_constant_gpt << endl;
    cout << "Copilot Test case 90 (Derivative of constant polynomial): " << derivative_constant_copilot << endl;

// Test case 91: Derivative of a linear polynomial (f(x) = 3x + 2)
    PolynomialWithChatGPT linear_poly_derivative({2, 3}); // Represents f(x) = 3x + 2
    PolynomialWithCopilot linear_poly_derivative_copilot({2, 3}); // Represents f(x) = 3x + 2
    auto derivative_linear_gpt = linear_poly_derivative.derivative(); // Derivative
    auto derivative_linear_copilot = linear_poly_derivative_copilot.derivative(); // Derivative
    cout << "Expected: 3" << endl;
    cout << "Chat_GPT Test case 91 (Derivative of linear polynomial): " << derivative_linear_gpt << endl;
    cout << "Copilot Test case 91 (Derivative of linear polynomial): " << derivative_linear_copilot << endl;

// Test case 92: Derivative of a quadratic polynomial (f(x) = x^2 + 2x + 1)
    PolynomialWithChatGPT quadratic_poly_derivative({1, 2, 1}); // Represents f(x) = x^2 + 2x + 1
    PolynomialWithCopilot quadratic_poly_derivative_copilot({1, 2, 1}); // Represents f(x) = x^2 + 2x + 1
    auto derivative_quadratic_gpt = quadratic_poly_derivative.derivative(); // Derivative
    auto derivative_quadratic_copilot = quadratic_poly_derivative_copilot.derivative(); // Derivative
    cout << "Expected: 2x + 2" << endl; // Should evaluate to 2x + 2
    cout << "Chat_GPT Test case 92 (Derivative of quadratic polynomial): " << derivative_quadratic_gpt << endl;
    cout << "Copilot Test case 92 (Derivative of quadratic polynomial): " << derivative_quadratic_copilot << endl;

// Test case 93: Derivative of a cubic polynomial (f(x) = x^3 - 3x^2 + 2)
    PolynomialWithChatGPT cubic_poly_derivative({2, 0, -3, 1}); // Represents f(x) = x^3 - 3x^2 + 2
    PolynomialWithCopilot cubic_poly_derivative_copilot({2, 0, -3, 1}); // Represents f(x) = x^3 - 3x^2 + 2
    auto derivative_cubic_gpt = cubic_poly_derivative.derivative(); // Derivative
    auto derivative_cubic_copilot = cubic_poly_derivative_copilot.derivative(); // Derivative
    cout << "Expected: 3x^2 - 6x" << endl; // Should evaluate to 3x^2 - 6x
    cout << "Chat_GPT Test case 93 (Derivative of cubic polynomial): " << derivative_cubic_gpt << endl;
    cout << "Copilot Test case 93 (Derivative of cubic polynomial): " << derivative_cubic_copilot << endl;

// Test case 94: Derivative of a polynomial with a higher degree (f(x) = 2x^4 + 3x^3 + x)
    PolynomialWithChatGPT higher_degree_poly_derivative({0, 1, 0, 3, 2}); // Represents f(x) = 2x^4 + 3x^3 + x
    PolynomialWithCopilot higher_degree_poly_derivative_copilot({0, 1, 0, 3, 2}); // Represents f(x) = 2x^4 + 3x^3 + x
    auto derivative_higher_degree_gpt = higher_degree_poly_derivative.derivative(); // Derivative
    auto derivative_higher_degree_copilot = higher_degree_poly_derivative_copilot.derivative(); // Derivative
    cout << "Expected: 8x^3 + 9x^2 + 1" << endl; // Should evaluate to 8x^3 + 9x^2 + 1
    cout << "Chat_GPT Test case 94 (Derivative of higher-degree polynomial): " << derivative_higher_degree_gpt << endl;
    cout << "Copilot Test case 94 (Derivative of higher-degree polynomial): " << derivative_higher_degree_copilot << endl;

// Test case 95: Evaluate derivative at a specific point (e.g., f(x) = x^2 + 2x at x = 1)
    double point_value = 1;
    double eval_derivative_quadratic_gpt = quadratic_poly_derivative.derivative().evaluate(point_value); // Evaluate at x = 1
    double eval_derivative_quadratic_copilot = quadratic_poly_derivative_copilot.derivative().evaluate(point_value); // Evaluate at x = 1
    cout << "Expected: 2(1) + 2 = 4" << endl;
    cout << "Chat_GPT Test case 95 (Evaluate derivative of quadratic at x=1): " << eval_derivative_quadratic_gpt << endl;
    cout << "Copilot Test case 95 (Evaluate derivative of quadratic at x=1): " << eval_derivative_quadratic_copilot << endl;

// Test case 96: Evaluate derivative at another point (e.g., f(x) = x^3 - 4x at x = 2)
    PolynomialWithChatGPT cubic_poly2_derivative({0, -4, 0, 1}); // Represents f(x) = x^3 - 4x
    PolynomialWithCopilot cubic_poly2_derivative_copilot({0, -4, 0, 1}); // Represents f(x) = x^3 - 4x
    double eval_derivative_cubic_gpt = cubic_poly2_derivative.derivative().evaluate(2); // Evaluate at x = 2
    double eval_derivative_cubic_copilot = cubic_poly2_derivative_copilot.derivative().evaluate(2); // Evaluate at x = 2
    cout << "Expected: 3(2^2) - 4 = 12 - 4 = 8" << endl;
    cout << "Chat_GPT Test case 96 (Evaluate derivative of cubic at x=2): " << eval_derivative_cubic_gpt << endl;
    cout << "Copilot Test case 96 (Evaluate derivative of cubic at x=2): " << eval_derivative_cubic_copilot << endl;


}



void displayMenu() {
    cout << "\n---- Polynomial Operations Menu ----" << endl;
    cout << "1. Add Polynomials" << endl;
    cout << "2. Subtract Polynomials" << endl;
    cout << "3. Multiply Polynomials" << endl;
    cout << "4. Evaluate Polynomial at a Point" << endl;
    cout << "5. Find Derivative" << endl;
    cout << "6. Find Integral (Definite and Indefinite)" << endl;
    cout << "7. Find Root using Newton's Method" << endl;
    cout << "8. Compose Two Polynomials" << endl;
    cout << "9. Run Hardcoded Test Cases" << endl;
    cout << "10. Exit" << endl;
    cout << "Select an option: ";
}

void getPolynomialCoefficients(vector<double>& coeffs) {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;
    coeffs.resize(degree + 1);
    for (int i = 0; i <= degree; ++i) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coeffs[i];
    }
}
int main() {
    int choice;
    vector<double> coeffs1, coeffs2;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 10) {
            cout << "Exiting..." << endl;
            break;
        }
//
        switch (choice) {
            case 1: {
                cout << "\nEnter coefficients for the first polynomial:" << endl;
                getPolynomialCoefficients(coeffs1);
                cout << "\nEnter coefficients for the second polynomial:" << endl;
                getPolynomialCoefficients(coeffs2);

                PolynomialWithChatGPT poly1ChatGPT(coeffs1), poly2ChatGPT(coeffs2);
                PolynomialWithCopilot poly1Copilot(coeffs1), poly2Copilot(coeffs2);

                cout << "\nResult of addition:" << endl;
                cout << "ChatGPT: " << (poly1ChatGPT + poly2ChatGPT) << endl;
                cout << "Copilot: " << (poly1Copilot + poly2Copilot) << endl;
                break;
            }
            case 2: {
                cout << "\nEnter coefficients for the first polynomial:" << endl;
                getPolynomialCoefficients(coeffs1);
                cout << "\nEnter coefficients for the second polynomial:" << endl;
                getPolynomialCoefficients(coeffs2);

                PolynomialWithChatGPT poly1ChatGPT(coeffs1), poly2ChatGPT(coeffs2);
                PolynomialWithCopilot poly1Copilot(coeffs1), poly2Copilot(coeffs2);

                cout << "\nResult of subtraction:" << endl;
                cout << "ChatGPT: " << (poly1ChatGPT - poly2ChatGPT) << endl;
                cout << "Copilot: " << (poly1Copilot - poly2Copilot) << endl;
                break;
            }
            case 3: {
                cout << "\nEnter coefficients for the first polynomial:" << endl;
                getPolynomialCoefficients(coeffs1);
                cout << "\nEnter coefficients for the second polynomial:" << endl;
                getPolynomialCoefficients(coeffs2);

                PolynomialWithChatGPT poly1ChatGPT(coeffs1), poly2ChatGPT(coeffs2);
                PolynomialWithCopilot poly1Copilot(coeffs1), poly2Copilot(coeffs2);

                cout << "\nResult of multiplication:" << endl;
                cout << "ChatGPT: " << (poly1ChatGPT * poly2ChatGPT) << endl;
                cout << "Copilot: " << (poly1Copilot * poly2Copilot) << endl;
                break;
            }
            case 4: {
                cout << "\nEnter coefficients for the polynomial:" << endl;
                getPolynomialCoefficients(coeffs1);

                double x;
                cout << "Enter the value of x: ";
                cin >> x;

                PolynomialWithChatGPT polyChatGPT(coeffs1);
                PolynomialWithCopilot polyCopilot(coeffs1);

                cout << "Polynomial evaluated at x = " << x << " is:" << endl;
                cout << "ChatGPT: " << polyChatGPT.evaluate(x) << endl;
                cout << "Copilot: " << polyCopilot.evaluate(x) << endl;
                break;
            }
            case 5: {
                cout << "\nEnter coefficients for the polynomial:" << endl;
                getPolynomialCoefficients(coeffs1);

                PolynomialWithChatGPT polyChatGPT(coeffs1);
                PolynomialWithCopilot polyCopilot(coeffs1);

                cout << "Derivative of the polynomial:" << endl;
                cout << "ChatGPT: " << polyChatGPT.derivative() << endl;
                cout << "Copilot: " << polyCopilot.derivative() << endl;
                break;
            }
            case 6: {
                cout << "\nEnter coefficients for the polynomial:" << endl;
                getPolynomialCoefficients(coeffs1);

                PolynomialWithChatGPT polyChatGPT(coeffs1);
                PolynomialWithCopilot polyCopilot(coeffs1);

                cout << "Indefinite integral of the polynomial:" << endl;
                cout << "ChatGPT: " << polyChatGPT.integral() << endl;
                cout << "Copilot: " << polyCopilot.integral() << endl;

                double x1, x2;
                cout << "Enter lower limit for definite integral: ";
                cin >> x1;
                cout << "Enter upper limit for definite integral: ";
                cin >> x2;

                cout << "Definite integral from " << x1 << " to " << x2 << " is:" << endl;
                cout << "ChatGPT: " << polyChatGPT.integral(x1, x2) << endl;
                cout << "Copilot: " << polyCopilot.integral(x1, x2) << endl;
                break;
            }
            case 7: {
                cout << "\nEnter coefficients for the polynomial:" << endl;
                getPolynomialCoefficients(coeffs1);

                PolynomialWithChatGPT polyChatGPT(coeffs1);
                PolynomialWithCopilot polyCopilot(coeffs1);

                double guess;
                cout << "Enter initial guess for root: ";
                cin >> guess;

                try {
                    cout << "Root of the polynomial:" << endl;
                    cout << "ChatGPT: " << polyChatGPT.getRoot(guess) << endl;
                    cout << "Copilot: " << polyCopilot.getRoot(guess) << endl;
                } catch (const exception &e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 8: {
                cout << "\nEnter coefficients for the first polynomial (p):" << endl;
                getPolynomialCoefficients(coeffs1);
                cout << "\nEnter coefficients for the second polynomial (q):" << endl;
                getPolynomialCoefficients(coeffs2);

                PolynomialWithChatGPT pChatGPT(coeffs1), qChatGPT(coeffs2);
                PolynomialWithCopilot pCopilot(coeffs1), qCopilot(coeffs2);

                cout << "\nResult of composition p(q(x)):" << endl;
                cout << "ChatGPT: " << pChatGPT.compose(qChatGPT) << endl;
                cout << "Copilot: " << pCopilot.compose(qCopilot) << endl;
                break;
            }
            case 9: {
                runHardCodedTestCases();
                break;
            }
        }
    }
}



