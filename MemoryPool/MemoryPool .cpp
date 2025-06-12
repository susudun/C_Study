
#include <vector>
#include <cstdlib>  // malloc/free ����� ���� ���

class MemoryPool {
private:
    std::vector<void*> pool;
    std::size_t blockSize;

public:
    MemoryPool(std::size_t size, std::size_t count) : blockSize(size) {
        for (std::size_t i = 0; i < count; ++i) {
            pool.push_back(malloc(blockSize));  // ���ο� �޸� ����� �Ҵ��Ͽ� ���Ϳ� ����
        }
    }
    void* allocate() {
        if (pool.empty()) return malloc(blockSize);  // �޸� Ǯ�� ��� ������ ���� �Ҵ�
        void* block = pool.back();
        pool.pop_back();
        return block;  // ���� ��� ����
    }

    void deallocate(void* ptr) {
        pool.push_back(ptr);  // ����� �޸𸮸� �ٽ� �����Ͽ� ���� ����
    }

    ~MemoryPool() {
        for (void* block : pool) free(block);  // �޸� Ǯ�� ���� �ִ� ��ϵ� ����
    }
