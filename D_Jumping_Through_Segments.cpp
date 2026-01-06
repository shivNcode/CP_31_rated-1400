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
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    int k = 0;
    k = (arr[0].first);
    int curr = arr[0].first;
    for(int i=1;i<n;i++){
        int a = abs(curr - arr[i].first);
        int b = abs(curr - arr[i].second);
        int val , diff;
        //cout<<a<<" "<<b<<" ";
        if(a>b){
            curr = arr[i].second;
            diff = b;
        }
        else{
            curr = arr[i].first;
            diff = a;
        }
        //cout<<val<<" \n";
        if(diff>k){
            k+=(diff-k)/2;
        }
    }
    cout<<k<<endl;
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

