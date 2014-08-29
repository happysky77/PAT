#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int n, k, m;
struct Stu{
	int id, scoresum, perfnum;
	bool ispass;
	vector<int> score_vec;
	Stu(int i): id(i) {
		scoresum = perfnum = 0;
		ispass = false;
		score_vec = vector<int>(k, INT_MIN);
	}
	bool operator< (const Stu& s) const{
		if(scoresum != s.scoresum)
			return scoresum > s.scoresum;
		if(perfnum != s.perfnum)
			return perfnum > s.perfnum;
		return id < s.id;
	}
};
int main(){
	scanf("%d%d%d", &n, &k, &m);
	vector<int> perf_vec(k, 0);
	for(int i = 0; i < k; ++i)
		scanf("%d", &perf_vec[i]);
	vector<Stu> stu_vec;
	for(int i = 0; i < n; ++i)
		stu_vec.push_back(Stu(i+1));
	int id, problem, score;
	for(int i = 0; i < m; ++i){
		scanf("%d%d%d", &id, &problem, &score);
		if(score > stu_vec[id-1].score_vec[problem-1]){
			if(score != -1 && !stu_vec[id-1].ispass)
				stu_vec[id-1].ispass = true;
			stu_vec[id-1].score_vec[problem-1] = score;
			if(score == perf_vec[problem-1]){
				stu_vec[id-1].perfnum++;
			}
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < k; ++j){
			int score = stu_vec[i].score_vec[j];
			if(score > 0){
				stu_vec[i].scoresum += score;
			}
		}
	}
	sort(stu_vec.begin(), stu_vec.end());
	int count = 0;
	int rank = 0;
	int lastscore = INT_MIN;
	for(auto itr = stu_vec.begin(); itr != stu_vec.end(); ++itr){
		if(itr->ispass){
			if(itr->scoresum != lastscore){
				rank = count;
				lastscore = itr->scoresum;
			}
			printf("%d %05d %d", rank+1, itr->id, itr->scoresum);
			for(int i = 0; i < k; ++i){
				if(itr->score_vec[i] != INT_MIN){
					printf(" %d", itr->score_vec[i] == -1? 0: itr->score_vec[i]);
				}else{
					printf(" -");
				}
			}
			printf("\n");
			count++;
		}
	}
	system("pause");
}