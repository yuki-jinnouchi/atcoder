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
void solve(int A, int B, int C, int D){
	vi cards(14, 0);
	cards[A]++;
	cards[B]++;
	cards[C]++;
	cards[D]++;
	int tmp = 0;
	int num = 0;
	rep(i, 14){
		if (cards[i] != 0){
			if (tmp == 0){
				tmp = i;
				num = cards[i];
			}
			else{
				if (cards[i] == 1 && num == 3){
					cout << "Yes" << endl;
					return;
				}
				else if (cards[i] == 3 && num == 1){
					cout << "Yes" << endl;
					return;
				}
				else if (cards[i] == 2 && num == 2){
					cout << "Yes" << endl;
					return;
				}else{
					cout << "No" << endl;
					return;
				}
			}
		}
	}
	cout << "No" << endl;
}

int main(){
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	solve(A, B, C, D);
    return 0;
}
