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
    //will store the each non friends;
    int n , m;
    cin >> n >> m ;
    //vector<pair<pair<int,int>, bool>> check(m, {{0, 0}, false});
    map<pair<int,int> , int> mpp;
    for(int i=0;i<m;i++){
        int a , b;
        cin >> a >> b;
        mpp[{a,b}] = 1;

    }
    int l = 1 , r = 1 , ans = 0;
    while(r<=n){
        if(mpp[{a,b}])
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

