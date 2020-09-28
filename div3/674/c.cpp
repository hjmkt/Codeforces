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

ll solve(ll n){
    if(n<=1) return 0;
    ll ret = LLONG_MAX;
    rep(i, min(n, (ll)sqrt(n+1)*2)){
        ll count = (n-1)/(1+i) + i;
        ret = min(ret, count);
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll t;
    cin >> t;

    rep(i, t){
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
}
