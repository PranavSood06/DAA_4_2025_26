#include<bits/stdc++.h>
using namespace std;
/*
Ques
Given:
An array of positive integers arr[]


A target sum S


Task:
 Find how many subsets of arr[] sum exactly to S.
Output:
 An integer representing the number of valid subsets.
*/

void helper(vector<int> &arr,int s,int sum,int curr,int &totalsubsets){
    if(curr == arr.size()){
        if(sum == s) totalsubsets++;
        return;
    }
    if(sum==s){
        totalsubsets++;
        sum=0;
        return ;
    }
    if(sum>s){
        sum=0;
        return ;
    }
    helper(arr,s,sum+arr[curr],curr+1,totalsubsets);
    helper(arr,s,sum,curr+1,totalsubsets);
}

int findtotalsubsets(vector<int> &arr,int &s){
    int sum = 0;
    int totalsubsets = 0;
    int curr = 0;
    helper(arr,s,sum,curr,totalsubsets);
    return totalsubsets;
}

int main(){
    int s;
    cin>>s;
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int subsets = findtotalsubsets(arr,s);
    cout<<subsets<<endl;
    return 0;
}