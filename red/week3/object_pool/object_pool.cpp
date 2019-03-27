#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>

using namespace std;

template<class T>
class ObjectPool {
private:
    T* ReuseObject() {
        T* object = nullptr;
        if (!free.empty()) {
            object = free.front();
            free.pop();
            allocated.insert(object);
        }
        return object;
    }

public:
    T* Allocate() {
        T* object = ReuseObject();
        if (object == nullptr) {
            object = new T;
            allocated.insert(object);
        }
        return object;
    }

    T* TryAllocate() {
        return ReuseObject();
    }

    void Deallocate(T* object) {
        auto it = allocated.find(object);
        if (it == end(allocated)) {
            throw invalid_argument("Object doesn't exist");
        }
        free.push(*it);
        allocated.erase(it);
    }

    ~ObjectPool() {
        while (!free.empty()) {
            delete free.front();
            free.pop();
        }
        for (auto object : allocated) {
            delete object;
        }
    }

private:
    set<T*> allocated;
    queue<T*> free;
};

void TestObjectPool() {
    ObjectPool<string> pool;

    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();

    *p1 = "first";
    *p2 = "second";
    *p3 = "third";

    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");

    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");

    pool.Deallocate(p1);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}
