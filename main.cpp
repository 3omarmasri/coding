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
        cout << "A. Cipher \n";
        cout << "B. Decipher \n";
        cout << "C. Exit\n";
        cout << "Enter your choice: ";

        cin >> choose;

        if (cin.peek() != '\n') {
            cout << "Invalid choice. Please try again.\n";
            cin.clear(); // Clear the error flag on cin
            while (cin.get() != '\n') // Discard remaining input until newline is encountered
                continue;
            continue; // Restart the loop
        }

        if (choose == 'a' || choose == 'b' || choose == 'c') {
            choose = toupper(choose);
        }
        if (choose != 'A' && choose != 'B' && choose != 'C') {
            cout << "Invalid choice. Please try again.\n";
            cin.clear();
            cin.ignore();
            continue;
        }

        cin.ignore();

        // Execute the chosen program or feature
        switch (choose) {
            case 'A':
                cypherExcuting();
                break;
            case 'B':
                decypherExcuting();
                break;
            case 'C':
                cout << "Exiting program. Goodbye!\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choose != 'C');
}

void cypherExcuting() {
    char choice;

    do {
        // Display menu options
        cout << "Choose The Atbash Cipher You Want:\n";
        cout << "A. Whole Alphabet Ciphering \n";
        cout << "B. Divide Alphabet Into 2 Halves Ciphering \n";
        cout << "C. Back \n";
        cout << "D. Exit \n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.peek() != '\n') {
            cout << "Invalid choice. Please try again.\n";
            cin.clear(); // Clear the error flag on cin
            while (cin.get() != '\n') // Discard remaining input until newline is encountered
                continue;
            continue; // Restart the loop
        }

        if (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd') {
            choice = toupper(choice);
        }
        if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D') {
            cout << "Invalid choice. Please try again.\n";
            cin.clear();
            cin.ignore();
            continue;
        }

        cin.ignore();

        // Execute the chosen program or feature
        switch (choice) {
            case 'A':
                wholeAlphabetCyphering();
                break;
            case 'B':
                divideAlphabetInto2Halves();
                break;
            case 'C':
                main();
            case 'D':
                cout << "Exiting program. Goodbye!\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 'D');
}

void decypherExcuting() {
    char choice;

    do {
        // Display menu options
        cout << "Choose The Atbash Decipher You Want:\n";
        cout << "A. Whole Alphabet Deciphering \n";
        cout << "B. Divide Alphabet Into 2 Halves Deciphering \n";
        cout << "C. Back \n";
        cout << "D. Exit \n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.peek() != '\n') {
            cout << "Invalid choice. Please try again.\n";
            cin.clear(); // Clear the error flag on cin
            while (cin.get() != '\n') // Discard remaining input until newline is encountered
                continue;
            continue; // Restart the loop
        }

        if (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd') {
            choice = toupper(choice);
        }
        if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D') {
            cout << "Invalid choice. Please try again.\n";
            cin.clear();
            cin.ignore();
            continue;
        }


        cin.ignore();

        // Execute the chosen program or feature
        switch (choice) {
            case 'A':
                wholeAlphabetCyphering();
                break;
            case 'B':
                divideAlphabetInto2Halves();
                break;
            case 'C':
                main();
            case 'D':
                cout << "Exiting program. Goodbye!\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 'D');
}

// Implementations of different programs or features
void wholeAlphabetCyphering() {
    cout << "Running Cypher Whole Alphabet from A - Z ...\n";
    cout << "Note: If You Entered a Non-Alphabet Character, It Will Be Ignored\n";
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
    cout << "Note: If You Entered a Non-Alphabet Character, It Will Be Ignored\n";
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

    cout << "The ciphered words is: " << cipheredWords << endl;

}
