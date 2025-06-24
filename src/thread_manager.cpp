#include "../include/thread_manager.h"
#include "../include/encryptor.h"
#include <thread>

using namespace std;

void parallelEncrypt(vector<char>& buffer, int threadCount, char key) {
    vector<thread> threads;
    int size = buffer.size();
    int chunk = (size + threadCount - 1) / threadCount;

    for (int i = 0; i < threadCount; ++i) {
        int start = i * chunk;
        int end = min(start + chunk, size);
        threads.emplace_back(encryptChunk, ref(buffer), start, end, key);
    }

    for (auto& t : threads) t.join();
}
