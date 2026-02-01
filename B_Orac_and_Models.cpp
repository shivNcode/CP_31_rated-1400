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
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    vector<bool> temp(n+1 , 0);
    int i = 2;
    int ans = 0;
    while(i<=n){

    int cnt = 0;
    while (i <= n && temp[i] == true) {
    i++;
    }
    if (i > n) break;

        int val = i;
        temp[val] = true;
        int prev = arr[val];
        for (int j = val; j <= n; j += val) {
    temp[j] = true;

    if (j == val) {
        cnt++;   // base element
    }
    else {
        if (arr[j] > arr[j - val]) {
            cnt++;
        }
        else if (j + val <= n && arr[j] < arr[j + val] && arr[j] > arr[j - val]) {
            cnt++;
        }
    }
}

        //cout<<cnt<<" " << endl;

        if(arr[1]<arr[val]) cnt++;
        ans = max(ans , cnt);
        i++;
    }
    ans = max(ans , 1LL);
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

