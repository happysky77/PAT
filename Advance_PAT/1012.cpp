#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int idx;
struct Student{
	string name;
	int grade[4];
	int bestGrade, bestIdx;
	bool operator< (const Student& s) const{
		return grade[idx] > s.grade[idx];
	}
};
char ranks[4] = {'A', 'C', 'M', 'E'};
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<Student> stu_vec;
	for(int i = 0; i < n; ++i){
		Student stu;
		cin >> stu.name >> stu.grade[1] >> stu.grade[2] >> stu.grade[3];
		stu.grade[0] = (stu.grade[1] + stu.grade[2] + stu.grade[3]) / 3;
		stu.bestGrade = n;
		stu.bestIdx = 4;
		stu_vec.push_back(stu);
	}
	for(int i = 0; i < 4; ++i){
		idx = i;
		sort(stu_vec.begin(), stu_vec.end());
		int count = 0;
		int rank = 0;
		int preGrade = -1;
		for(auto itr = stu_vec.begin(); itr != stu_vec.end(); ++itr){
			if(preGrade == -1 || itr->grade[i] != preGrade){
				rank = count;
			}
			if(itr->bestGrade > rank){
				itr->bestGrade = rank;
				itr->bestIdx = idx;
			}
			count++;
			preGrade = itr->grade[i];
		}
	}
	unordered_map<string, Student> stu_map;
	for(auto itr = stu_vec.begin(); itr != stu_vec.end(); ++itr){
		stu_map[itr->name] = *itr;
	}
	string name;
	for(int i = 0; i < m; ++i){
		cin >> name;
		auto itr = stu_map.find(name);
		if(itr != stu_map.end()){
			cout << ((itr->second).bestGrade+1) << " " << ranks[(itr->second).bestIdx] << endl;
		}else{
			cout << "N/A" << endl;
		}
	}
	system("pause");
}