#include <iostream>
#include <ostream>

int main() {
    int a, b;
    int n;
    while (std::cin >> n) {
        while (n--) {
            std::cin >> a >> b;
            std::cout << a + b << std::endl;
        }
    }
}