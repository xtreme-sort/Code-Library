#include <bits/stdc++.h>
using namespace std;


template<bool maximum_mode>
int optimal_subarray_sum(const vector<int> &A) {
    int sum = 0, best = 0;
 
    for (const auto &a : A) {
        sum = maximum_mode ? max(sum + a, INT64_C(0)) : min(sum + a, INT64_C(0));
        best = maximum_mode ? max(best, sum) : min(best, sum);
    }
 
    return best;
}
