#include<bits/stdc++.h>
using namespace std;

void update(int * arr, int indx, int n, int val)
{
	for (; indx<=n;) {
		arr[indx] += val;
		indx += (indx & -indx);
	}
}

bool check(long long int num)
{
	if (num < 0){
		return false;
	}
	int temp1, temp2;
	temp1 = (int)(num % 10ll);

	while (num) {
		temp2 = (int)(num % 10ll);
		num /= 10ll;
	}

	if (temp2 == temp1) {
		return true;
	}else{
		return false;
	}
}

int read(int * arr, int indx, int n)
{
	int sum  = 0;

	for (; indx>0; ) {
		sum+=arr[indx];
		indx-=(indx&-indx)
	}
	return sum;
}

int main(void)
{
	int n, q;

	scanf ("%d %d", &n, &q);

	long long int a[n];
	int i, j;

	for (i = 0; i < n; i++) {
		scanf ("%lld", &a[i]);
		if (check(a[i])) {
			a[i] = 1;
		}else{
			a[i] = 0;
		}
	}
	int arr[n+1];
	memset(arr, 0, sizeof(arr));

	for (i = 1; i <= n; i++) {
			update(arr, i, n, a[i-1]);
	}

int ans, l, r;
		long long num;
	while (q--) {
		

		scanf("%d", &ans);

		if (ans == 1) {
			scanf ("%d %d",&l, &r);
			if (l != 1) {
				printf("%d\n", read(arr, r, n)-read(arr, l-1, n));
			}else{
				printf("%d\n", read(arr, r, n));
			}
		}else{
			scanf("%d %lld", &l, &num);
			if (a[l-1] == 1) {
				update(arr, l, n, -1);
			}
			if (check(num)) {
				a[l-1] = 1;
				update(arr, l, n,1);
			}else{
				a[l=1] = 0;
				update(arr, l, n,0);
			}
		}
	}

	return 0;
}