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
    string str;
    cin >> str;
    vector<int> pr(n) , sf(n);
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(str[i]=='*') cnt++;
        pr[i] = cnt;
    }
    cnt = 0;
    for(int i=n-1;i>=0;i--){
        if(str[i]=='*') cnt++;
        sf[i] = cnt;
    }
    int total = sf[0];
    int i = 0;
    while(i<n && str[i]=='.'){
        i++;
    }
    int j = n-1;
    while(j>=0 && str[j]=='.'){
        j--;
    }
    int ans = 0;
    //cout << i <<" " << j << endl;
    while(i<j && (pr[i]<=(total - pr[i]))){
        //cout << i<<" " << j <<" " << pr[i] << " " << (total - pr[i]) << endl;
        if(str[i]=='.'){
            ans+=pr[i];

        }
        i++;

    }

    while(i<j && sf[j] <= (total - sf[j])){

        if(str[j]=='.'){
            ans+=sf[j];
            //continue;
        }
        j--;
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

