#include <iostream>
#include <bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define maxn 1000
// Constraint on energy boost level and Traps are defined here. 
const int maximum_number=1000,minimum_number=-1000;
 
using namespace std;  
 
int dp[201][201]; //dp table to memorize the repetitive recursive calls
     int dungeon(vector<vector<int>> &mat,int i,int j)
    {
          if(dp[i][j]!=-1)  // if we already encounter the subproblem then return it directly
          {
              return dp[i][j];
          }
        int ans;
        if(i==mat.size()-1 && j==mat[0].size()-1) // boundary levels
        {
            ans=mat[i][j];
        }
        else if(j==mat[0].size()-1)
        {
           ans=dungeon(mat,i+1,j)+mat[i][j];
         
        }
       else  if(i==mat.size()-1)
        {
             ans=dungeon(mat,i,j+1)+mat[i][j];
        }
        else{
         ans=max(dungeon(mat,i,j+1),dungeon(mat,i+1,j))+mat[i][j]; // either move rightwards or downwards
        }                                                         
        ans=ans>=0 ? 0:ans;  //if ans(needed health at some instance) is already positive then no extra health needed                                  
          dp[i][j]=ans;
        return ans;
    }
  
     
 
int main()
 
{
memset(dp,-1,sizeof(dp)); 
  int n=3,m=3;
vector<vector<int>> matrix={
    {-2,-3,3 },
    {-5,-10,1},
    {10,30,-5}
};
cout<<"Entered Matrix is shown below:\n\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    
   // We need to give absolute of (returned answer) + 1 health to rescue princess
    cout<<"\nMinimum Health Required to rescue the princess = "<<abs(dungeon(matrix,0,0))+1; 
 
    return 0;
}
