#include <iostream>
#include <string>
using namespace std;

// Function prototypes for different programs or features
void wholeAlphabetCyphering();
void divideAlphabetInto2Halves();

int main() {
    char choice;

    do {
        // Display menu options
        cout << "Menu:\n";
        cout << "1. Whole Alphabet Cyphering \n";
        cout << "2. Divide Alphabet Into 2 Halves \n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        // Execute the chosen program or feature
        switch (choice) {
            case '1':
                wholeAlphabetCyphering();
                break;
            case '2':
                divideAlphabetInto2Halves();
                break;
            case '3':
                cout << "Exiting program. Goodbye!\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}

// Implementations of different programs or features
void wholeAlphabetCyphering() {
    cout << "Executing Program 1...\n";


    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string word;

    cout << "Enter the word you want to cipher: ";
    getline(cin, word);

    string ciphered_word = "";
    for (char letter : word) {
        if (isalpha(letter)) {
            int position = alphabet.find(toupper(letter)) + 1;
            int reverse_position = 26 - position + 1;
            char reverse_letter = alphabet[reverse_position - 1];
            ciphered_word += reverse_letter;
        }
    }
    cout << "The ciphered word is: " << ciphered_word << endl;

}

void divideAlphabetInto2Halves() {
    cout << "Executing Program 2...\n";

    string alphabet = "ABCDEFGHIJKLM";
    string nlphabet = "NOPQRSTUVWXYZ";
    string word;

    cout << "Enter the word you want to cipher: ";
    getline(cin, word);

    string ciphered_word = "";
    for (char letter : word) {
        if (isalpha(letter)) {
            if (letter >= 'A' && letter <= 'M') { // First half of the alphabet
                int position = alphabet.find(toupper(letter)) + 1;
                int reverse_position = 13 - position + 1;
                char reverse_letter = alphabet[reverse_position - 1];
                ciphered_word += reverse_letter;
            } else if (letter >= 'N' && letter <= 'Z') { // Second half of the alphabet
                int position = nlphabet.find(toupper(letter)) + 1;
                int reverse_position = 13 - position + 1;
                char reverse_letter = nlphabet[reverse_position - 1];
                ciphered_word += reverse_letter;
            }
        }
    }

    // Insert a space between the two halves of the ciphered word
    int half_length = ciphered_word.length() / 2;
    ciphered_word.insert(half_length, " ");
    cout << "The ciphered word is: " << ciphered_word << endl;
}

