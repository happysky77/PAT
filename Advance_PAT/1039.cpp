#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> name2course[26*26*26*10];
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	vector<vector<char*> > courses(k+1);
	for(int i = 0; i < k; ++i){
		int idx, ni;
		scanf("%d%d", &idx, &ni);
		courses[idx].resize(ni);
		for(int j = 0; j < ni; ++j){
			char* name = new char[5];
			scanf("%s", name);
			courses[idx][j] = name;
		}
	}
	for(int i = 1; i <= k; ++i){
		for(int j = 0; j < courses[i].size(); ++j){
			char* name = courses[i][j];
			int tmp = (name[0] - 'A')*26*26*10 + (name[1] - 'A')*26*10 + (name[2] - 'A')*10 + name[3] - '0';
			name2course[tmp].push_back(i);
		}
	}
	char c[5];
	for(int i = 0; i < n; ++i){
		scanf("%s", c);
		int tmp = (c[0] - 'A')*26*26*10 + (c[1] - 'A')*26*10 + (c[2] - 'A')*10 + c[3] - '0';
		printf("%s %d", c, name2course[tmp].size());
		for(int j = 0; j < name2course[tmp].size(); ++j){
			printf(" %d", name2course[tmp][j]);
		}
		printf("\n");
	}
	for(int i = 0; i < courses.size(); ++i)  
    {  
        for(int j = 0; j < courses[i].size(); ++j)  
        {  
            delete[] courses[i][j];  
        }  
    }
	system("pause");
}