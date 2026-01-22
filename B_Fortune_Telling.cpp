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
    int n , x , y;
    cin >> n >> x >> y;
    vector<int> arr(n);
    int odd = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]&1) odd++;
    }
    if(y&1){
        if(odd&1){
            //parity changes
            if(x&1){
                cout << "Bob" << endl;
                return;
            }
            else{
                cout << "Alice" << endl;
                return;
            }
        }
        else{
            //parity not change
            if(x&1){
                cout << "Alice" << endl;
                return;
            }
            else{
                cout << "Bob" << endl;
                return;
            }
        }
    }
    else{
        if(odd&1){
            //parity changes
            if(x&1){
                cout << "Alice" << endl;
                return;
            }
            else{
                cout << "Bob" << endl;
                return;
            }
        }
        else{
            //parity not change
            if(x&1){
                cout << "Bob" << endl;
                return;
            }
            else{
                cout << "Alice" << endl;
                return;
            }
        }
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

