#include <bits/stdc++.h>
#include <math.h>
#include <ratio>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        //检测到循环则不是快乐数
        unordered_set<int> hashSet;
        while (n != 1) {
            if (hashSet.find(n)!= hashSet.end()) {
                return false;
            }
            hashSet.insert(n);
            n = nextNums(n);
        }
        
        return true; 
    }

    int nextNums(int n ){
        int sum = 0;
        int k = 1;
        while (n) {
            int temp = n % 10;
            n = n / 10;
            sum += temp * temp;
        }
        return sum;
    }
    
};  

int main(){
    Solution solution;
    solution.isHappy(7);
    return 0;
}