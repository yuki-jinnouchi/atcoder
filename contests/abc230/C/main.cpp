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
void solve(ll N, ll A, ll B, ll P, ll Q, ll R, ll S){
	ll ka_min = max(1 - A, 1 - B);
	ll ka_max = min(N - A, N - B);
	ll kb_min = max(1 - A, B - N);
	ll kb_max = min(N - A, B - 1);
	reps(i, P, Q + 1){
		reps(j, R, S + 1){
			if ((A + ka_min) <= i && i <= (A + ka_max) && \
				j - B == i - A){
				cout << '#';
			}else if((A + kb_min) <= i && i <= (A + kb_max) && \
				B - j == i - A){
				cout << '#';
			}else{
				cout << '.';
			}
		}
		cout << endl;
	}
}

int main(){
	ll N, A, B, P, Q, R, S;
	cin >> N >> A >> B;
	cin >> P >> Q >> R >> S;
	solve(N, A, B, P, Q, R, S);
    return 0;
}
