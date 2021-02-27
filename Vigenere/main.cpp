#include <iostream>
#include "vigenere.h"

using namespace std;

int main()
{
    vigenere k;
    int choice;
    cout << "VIGENERE ENCRYPTION & DECRYPTION" << endl;
    cout << "------------------------------" << endl << endl;
    do
    {
        cout << "Press 1 For Encryption" << endl;
        cout << "Press 2 For Decryption" << endl;
        cout << "Press 0 For Exit Program" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            {
            cout << "Press Enter Text For Encryption" << endl;
            string text;
            cin >> text;
            cout << "Please Enter Key Text For Switching" << endl;
            string key;
            cin >> key;
            k.encryption(text, key);
            }
            break;
        case 2:
            {
            cout << "Press Enter Encrypted Text For Decryption" << endl;
            string encryptedText;
            cin >> encryptedText;
            cout << "Please Enter Key" << endl;
            string key;
            cin >> key;
            k.decryption(encryptedText, key);
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
