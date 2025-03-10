#include <bits/stdc++.h>

using namespace std;

    // For every i, finds the largest j < i such that `compare(values[j], values[i])` is true, or -1 if no such j exists.
    template<typename T, typename T_compare>
    vector<int> closest_left(const vector<T> &values, T_compare &&compare) {
        int n = int(values.size());
        vector<int> closest(n);
        vector<int> stack;

        for (int i = 0; i < n; i++) {
            while (!stack.empty() && !compare(values[stack.back()], values[i]))
                stack.pop_back();

            closest[i] = stack.empty() ? -1 : stack.back();
            stack.push_back(i);
        }

        return closest;
    }




// For every i, finds the smallest j > i such that `compare(values[j], values[i])` is true, or `n` if no such j exists.
template<typename T, typename T_compare>
vector<int> closest_right(const vector<T> &values, T_compare &&compare) {
    int n = int(values.size());
    vector<int> closest(n);
    vector<int> stack;

    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty() && !compare(values[stack.back()], values[i]))
            stack.pop_back();

        closest[i] = stack.empty() ? n : stack.back();
        stack.push_back(i);
    }

    return closest;
}