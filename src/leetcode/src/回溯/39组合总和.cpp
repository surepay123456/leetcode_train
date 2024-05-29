
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../../include/header.h"

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        backtracking(candidates, sum, target);
        return ans;
    }

   private:
    vector<vector<int>> ans;
    vector<int> path;

    unordered_set<string> hashSet;

    void backtracking(vector<int>& candidates, int sum, int target) {
        if (sum == target) {
            //判断该组合是否已经在ans中
            vector<int> temp = path;
            sort(temp.begin(), temp.end());
            string strPath = vectorToString(temp);
            if (hashSet.find(strPath) == hashSet.end()) {
                ans.push_back(temp);
                hashSet.insert(strPath);
                return;
            }
        }

        if (sum > target) {
            return;
        }

        for (int i = 0; i <= candidates.size() - 1; i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, sum, target);
            path.pop_back();
            sum -= candidates[i];
        }
    }

    string vectorToString(const vector<int>& vec) {
        ostringstream oss;
        for (const auto& v : vec) {
            oss << v << ' ';
        }
        return oss.str();
    }
};

int main() {
    vector<int> candidates{2, 3, 5};
    Solution solution;
    vector<vector<int>> result = solution.combinationSum(candidates, 8);
    for (auto& vec : result) {
        for (auto& i : vec) {
            cout << i;
        }
        cout << endl;
    }
}