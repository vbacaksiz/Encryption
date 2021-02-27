#include "caesar.h"

caesar::caesar()
{
    //ctor
}

void caesar::encryption(string input, int shift)
{
    string encryptedText = "";
    for (int i=0; i < input.length(); i++)
        encryptedText += turnCaesar(tolower(input[i]), shift);
    cout << "Encrypted Text = " << encryptedText << endl << endl;

}

void caesar::decryption(string input)
{
    string *predictions;
    predictions = unturnCaesar(input);
    cout << endl << "PREDICTIONS OF DECRYPTED TEXT" << endl << endl;
    for(int i=0; i < 23; i++)
    {
        cout << *(predictions+i) << endl;
    }
    cout << endl;
}

string caesar::turnCaesar(char letter, int shift)
{
    string encryptionResult = "";
    for (int i = 0; i < alphabet.length(); i++)
    {
        if(letter == ' ')
            encryptionResult = ' ';

        if(alphabet[i] == letter)
        {
            if(i+shift <= alphabet.length())
                encryptionResult = alphabet[i+shift];
            else
                encryptionResult = alphabet[-(alphabet.length()-(i+shift))];
        }
    }
    return encryptionResult;
}

string* caesar::unturnCaesar(string input)
{
    string *decryptions = new string[alphabet.length()];
    for (int i = 0; i <= alphabet.length() - 1; i++)
    {
        string estimatedText = "";
        for (int j = 0; j < input.length(); j++)
        {
            if(input[j] == ' ')
                estimatedText += ' ';

            for (int k=0 ; k < alphabet.length(); k++)
            {
                if(input[j] == alphabet[k])
                {
                    if(k-i < 0)
                    {
                        estimatedText += alphabet[alphabet.length()+(k-i)];
                    }
                    else
                        estimatedText += alphabet[(k-i)];
                        break;
                }
            }

        }
        decryptions[i] = estimatedText;
    }
    return decryptions;
}

