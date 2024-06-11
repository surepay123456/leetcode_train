#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

int main() {
    std::string s;
    while (std::getline(std::cin, s)) {
        int n = 0;
        double sum = 0;
        bool flag = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ')
                continue;
            else if (s[i] == 'A') {
                sum += 4;
                n++;
            } else if (s[i] == 'B') {
                sum += 3;
                n++;
            } else if (s[i] == 'C') {
                sum += 2;
                n++;
            } else if (s[i] == 'D') {
                sum += 1;
                n++;
            } else if (s[i] == 'F') {
                sum += 0;
                n++;
            }

            else {
                flag = false;
                std::cout << "Unknown" << std::endl;
                break;
            }
        }
        if (flag) printf("%.2f\n", sum / static_cast<double>(n));
    }
}