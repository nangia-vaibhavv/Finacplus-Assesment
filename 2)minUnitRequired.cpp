

// using greedy therefore sorting
#include <bits/stdc++.h>
using namespace std;

void unitsRequired(int n, int arr[], int target)
{
    sort(arr, arr + n);
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (target >= arr[i])
        {
            target -= arr[i];
            ans.push_back(arr[i]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout << "Units required=" << ans.size() << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    unitsRequired(n, arr, target);
    return 0;
}




// memoization approach

// #include<bits/stdc++.h>
// using namespace std;
//     int unitsRequired(int ind,vector<int>&nums,int target){
//         if(ind==0){
//             if(target%nums[0]==0)return target/nums[0];
//             return 1e9;
//         }
//         int notTake=0+unitsRequired(ind-1,nums,target);
//         int take=INT_MAX;
//         if(nums[ind]<=target){
//             take=1+unitsRequired(ind,nums,target-nums[ind]);
//         }
//         int ans= min(take,notTake);
//         if(ans>=1e9)return -1;
//         return ans;
//     }

 
//     int main(){
//         int n;
//         cin>>n;
//         vector<int>arr(n);
//         vector<int>res;

//         for(int i=0;i<n;i++)cin>>arr[i];
//         int amount;
//         cin>>amount;
//         cout<<unitsRequired(n,arr,amount)<<endl;
//         return 0;
//     }





