#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string name, id;
	int grade, mingrad, maxgrad;
	map<int, int> grade_map;
	vector<string> name_vec;
	vector<string> id_vec;
	for(int i = 0; i < n; ++i){
		cin >> name >> id >> grade;
		grade_map[grade] = i; 
		name_vec.push_back(name);
		id_vec.push_back(id);
	}
	cin >> mingrad >> maxgrad;
	int count = 0;
	map<int, int>::reverse_iterator itr;
	for(itr = grade_map.rbegin(); itr != grade_map.rend(); ++itr){
		if(itr->first <= maxgrad && itr->first >= mingrad){
			cout << name_vec[itr->second] << " " << id_vec[itr->second] << endl;
			count++;
		}
	}
	if(count == 0){
		cout << "NONE" << endl;
	}
	system("pause");
}