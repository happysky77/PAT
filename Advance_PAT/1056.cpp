#include<iostream>
using namespace std;
void getrank(int* num, int* order, int* rank, int p, int g)
{
	bool flag = true;
	bool known[1005];
	for(int i = 0; i < p; ++i)
		known[i] = false;
	int group, max, count, idx;
	group = p;
	while(flag){
		//记得更新group
		group = group%g==0? group/g: group/g+1;
		if(group == 1)
			flag = false;
		count = 0;
		idx = max = -1;
		for(int i = 0; i < p; ++i){
			if(!known[order[i]]){
				//count == g的判断要放在最前面，如果放在后面，则在p是g的整数倍时，idx错误
				if(count == g){
					max = idx = -1;
					count = 1;
				}else
					count++;
				if(num[order[i]] > max){
					if(idx!=-1){
						rank[idx] = group + 1;
						known[idx] = true;
					}
					max = num[order[i]];
					idx = order[i];
				}else{
					rank[order[i]] = group + 1;
					known[order[i]] = true;
				}
			}
		}
	}
	rank[idx] = 1;
}
int main()
{
	int p, g;
	cin >> p >> g;
	int num[1005];
	int order[1005];
	for(int i = 0; i < p; ++i){
		cin >> num[i];
	}
	for(int i = 0; i < p; ++i){
		cin >> order[i];
	}
	int rank[1005];
	getrank(num, order, rank, p, g);
	cout << rank[0];
	for(int i = 1; i < p; ++i)
		cout << " " << rank[i];
	cout << endl;
	system("pause");
}