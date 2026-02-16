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

void Solve()
{
    // write solution here.
    int n , m;
    cin >> n >> m;
    vector<int> a(n) , b(n);
    a[0] = 1;
    for(int i=1;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    //for(int i:a) cout << i << " ";
    //cout << endl;
    //for(int i:b) cout << i << " ";
    //cout << endl;
    int k = 0 , ans = 0;;
    for(int i=0;i<n;i++){
        //cout << a[i] << " :";
        while(k<n && b[k]<=a[i]){
            //cout << b[k] << " ";
            k++;
        }
        if(k<n && b[k]>a[i]){
            ans++;
            //cout << b[k] << " ";
            k++;
        }
        //cout << endl;
    }
    cout <<n -  ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}

/*
Notes:

*/