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
void solve(ll N, ll X, vll A){
	sort(all(A));
	ll sum = 0;

	rep(i, N - 3) {
		sum += A[i + 1];
	}

	if (sum >= X) {
		cout << 0 << endl;
	} else {
		if (sum + A[N - 2] < X) {
			cout << -1 << endl;
		} else if (sum + A[0] >= X) {
			cout << 0 << endl;
		} else {
			cout << X - sum << endl;
		}
	}
}

int main(){
	ll N, X;
	cin >> N >> X;
	vll A(N - 1, 0);
	rep(i, N - 1) {
		cin >> A[i];
	}
	solve(N, X, A);
	return 0;
}
