#include <iostream>
#include "polybius.h"

using namespace std;

int main()
{
    polybius k;
    int choice;
    cout << "POLYBIUS ENCRYPTION & DECRYPTION" << endl;
    cout << "--------------------------------" << endl << endl;
    do
    {
        cout << "Press 1 For Encryption" << endl;
        cout << "Press 2 For Decryption" << endl;
        cout << "Press 0 For Exit Program" << endl;
        cin >> choice;
        string choiceString;
        getline(cin, choiceString);
        switch (choice)
        {
        case 1:
            {
            cout << "Press Enter Text For Encryption" << endl;
            string text;
            getline(cin, text);
            k.encryption(text);
            }
            break;
        case 2:
            {
            cout << "Press Enter Encrypted Text For Decryption" << endl;
            string encryptedText;
            getline(cin, encryptedText);
            k.decryption(encryptedText);
            }
            break;
        case 0:
            break;
        default:
            cout << "Wrong Input!!" << endl << endl;
            break;
        }
    }while (choice != 0);
    return 0;
}
