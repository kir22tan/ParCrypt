#include "../include/file_manager.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

vector<char> readFile(const string& path) {
    ifstream fin;
    fin.open(path, ios::binary);  // ✔ safer and more compatible

    if (!fin.is_open()) {
        throw runtime_error("Failed to open input file: " + path);
    }

    fin.seekg(0, ios::end);
    size_t size = fin.tellg();
    fin.seekg(0);

    vector<char> buffer(size);
    fin.read(buffer.data(), size);
    fin.close();
    return buffer;
}

void writeFile(const string& path, const vector<char>& data) {
    ofstream fout;
    fout.open(path, ios::binary);  // ✔ same pattern for writing

    if (!fout.is_open()) {
        throw runtime_error("Failed to open output file: " + path);
    }

    fout.write(data.data(), data.size());
    fout.close();
}
