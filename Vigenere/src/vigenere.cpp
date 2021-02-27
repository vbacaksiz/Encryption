#include "vigenere.h"

vigenere::vigenere()
{
    //ctor
}

void vigenere::encryption(string input, string key)
{
    int* inputTextIndex = convertTextToIndex(input);
    int* keyIndex = switching(key, input.length());
    int* encryptedTextIndex = encrypt(inputTextIndex, keyIndex, input.length());
    string encryptedText = convertEncryptedAndDecryptedText(encryptedTextIndex, input.length());
    cout << encryptedText << endl << endl << endl;
}

void vigenere::decryption(string input, string key)
{
    int* inputTextIndex = convertTextToIndex(input);
    int* keyIndex = switching(key, input.length());
    int* decryptedTextIndex = decrypt(inputTextIndex, keyIndex, input.length());
    string decryptedText = convertEncryptedAndDecryptedText(decryptedTextIndex, input.length());
    cout << decryptedText << endl << endl << endl;
}

int* vigenere::convertTextToIndex(string input)
{
    int* textIndex = new int[input.length()];
    for(int i=0; i < input.length(); i++)
    {
        for(int j=0; j < alphabet.length(); j++)
        {
            if(tolower(input[i]) == alphabet[j])
            {
                textIndex[i] = j;
            }
        }

    }
    return textIndex;
}

int* vigenere::switching(string key, int textLength)
{
    int keyTextModInputText = 0;
    int* keyIndex = new int[textLength];
    for(int i=0; i < textLength; i++)
    {
        if(i % key.length() == 0)
            keyTextModInputText = 0;
        for(int j=0; j < alphabet.length(); j++)
        {
            if(tolower(key[i]) == alphabet[j])
            {
                keyIndex[i] = j;
                keyTextModInputText += 1;
            }
        }
    }
    return keyIndex;
}

int* vigenere::encrypt(int* textIndex, int* keyIndex, int length)
{
    int* encryptedText = new int[length];
    for(int i=0; i < length; i++)
    {
        encryptedText[i] = (textIndex[i]+keyIndex[i]) % alphabet.length();
    }
    return encryptedText;
}

int* vigenere::decrypt(int* textIndex, int* keyIndex, int length)
{
    int* decryptedText = new int[length];
    for(int i=0; i < length; i++)
    {
        decryptedText[i] = (textIndex[i]-keyIndex[i]);
        if(decryptedText[i] < 0)
            decryptedText[i] += alphabet.length();
    }
    return decryptedText;
}

string vigenere::convertEncryptedAndDecryptedText(int *encryptedAndDecryptedText, int length)
{
    string text = "";
    for(int i=0; i < length; i++)
    {
        text += alphabet[encryptedAndDecryptedText[i]];
    }
    return text;
}
