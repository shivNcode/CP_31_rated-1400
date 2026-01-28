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
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        arr[i] = arr[i]%k;
    }
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        int val = k - arr[i];
        if(val>0 && arr[i]!=0){
            mpp[val]++;
        }
    }
    int maxi = 0;
    for(auto it:mpp){
        maxi = max(maxi , it.first + ((it.second-1)*k));
    }
    if(maxi!=0) cout << maxi+1 << endl;
    else cout << 0 << endl;
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

