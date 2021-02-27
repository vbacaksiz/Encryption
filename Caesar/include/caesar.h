#ifndef CAESAR_H
#define CAESAR_H
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>

using namespace std;

class caesar
{
    public:
        caesar();
        void encryption(string input, int shift);
        void decryption(string input);

    private:
        string alphabet = "abcdefghijklmnoprstuvyz";
        string turnCaesar(char letter, int shift);
        string *unturnCaesar(string input);
};

#endif // CAESAR_H
