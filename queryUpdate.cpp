#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define mk(a, b) make_pair(a, b)
#define pr(n) printf("%d\n", n)
#define sc(n) scanf ("%d", &n)
#define scll(n) scanf ("%lld", &n)
#define prll(n) printf("%lld\n", n)
#define MOD 1000000007ll

ll n, m, bit1[1000000], bit2[1000000], k;

void updateSingle (ll *bit, ll ind, ll val) {
	if (ind <= 0) {
		return ;
	}
	while (ind <= n) {
		bit[ind] += val;
		ind += (ind & -ind);
	}
}

void update (ll l, ll r, ll val) {
	updateSingle(bit1, l, val);
	updateSingle (bit1, r+1, -val);
	updateSingle (bit2, l, val*(l-1));
	updateSingle (bit2, r + 1, -(val * r));
	return ;
}

ll readSingle (ll * bit, ll l) {
	ll sum = 0;
	while (l > 0) {
		sum+=bit[l];
		l -= (l & -l);
	}
	return sum;
}

ll readQuery (ll l) {
	return readSingle (bit1, l) * l - readSingle (bit2, l);
}

ll read (ll l, ll r) {
	return readQuery (r) - readQuery (l-1);
}

int main (void) {
		scll(n);
		scll(m);
		scll(k);
		ll arr[2], t, l, r, val;
		ll i;
		for (i = 1; i <= n; i++) {
			scll(val);
			update(i, i, val);
		}
		while (m--) {
				scll (arr[0]), scll(arr[1]), scll(val);
				sort(arr, arr+2);
				update(arr[0], arr[1], val);
		}
		while(k--){
				scll (arr[0]), scll(arr[1]);
				sort(arr, arr+2);
				cout<<(read (arr[0], arr[1]))<<" ";
		}
	return 0;
}
