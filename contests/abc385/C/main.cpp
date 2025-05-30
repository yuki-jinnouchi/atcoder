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
void solve(int N, vi H){
	// vvi dp(N, vi(N, 0));
	int past, t_count, times;
	int count = 0;
	rep(i, N){
		rep(j, i + 1){
			t_count = 0;
			times = 0;
			past = 0;
			while(times * (i + 1) + j < N){
				if(H[times * (i + 1) + j] == past){
					t_count++;
				}
				else{
					past = H[times * (i + 1) + j];
					count = max(count, t_count);
					t_count = 1;
				}
				times++;
			}
			count = max(count, t_count);
		}
	}
	cout << count << endl;
}

int main(){
	int N;
	cin >> N;
	vi H(N);
	rep(i, N){
		cin >> H[i];
	}
	solve(N, H);
	return 0;
}
