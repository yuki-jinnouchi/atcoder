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
void solve(ll M, ll S_x, ll S_y, set<pair<ll, ll>> stx, set<pair<ll, ll>> sty, vi D, vll C){
	ll x, y, nx, ny;
	x = S_x;
	y = S_y;

	ll count = 0;
	ll min_x, max_x, min_y, max_y;
	rep(i, M){
		if (D[i] == (int) 'U' || D[i] == (int) 'D'){
			if (D[i] == (int) 'U'){
				nx = x;
				ny = y + 1 * C[i];
				min_x = x;
				max_x = x;
				min_y = y;
				max_y = ny;
			} else if (D[i] == (int) 'D'){
				nx = x;
				ny = y + -1 * C[i];
				min_x = x;
				max_x = x;
				min_y = ny;
				max_y = y;
			}
			auto itr = stx.lower_bound(make_pair(x, min_y));
			while (itr != stx.end() && itr->first == x && itr->second <= max_y){
				sty.erase(make_pair(itr->second, itr->first));
				stx.erase(itr++);
				count++;
			}
		} else if (D[i] == (int) 'L' || D[i] == (int) 'R'){
			if (D[i] == (int) 'L'){
				nx = x + -1 * C[i];
				ny = y;
				min_x = nx;
				max_x = x;
				min_y = y;
				max_y = y;
			} else if (D[i] == (int) 'R'){
				nx = x + 1 * C[i];
				ny = y;
				min_x = x;
				max_x = nx;
				min_y = y;
				max_y = y;
			}
			auto itr = sty.lower_bound(make_pair(y, min_x));
			while (itr != sty.end() && itr->first == y && itr->second <= max_x){
				stx.erase(make_pair(itr->second, itr->first));
				sty.erase(itr++);
				count++;
			}
		}
		x = nx;
		y = ny;
	}
	cout << x << ' ' << y << ' ' << count << endl;
}

int main(){
	ll N, M, S_x, S_y;
	cin >> N >> M >> S_x >> S_y;
	// vi X(N), Y(N);
	// unordered_set<pair<ll, ll>, phash> st;
	set<pair<ll, ll> > stx;
	set<pair<ll, ll> > sty;
	ll X, Y;
	rep(i, N){
		cin >> X >> Y;
		stx.insert(make_pair(X, Y));
		sty.insert(make_pair(Y, X));
		// cout << X << ' ' << Y << endl;
	}
	vi D(M);
	vll C(M);
	char d;
	ll c;
	rep(i, M){
		cin >> d >> c;
		D[i] = (int) d;
		C[i] = c;
		// cout << D[i] << ' ' << C[i] << endl;
	}
	solve(M, S_x, S_y, stx, sty, D, C);
}
