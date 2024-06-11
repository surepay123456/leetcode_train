#include <iostream>
#include <string>

int main() {
    std::string s;
    int n;
    int sum;
    int result;
    while (std::cin >> n) {
        if (n == 0) {
            return 0;
        }
        std::cin.ignore();
        std::getline(std::cin, s);
        sum = 0;
        n = 0;
        result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }

            sum += s[i] - '0';
            n++;
        }
        int average = sum / n;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] - '0' > average) {
                result += s[i] - '0' - average;
            }
        }
        std::cout << result << std::endl;
    }
}