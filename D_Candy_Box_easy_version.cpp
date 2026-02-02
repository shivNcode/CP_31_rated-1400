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
    vector<int> arr(n);
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        mpp[arr[i]]++;
    }
    vector<int> temp;
    for(auto it:mpp){
        temp.push_back(it.second);
    }
    sort(temp.begin() , temp.end());
    int s = temp.size();
    int val = temp[s-1];
    int ans = temp[s-1];
    //cout << val << endl;
    for(int i=s-2;i>=0;i--){
        //cout << ans << endl;
        val = min(val-1 , temp[i]);
        //cout << val << endl;
        if(val > 0)ans+=val;
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

