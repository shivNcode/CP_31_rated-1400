
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


int pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}


void Solve() {
    // write solution here
    int n , m;
    cin >> n >> m;
    int temp = n;
    while(temp%10==0) temp/=10;
   // cout << temp << endl;
    int t2 = 2 , t5 = 5;
    int w = 0;
    while(temp%5==0) temp/=5 , t2*=2  , w = 5;
    while(temp%2==0) temp/=2 , t5*=5 , w = 2;
    t2/=2;
    t5/=5;
    //cout << t2 << " " << t5 <<endl;
    if(t2>=2){
        while(t2!=1 && t2>m){
            t2/=2;
        }
        int val = m/t2;
        //cout << ".";
        int ans = n*t2;

        int d = 0;
        while(val > 10){
            val/=10;
            d++;
        }

        //cout << n << " " << t2 <<" " << val << " " << pow(10 , d) << endl;
        ans = ans * val * pow(10 , d);
        cout<<ans<<endl;
        return ;
    }
    else if(t5>=5){
        while(t5!=1 && t5>m){
            t5/=5;
        }
        int val = m/t5;
        int d = 0;
        int ans = n*t5;
        while(val > 10){
            val/=10;
            d++;
        }
         //cout << n << " " << t2 <<" " << val << " " << pow(10 , d) << endl;
        ans = ans * val * pow(10 , d);
        cout << ans << endl;
        return;
    }

    int dig = 0;
    temp = m;
    while(temp>10){
        temp/=10;
        dig++;
    }
    int val = n * temp * pow(10 , dig);
    cout << val << endl;
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
In this question 
*/

