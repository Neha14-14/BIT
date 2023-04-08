#include<bits/stdc++.h>
using namespace std;


void update (vector<vector<int > > &tree, int  indx, int n, char c)
{
	int temp;
	char a;
	while (indx <= n) {
		temp = (c - 'a');
		tree[indx][temp] += 1;
		indx += (indx & -indx);
		//printf("success1\n");
	}
	//printf("Yaha to khus raha h mother fucker\n");
	//return tree;
}
void remove (vector<vector<int > > &tree, int  indx, int n, char c)
{
	int temp;
	char a;
	while (indx <= n) {
		temp = (c - 'a');
		tree[indx][temp] -= 1;
		indx += (indx & -indx);
		//printf("success1\n");
	}
	//printf("Yaha to khus raha h mother fucker\n");
	//return tree;
}

void read(vector<vector<int > > &tree, int indx, vector<int> &v)
{
	int i;
	while (indx > 0) {
		for (i = 0; i < 26; i++){
			v[i] += tree[indx][i];
		}
		indx -= (indx & -indx);
	}
	//return v;
}

void loop (vector<vector<int> > tree, int n)
{
	int i, j;
	for (i = 0; i <= n; i++) {
		for (int j = 0; j < 26; j++) {
			printf("%d ", tree[i][j]);
		}
		printf("\n");
	}
}

int main (void)
{
	int n, q;
	scanf ("%d %d", &n, &q);
	vector<int> v(26, 0);
	vector<vector<int> > tree(n+1, v);

	int i;

	/*for (i = 0; i <= n; i++) {
		vector<int> v(26,0);
		tree.push_back(v);
	}*/

	/*for (i = 0; i <= n; i++) {
		for (int j = 0; j < 26; j++) {
			printf("%d ", tree[i][j]);
		}
		printf("\n");
	}*/

	string s;
	cin>>s;
	//int i;
	i =0 ;

	while (s[i] != '\0') {
		update(tree, i+1, n, s[i]);
		i++;
	}

	//loop(tree, n);

	vector<int> v1(26,0), v2(26,0);
	int ans;
	int x,y;
	char c;
	int e, o;
	int ctr = 0;
	while (q--){
		e = 0;
		o = 0;
		scanf("%d", &ans);

		if (ans == 1) {
			scanf("%d %c", &x, &c);
			remove(tree, x, n, s[x-1]);
			s[x-1] = c;
			update(tree, x, n, c);
		}else{
			scanf("%d %d", &x, &y);
			read(tree, y, v1);
			if (x != 1){
				read(tree, x-1, v2);
			}

			for (i = 0; i < 26; i++){
			//printf("%d %d\n",v1[i], v2[i] );
				x = abs(v1[i]-v2[i]);
				if (x % 2 == 1){
					o++;
				}
			}
			if(o == 0 || o == 1) {
				printf("yes\n");
			}else{
				printf("no\n");
			}
		}

		//loop(tree, n);
		fill(v1.begin(), v1.end(), 0);
		fill(v2.begin(), v2.end(), 0);
	}

	return 0;
}