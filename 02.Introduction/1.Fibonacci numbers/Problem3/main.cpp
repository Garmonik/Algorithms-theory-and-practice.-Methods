#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

class Fibonacci final {
public:
    static int get_remainder(int64_t n, int m) {
        assert(n >= 1);
        assert(m >= 2);
        int64_t period = 0;
        const int64_t sz = std::min(n + 1, static_cast<int64_t>(6 * m + 2));
        std::vector<int64_t> F(sz, 0);
        F[0] = 0;
        F[1] = 1;
        // вычисляем период Пизано
        for (int64_t i = 2; i < sz; ++i) {
            F[i] = (F[i - 1] + F[i - 2]) % m;
            if (F[i] == 1 && F[i - 1] == 0) {
                period = i - 1;
                break;
            }
        }
        return period == 0 ? F[n] : F[n % period];
    }
};

int main() {
    int64_t n;
    int m;
    std::cin >> n >> m;
    std::cout << Fibonacci::get_remainder(n, m) << std::endl;
    return 0;
}
