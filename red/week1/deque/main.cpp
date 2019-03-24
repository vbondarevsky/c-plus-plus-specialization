#include "test_runner.h"
#include "deque.h"

using namespace std;

void TestDeque() {
    Deque<int> deque;
    ASSERT(deque.Empty());
    ASSERT_EQUAL(deque.Size(), 0u);
    deque.PushBack(5);
    ASSERT(!deque.Empty());
    ASSERT_EQUAL(deque.Size(), 1u);
    ASSERT_EQUAL(deque.Front(), 5);
    ASSERT_EQUAL(deque.Back(), 5);
    deque.PushFront(9);
    ASSERT_EQUAL(deque.Size(), 2u);
    ASSERT_EQUAL(deque.Front(), 9);
    ASSERT_EQUAL(deque.Back(), 5);

    try {
        deque.At(2);
        ASSERT(false);
    } catch (out_of_range& error) {
    } catch (exception& error) {
        ASSERT(false);
    }

    ASSERT_EQUAL(deque.At(0), 9);
    ASSERT_EQUAL(deque.At(1), 5);
    deque[1] = 11;
    ASSERT_EQUAL(deque.At(1), 11);

    deque.PushFront(3);
    deque.PushFront(7);
    ASSERT_EQUAL(deque.Size(), 4u);
    ASSERT_EQUAL(deque.At(0), 7);
    ASSERT_EQUAL(deque.At(1), 3);
    ASSERT_EQUAL(deque.At(2), 9);
    ASSERT_EQUAL(deque.At(3), 11);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestDeque);
    return 0;
}
