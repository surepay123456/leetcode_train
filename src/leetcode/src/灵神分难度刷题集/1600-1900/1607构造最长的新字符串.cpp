#include <bits/stdc++.h>

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestString(int x, int y, int z) {
        return (min(x, y) * 2 + (x != y) + z) * 2;
    }
};