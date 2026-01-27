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
int nC2(int n) {
    if (n < 2) return 0;
    return (n * (n - 1)) / 2;
}

void Solve() {
    // write solution here
    int a , b , k;
    cin >> a >> b >> k;
    vector<pair<int,int>> pr(k);
    unordered_map<int,int> boys , girls;
    for(int i=0;i<k;i++){
        cin >> pr[i].first;
    }
    for(int i=0;i<k;i++){
        cin >> pr[i].second;
        boys[pr[i].first]++;
        girls[pr[i].second]++;
    }
    int ans = nC2(k);
    for(auto it:boys){
        ans-=(nC2(it.second));
    }
    for(auto it:girls){
        ans-=(nC2(it.second));
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

