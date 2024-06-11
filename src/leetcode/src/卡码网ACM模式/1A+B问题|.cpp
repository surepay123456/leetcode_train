#include <iostream>
#include <ostream>

int main(){
    int a, b;
    while (std::cin >> a >> b) {
        std::cout << a + b << std::endl;
    }
}