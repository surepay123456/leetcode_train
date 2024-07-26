#include <bits/stdc++.h>

#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
class LUPrefix {
   public:
    LUPrefix(int n) { x = 1; }

    void upload(int video) { set.insert(video); }

    int longest() {
        while (set.count(x)) {
            x++;
        }
        return x - 1;
    }

   private:
    unordered_set<int> set;
    int x;
};
