#include "../include/thread_manager.h"
#include "../include/encryptor.h"

void parallelEncrypt(vector<char>& buffer, int threadCount, const string& password) {
    vector<thread> threads;
    int n = buffer.size();
    int chunkSize = (n + threadCount - 1) / threadCount;

    auto encryptChunk = [&](int start) {
        int end = min(start + chunkSize, n);
        for (int i = start; i < end; i++) {
            buffer[i] ^= password[i % password.size()];
        }
    };

    for (int i = 0; i < (int)threadCount; i++) {
        int startIndex = i * chunkSize;
        if (startIndex >= n) break;
        threads.push_back(thread(encryptChunk, startIndex));
    }

    for (int i = 0; i < (int)threads.size(); i++) {
        threads[i].join();
    }
}
