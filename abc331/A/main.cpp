#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cassert>
using namespace std;

void solve(long long M, long long D, long long y, long long m, long long d){
	int i = 0;
	if (d == D){
		i = 1;
		d = 1;
	} else {
		d += 1;
	}
	if (m == M && i == 1){
		m = 1;
		y += 1;
	} else if (i == 1){
		m += 1;
	} 
	printf("%lld %lld %lld\n", y, m, d);
	return ;
}

// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main(){
	long long M;
	std::scanf("%lld", &M);
	long long D;
	std::scanf("%lld", &D);
	long long y;
	std::scanf("%lld", &y);
	long long m;
	std::scanf("%lld", &m);
	long long d;
	std::scanf("%lld", &d);
	solve(M, D, y, m, d);
	return 0;
}
