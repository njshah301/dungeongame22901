/*
             Program: Minimum required Health and optimal Path to rescue Princess
             Approach:Dynamic Programming Approach [Top - Down DP]
             Time Complexity: O(M*N)
             Space Complexity: O(M*N)
*/
 
#include <iostream>
#include <bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define maxn 1000
using namespace std;
const int maximum_number=1000,minimum_number=-1000;
void dungeon_game(vector<vector<int>> &matrix)
{
int n=matrix.size();
int m=matrix[0].size();
vector<vector<int>> dungeon(n+1,vector<int> (m+1,INT_MIN+maxn)); // 2D vector of size (n+1)*(m+1) initialize with minimum value
 
dungeon[n-1][m-1]=matrix[n-1][m-1]>=0? 0:matrix[n-1][m-1]; //if princess cell (last cell) has no traps then
                                                          //no extra health needed for particular instance
 
for(int i=n-1;i>=0;i--)
{
    for(int j=m-1;j>=0;j--)
    {
        if(i==n-1 && j==m-1) continue;
        int rightwards_cost=matrix[i][j]+dungeon[i][j+1];        
        int downwards_cost=matrix[i][j]+dungeon[i+1][j];
//if cost (rightwards or downwards) are already positive then
//no extra health needed at this particular instance
        rightwards_cost=rightwards_cost>=0 ? 0:rightwards_cost; 
        downwards_cost=downwards_cost>=0 ? 0: downwards_cost;
        dungeon[i][j]=max(rightwards_cost,downwards_cost); 
    }
}
 
cout<<"min health required to rescue Princess= "<<abs(dungeon[0][0])+1<<"\n\n";
 // Trace Back the optimal path
vector <pair<int,int>> min_path;
 
min_path.push_back({0,0}); // starting index (cell)
int x=0,y=0;
while(!(x==n-1 && y==m-1))
{
    int right=dungeon[x][y+1];
    int left=dungeon[x+1][y];
    if(right>=left)
    {
        x=x;
        y=y+1;
       
    }
    else
    {
        x=x+1;
        y=y;
    }
    if(!(x==n-1 && y==m-1))
     min_path.push_back({x,y}); // insertion of optimal cells into optimal path
}
 
cout<<"King should go for this path to save princess: \n\n";
 
for(auto path_to_min: min_path)
{
    cout<<"("<<path_to_min.first<<","<<path_to_min.second<<")"<<" -> ";
}
cout<<"("<<n-1<<","<<m-1<<")";
 
 
 
 
}
int main()
 
{
 
  int n,m;
  cout<<"Enter Number of rows and colums: \n";
  cin>>n>>m;
 
   vector <vector<int>> matrix(n,vector<int> (m));
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           matrix[i][j]=(rand()%(maximum_number + 1 - minimum_number)) + minimum_number;
       }
   }
cout<<"\nDungeon matrix set by the Dungeon Master is as follows:\n\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
   cout<<"\n";
   dungeon_game(matrix);
 
    return 0;
}

