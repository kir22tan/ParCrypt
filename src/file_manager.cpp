#include "../include/file_manager.h"
#include <fstream>
#include <stdexcept>

vector<char> readFile(const string& path) {
    ifstream fin(path, ios::binary);
    if (!fin) {
        throw runtime_error("Failed to open input file: " + path);
    }

    vector<char> buffer;
    char ch;
    while (fin.get(ch)) {
        buffer.push_back(ch);
    }

    fin.close();
    return buffer;
}

void writeFile(const string& path, const vector<char>& data) {
    ofstream fout(path, ios::binary);
    if (!fout) {
        throw runtime_error("Failed to open output file: " + path);
    }

    for (int i = 0; i < (int)data.size(); i++) {
        fout.put(data[i]);
    }

    fout.close();
}
