#include<bits/stdc++.h>
using namespace std;

void update(int * tree, int ind, int val, int n)
{
	while (ind <= n) {
		tree[ind] += val;
		ind += (ind&-ind);
	}
}

int  read(int * tree, int inx, int n)
{
	int sum = 0;

	while (inx > 0) {
		sum += tree[inx];
		inx -= (inx & -inx);
	}
	return sum;
}

int readSingle (int * tree, int idx, int n)
{
	if (idx > 0) {
		int sum = tree[idx];
		int z = (idx) - (idx & -idx);

		idx--;
		while (z != idx){
			sum-= tree[idx];
			idx -= (idx & -idx);
			//printf("%s\n","Set\n" );
		}
		return sum;
	}
	return -1;
}


int main(void) {
	int n;
	scanf ("%d", &n);

	int arr[n+1], i;

	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	int tree[n+1] = {0};

	for (i = 1; i <= n; i++) {
		update(tree, i, arr[i], n);
	}

	printf("1. read till index i\n2.readSingle index i\n3.exit\n");

	int ans = 1;
	int num;
	int idx;
	while (ans) {
		scanf("%d %d", &num, &idx);
		switch(num){
			case 1:
				//printf("%s\n", "Sucess1\n");
				printf("%d\n", read(tree, idx, n));
				break;
			case 2:
				printf("%d\n", readSingle(tree, idx, n));
				break;
			case 3:
				ans = 0;
				break;
		}
	}
	return 0;
}
