#pragma once
#include <vector>
#include <string>

using namespace std;

void xorEncrypt(vector<char>& data, const string& password);

vector<char> prepareEncryptedBuffer(const vector<char>& rawData, const string& password);

bool validatePasswordAndDecrypt(vector<char>& encryptedBuffer, const string& inputPassword);
