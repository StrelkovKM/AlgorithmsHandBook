#include <atomic>

class Spinlock {
private:
    std::atomic_flag flag = ATOMIC_FLAG_INIT;

public:
    void lock() {
        while( flag.test_and_set() != true) {
        }
        return;
    }

    void unlock() {
        
    }
};