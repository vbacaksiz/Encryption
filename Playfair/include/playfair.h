#ifndef PLAYFAIR_H
#define PLAYFAIR_H
#include <iostream>
#include <string.h>

using namespace std;

class playfair
{
    public:
        playfair();
        void encryption(string input, string key)
        {
            assignAlphabet(key);
            string encryptedText = "";
            for(int i=0; i < input.length(); i+=2)
            {
                if(input[i] != ' ' && input[i+1] != ' ')
                {
                    encryptedText += encrypt(tolower(input[i]), tolower(input[i+1]));
                }
                else if(input [i] != ' ' && input[i+1] == ' ')
                {
                    encryptedText += encrypt(tolower(input[i]), tolower(input[i+2]));
                    i += 1;
                }
                else
                {
                    i -= 1;
                }
            }
            cout << encryptedText << endl;
        }
        void decryption(string input, string key)
        {
            assignAlphabet(key);
            decyptionResult(input);
        }

    private:
        string alphabet = "abcdefghiklmnopqrstuvwxyz";
        /*char alphabetDesignForPlayfair[8][4]={ {'p','l','a','y'},{'f','ý','r','s'},{'e','b','c','ç'},{'d','g','ð','h'},
		{'i','j','k','m'},{'n','o','ö','q'},{'þ','t','u','ü'},{'v','w','x','z'}};;*/
		char alphabetDesignForPlayfair[5][5];
		int numOfPrediction = 1;
		int alphabetDesignForPlayfairLineColumnLength = sizeof(alphabetDesignForPlayfair)/sizeof(alphabetDesignForPlayfair[0]);

        string assignAlphabet(string key)
        {
            string text = "";
            int sameLetters[key.length()] = {0};
            int alphabetLine = 0;
            int alphabetColumn = 0;
            for(int i=0; i < key.length(); i++)
            {
                if(key[i] == 'j')
                    key[i] = 'i';
                for(int j=i+1; j < key.length(); j++)
                {
                    if(key[i] != ' ')
                    {
                        if(key[i] == key[j])
                        {
                            sameLetters[j] = 1;
                            key[j] = ' ';
                        }
                    }
                }

                if(sameLetters[i] == 0)
                {
                    alphabetDesignForPlayfair[alphabetLine][alphabetColumn] = key[i];
                    alphabetColumn += 1;
                    if(alphabetColumn > 0 && alphabetColumn % alphabetDesignForPlayfairLineColumnLength == 0)
                    {
                        alphabetColumn = 0;
                        alphabetLine += 1;
                    }
                }
            }
            int sameLettersAlphabets = 0;
            for(int j=0; j < alphabet.length() ; j++)
            {
                if(alphabetLine >= 1)
                {
                    for(int k=0; k < alphabetLine; k++)
                    {
                        for(int l=0; l < alphabetDesignForPlayfairLineColumnLength; l++)
                        {
                            if(alphabet[j] == alphabetDesignForPlayfair[k][l])
                            {
                                sameLettersAlphabets = 1;
                            }
                        }
                    }
                }
                else
                {
                    for(int l=0; l < alphabetColumn; l++)
                    {
                        if(alphabet[j] == alphabetDesignForPlayfair[0][l])
                            sameLettersAlphabets = 1;
                    }
                }
                if(sameLettersAlphabets == 0)
                {
                    alphabetDesignForPlayfair[alphabetLine][alphabetColumn] = alphabet[j];
                    alphabetColumn += 1;
                    if(alphabetColumn > 0 && alphabetColumn % alphabetDesignForPlayfairLineColumnLength == 0)
                    {
                        alphabetColumn = 0;
                        alphabetLine += 1;
                    }
                }
                sameLettersAlphabets = 0;
            }
            for(int i=0; i < alphabetDesignForPlayfairLineColumnLength ; i++)
            {
                for(int j=0; j < alphabetDesignForPlayfairLineColumnLength ; j++)
                {
                    cout << alphabetDesignForPlayfair[i][j] ;
                }
            }
            cout << endl;
            return text;
        }

        int* findIndex(char value)
        {
            int* index = new int[2];
            for(int i=0;i < alphabetDesignForPlayfairLineColumnLength; i++)
            {
                for(int j=0; j < alphabetDesignForPlayfairLineColumnLength ; j++)
                {
                    if(alphabetDesignForPlayfair[i][j] == value)
                    {
                        index[0] = i;
                        index[1] = j;
                    }
                }
            }
            return index;
        }

        string encrypt(char firstInputBlock, char secondInputBlock)
        {
            //ETV = EncrpytedTextValue
            char firstETV;
            char secondETV;

            if(firstInputBlock == 'j')
                firstInputBlock = 'i';

            if(secondInputBlock == 'j')
                secondInputBlock = 'j';

            cout << firstInputBlock << endl;
            cout << secondInputBlock << endl;

            //IBIV = InputBlockIndexValue
            int* firstIBIV = findIndex(firstInputBlock);
            int* secondIBIV = findIndex(secondInputBlock);

            if(firstIBIV[0] == secondIBIV[0])
            {
                firstETV = alphabetDesignForPlayfair[firstIBIV[0]][(firstIBIV[1]+1) % alphabetDesignForPlayfairLineColumnLength];
                secondETV = alphabetDesignForPlayfair[secondIBIV[0]][(secondIBIV[1]+1) % alphabetDesignForPlayfairLineColumnLength];
            }
            else if(firstIBIV[1] == secondIBIV[1])
            {
                firstETV = alphabetDesignForPlayfair[(firstIBIV[0]+1)% alphabetDesignForPlayfairLineColumnLength][firstIBIV[1]];
                secondETV = alphabetDesignForPlayfair[(secondIBIV[0]+1)% alphabetDesignForPlayfairLineColumnLength][secondIBIV[1]];
            }
            else
            {
                firstETV = alphabetDesignForPlayfair[firstIBIV[0]][secondIBIV[1]];
                secondETV = alphabetDesignForPlayfair[secondIBIV[0]][firstIBIV[1]];
            }
            string encryptText = "";
            encryptText += firstETV;
            encryptText += secondETV;
            return encryptText;
        }

        string decrypt(char firstInputBlock, char secondInputBlock)
        {
            //ETV = EncrpytedTextValue
            char firstETV;
            char secondETV;

            //IBIV = InputBlockIndexValue
            int* firstIBIV = findIndex(firstInputBlock);
            int* secondIBIV = findIndex(secondInputBlock);

            if(firstIBIV[0] == secondIBIV[0])
            {
                firstETV = alphabetDesignForPlayfair[firstIBIV[0]][(firstIBIV[1]+alphabetDesignForPlayfairLineColumnLength-1) % alphabetDesignForPlayfairLineColumnLength];
                secondETV = alphabetDesignForPlayfair[secondIBIV[0]][(secondIBIV[1]+alphabetDesignForPlayfairLineColumnLength-1) % alphabetDesignForPlayfairLineColumnLength];
            }
            else if(firstIBIV[1] == secondIBIV[1])
            {
                firstETV = alphabetDesignForPlayfair[(firstIBIV[0]+5-1)% alphabetDesignForPlayfairLineColumnLength][firstIBIV[1]];
                secondETV = alphabetDesignForPlayfair[(secondIBIV[0]+5-1)% alphabetDesignForPlayfairLineColumnLength][secondIBIV[1]];
            }
            else
            {
                firstETV = alphabetDesignForPlayfair[firstIBIV[0]][secondIBIV[1]];
                secondETV = alphabetDesignForPlayfair[secondIBIV[0]][firstIBIV[1]];
            }
            if(firstETV == 'i')
                numOfPrediction++;

            if(secondETV == 'i')
                numOfPrediction++;
            string decryptText = "";
            decryptText += firstETV;
            decryptText += secondETV;
            return decryptText;
        }

        string decyptionResult(string input)
        {
            string decryptedText = "";
            for(int i=0; i < input.length(); i+=2)
            {
                if(input[i] != ' ' && input[i+1] != ' ')
                {
                    decryptedText += decrypt(tolower(input[i]), tolower(input[i+1]));
                }
                else if(input [i] != ' ' && input[i+1] == ' ')
                {
                    decryptedText += decrypt(tolower(input[i]), tolower(input[i+2]));
                    i += 1;
                }
                else
                {
                    i -= 1;
                }
            }
            if(numOfPrediction > 1)
            {
                cout << endl << "PREDICTIONS OF DECRYPTED TEXT" << endl << endl;
                for(int i=0; i < numOfPrediction; i++)
                {
                    for(int k=0; k < decryptedText.length(); k++)
                    {
                        cout << decryptedText << endl;
                        if(decryptedText[k] == 'i')
                            decryptedText[k] = 'j';
                    }
                }
            }
            else
            {
                cout << endl << "decrypted Text = " << decryptedText << endl;
            }
        }
};

#endif // PLAYFAIR_H
