#include <iostream>
#include <string>

using namespace std;
void cypherExcuting();
void decypherExcuting();
void wholeAlphabetCyphering();
void divideAlphabetInto2Halves();

int main() {
    char choose;

    do {
        // Display menu options
        cout << "Choose if You Want to Cipher or Decipher or Exit:\n";
        cout << "1. Cipher \n";
        cout << "2. Decipher \n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        cin >> choose;
        cin.ignore();

        // Execute the chosen program or feature
        switch (choose) {
            case '1':
                cypherExcuting();
                break;
            case '2':
                decypherExcuting();
                break;
            case '3':
                cout << "Exiting program. Goodbye!\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choose != '3');

}

void cypherExcuting() {
    char choice;

    do {
        // Display menu options
        cout << "Choose The Atbash Cipher You Want:\n";
        cout << "1. Whole Alphabet Ciphering \n";
        cout << "2. Divide Alphabet Into 2 Halves Ciphering \n";
        cout << "3. Back \n";
        cout << "4. Exit \n";
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
                main();
            case '4':
                cout << "Exiting program. Goodbye!\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != '4');

}

void decypherExcuting() {
    char choice;

    do {
        // Display menu options
        cout << "Choose The Atbash Decipher You Want:\n";
        cout << "1. Whole Alphabet Deciphering \n";
        cout << "2. Divide Alphabet Into 2 Halves Deciphering \n";
        cout << "3. Back \n";
        cout << "4. Exit \n";
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
                main();
            case '4':
                cout << "Exiting program. Goodbye!\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != '4');

}

// Implementations of different programs or features
void wholeAlphabetCyphering() {
    cout << "Running Cypher Whole Alphabet from A - Z ...\n";

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string words;

    cout << "Enter the words you want to cipher: ";

    getline(cin, words);

    string cipheredWords = "";

    for (char letter : words) {
        if (isalpha(letter)) {
            int position = alphabet.find(toupper(letter)) + 1;
            int positionReversed = 26 - position + 1;
            char letterReversed = alphabet[positionReversed - 1];
            cipheredWords += letterReversed;
        }
    }

    cout << "The ciphered words is: " << cipheredWords << endl;

}

void divideAlphabetInto2Halves() {
    cout << "Running Cypher With Dividing Alphabet Into 2 Halves ...\n";

    string alphabetHalve1 = "ABCDEFGHIJKLM";
    string alphabetHalve2 = "NOPQRSTUVWXYZ";
    string words;

    cout << "Enter the words you want to cipher: ";

    getline(cin, words);

    string cipheredWords = "";

    for (char letter: words) {
        if (isalpha(letter)) {
            if ((letter >= 'A' && letter <= 'M') || (letter >= 'a' && letter <= 'm')) { // First half of the alphabet
                int position = alphabetHalve1.find(toupper(letter)) + 1;
                int positionReversed = 13 - position + 1;
                char letterReversed = alphabetHalve1[positionReversed - 1];
                cipheredWords += letterReversed;
            } else if (letter >= 'N' && letter <= 'Z' ||
                       (letter >= 'n' && letter <= 'z')) { // Second half of the alphabet
                int position = alphabetHalve2.find(toupper(letter)) + 1;
                int positionReversed = 13 - position + 1;
                char letterReversed = alphabetHalve2[positionReversed - 1];
                cipheredWords += letterReversed;
            }
        }
    }

    cout << "The ciphered words is: " << cipheredWords << endl;

}
