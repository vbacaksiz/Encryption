#ifndef VIGENERE_H
#define VIGENERE_H
#include <iostream>
#include <string>

using namespace std;


class vigenere
{
    public:
        vigenere();
        void encryption(string input, string key);
        void decryption(string input, string key);

    private:
        string alphabet = "abcdefghijklmnopqrstuvwxyz";

        int* convertTextToIndex(string input);
        int* switching(string key, int textLength);
        int* encrypt(int* textIndex, int* keyIndex, int length);
        int* decrypt(int* textIndex, int* keyIndex, int length);
        string convertEncryptedAndDecryptedText(int *encryptedAndDecryptedText, int length);
};

#endif // VIGENERE_H
