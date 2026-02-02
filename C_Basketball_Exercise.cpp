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
    vector<int> a(n) , b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    vector<int> dp1(n , 0) , dp2(n , 0);
    dp1[0] = a[0];
    dp2[0] = b[0];
    for(int i=1;i<n;i++){
        dp1[i] = max(a[i] + dp2[i-1] , dp1[i-1]);
        dp2[i] = max(b[i] + dp1[i-1] , dp2[i-1]);
    }
    int ans = max(dp1[n-1] , dp2[n-1]);
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

