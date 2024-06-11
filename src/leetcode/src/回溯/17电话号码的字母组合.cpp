
#include "../../include/header.h"
#include <dbg.h>
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        size = digits.size();
        if(size == 0) return {};
        backtracking(digits, 0);
        return ans;
    }

private:

    vector<string> ans;
    string path;
    int size;

    void backtracking(string digits, int index ){
        if(path.size() == size){
            ans.push_back(path);
            return;
        }
        if(index == size) cout << "error" << endl;
        
        string selectString;
        switch (digits[index])
        {
        case '2':
            selectString = "abc";
            break;
        case '3':
            selectString = "def";
            break;
        case '4':
            selectString = "ghi";
            break;
        case '5':
            selectString = "jkl";
            break;
        case '6':
            selectString = "mno";
            break;
        case '7':
            selectString = "pqrs";
            break;
        case '8':
            selectString = "tuv";
            break;
        
        case '9':
            selectString = "wxyz";
            break;
        }   

        for(int i = 0; i <= selectString.size() - 1; i++){
            path.push_back(selectString[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }
};

int main(){
    string digits("23");
    Solution solution;
    vector<string> ans = solution.letterCombinations(digits);
    dbg(ans);
    for(auto& str : ans){
        cout << str << endl;
    }
}