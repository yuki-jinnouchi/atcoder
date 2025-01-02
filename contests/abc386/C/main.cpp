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
void solve(string S, string T){
	int S_size = S.size();
	int T_size = T.size();

	int i = 0;
	int j = 0;
	int count = 0;

	if (S_size == T_size){
		while(i < S_size){
			if (S[i] == T[i]){
				i++;
			} else {
				count++;
				i++;
			}
		}
		if (count <= 1){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
		return;
	} else if (S_size + 1 == T_size){
		while(i + j < T_size){
			if (S[i] == T[i + j]){
				i++;
			} else {
				j++;
			}
		}
		if (j == 1 && i == S_size){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
		return;
	} else if (S_size == T_size + 1){
		while(i + j < S_size){
			if (S[i + j] == T[i]){
				i++;
			} else {
				j++;
			}
		}
		if (j == 1 && i == T_size){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
		return;
	} else {
		cout << "No" << endl;
		return;
	}
}

int main(){
	ll K;
	string S;
	string T;
	cin >> K;
	cin >> S;
	cin >> T;
	solve(S, T);
    return 0;
}
