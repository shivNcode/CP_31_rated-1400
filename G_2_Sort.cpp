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

    int n , k;
    cin >> n >> k;
    vector<int> a(n) , b(n);
    for(int i=0;i<n;i++) cin >> a[i] , b[i] = a[i]/2;

    vector<int> ans;
    int first = 0 , second = 0;
    for(int i = 1;i<n;i++){
        if(a[i]<=b[i-1]){
            second = i-1;

            ans.push_back(second - first + 1);
            first = i;
        }
    }
    if(first!=n-1){

        ans.push_back(n-1 - first + 1);
    }

    int v = k+1;
    int val = 0;
    for(auto it:ans){
        int vv = 0;
        vv = max(vv , it - v + 1);
        val+=vv;
    }
    cout << val <<endl;

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

i just did one obseravtion which is if the current element if less than the half of the previous element then they cont form sorted subarray so we mark that point and for ahead 

*/

