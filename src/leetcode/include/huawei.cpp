#include "header.h"
#include <bits/stdc++.h>
class Solution1{
    
    public:
        double averageLenght(string str){
            vector<int> nums;
            int num = 0;
            for(auto& c : str){
                if(c == ' '){
                   nums.push_back(num);
                   num = 0; 
                }
                else{
                    num++;
                }
            }
            nums.push_back(num);
            double sum = 0;
            for(auto &n : nums){
               sum += n; 
            }
            return sum/nums.size();
        }
};


class Solution2{

public:
    void traverse(string& str){
        for(char& c : str){
            //
            if(c == 'a'|| c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                uppcase(c); 
            }
            else{
                lowercase(c);
            }
        }
    }
private:
    void uppcase(char& ch){
        if('a' <= ch && ch <= 'z'){
            ch = 'A' + (ch - 'a');
        }
        return;
    }
    
    void lowercase(char& ch){
        if('A' <= ch &&  ch <= 'Z'){
            ch = 'a' + (ch - 'A');
        }
        return;
    }
};

int main()
{
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;
    cout << int('A') << endl;
    cout << int('Z') << endl;
    
    string str;   
    // // cin >> str;
    getline(cin, str);

    // Solution1 solution;
    // cout << std::fixed << std::setprecision(2) <<   solution.averageLenght(str);
    // return 0;
    // char a = 'A';
    // char b = 'b';
    // cout << int(a) << endl;
    // cout << int(b) << endl;

    Solution2  solution;
    solution.traverse(str);
    cout  <<  str << endl;
        return 0; 

}
