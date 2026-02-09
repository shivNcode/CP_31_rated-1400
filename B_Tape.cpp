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
    // write solution here.
    int n , m , k;
    cin >> n >> m >>k;
    vector<int> diff;
    int prev = 0;
    for(int i=0;i<n;i++){
        int v;
        cin >> v;
        if(i==0) prev = v;
        else {
            diff.push_back(v - prev-1);
            prev = v;
        }
    }
    sort(diff.begin() , diff.end());
    int ans = n;
    int i = n;
    int x = 0;
    while(i>k){
        ans+=diff[x];
        x++;

        i--;
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
