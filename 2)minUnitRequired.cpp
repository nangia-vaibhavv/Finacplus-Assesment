#include<bits/stdc++.h>
using namespace std;

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        for(int target=0;target<=amount;target++)
        {
            if(target%coins[0]==0)dp[0][target]=target/coins[0];
            else dp[0][target]=1e9;
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int target=0;target<=amount;target++)
            {
                int nottake=dp[ind-1][target];
        int take=INT_MAX;
        if(coins[ind]<=target)take=1+dp[ind][target-coins[ind]];
                dp[ind][target]=min(take,nottake);
            }
        }
        int ans=dp[n-1][amount];
        if(ans>1e8)return -1;
        else return ans;
    }
    int main(){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int amount;
        cin>>amount;
        cout<<coinChange(arr,amount);
        return 0;
    }