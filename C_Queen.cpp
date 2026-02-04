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
    int n;
    cin >> n;
    vector<int> mark(n+1 , 0);
    map<int,vector<int>> mpp;
    for(int i=1;i<=n;i++){
        int p , c;
        cin >> p >> c;
        if(c==1) mark[i] = 1;
        mpp[p].push_back(i);
    }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(mark[i]){
            bool all = true;
            for(auto it:mpp[i]){
                    if(mark[it]==0) all = false;
            }
            if(all) ans.push_back(i);
        }
    }
    if(ans.size()==0) cout << -1 << endl;
    for(int i:ans){
        cout << i << " ";
    }
    cout << endl;

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
