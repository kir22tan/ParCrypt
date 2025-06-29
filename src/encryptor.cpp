#include "../include/encryptor.h"

void xorEncrypt(vector<char>& data, const string& key) {
    if (key.empty()) return;
    int n = key.length();
    for (int i = 0; i < (int)data.size(); i++) {
        data[i] ^= key[i % n];
    }
}

vector<char> prepareEncryptedBuffer(const vector<char>& raw, const string& key) {
    vector<char> data = raw;
    xorEncrypt(data, key);

    vector<char> res;
    res.push_back((char)key.length());

    for (int i = 0; i < (int)key.length(); i++) {
        res.push_back(key[i]);
    }

    res.insert(res.end(), data.begin(), data.end());
    return res;
}

bool validatePasswordAndDecrypt(vector<char>& buf, const string& key) {
    if (buf.empty()) return false;

    int len = (int)buf[0];
    if ((int)buf.size() < 1 + len) return false;

    string pass(buf.begin() + 1, buf.begin() + 1 + len);
    if (pass != key) return false;

    vector<char> data(buf.begin() + 1 + len, buf.end());
    xorEncrypt(data, key);
    buf = data;
    return true;
}
