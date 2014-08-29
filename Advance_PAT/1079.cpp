#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct Chain{
	int id, height;
	Chain* fChild;
	Chain* sibling;
	Chain(int i): id(i) {fChild = sibling = NULL; height = 0;};
};
int main()
{
	int n;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	r = 1.0 + r / 100;
	vector<Chain*> chain_vec;
	for(int i = 0; i < n; ++i){
		chain_vec.push_back(new Chain(i));
	}
	int k, id, num;
	vector<int> retailers(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &k, &num);
		if(k == 0){
			retailers[i] = num;
		}else{
			chain_vec[i]->fChild = chain_vec[num];
			Chain* tmp = chain_vec[num];
			for(int j = 1; j < k; ++j){
				scanf("%d", &num);
				tmp->sibling = chain_vec[num];
				tmp = tmp->sibling;
			}
		}
	}

	double prices = 0.0f;
	queue<Chain*> chain_que;
	chain_que.push(chain_vec[0]);
	chain_que.push(NULL);
	while(!chain_que.empty()){
		Chain* tmp = chain_que.front();
		chain_que.pop();
		if(tmp){
			int rootHeight = tmp->height;
			if(retailers[tmp->id]){
				prices += retailers[tmp->id] * p * pow(r, rootHeight);
			}else{
				tmp = tmp->fChild;
				while(tmp){
					tmp->height = rootHeight+1;
					chain_que.push(tmp);
					tmp = tmp->sibling;
				}
			}
		}else{
			if(chain_que.empty()){
				break;
			}else{
				chain_que.push(NULL);
			}
		}
	}

	printf("%.1f\n", prices);
	system("pause");
}