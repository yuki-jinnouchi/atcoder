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

int check(int N){
	int x, y;
	x= 1;
	while(x <= 1000){
		y = 1;
		while(y <= 1000 && (4 * x * y) + (3 * (x + y)) <= 1000){
			if ((4 * x * y) + (3 * (x + y)) == N){
				return true;
			}
			y++;
		}
		x++;
	}
	return false;
}

/* main section */
void solve(int N, vi S){
	int ans = 0;
	rep(i, N){
		if (check(S[i]) != true){
			ans++;
		}
	}
	cout << ans << endl;
}

int main(){
	int N;
	cin >> N;
	vi S(N);
	rep(i, N) cin >> S[i];
    solve(N, S);
    return 0;
}
