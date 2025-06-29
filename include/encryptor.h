#pragma once
#include <vector>
#include <string>

using namespace std;

vector<char> attachHeader(const vector<char>& data, const string& password);
bool validatePasswordAndDecrypt(vector<char>& data, const string& password);
