/*Problem Statement: Given a String, 
find the length of longest substring without any repeating character.*/

#include <bits/stdc++.h>

#include<unordered_set>

using namespace std;

int Solve(string str){
    if(str.size()==0)
    return 0;

    int maxans=INT_MIN;
    unordered_set<int>set;
    int l=0;
    for(int r=0; r<str.length(); r++){
        if(set.find(str[r])!=set.end()){
            while(l<r && set.find(str[r])!=set.end()){
                set.erase(str[l]);
                l++;
            }
        }
        set.insert(str[r]);
        maxans=max(maxans, r-l+1);
    }
    return maxans;
}
int main() {
  string str = "takeUforward";
  cout << "The length of the longest substring without repeating characters is " << 
  Solve(str);
  return 0;
}