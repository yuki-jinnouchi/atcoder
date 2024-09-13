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
void solve(ll N, ll M, string S, string T){
	ll flag;
	bool flag_a = true;
	bool flag_b = true;

	rep(i, N) {
		if (S[i] != T[i]) {
			flag_a = false;
		}
	}

	rep(i, N) {
		if (S[N - 1 - i] != T[M - 1 - i]) {
			flag_b = false;
		}
	}

	if (flag_a == true && flag_b == true)
		flag = 0;
	if (flag_a == true && flag_b == false)
		flag = 1;
	if (flag_a == false && flag_b == true)
		flag = 2;
	if (flag_a == false && flag_b == false)
		flag = 3;

	cout << flag << endl;
}

int main(){
	ll N, M;
	cin >> N >> M;
	string S;
	cin >> S;
	string T;
	cin >> T;
    solve(N, M, S, T);
    return 0;
}
