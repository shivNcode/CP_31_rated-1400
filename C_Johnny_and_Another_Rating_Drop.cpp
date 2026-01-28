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
int btt(int a, int b) {
    int x = a ^ b;
    int count = 0;

    while (x) {
        x = x & (x - 1);
        count++;
    }
    return count;
}

void Solve() {
    // write solution here
    int n;
    cin >> n;
    vector<int> arr(64 , 0);
    arr[1] = 1;
    for(int i=2;i<64;i++){
        for(int j = i-1;j>=0;j--){
            arr[i]+=(arr[j]);
        }
        arr[i]+=(i);
    }
    int i = 1 , ans = 0;
    while(n>0){
        int val = n&1;
        n = n >> 1;
        if(val) ans+=arr[i];
        i++;
    }
    cout << ans << endl;
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

