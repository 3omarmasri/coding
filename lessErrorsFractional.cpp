#include <iostream>
#include <regex>
#include <string>
#include <numeric>
#include <cctype>
#include <stdexcept>
// error: whole number
using namespace std;

// Structure definition
struct Rational {
    int numerator;
    int denominator;
};

// Function prototype
Rational parseFraction(const string& fraction);
Rational add(Rational a, Rational b);
Rational subtract(Rational a, Rational b);
Rational multiply(Rational a, Rational b);
Rational divide(Rational a, Rational b);
void simplify(Rational& rational);

// Function definition
Rational parseFraction(const string& fraction) {
    regex pattern("(-?\\d+)/(-?\\d+)");
    smatch match;
    if (!regex_search(fraction, match, pattern)) {
        throw invalid_argument("Invalid fraction format: " + fraction);
    }
    int numerator = stoi(match[1]);
    int denominator = stoi(match[2]);
    // If the denominator is negative, make both numerator and denominator negative
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    return {numerator, denominator};
}


// Function to add two rational numbers
Rational add(Rational a, Rational b) {
    Rational result;
    // Find the least common multiple (LCM) of denominators
    int lcm = (a.denominator * b.denominator) / gcd(a.denominator, b.denominator);
    // Adjust the numerators
    result.numerator = (a.numerator * lcm / a.denominator) + (b.numerator * lcm / b.denominator);
    result.denominator = lcm;
    return result;
}
Rational subtract(Rational a, Rational b){
    Rational result;
    // Find the least common multiple (LCM) of denominators
    int lcm = (a.denominator * b.denominator) / gcd(a.denominator, b.denominator);
    // Adjust the numerators
    result.numerator = (a.numerator * lcm / a.denominator) - (b.numerator * lcm / b.denominator);
    result.denominator = lcm;
    return result;
}
Rational multiply(Rational a, Rational b){
    Rational result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return result;
}
Rational divide(Rational a, Rational b){
    Rational result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    return result;
}

// Function to simplify a rational number
void simplify(Rational& rational) {
    int gcd_val = gcd(rational.numerator, rational.denominator);
    rational.numerator /= gcd_val;
    rational.denominator /= gcd_val;
    int remain;
    if (rational.numerator > rational.denominator && rational.denominator != 1){
        remain = rational.numerator / rational.denominator;
        rational.numerator %= rational.denominator;
        cout << remain;
    }
}


int main() {
    while(true){
        string input;
        cout << "\nEnter expression and make sure operation is surrounded by spaces (or type 'exit'): ";
        getline(cin, input);
        for (char& c : input)
            c = tolower(c);

        // Modified regex pattern to match both fractions and whole numbers
        regex pattern("^\\s*(-?\\d+)(/(-?\\d+))?\\s*\\s([+\\-\\s/*])\\s\\s*(-?\\d+)(/(-?\\d+))?\\s*$");
        smatch match;

        if (regex_search(input, match, pattern)) {
            Rational operand1 = match[3].str().empty() ? Rational{stoi(match[1]), 1} : parseFraction(match[1].str() + "/" + match[3].str());
            Rational operand2 = match[7].str().empty() ? Rational{stoi(match[5]), 1} : parseFraction(match[5].str() + "/" + match[7].str());

            char op = match[4].str()[0];
            if (operand1.denominator == 0 || operand2.denominator == 0) {
                cout << "\nYou cannot divide by zero\n";
                continue;
            }
            Rational result;
            switch (op) {
                case '+':
                    result = add(operand1, operand2);
                    break;
                case '-':
                    result = subtract(operand1, operand2);
                    break;
                case '*':
                    result = multiply(operand1, operand2);
                    break;
                case '/':
                    if (operand2.numerator == 0) {
                        cout << "\nYou cannot divide by zero\n";
                        continue;
                    }
                    result = divide(operand1, operand2);
                    break;
            }
            cout << "Result: ";
            simplify(result); // Simplify the result
            if (result.denominator == 1)
                cout << " " << result.numerator << endl;
            else
                cout << " " << result.numerator << "/" << result.denominator << endl;
        }
        else if (input == "exit"){
            break;
        }
        else {
            cout << "\nInvalid input\n";
            continue;
        }
    }
    return 0;
}
//    Rational operand1 = parseFraction(match[1].str() + "/" + match[2].str());
//    Rational operand2 = parseFraction(match[4].str() + "/" + match[5].str());
//
//    char op = match[3].str()[0];
//    if (operand1.denominator == 0 || operand2.denominator == 0) {
//        cout << "\nYou cannot divide by zero\n";
//        continue;
//    }
//    Rational result;
//    switch (op) {
//        case '+':
//            result = add(operand1, operand2);
//            break;
//        case '-':
//            result = subtract(operand1, operand2);
//            break;
//        case '*':
//            result = multiply(operand1, operand2);
//            break;
//        case '/':
//            if (operand2.numerator == 0) {
//                cout << "\nYou cannot divide by zero\n";
//                continue;
//            }
//            result = divide(operand1, operand2);
//            break;
//    }
//    cout << "Result: ";
//    simplify(result); // Simplify the result
//    if (result.denominator == 1)
//        cout << " " << result.numerator << endl;
//    else
//        cout << " " << result.numerator << "/" << result.denominator << endl;
//}
