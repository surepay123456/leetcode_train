#include <bits/stdc++.h>

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet;
        for (int i = 0; i < nums1.size(); i++) {
            if (hashSet.find(nums1[i]) == hashSet.end()) {
                hashSet.insert(nums1[i]);
            }
        }

        vector<int> result;
        unordered_set<int> resultsHash;
        for (int i = 0; i < nums2.size(); i++) {
            if (hashSet.find(nums2[i]) != hashSet.end()) {
                if (resultsHash.find(nums2[i]) == resultsHash.end()) {
                    result.push_back(nums2[i]);
                    resultsHash.insert(nums2[i]);
                }
            }
        }
        return result;
    }
};