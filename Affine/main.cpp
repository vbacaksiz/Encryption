#include <iostream>
#include "affine.h"

using namespace std;

int main()
{
    affine k;
    int choice;
    cout << "AFFINE ENCRYPTION & DECRYPTION" << endl;
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
            cout << "Please Enter a (a*x+b) mod n" << endl;
            int a;
            cin >> a;
            cout << "Please Enter b (a*x+b) mod n" << endl;
            int b;
            cin >> b;
            k.encryption(a, b, text);
            }
            break;
        case 2:
            {
            cout << "Press Enter Encrypted Text For Decryption" << endl;
            string encryptedText;
            cin >> encryptedText;
            cout << "Please Enter a (a*x+b) mod n" << endl;
            int a;
            cin >> a;
            cout << "Please Enter b (a*x+b) mod n" << endl;
            int b;
            cin >> b;
            k.decryption(a, b, encryptedText);
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
