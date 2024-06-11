#include <iostream>

int main() {
    int n, k;
    int sum = 0;
    while (std::cin >> n) {
        if (n == 0) return 0;
        while (n -- ) {
           std::cin >> k;
           sum += k; 
        }
        std::cout << sum << std::endl;
        sum = 0;
    }
}