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
void solve(ll N, ll Q, vll A, vll x, ll min, ll max){

	ll max_count;
	ll min_count;
	ll middle;

	rep(i, Q) {
		if (x[i] < min) {
			cout << N << endl;
		} else if (x[i] > max) {
			cout << 0 << endl;
		} else {
			max_count = N - 1;
			min_count = 0;
			while (max_count - min_count > 1) {
				middle = (max_count + min_count) / 2;
				if (A[middle] < x[i]) {
					min_count = middle;
				} else {
					max_count = middle;
				}
			}
			cout << N - (min_count + 1) << endl;
		}
	}
}


int main(){
    ll N, Q;
	cin >> N >> Q;

	ll max = LONG_LONG_MIN;
	ll min = LONG_LONG_MAX;

	vll A(N);
	rep(i, N) {
		cin >> A[i];
		if (A[i] > max)
			max = A[i];
		if (A[i] < min)
			min = A[i];
	}

	vll x(Q);
	rep(i, Q) {
		cin >> x[i];
	}

	sort(all(A));
	solve(N, Q, A, x, min, max);
    return 0;
}
