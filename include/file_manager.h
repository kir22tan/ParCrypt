#pragma once

#include <vector>
#include <string>
using namespace std;

vector<char> readFile(const string& path);

void writeFile(const string& path, const vector<char>& data);
