
#include <vector>
#include <cstdlib>  // malloc/free 사용을 위한 헤더

class MemoryPool {
private:
    std::vector<void*> pool;
    std::size_t blockSize;

public:
    MemoryPool(std::size_t size, std::size_t count) : blockSize(size) {
        for (std::size_t i = 0; i < count; ++i) {
            pool.push_back(malloc(blockSize));  // 새로운 메모리 블록을 할당하여 벡터에 저장
        }
    }
    void* allocate() {
        if (pool.empty()) return malloc(blockSize);  // 메모리 풀이 비어 있으면 새로 할당
        void* block = pool.back();
        pool.pop_back();
        return block;  // 기존 블록 재사용
    }

    void deallocate(void* ptr) {
        pool.push_back(ptr);  // 사용한 메모리를 다시 저장하여 재사용 가능
    }

    ~MemoryPool() {
        for (void* block : pool) free(block);  // 메모리 풀에 남아 있는 블록들 해제
    }
