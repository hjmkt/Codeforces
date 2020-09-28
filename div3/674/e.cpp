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


ll min_win(vll a, vll b){
    if(b[0]+b[1]==0) return a[1];
    if(b[1]+b[2]==0) return a[2];
    if(b[2]+b[0]==0) return a[0];
    if(a[0]+a[1]==0) return b[0];
    if(a[1]+a[2]==0) return b[1];
    if(a[2]+a[0]==0) return b[2];
    ll m = LLONG_MAX;
    if(a[0]>0 && b[0]>0) m = min(m, min_win({a[0]-min(a[0], b[0]), a[1], a[2]}, {b[0]-min(a[0], b[0]), b[1], b[2]}));
    if(a[0]>0 && b[2]>0) m = min(m, min_win({a[0]-min(a[0], b[2]), a[1], a[2]}, {b[0], b[1], b[2]-min(a[0], b[2])}));
    if(a[1]>0 && b[1]>0) m = min(m, min_win({a[0], a[1]-min(a[1], b[1]), a[2]}, {b[0], b[1]-min(a[1], b[1]), b[2]}));
    if(a[1]>0 && b[0]>0) m = min(m, min_win({a[0], a[1]-min(a[1], b[0]), a[2]}, {b[0]-min(a[1], b[0]), b[1], b[2]}));
    if(a[2]>0 && b[2]>0) m = min(m, min_win({a[0], a[1], a[2]-min(a[2], b[2])}, {b[0], b[1], b[2]-min(a[2], b[2])}));
    if(a[2]>0 && b[1]>0) m = min(m, min_win({a[0], a[1], a[2]-min(a[2], b[1])}, {b[0], b[1]-min(a[2], b[1]), b[2]}));
    return m;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll n;
    cin >> n;
    vll a(3), b(3);
    rep(i, 3) cin >> a[i];
    rep(i, 3) cin >> b[i];

    ll m = min_win(a, b);
    ll M = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);

    cout << m << " " << M << endl;
}
