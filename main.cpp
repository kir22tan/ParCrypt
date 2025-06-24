#include <iostream>
#include <vector>
#include <string>
#include "include/file_manager.h"
#include "include/thread_manager.h"
#include "include/env_loader.h"
#include "include/constants.h"

using namespace std;

int main() {
    try {
        char key = loadKeyFromEnv();

        cout << "Enter file path to encrypt/decrypt: ";
        string input;
        cin >> input;

        cout << "Encrypt (E) or Decrypt (D)? ";
        char mode;
        cin >> mode;

        vector<char> buffer = readFile(input);

        // Encrypt/Decrypt (XOR is symmetric)
        parallelEncrypt(buffer, THREAD_COUNT, key);

        string outFile = (mode == 'E' || mode == 'e') ? "encrypted.dat" : "decrypted.txt";
        writeFile(outFile, buffer);

        cout << "Done. Output saved as: " << outFile << endl;
    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
