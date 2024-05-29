#include <bits/stdc++.h>
#include <dbg.h>

#include <codecvt>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 将nums2转换为单调栈
        // 每个值对值 来建立哈希表
        stack<int> greeterStack;
        unordered_map<int, int> hashTable;
        int n = nums2.size();
        greeterStack.push(nums2[n - 1]);
        hashTable.insert({nums2[n - 1] , -1});
        for (int i = n - 2; i >= 0; i--) {
            while (!greeterStack.empty()) {
                if (nums2[i] >= greeterStack.top()) {
                    greeterStack.pop();
                } else {
                    break;
                }
            }

            if (greeterStack.empty()) {
                hashTable.insert({nums2[i], -1});
                greeterStack.push(nums2[i]);
            } else {
                hashTable.insert({nums2[i], greeterStack.top()});
                greeterStack.push(nums2[i]);
            }
        }
        int n2 = nums1.size();
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            result.push_back(hashTable[nums1[i]]);
        }

        return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums1 {4,1,2};
    vector<int> nums2 { 1, 3, 4, 2};
    vector<int> result;
    result  = solution.nextGreaterElement(nums1, nums2);
    dbg(result);
    return 0;
}