#include <bits/stdc++.h>
#include <dbg.h>

#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> h;
        vector<vector<string>> ans;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> a(26, 0);
            for (int j = 0; j < strs[i].size(); j++) {
                a[strs[i][j] - 'a']++;
            }
            // 遍历已经分类
            bool isContained = false;
            for (int k = 0; k < h.size(); k++) {
                if (isSame(a, h[k])) {
                    ans[k].push_back(strs[i]);
                    isContained = true;
                    break;
                }
            }
            if (!isContained) {
                h.push_back(a);
                ans.resize(ans.size() + 1);
                ans[ans.size() - 1].push_back(strs[i]);
            }
            // dbg(ans);
        }
        return ans;
    }
    bool isSame(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution;
    dbg(solution.groupAnagrams(strs));
    return 0;
}