#include "test_runner.h"

using namespace std;

template<class T>
class Table {
public:
    Table(size_t rows, size_t columns) {
        Resize(rows, columns);
    }

    pair<size_t, size_t> Size() const {
        return {cells_.size(), (cells_.empty() ? 0 : cells_[0].size())};
    }

    vector<T>& operator[](size_t index) {
        return cells_[index];
    }

    const vector<T>& operator[](size_t index) const {
        return cells_[index];
    }

    void Resize(size_t rows, size_t columns) {
        cells_.resize(rows);
        for (auto& column: cells_) {
            column.resize(columns);
        }
    }

private:
    vector<vector<T>> cells_;
};

void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}
