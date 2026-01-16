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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]%2==1) a[i]+=(a[i]%10);
    }
    if(count(a.begin() , a.end() , a[0])==n){
        cout << "Yes" << endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i]%2==1) a[i]+=(a[i]%10);
    }
    // int c = 0;
    // for(int i=0;i<n;i++){
    //     if(a[i]%10!=c){
    //         break;
    //     }
    //     if(i==n-1){
    //         cout << "No" << endl;
    //         return;
    //     }
    // }

	for (int i = 0; i < n; i++) {
				if (a[i] % 10 == 0) { // stuck at this value forever
						cout << "No\n";
						return;
				}
		}

    for(int i=0;i<n;i++){
        while(a[i]%10!=2){
            a[i]+=(a[i]%10);
        }
        a[i] = a[i]%20;
    }
    if(count(a.begin() , a.end() , a[0])==n){
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
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

