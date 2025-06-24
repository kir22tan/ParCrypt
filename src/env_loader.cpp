#include "../include/env_loader.h"
#include <fstream>
#include <sstream>

using namespace std;

char loadKeyFromEnv() {
    ifstream file(".env");
    string line;
    while (getline(file, line)) {
        if (line.find("XOR_KEY=") == 0) {
            string val = line.substr(8);
            int key = 0;
            stringstream ss;
            if (val.find("0x") == 0 || val.find("0X") == 0) {
                ss << hex << val;
            } else {
                ss << val;
            }
            ss >> key;
            return static_cast<char>(key);
        }
    }
    throw runtime_error("XOR_KEY not found in .env file");
}
