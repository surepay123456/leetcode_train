#include <bits/stdc++.h>

#include <cstdio>
#include <iostream>
#include <string>

bool isHuiwen(std::string str);
int main() {
    // std::string str;
    // std::cin >> str;
    std::string str = "aaa";
    // 计算 str 中子串是回文子串的个数
    // 子串起始位置i 末尾位置j
    // 暴力方法 O(n^2) 每一次判断是否是回文子串
    // 动态规划法 dp[n] 指的是以str[n] 结尾的回文子串 总的回文子串即sum(dp[n])
    // int result = 0;
    // for (int i = 0; i < str.size(); i++) {
    //     for (int j = i; j < str.size(); j++) {
    //         std::string temp = str.substr(i, j - i + 1);
    //         if (isHuiwen(temp)) result++;
    //     }
    // }

    // //双指针法 以当前遍历的位置左右指针双向移动
    // // 问题： 不适合回文串是偶数的情况
    // int left, right;
    // int result = 0;
    // for (int i = 0; i < str.size(); i++) {
    //     left = i;
    //     right = i;
    //     while (left >= 0 && right < str.size()) {
    //         if (str[left] == str[right]) {
    //             result++;
    //             left--;
    //             right++;
    //         } else {
    //             break;
    //         }
    //     }
    // }

    // std::cout << result << std::endl;
    return 0;
}

bool isHuiwen(std::string str) {
    int i = 0;
    int j = int(str.size()) - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}