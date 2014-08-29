#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h> 
#include <string.h>
using namespace std;
struct Elem{
	char regist[14];
	int score;
	int locate;
	Elem(){score = locate = 0;}
	Elem(char* r, int s, int l): score(s), locate(l) {strcpy(regist, r);};
};
bool compare( const Elem a, const Elem b)
{
	if(a.score != b.score){
		return a.score > b.score;
	} else {
		return strcmp(a.regist, b.regist) < 0;
	}
}
int main()
{
	int n = 0;
	cin >> n;
	char regist[14];
	int score = 0;
	vector<Elem> stu;
	int k = 0;
	int sum = 0;
	for(int i = 0; i <n; ++i){
		cin >> k;
		sum += k;
		while(k--){
			cin >> regist >> score;
			Elem elem(regist, score, i+1);
			stu.push_back(elem);
		}
	}
	cout << sum << "\n";
	sort(stu.begin(), stu.end(), compare);

	int* idx = new int[n];
	int* count = new int[n];
	int* l_score = new int[n];
	for(int i = 0; i < n; ++i){
		idx[i] = count[i] = 0;
		l_score[i] = -1;
	}
	int t_idx, t_count, last_score;
	t_idx = t_count = 0;
	last_score = -1;
	for(int i = 0; i < sum; ++i){
		Elem e = stu[i];
		t_count++;
		if(e.score != last_score){
			t_idx = t_count;
			last_score = e.score;
		}
		count[e.locate-1]++;
		if(e.score != l_score[e.locate-1]){
			idx[e.locate-1] = count[e.locate-1];
			l_score[e.locate-1] = e.score;
		}
		cout << e.regist << " " << t_idx << " " << e.locate << " " << idx[e.locate-1] << "\n";
	}
	delete []idx;
	delete []count;
	delete []l_score;
	system("pause");
}