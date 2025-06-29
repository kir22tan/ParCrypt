#include "../include/thread_manager.h"
#include <thread>
#include <algorithm>

void parallelEncrypt(vector<char>& data, int threadCount, const string& password) {
    vector<thread> threads;
    int n = data.size();
    int chunkSize = (n + threadCount - 1) / threadCount;

    auto encryptPart = [&](int startIndex) {
        int endIndex = min(startIndex + chunkSize, n);
        for (int i = startIndex; i < endIndex; i++) {
            data[i] ^= password[i % password.length()];
        }
    };

    for (int i = 0; i < threadCount; i++) {
        int start = i * chunkSize;
        if (start >= n) break;
        threads.push_back(thread(encryptPart, start));
    }

    for (int i = 0; i < threads.size(); i++) {
        threads[i].join();
    }
}
