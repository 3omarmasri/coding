#include <bits/stdc++.h>
using namespace std;

const int maxInputLetters = 80;
const int maxKeyLetters = 8;

string input;
string key;

void userInput() {
    cout << "Enter the message: ";
    getline(cin, input);
    for(char letter : input) {
        if (input.length() > maxInputLetters) {
            cout << "Too many letters entered. Please limit to " << maxInputLetters << " letters." << endl;
            userInput();
        }
    }
}

void userKey() {
    cout << "Enter the key: ";
    getline(cin, key);
    for(char letter : key){
        if (key.length() > maxKeyLetters){
            cout << "Too many letters entered. Please limit to " << maxKeyLetters << " letters." << endl;
            userKey();
        }
    }
    transform(key.begin(), key.end(), key.begin(), ::toupper); // Convert key to uppercase
}

void vigenereCipher(bool encrypt = true) {
    string encryptedMessage = "";
    int keyIndex = 0;

    for (char c : input) {
        c = toupper(c);
        if (isalpha(c)) {  // Check if the character is a letter
            int shift = (key[keyIndex % key.length()] - 'A') * (encrypt ? 1 : -1);
            char encryptedChar = ((c - 'A' + shift + 26) % 26) + 'A';
            encryptedMessage += encryptedChar;
            keyIndex++;
        } else {
            encryptedMessage += c;
            keyIndex++;
        }
    }
    cout << "Encrypted message: " << encryptedMessage << endl;
}

void vigenereDecipher() {
    string decryptedMessage = "";
    int keyIndex = 0;

    for (char c : input) {
        c = toupper(c);
        if (isalpha(c)) {  // Check if the character is a letter
            int shift = (key[keyIndex % key.length()] - 'A') * -1;
            char decryptedChar = ((c - 'A' + shift + 26) % 26) + 'A';
            decryptedMessage += decryptedChar;
            keyIndex++;
        } else {
            decryptedMessage += c;
            keyIndex++;
        }
    }
    cout << "Decrypted message: " << decryptedMessage << endl;
}

int main() {
    cout << "Welcome to the Vigenere Cipher program!\n";

    char choose;

    // Main menu loop
    do {
        // Display menu options
        cout << "Choose if You Want to Cipher or Decipher or Exit:\n";
        cout << "A. Cipher \n";
        cout << "B. Decipher \n";
        cout << "C. Exit\n";
        cout << "Enter your choice: ";

        // Input choice from user
        cin >> choose;

        // Check for non-numeric input
        if (cin.peek() != '\n') {
            cout << "Invalid choice. Please try again.\n";
            cin.clear(); // Clear the error flag on cin
            while (cin.get() != '\n') // Discard remaining input until newline is encountered
                continue;
            continue; // Restart the loop
        }

        // Convert lowercase input to uppercase
        if (choose == 'a' || choose == 'b' || choose == 'c') {
            choose = toupper(choose);
        }

        // Validate choice
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
                userInput();
                userKey();
                vigenereCipher();
                break;
            case 'B':
                userInput();
                userKey();
                vigenereDecipher();
                break;
            case 'C':
                cout << "Exiting program. Goodbye!\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choose != 'C');
}
