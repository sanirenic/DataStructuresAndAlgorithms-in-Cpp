/*Problem Statement: Given two arrays representing children’s green factor and cookie sizes, 
the goal is to maximise the number of content children.

Each child i has a greed factor of g[i], which is the minimum size of a cookie that will make the child content.
Each cookie j has a size of s[j]. If s[j] >= g[j], we can assign cookie j to child i, making the child content. 
Each child can only receive one cookie.*/

#include <vector>   
#include <algorithm>
#include <iostream>

using namespace std;

int findContentChildren(vector<int>& greed, vector<int>& cookieSize){
    int n=greed.size();
    int m=cookieSize.size();

    sort(greed.begin(), greed.end());
    int l=0;
    int r=0;

    while(l<m && r<n){
        if(greed[r]<=cookieSize[l]){
            r++;
        }
        l++;
    }
    return r;
}

int main(){
    vector<int> greed={1, 5, 3, 3, 4};
    vector<int>cookieSize={4, 2, 1, 2, 1, 3};

    cout<<"Array representing greed; ";
    for(int i=0; i<greed.size(); i++){
        cout<<greed[i]<<" ";
    }
    cout<<endl;

    cout<<"Array representing cookie size: ";
    for(int i=0; i<cookieSize.size(); i++){
        cout<<cookieSize[i]<<" ";
    }
    int ans=findContentChildren(greed, cookieSize);
    cout<<endl<<"no of kids assigned cookies "<<ans;
    cout<<endl;
    return 0;
}