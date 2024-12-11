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
// void solve(long long N, std::vector<std::string> S){

// }

int main(){
	ll N;
	cin >> N;
	vector<pair<string, ll>> S;
	string s;
	int num;
	bool flag;
	rep(i, N) {
		flag = false;
		cin >> s;

		num = 0;
		while(num < (int) S.size()) {
			if (S[num].first == s) {
				S[num].second++;
				flag = true;
			}
			num++;
		}
		if (!flag) {
			S.pb(mp(s, 1));
		}
	}
	sort(begin(S), end(S), [](auto a, auto b) {
		return a.second > b.second;
	});
	cout << S[0].first << endl;
    return 0;
}
