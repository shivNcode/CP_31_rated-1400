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
static const int MOD = 1000000007;

int fac(int n){
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = (fact * i) % MOD;
    }
    return fact;

}




void Solve() {
    // write solution here
    int n;
    cin >> n;
    vector<int> arr(n);
    int all ;
    int zero = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(i==0) all = arr[0];
        else all = all&arr[i];
        if(arr[i]==0) zero++;
    }
    int cnt = 0;
    cnt = count(arr.begin() , arr.end() , all);
    if (cnt >= 2) {
    int ways = (cnt * (cnt - 1)) % MOD;
    ways = (ways * fac(n - 2)) % MOD;
    cout << ways << endl;
    }
    else{
        cout << 0 << endl;
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

