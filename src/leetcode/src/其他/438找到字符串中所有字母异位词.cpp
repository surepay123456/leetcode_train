#include "../include/header.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;
        int i = 0;
        int j = 0;
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        int valid = 0;
        int n = s.size(); 
        int length = p.size();
        for(char c : p) need[c]++;
         
        while (j < n)
        {
            window[s[j]] ++;
            if(need.count(s[j])){
            if(window[s[j]] == need[s[j]]) valid ++; // 有个字符满足了数量要求
            }
            while(j - i + 1 >= length){
                if(valid == need.size()){               //找到字母异位词
                    ans.push_back(i);

                }
                //收缩window 
                if(need.count(s[i])){
                    // valid --;
                    if(window[s[i]] == need[s[i]]){
                        valid --;
                    }
                }
                window[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }

    bool checkAgagrams(string a, string b){
        if(a.size() != b.size()){
            return false;
        }

        int hash[26] = {0};
        
        for(int i = 0 ; i < b.size(); i++){
            hash[b[i] - 'a'] += 1;
        }

        for (int i = 0; i < a.size(); i++)
        {
            hash[a[i] - 'a'] -= 1;
        }
        
        for (int i = 0; i < 26; i++)
        {
            if(hash[i] != 0){
                return false;
            }
        }
    }
};

int main(){
    string s = "baa";
    string p = "aa";
    Solution solution;
    vector<int> ans;
    ans = solution.findAnagrams(s, p);
    for(auto& i : ans){
        cout << i << endl;
    }
    return 0;
}