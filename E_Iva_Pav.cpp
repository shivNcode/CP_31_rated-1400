#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
int bs(int low , int high , vector<int>& arr , vector<vector<int>>& pr , int k){
    int l = low , ans = -1;
    //cout << low << " " << high << endl;
    while(low<=high){
        int mid = low + (high-low)/2;
        int val = 0 , adder = 1 , zero = 0;
        for(int i=0;i<32;i++){
            zero = pr[mid][i] - pr[l-1][i];
            if(zero==0){
                val+=adder;
            }
            adder*=2;
        }
        //cout << val << endl;
        if(val>=k){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}
void Solve()
{
    // write solution here.
    int n;
    cin >> n;
    vector<int> arr(n+1 , 0);
    vector<vector<int>> pr(n+1 , vector<int>(32 , 0));
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        int v = arr[i];
        for(int j=0;j<32;j++){
            if(v%2==0){
                pr[i][j] = 1;
            }
            else pr[i][j] = 0;
            v/=2;
            if(i>0) pr[i][j]+=pr[i-1][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<15;j++){
            //cout << pr[i][j] << " ";
        }
        //cout << endl;
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int l , k;
        cin >> l >> k ;
        int ans = bs(l , n , arr , pr , k);
        cout << ans << " ";
    }
    cout << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}

/*
Notes:
Which include the use of the prefix zero for the bitmask operation and also the use of binary search and basicall when we have give l and we look for the r then we can traverse the whole r from l so we need to check for largest r index so we do binary search for this and when we take a particular r then we have to check for each bit postion in the range of 1-32 wether there is zero bit at any postion from l to r if there then we can't add the power of s of that postion to the complete AND and ones we get value like this we will we will check for k

*/