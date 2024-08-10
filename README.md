This directory contains a program to encrypt text files and another one to decrypt them respectively. 

Locigal to encrypt:

Program that encrypts a .txt file using ASCII CODE. 
The logic to encrypt the files is to add 5 to the ASCII code of each character and change special characters for other ones. 
For example, the last characters from 122 to 126 are changed to 34 to 38, spaces are changed to 126 in ASCII code
and y is changed to exclamation marks (!).
And if we find a newline or a carriage return, we do nothing.

LogicaL to decrypt:

Program that decrypts a .txt file using ASCII CODE. 
The logic to decrypt the files is to subtract 5 from the ASCII code of each character and change special characters for other ones.
For example, the characters from 34 to 38 are changed to 122 to 126, 126 is changed to spaces in ASCII code
and exclamation marks (!) are changed to y.
And if we find a newline or a carriage return, we do nothing.