#include "polybius.h"

polybius::polybius()
{
    //ctor
}

void polybius::encryption(string input)
{
    string encryptedText = "";
    for(int i=0; i<input.length(); i++)
    {
        encryptedText += turnPolybius(tolower(input[i]));
    }
    cout<<"Encrypted Text = "<< encryptedText << endl << endl << endl;
}

void polybius::decryption(string input)
{
    string decryptedText = "";
    int n = input.length();
    int line;
    int column;
    for (int j = 0; j < n; j+=2)
    {
        if(input[j] == ' ')
        {
            decryptedText += ' ';
            j=j-1;
            continue;
        }
        else
        {
            line = input[j];
            column = input[j+1];
            //-48 for ASCII
            decryptedText += unturnPolybius(line-48, column-48);
        }
    }
    cout<<"Decrypted Text = "<< decryptedText << endl << endl << endl;
}

string polybius::turnPolybius(char letter)
{
    string encryptionResult = "";
    if(letter != ' ')
    {
        for(int i=0; i<sizeof(alphabet)/sizeof(alphabet[0]); i++)
        {
            for(int j=0; j<sizeof(alphabet[0])/sizeof(alphabet[0][0]); j++)
            {
                if(letter == alphabet[i][j])
                {
                    encryptionResult += ToString(i+1);
                    encryptionResult += ToString(j+1);
                    break;
                }
            }
        }
    }
    else
    {
        encryptionResult += ' ';
    }
    return encryptionResult;
}

char polybius::unturnPolybius(int line, int column)
{
    //-1 for logic of array
    return alphabet[line-1][column-1];
}


