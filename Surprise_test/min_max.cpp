#include <bits/stdc++.h>
using namespace std;
int maxMin(int k, vector<int> arr) {
    long long n = arr.size();
    sort(arr.begin(), arr.end());
    int diff = INT_MAX;
    for(int i = 0 ; i < n-k+1; i++){
        diff = min(arr[k-1+i] - arr[i], diff);
    }
    return diff;
}