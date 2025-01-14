/**
 * author:  Jini
 * sampled by
 *  https://gist.github.com/yoshihikosuzuki/bbf67915b0920954eb069be3c49b924d
**/

#include <bits/stdc++.h>
using namespace std;

/* alias */
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int, int>;
using sts = set<string>;

/* define short */
#define pb push_back
#define mp make_pair
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define rrepd(i,n) for(ll i=n;i>=1;i--)

/* main section */
void solve(ll N, vll q, vll r, ll Q, vll t, vll d){
	ll tmp;
	ll ans;
	rep(j, Q){
		ans = 0;
		rep(i, N){
			if (t[j] == i + 1){
				tmp = d[j] % q[i];
				if (tmp <= r[i]){
					ans = (d[j] / q[i]) * q[i] + r[i];
				} else {
					ans = ((d[j] / q[i]) + 1) * q[i] + r[i];
				}
			}
		}
		cout << ans << endl;
	}
}

int main(){
    ll N, Q;
	cin >> N;
	vll q(N), r(N);
	rep(i, N) cin >> q[i] >> r[i];
	cin >> Q;
	vll t(Q), d(Q);
	rep(i, Q) cin >> t[i] >> d[i];
	solve(N, q, r, Q, t, d);
	return 0;
}
