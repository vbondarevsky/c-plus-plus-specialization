#include <iostream>
#include <vector>

int main() {
    int N, R;
    std::cin >> N >> R;

    uint64_t weight = 0;
    for (auto i = 0; i < N; ++i) {
        int W, H, D;
        std::cin >> W >> H >> D;
        weight += static_cast<uint64_t >(W) * H * D;
    }
    weight *= R;

    std::cout << weight << std::endl;
    return 0;
}