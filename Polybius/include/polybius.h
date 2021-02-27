#ifndef POLYBIUS_H
#define POLYBIUS_H
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>

template <typename T>
std::string ToString(T val)
{
    std::stringstream stream;
    stream << val;
    return stream.str();
}

using namespace std;

class polybius
{
    public:
        polybius();
        void encryption(string input);
        void decryption(string input);

    private:
        char alphabet[4][7] = {{ 'a', 'b', 'c', 'd', 'e', 'f', 'g' },
			{ 'h', 'i', 'j', 'k', 'l', 'm', 'n' },
			{ 'o', 'p', 'q', 'r', 's', 't', 'u' },
			{ 'v', 'w', 'x', 'y', 'z' } };

        string turnPolybius(char letter);
        char unturnPolybius(int line, int column);

};

#endif // POLYBIUS_H
