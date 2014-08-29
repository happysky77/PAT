#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int col;
struct Student{
	char id[7];
	char name[10];;
	int grade;
	bool operator< (const Student& s) const{
		if(col == 1){
			return strcmp(id, s.id) < 0;
		}
		if(col == 2){
			if(strcmp(name, s.name) != 0){
				return strcmp(name, s.name) < 0;
			}else{
				return strcmp(id, s.id) < 0;
			}
		}
		if(col == 3){
			if(grade != s.grade){
				return grade < s.grade;
			}else{
				return strcmp(id, s.id) < 0;
			}
		}
	}
};
int main(){
	int n;
	scanf("%d %d", &n, &col);
	vector<Student> s_vec;
	for(int i = 0; i < n; ++i){
		Student s;
		scanf("%s %s %d", s.id, s.name, &s.grade);
		s_vec.push_back(s);
	}
	sort(s_vec.begin(), s_vec.end());
	for(auto itr = s_vec.begin(); itr != s_vec.end(); ++itr){
		printf("%s %s %d\n", itr->id, itr->name, itr->grade);
	}
	system("pause");
}