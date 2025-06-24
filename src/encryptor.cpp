#include "../include/encryptor.h"

using namespace std;

void encryptChunk(vector<char>& data, int start, int end, char key) {
    for (int i = start; i < end; ++i) {
        data[i] ^= key;
    }
}
