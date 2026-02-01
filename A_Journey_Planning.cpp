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
    int n;
    cin >> n;
    vector<int> b(n);
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin >> b[i];
        arr[i].first = (i+1) - b[i];
        arr[i].second = b[i];
    }
    sort(arr.begin() , arr.end());
    int prev = -1e11;
    int val = arr[0].second , ans = 0;
    for(int i=0;i<n;i++){
        //cout << arr[i].first <<" "<<arr[i].second<<endl;
    }
    for(int i=0;i<n;i++){
        if(arr[i].first!=prev){
            prev = arr[i].first;
            val = arr[i].second;
        }
        else val+=arr[i].second;
        ans = max(ans , val);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}


/*
Notes:

*/

