#include <bits/stdc++.h>
using namespace std;
int superDigit(string n, int k) {
    
    long long t = 0;
    for(auto i: n){
        t += i-'0';
    }
    t *= k;
    string s = to_string(t);
    if(s.length() == 1){
        return t;
    }else{
        return superDigit(s, 1);        
    }
}