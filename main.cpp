#include "include/thread_manager.h"
#include "include/encryptor.h"
#include "include/file_manager.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== ParCrypt ===\n\n";
    cout << "1. Encrypt a file\n";
    cout << "2. Decrypt a file\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;
    cin.ignore();

    string inPath, outName, password;

    if (choice == 1) {
        cout << "Enter path of file to encrypt: ";
        getline(cin, inPath);

        cout << "Enter password: ";
        getline(cin, password);

        cout << "Enter name for encrypted file (e.g., secret.bin): ";
        getline(cin, outName);

        try {
            vector<char> data = readFile(inPath);
            parallelEncrypt(data, 4, password);
            vector<char> encrypted = attachHeader(data, password);
            writeFile("encrypt/" + outName, encrypted);
            cout << "\n File encrypted and saved to encrypt/" << outName << "\n";
        } catch (exception& e) {
            cout << " Error: " << e.what() << "\n";
        }
    }
    else if (choice == 2) {
        cout << "Enter name of encrypted file (inside encrypt/): ";
        getline(cin, outName);

        cout << "Enter password: ";
        getline(cin, password);

        cout << "Enter name for decrypted file (e.g., final.txt): ";
        string finalName;
        getline(cin, finalName);

        try {
            vector<char> data = readFile("encrypt/" + outName);

            if (!validatePasswordAndDecrypt(data, password)) {
                cout << "\n Incorrect password. Aborting.\n";
                return 1;
            }

            writeFile("decrypt/" + finalName, data);
            cout << "\n File decrypted and saved to decrypt/" << finalName << "\n";
        } catch (exception& e) {
            cout << " Error: " << e.what() << "\n";
        }
    }
    else {
        cout << " Invalid option.\n";
    }

    return 0;
}
