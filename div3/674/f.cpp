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

ll pow_mod(ll n, ll m, ll mod=1000000007){
    ll a = 1;
    while(m>0){
        if(m&1) a = a*n % mod;
        n = n*n % mod;
        m >>= 1;
    }
    return a;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll n;
    cin >> n;
    string s;
    cin >> s;

    vll a(n+1, 0), b(n+1, 0), c(n+1, 0), q(n+1, 0);
    rep(i, n){
        a[i+1] = s[i]=='a'? a[i]+1 : a[i];
        b[i+1] = s[i]=='b'? b[i]+1 : b[i];
        c[i+1] = s[i]=='c'? c[i]+1 : c[i];
        q[i+1] = s[i]=='?'? q[i]+1 : q[i];
    }

    ll count = 0;
    rep(i, n){
        if(s[i]=='b' || s[i]=='?'){
            ll r1 = a[i]*pow_mod(3, q[i]) % 1000000007;
            if(q[i]>0) r1 = (r1+q[i]*pow_mod(3, q[i]-1)) % 1000000007;
            ll r2 = (c[n]-c[i+1])*pow_mod(3, q[n]-q[i+1]) % 1000000007;
            if(q[n]-q[i+1]>0) r2 = (r2+(q[n]-q[i+1])*pow_mod(3, q[n]-q[i+1]-1)) % 1000000007;
            count = (count+r1*r2) % 1000000007;
        }
    }
    cout << count << endl;
}
