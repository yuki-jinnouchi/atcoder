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
void solve(ll N, string S){
	vvll s;
	vll tmp_v;
	ll tmp_1 = 0;
	ll tmp_2 = 0;
	rep(i, N){
		if (S[i] == '/'){
			if (tmp_1 > 0){
				tmp_v = {1, tmp_1};
				s.pb(tmp_v);
				tmp_1 = 0;
			} else if (tmp_2 > 0){
				tmp_v = {2, tmp_2};
				s.pb(tmp_v);
				tmp_2 = 0;
			}
			tmp_v = {0, 1};
			s.pb(tmp_v);
		} else if (S[i] == '1') {
			if (tmp_2 > 0){
				tmp_v = {2, tmp_2};
				s.pb(tmp_v);
				tmp_2 = 0;
			}
			tmp_1++;
		} else if (S[i] == '2') {
			if (tmp_1 > 0){
				tmp_v = {1, tmp_1};
				s.pb(tmp_v);
				tmp_1 = 0;
			}
			tmp_2++;
		}
        if (i == N - 1){
            if (tmp_1 > 0){
                tmp_v = {1, tmp_1};
                s.pb(tmp_v);
            } else if (tmp_2 > 0){
                tmp_v = {2, tmp_2};
                s.pb(tmp_v);
            }
        }
    }

	ll ans = 0;
	ll tmp, tmp_1l, tmp_2l;
	rep(i, s.size()){
		tmp_1l = 0;
        tmp_2l = 0;
		if (s[i][0] == 0){
			tmp = 1;
			if (0 < i && s[i-1][0] == 1){
				tmp_1l = s[i-1][1];
			}
			if (i < (ll) s.size() - 1 && s[i+1][0] == 2){
				tmp_2l = s[i+1][1];
			}
            tmp += 2 * min(tmp_1l, tmp_2l);
			ans = max(ans, tmp);
		}
	}
	cout << ans << endl;
}

int main(){
	ll N;
	string S;
	cin >> N;
	cin >> S;
	solve(N, S);
    return 0;
}

