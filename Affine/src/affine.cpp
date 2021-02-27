#include "affine.h"

affine::affine()
{
    //ctor
}

void affine::encryption(int a, int b, string input)
{
    string encryptedText;
    encryptedText = turnAffine(a, b, input);
    cout << "Encrypted Text = " << encryptedText << endl << endl << endl;
}

void affine::decryption(int a, int b, string input)
{
    string decryptedText;
    decryptedText = unturnAffine(a, b, input);
    cout << "Decrypted Text = " << decryptedText << endl << endl << endl;
}

string affine::turnAffine(int a, int b, string input)
{
    int *encryptionResult = new int[input.length()];

    for(int i=0; i < input.length(); i++)
    {
        for(int j=0; j < alphabetLength; j++)
        {
            if(tolower(input[i]) == alphabet[j])
            {
                encryptionResult[i] = (a*j+b)%alphabetLength;
            }
        }
    }
    return convertIntToText(encryptionResult, input.length());
}

string affine::unturnAffine(int a, int b, string input)
{
    int *decryptionResult = new int[input.length()];
    int ax;

    for(int i=0; i < alphabetLength ; i++)
    {
        if((a*i)%alphabetLength == 1)
           ax = i;
    }

    for(int k=0; k < input.length(); k++)
    {
        for(int j=0; j < alphabetLength; j++)
        {
            if(tolower(input[k]) == alphabet[j])
            {
                decryptionResult[k] = (ax*(j-b)%alphabetLength);
            }
        }
    }
    return convertIntToText(decryptionResult, input.length());
}

string affine::convertIntToText(int *integerarray, int length)
{
    string result = "";
    for(int i=0; i < length; i++)
    {
        result += alphabet[integerarray[i]];
    }
    return result;
}
