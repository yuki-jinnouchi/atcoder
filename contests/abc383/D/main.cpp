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

vll  eratosthenes(ll n){
	vector<bool> prime(n + 1, true);
	prime[0] = false;
	prime[1] = false;

	vll primes;
	for (ll i = 2; i < n + 1; i++){
		if (prime[i]){
			primes.pb(i);
			for (ll j = 2 * i; j <= n; j += i){
				prime[j] = false;
			}
		}
	}
	return primes;
}

void solver(ll n){

	vll primes = eratosthenes((ll) sqrt(n / 4));
	// cout << (ll) sqrt(n / 4) << endl;
	ll p_size = (ll) primes.size();
	// cout << primes.size() << endl;
	// rep(i, primes.size()){
	// 	cout << primes[i] << endl;
	// }

	ll count = 0;
	for (ll i = 0; i < p_size && pow(primes[i], 4) <= n; i++){
		if (pow(primes[i], 8) <= n)
			count++;
		for (ll j = 1; i + j < p_size && pow(primes[i], 2) * pow(primes[i + j], 2) <= n; j++){
			count++;
		}
	}
	cout << count << endl;
}

/* main section */
int main(){
	ll n;
	cin >> n;
	solver(n);
	return 0;
}
