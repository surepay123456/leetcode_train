#include <iostream>

int main() {
    int m, n, k;
    int sum = 0;
    while (std::cin >> m) {
        while (m--) {
            std::cin >> n;
            while (n--) {
                std::cin >> k;
                sum += k;
            }
            std::cout << sum << std::endl;
            sum = 0;
            if (m) std::cout << std::endl;
        }
    }
}