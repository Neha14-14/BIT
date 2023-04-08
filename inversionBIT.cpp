#include<bits/stdc++.h>
using namespace std;

void update (int * tree, int indx, int val, int n)
{
	while (indx <= n){
		tree[indx] += val;
		indx += (indx & -indx);
	}

	return ;
}

int read (int * tree, int indx, int n)
{
	int sum = 0;

	while (indx > 0) {
		sum += tree[indx];

		indx -= (indx & -indx);
	}

	return sum;
}

long long int  invertion(int * arr, int max, int * tree, int n)
{
	long long int count = 0, j;

	for (j = n-1; j >=0; j--) {
		count += (long long )read(tree, arr[j]-1, max);
		update(tree, arr[j], 1, max);
	}

	return count;
}

int main (void)
{
	int test;
	scanf ("%d", &test);

	while (test--) {
	//getchar();
	int n;
	scanf ("%d", &n);
	if (n == 0){
		printf("\n0\n");
		continue;
	}
	int arr[n];
	int i;
	int max = 0;
	for (i =0;i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (i =0 ; i < n; i++) {
		if (max < arr[i]){
			max = arr[i];
		}
	}

	//getchar();
	//getchar();
	int tree[max+1];

	memset(tree,0,sizeof(tree));

	long long int ans;

	ans = (long long )invertion(arr, max, tree, n);

	printf("\n%lld\n", ans);
	}
	return 0;
}