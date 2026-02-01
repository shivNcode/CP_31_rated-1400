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
    vector<int> arr(n+1) , neg(n+1 , 0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int v = 0;
    for(int i=1;i<=n;i++){
        if(arr[i-1]<0) v++;
        neg[i] = v;
    }
    int even = 1 , odd = 0 , ans = 0;
    // if(arr[0]>0) even = 1;
    // else odd = 1;
    for(int i=1;i<=n;i++){
       // cout << even <<" "<<odd << endl;
        if(neg[i]&1){
            ans+=odd;
            odd++;
        }
        else{
            ans+=even;
            even++;
        }
    }
    cout << (((n)*(n+1))/2)-ans <<" " << ans << endl;
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
A subarray will have a positive product only when it contains an even number of negative elements. So instead of checking every subarray, we move through the array and keep track of how many negative numbers we have seen so far. We only care whether this count is even or odd. At each index, we compare the current state with all previous states: if the number of negatives so far is even, then every previous even state forms a valid subarray ending at this index; if it is odd, then every previous odd state forms a valid subarray. By counting how many even and odd states we have already seen, we can quickly add the number of valid subarrays without checking them one by one.
*/

