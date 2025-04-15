#include <bits/stdc++.h>
using namespace std;


// Given a list of values, finds the minimum total amount of movement needed to make them all equal.
template<typename T_out, typename T_in> T_out min_equal_distance(vector<T_in> values) {
    if (values.empty())
        return 0;
 
    int n = int(values.size());
    nth_element(values.begin(), values.begin() + n / 2, values.end());
    T_in median = values[n / 2];
    T_out total = 0;
 
    for (T_in x : values)
        total += abs(x - median);
 
    return total;
}

 
// Given a list of values, finds the minimum total amount of movement to make them contiguous (x, x + 1, x + 2, ...).
template<typename T_out, typename T_in> T_out min_contiguous_distance(vector<T_in> values) {
    if (!is_sorted(values.begin(), values.end()))
        sort(values.begin(), values.end());
 
    for (int i = 0; i < int(values.size()); i++)
        values[i] -= i;
 
    return min_equal_distance<T_out>(values);
}