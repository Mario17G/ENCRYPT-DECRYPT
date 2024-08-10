/*
Program that encrypts a .txt file using ASCII CODE. 
The logic to encrypt the files is to add 5 to the ASCII code of each character and change special characters for other ones. 
For example, the last characters from 122 to 126 are changed to 34 to 38, spaces are changed to 126 in ASCII code
and y is changed to exclamation marks (!).
And if we find a newline or a carriage return, we do nothing.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// We declare the function to encrypt the file and its parameter is the name of the file
void Encrypt(string File_name);

int main(int argc, char** argv) {
    string file_name;

    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file_name>" << endl;
        return 1;
    }

    file_name = argv[1];

    cout << "\n------------------------------------------------\n";
    cout << "\tTEXT FILE ENCRYPTER";
    cout << "\n------------------------------------------------\n";

    // Call the function to encrypt the file with the provided file name
    Encrypt(file_name);

    return 0;
}

// Function to encrypt the file
void Encrypt(string File_name) {
    char character;
    char encrypted_char;
    string encrypted_text;

    // We create an ifstream object to read the file
    ifstream file(File_name);

    // We check if the file opened correctly
    if (!file.is_open()) {

        cerr << "\nThe file couldn't be opened: " << File_name << endl;

        return;

    }

    // Read the file character by character
    while (file.get(character)) {

       if (character == 32) {

            encrypted_char = 126;

        } else if (character == 121) {

            encrypted_char = 33;

        } else if (character == '\n' || character == '\r') {

            encrypted_char = character; 

        } else if (character >= 122 && character <= 126) {

            encrypted_char = character - 88; 

        } else {

            encrypted_char = character + 5;

        }

        encrypted_text += encrypted_char;

    }    
           


    // We close the file
    file.close();

    // Print the encrypted text to the console
    cout << "\nEncrypted text:\n\n" << encrypted_text << endl;

    // We create an ofstream object to write the encrypted text to a new file
    ofstream encrypted_file("encrypted_" + File_name);
    if (!encrypted_file.is_open()) {
        cerr << "\nThe encrypted file couldn't be created: encrypted_" << File_name << endl;
        return;
    }

    // Write the encrypted text to the new file
    encrypted_file << encrypted_text;

    // We close the encrypted file
    encrypted_file.close();

    cout << "\nFile encrypted successfully as encrypted_" << File_name << endl;
}

