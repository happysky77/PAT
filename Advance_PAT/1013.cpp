#include <iostream>
#include <vector>
using namespace std;
int find_parent(int x, vector<int>& parent){
	if(parent[x] == x){
		return x;
	}else{
		return find_parent(parent[x], parent);
	}
}
void union_city(int x, int y, vector<int>& parent){
	x = find_parent(x, parent);
	y = find_parent(y, parent);
	if(x != y){
		int m = min(x,y);
		x == m? parent[y] = m: parent[x] = m;
	}
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<bool> > matrix;
	for(int i = 0; i < n; ++i){
		matrix.push_back(vector<bool>(n, false));
	}
	int c1, c2;
	for(int i = 0; i < m; ++i){
		cin >> c1 >> c2;
		matrix[c1-1][c2-1] = matrix[c2-1][c1-1] = true;
	}
	vector<int> cs(k, 0);
	for(int i = 0; i < k; ++i){
		cin >> cs[i];
	}
	for(int i = 0; i < k; ++i){
		int c = cs[i] - 1;
		vector<int> parent(n, 0);
		for(int j = 0; j < n; ++j){
			parent[j] = j;
		}
		for(int j = 0; j < n; ++j){
			if(j != c){
				for(int k = j+1; k < n; ++k){
					if(k != c && matrix[j][k]){
						union_city(j, k, parent);
					}
				}
			}
		}
		int count = 0;
		for(int i = 0; i < n; ++i){
			if(i != c && parent[i] == i)
				count++;
		}
		cout << count-1 << endl;
	}
	system("pause");
}