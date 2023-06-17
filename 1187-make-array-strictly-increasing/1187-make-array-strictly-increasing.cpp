class Solution {
public:
    int solve(int i,int j,int &a,int &b,int p,vector<vector<int>> &dp,vector<int> &v1,vector<int> &v2){
        if(i==a){
            return 0;
        }
        j = upper_bound(v2.begin()+j,v2.end(),p)-v2.begin();
        if(dp[i][j] != -1)return dp[i][j];
        if(j==b && v1[i]<=p)return 2001;
        int take = 2001,nottake = 2001;
        if(j!=b)
        take = solve(i+1,j+1,a,b,v2[j],dp,v1,v2)+1;
        if(v1[i]>p)
        nottake = solve(i+1,j,a,b,v1[i],dp,v1,v2);
        return dp[i][j] = min(take,nottake);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(),m=arr2.size();
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        sort(arr2.begin(),arr2.end());
        int a= solve(0,0,n,m,-1,dp,arr1,arr2);
        if(a>n)return -1;
        return a;
    }
};

// class Solution {
// private:
//     int dfs(vector<int>& arr1, vector<int>& arr2, vector<vector<int>>& dp, int i, int j, bool isPrevSwap) {
//         if (i == arr1.size()) return 0;
//         if (j == arr2.size()) return -1;
//         if (dp[i][j] == INT_MAX) {
//             // at each step, either perform a swap, or keep it the same (if possible)
//             if (isPrevSwap) {
//                 if (arr2[j] < arr1[i]) dp[i][j] = min(dp[i][j], dp[i-1][j]);
                
//             } else {
//                 if (arr1[i-1] < arr[i]) dp[i][j] = min(dp[i][j], dp[i-1][j]);
//             }
            
            
//         }
//         return dp[i][j];
//     }
// public:
//     int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
//         sort(arr2.begin(), arr2.end());
//         auto m{static_cast<int>arr1.size()};
//         auto n{static_cast<int>arr2.size()};
        
//         // dp[i][j] := number of swaps it takes to make arr1[0..i] strictly increasing
//         vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
//         return dfs(arr1, arr2, dp, 0, 0, false);
//     }
// };
