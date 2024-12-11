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
void solve(ll N, ll K, vvll P){
	sort(all(P), [](vll a, vll b){return a[1] > b[1];});
	int temp = 0;
	rep(i, N){
		if (i < K){
			P[i][2] = true;
			if (i == K - 1)
				temp = P[i][1];
		}else{
			if (temp - P[i][1] <= 300)
				P[i][2] = true;
			else
				P[i][2] = false;
		}
	}
	sort(all(P), [](vll a, vll b){return a[0] < b[0];});
	rep(i, N){
		if (P[i][2])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}

int main(){
	ll N, K;
	cin >> N >> K;

	vvll P(N, vll(3, 0));
	ll temp;
	ll sum;
	rep(i, N){
		P[i][0] = i;
		temp = 0;
		sum = 0;
		rep(j, 3){
			cin >> temp;
			sum += temp;
		}
		P[i][1] = sum;
	}
    solve(N, K, P);
    return 0;
}
