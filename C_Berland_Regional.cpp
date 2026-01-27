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
    int n ;
    cin >> n;
    vector<int> u(n) , s(n);
    vector<vector<int>> arr(n+1);
    for(int i=0;i<n;i++) cin >> u[i];
    for(int i=0;i<n;i++){
        cin >> s[i];
        arr[u[i]].push_back(s[i]);
    }
    for(int i=1;i<=n;i++){
        sort(arr[i].begin() , arr[i].end());
        int j = 1;
        for(int i = 0;i<arr[i].size();i+=j){
            
        }
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

