#include "../include/encryptor.h"

vector<char> attachHeader(const vector<char>& data, const string& password) {
    vector<char> result;
    result.push_back((char)password.length());
    for (char ch : password) result.push_back(ch);
    result.insert(result.end(), data.begin(), data.end());
    return result;
}

bool validatePasswordAndDecrypt(vector<char>& data, const string& password) {
    if (data.empty()) return false;

    int len = (int)data[0];
    if ((int)data.size() < 1 + len) return false;

    string stored(data.begin() + 1, data.begin() + 1 + len);
    if (stored != password) return false;

    vector<char> decrypted(data.begin() + 1 + len, data.end());
    for (int i = 0; i < decrypted.size(); i++) {
        decrypted[i] ^= password[i % password.length()];
    }

    data = decrypted;
    return true;
}
