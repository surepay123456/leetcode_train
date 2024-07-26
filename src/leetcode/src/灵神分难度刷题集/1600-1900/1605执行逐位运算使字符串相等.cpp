#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <dbg.h>
using namespace std;

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        bool b1 = (s.find('1') != string::npos);
        bool b2 = (target.find('1') != string::npos);
        // dbg(s.find('1'),target.find('1'));
        // dbg(b1, b2);
        return (b1 == b2);
    }
};
int main(){
    string s = "11";
    string target = "00";
    Solution solution;
    if (solution.makeStringsEqual(s, target)) {
        cout << "true" << endl; 
    }
    return 0;
}