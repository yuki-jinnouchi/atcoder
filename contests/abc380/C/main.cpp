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
void print_vll(vll v){
	rep(i, v[1])
		cout << v[0];
}

void solve(ll N, ll K, string S){
	vvll V;
	vll v(2, 0);

	ll cnt = 0;
	rep(i, N){
		if (i == 0 || S[i] == S[i - 1]){
			cnt++;
		}
		if (i != 0 && S[i] != S[i - 1]){
			v[0] = S[i - 1] - '0';
			v[1] = cnt;
			V.pb(v);
			cnt = 1;
		}
		if (i == N - 1){
			v[0] = S[i] - '0';
			v[1] = cnt;
			V.pb(v);
		}
	}

	// rep(i, V.size()){
	// 	cout << V[i][0] << " " << V[i][1] << endl;
	// }

	cnt = 0;
	rep(i, V.size()){
		if (V[i][0] == 1){
			cnt++;
		}
		if (cnt == K - 1){
			print_vll(V[i]);
			print_vll(V[i + 2]);
			print_vll(V[i + 1]);
			i = i + 2;
			cnt++;
		} else {
			print_vll(V[i]);
		}
	}
	cout << endl;
}

int main(){
	ll N;
	ll K;
	string S;
	cin >> N >> K;
	cin >> S;
    solve(N, K, S);
    return 0;
}
