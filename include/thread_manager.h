#pragma once
#include <vector>
#include <string>
#include <thread>

using namespace std;

const int THREAD_COUNT = 4;

void parallelEncrypt(vector<char>& buffer, int threadCount, const string& password);
