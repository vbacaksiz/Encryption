#ifndef AFFINE_H
#define AFFINE_H
#include <iostream>
#include <string>

using namespace std;


class affine
{
    public:
        affine();
        void encryption(int a, int b, string input);
        void decryption(int a, int b, string input);

    private:
        string alphabet="abcdefghijklmnopqrstuvwxyz";
        int alphabetLength=alphabet.length();

        string turnAffine(int a,int b, string input);
        string unturnAffine(int a, int b, string input);
        string convertIntToText(int *integerarray, int length);

};

#endif // AFFINE_H
