#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

#define REP(i, n, m) for(ll i=n; i<(ll)m; ++i)
#define IREP(i, n, m) for(ll i=n-1; i>=m; --i)
#define rep(i, n) REP(i, 0, n)
#define irep(i, n) IREP(i, n, 0)
#define all(v) v.begin(), v.end()
#define vprint(v) for(auto e:v){cout<<e<<" ";};cout<<endl;
#define vvprint(vv) for(auto v:vv){vprint(v)};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll t;
    cin >> t;

    rep(i, t){
        ll n, m;
        cin >> n >> m;
        vvvll s(n, vvll(2, vll(2)));
        rep(i, n){
            cin >> s[i][0][0] >> s[i][0][1];
            cin >> s[i][1][0] >> s[i][1][1];
        }
        if(m%2!=0){
            cout << "NO" << endl;
            continue;
        }
        bool possible = false;
        rep(i, n){
            if(s[i][0][1]==s[i][1][0]){
                possible = true;
                break;
            }
        }
        if(possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
