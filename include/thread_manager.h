#pragma once
#include <vector>
#include <string>

using namespace std;

void parallelEncrypt(vector<char>& data, int threadCount, const string& password);
