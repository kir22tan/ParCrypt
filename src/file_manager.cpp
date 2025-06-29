#include "../include/file_manager.h"
#include <fstream>
#include <stdexcept>

vector<char> readFile(const string& path) {
    ifstream fin(path, ios::binary);
    if (!fin) throw runtime_error("Can't open: " + path);

    vector<char> data;
    char ch;
    while (fin.get(ch)) data.push_back(ch);

    fin.close();
    return data;
}


void writeFile(const string& filePath, const vector<char>& data) {
    ofstream fout(filePath, ios::binary);
    if (!fout.is_open()) throw runtime_error("Could not write to: " + filePath);

    for (int i = 0; i < data.size(); i++) fout.put(data[i]);
    fout.close();
}
