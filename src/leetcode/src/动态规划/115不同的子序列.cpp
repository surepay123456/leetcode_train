#include <bits/stdc++.h>

#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int numDistinct(string s, string t) {
        // s里面有多少个t
        int m = s.size();
        int n = t.size();
        vector<vector<uint64_t>> dp(m + 1, vector<uint64_t>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1; // 表示有空字符串的个数
        }
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0; // s此时为空字符串
        }
        dp[0][0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        
        return dp[m][n];
    }
};

int main(){
    string s("xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo");
    string t("rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys");
    Solution solution;
    cout << solution.numDistinct(s, t) << endl;
    return 0;
}

/*
    1 0 0 0 0 0 0
m   1 0 0 0 0 0 0 


*/