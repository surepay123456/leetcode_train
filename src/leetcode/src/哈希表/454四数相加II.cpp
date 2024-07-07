#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums1.size(); i ++) {
            for (int j = 0; j < nums2.size(); j++) {
                hashMap[nums1[i] + nums2[j]] ++;
            }
        }

        int result = 0;
        for (int k = 0; k < nums3.size(); k++) {
            for (int l = 0; l < nums4.size(); l++) {
                if (hashMap.find(-(nums3[k] + nums4[l])) != hashMap.end()) {
                    result += hashMap[- nums3[k] - nums4[l]];
                }
            }
        }

        return result;
    }
};