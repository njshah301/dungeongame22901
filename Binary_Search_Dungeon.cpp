#include <bits/stdc++.h>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

/*
Author :- Kanishk Patel
Project :- Dungeon Game
Objective :- Minimize initial health using ternary search algorithm to enter the dungeon
    --> This code will calculate minimum health required for knight to enter a dungeon.
    --> calculateMinimumHP will accept dungeon as parameter and calculate minimum health using ternary search algorithm.
    --> minimum HP will be in range [1,1000*(rn+cn)+1].
    --> range of HP will be divided in 3 sub parts and we will have two median values.
    --> rn indicates row number and cn indicates column number.
    --> acceptable is implemented using dynamic programming which will return 1 if knight traverse dungeon with initHealth sucessfully.
    --> initHealth indicates initial health.
    --> calculateMinimumHP will minimize initial health and return minimum health.
    --> time complexity for this algorithm is of order O(2*rn*cn*log3(Z)), where Z=1000*(rn+cn)+1
*/

int rn,cn;
int calculateMinimumHP(vector<vector<int>>& dungeon);
bool acceptable(vector<vector<int>>& dungeon, int initHealth);

int main() 
{
vector<vector<int>> matrix={
    {-2,-3,3 },
    {-5,-10,1},
    {10,30,-5}
};
cout<<"Entered Matrix is shown below:\n\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }    
 // function call below will use inary search algorithm to calculate minimum HP to enter the dungeon
    cout<<"\nMinimum Health Required to rescue the princess = "<<calculateMinimumHP(matrix);
 
    return 0;
}


int calculateMinimumHP(vector<vector<int>>& dungeon)
{
    rn=dungeon.size();                             //find row number
    cn=dungeon[0].size();                          //find column number
    int minh=1, maxh=1000*(rn+cn)+1, ans=maxh, mid1, mid2;  //if all elements are positive then, ans=1 else worst case scenario(all elements are -1000) ans=1000*(rn+cn)+1
    while(minh<=maxh)                              //Binary Search Algorithm
    {
        while(minh<=maxh)
        {
            mid1=minh+(maxh-minh)/3;
            mid2=maxh-(maxh-minh)/3;
            if(acceptable(dungeon,mid1))                
            {
                ans=mid1;
                maxh=mid1-1;
            }
            else if(acceptable(dungeon,mid2))                                      
            {
                ans=mid2;
                minh=mid1+1;
                maxh=mid2-1;
            }
            else
            {
                minh=mid2+1;
            }
        }
    }
    return ans;
}

bool acceptable(vector<vector<int>>& dungeon, int initHealth)
{
    vector<vector<int>> test(rn, vector<int>(cn, 0));     // vector with all initial value 0
    test[0][0]= initHealth + dungeon[0][0];               // enters in the first cell of dungeon
    for(int i=0; i<rn; ++i)
    {
        for(int j=0; j<cn; ++j)
        {
            if(i>0 && test[i-1][j]>0)                     // if knight advances in row(horizontal)
            {
                test[i][j]=max(test[i][j],test[i-1][j]+dungeon[i][j]);
            }
            if(j>0 && test[i][j-1]>0)                     // if knight advances in column(vertical)
            {
                test[i][j]=max(test[i][j],test[i][j-1]+dungeon[i][j]);
            }
        }
    }
    return test[rn-1][cn-1]>0;                           // if kinght survives with initial health then BINGO(1)
}