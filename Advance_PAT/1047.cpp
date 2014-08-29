#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(const char* ch1, const char* ch2){
	return strcmp(ch1, ch2) < 0;
}
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	map<int, vector<char*> > course_map;
	int c, course;
	for(int i = 0; i < n; ++i){
		char* name = new char(5);
		scanf("%s%d", name, &c);
		for(int j = 0; j < c; ++j){
			scanf("%d", &course);
			course_map[course].push_back(name);
		}
	}
	int cid = 1;
	for(auto itr = course_map.begin(); itr != course_map.end() && cid <= k; ){
		if(cid < itr->first){
			printf("%d %d\n", cid, 0);
		}else if(cid == itr->first){
			printf("%d %d\n", itr->first, itr->second.size());
			sort(itr->second.begin(), itr->second.end(), cmp);
			for(int i = 0; i < itr->second.size(); ++i){
				printf("%s\n", itr->second[i]);
			}
			itr++;
		}
		cid++;
	}
	system("pause");
}