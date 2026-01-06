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

void Solve() {
    // write solution here
    int n , k;
    cin>>n>>k;
    int ans = 1e18;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ans = min(ans , arr[i]);
    }
    sort(arr.begin() , arr.end());
    if(k>2){
        cout<<0<<endl;
        return;
    }
    else if(k==2){
        // vector<int> diff;

        // for(int i=0;i<n;i++){
        //     for(int j = i+1;j<n;j++){
        //         int val = abs(arr[i] - arr[j]);
        //         diff.push_back(val);
        //         ans = min(ans , val);
        //     }
        // }

        // for(int i=0;i<diff.size();i++){
        //     //cout<<diff[i]<<" ";
        //     vector<int> temp = arr;
        //     // temp.resize(temp.size()+1);
        //     // temp[temp.size()-1] = diff[i];
        //     temp.push_back(diff[i]);
        //     sort(temp.begin() , temp.end());
        //     for(int j=0;j<temp.size()-1;j++){
        //         //cout<<temp[j]<<" ";
        //         ans = min(ans , abs(temp[j]-temp[j+1]));
        //     }
        //     //cout<<endl;
        // }
        // cout<<ans<<endl;


        for(int i=0;i<n-1;i++){
        ans = min(ans , arr[i+1] - arr[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int diff = arr[j] - arr[i];

            // binary search for closest element to diff
            int pos = lower_bound(arr.begin(), arr.end(), diff) - arr.begin();

            if(pos < n){
                ans = min(ans , abs(arr[pos] - diff));
            }
            if(pos > 0){
                ans = min(ans , abs(arr[pos-1] - diff));
            }
        }
    }

    cout<<ans<<endl;

    
        return;
    }else{
        // int ans = 1e18;
        for(int i=0;i<n-1;i++){
            ans = min(ans , abs(arr[i]-arr[i+1]));
        }
        cout<<ans<<endl;
        return;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}


/*
Notes:

*/

