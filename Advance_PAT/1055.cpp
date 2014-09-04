#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Person{
	char name[10];
	int age, worth;
	bool operator< (const Person& p){
		if(worth != p.worth){
			return worth > p.worth;
		}
		if(age != p.age){
			return age < p.age;
		}
		return strcmp(name, p.name) < 0;
	}
};
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	vector<Person> person_vec;
	for(int i = 0; i < n; ++i){
		Person p;
		scanf("%s%d%d", p.name, &p.age, &p.worth);
		person_vec.push_back(p);
	}
	sort(person_vec.begin(), person_vec.end());
	vector<int> age_count(201,0);
	vector<int> filters(n,0);
	int idx = 0;
	for(int i = 0; i < n; ++i){
		if(age_count[person_vec[i].age]++ < 100){
			filters[idx++] = i;
		}
	}
	int m, amin, amax;
	for(int i = 1; i <= k; ++i){
		scanf("%d%d%d", &m, &amin, &amax);
		printf("Case #%d:\n", i);
		int count = 0;
		for(int j = 0; j < idx; ++j){
			Person p = person_vec[filters[j]];
			if(p.age >= amin && p.age <= amax){
				printf("%s %d %d\n", p.name, p.age, p.worth);
				count++;
				if(count == m){
					break;
				}
			}
		}
		if(count == 0){
			printf("None\n");
		}
	}
	system("pause");
}