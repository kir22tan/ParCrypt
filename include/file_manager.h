#pragma once
#include <vector>
#include <string>

using namespace std;

vector<char> readFile(const string& filePath);
void writeFile(const string& filePath, const vector<char>& data);
