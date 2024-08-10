/*
Program that decrypts a .txt file using ASCII CODE. 
The logic to decrypt the files is to subtract 5 from the ASCII code of each character and change special characters for other ones.
For example, the characters from 34 to 38 are changed to 122 to 126, 126 is changed to spaces in ASCII code
and exclamation marks (!) are changed to y.
And if we find a newline or a carriage return, we do nothing.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// We declare the function to decrypt the file and its parameter is the name of the file
void Decrypt(string File_name);

int main(int argc, char** argv) {
    string file_name;

    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file_name>" << endl;
        return 1;
    }

    file_name = argv[1];

    cout << "\n------------------------------------------------\n";
    cout << "\tTEXT FILE DECRYPTOR";
    cout << "\n------------------------------------------------\n";

    // Call the function to decrypt the file with the provided file name
    Decrypt(file_name);

    return 0;
}

// Function to decrypt the file
void Decrypt(string File_name) {
    char character;
    char decrypted_char;
    string decrypted_text;

    // We create an ifstream object to read the file
    ifstream file(File_name);

    // We check if the file opened correctly
    if (!file.is_open()) {

        cerr << "\nThe file couldn't be opened: " << File_name << endl;

        return;

    }

    // Read the file character by character
    while (file.get(character)) {

        if (character == 126) {

            decrypted_char = 32;

        } else if (character == 33) {

            decrypted_char = 121;

        } else if (character == '\n' || character == '\r') {

            decrypted_char = character; 

        } else if (character >= 34 && character <=38) {

            decrypted_char = character + 88; 

        } else {

            decrypted_char = character - 5;

        }

        decrypted_text +=  decrypted_char;

    }

    // We close the file
    file.close();

    // Print the decrypted text to the console
    cout << "\nEncrypted text:\n\n" << decrypted_text << endl;

    // We create an ofstream object to write the decrypted text to a new file
    ofstream decrypted_file("decrypted_" + File_name);

    //We check if the file was created
    if (!decrypted_file.is_open()) {
        cerr << "\nThe decrypted file couldn't be created: encrypted_" << File_name << endl;
        return;
    }

    // Write the encrypted text to the new file
    decrypted_file << decrypted_text;

    // We close the encrypted file
    decrypted_file.close();

    cout << "\nFile decrypted successfully as Decrypted_" << File_name << endl;
}
