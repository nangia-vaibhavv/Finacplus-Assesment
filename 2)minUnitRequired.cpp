#include<bits/stdc++.h>
using namespace std;

    int unitsRequired(vector<int>& units, int amount) {
        int n=units.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        for(int target=0;target<=amount;target++)
        {
            if(target%units[0]==0)dp[0][target]=target/units[0];
            else dp[0][target]=1e9;
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int target=0;target<=amount;target++)
            {
                int nottake=dp[ind-1][target];
        int take=INT_MAX;
        if(units[ind]<=target)take=1+dp[ind][target-units[ind]];
                dp[ind][target]=min(take,nottake);
            }
        }
        int ans=dp[n-1][amount];
        if(ans>1e8)return -1;
        else return ans;
    }

    // MEMOIZATION FUNCTION
    //  int solve(int ind, int target, vector<int>&coins, vector<vector<int>>&dp)
    // {
    //     if(ind==0)
    //     {
    //         if(target%coins[0]==0)return target/coins[0];
    //         return 1e9;
    //     }
    //     if(dp[ind][target]!=-1) return dp[ind][target];
    //     int nottake=solve(ind-1,target,coins,dp);
    //     int take=INT_MAX;
    //     if(coins[ind]<=target)take=1+solve(ind,target-coins[ind],coins,dp);
    //     return dp[ind][target]= min(take,nottake);
    // }
    int main(){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int amount;
        cin>>amount;
        cout<<unitsRequired(arr,amount);
        return 0;
    }
