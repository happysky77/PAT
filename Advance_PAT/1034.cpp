#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct Elem{
	string id;
	int weight;
	int set_idx;
	Elem(string s): id(s) {weight = set_idx = 0;}
};
int main(){
	int n, k;
	cin >> n >> k;
	unordered_map<string, Elem*> elem_map;
	vector<unordered_set<string> > set_vec;
	vector<int> weight_vec;
	string s1, s2;
	int weight;
	int idx = 0;
	for(int i = 0; i < n; ++i){
		cin >> s1 >> s2 >> weight;
		auto itr1 = elem_map.find(s1);
		auto itr2 = elem_map.find(s2);
		if(itr1 == elem_map.end() && itr2 == elem_map.end()){
			Elem* e1 = new Elem(s1);
			e1->weight += weight;
			e1->set_idx = idx;
			elem_map[s1] = e1;
			Elem* e2 = new Elem(s2);
			e2->weight += weight;
			e2->set_idx = idx++;
			elem_map[s2] = e2;

			unordered_set<string> newset;
			newset.insert(s1);
			newset.insert(s2);
			set_vec.push_back(newset);
			weight_vec.push_back(weight);
		}else if(itr1 == elem_map.end()){
			int set_idx = itr2->second->set_idx;
			Elem* e1 = new Elem(s1);
			e1->weight += weight;
			e1->set_idx = set_idx;
			elem_map[s1] = e1;
			itr2->second->weight += weight;

			set_vec[set_idx].insert(s1);
			weight_vec[set_idx] += weight;
		}else if(itr2 == elem_map.end()){
			int set_idx = itr1->second->set_idx;
			Elem* e2 = new Elem(s2);
			e2->weight += weight;
			e2->set_idx = set_idx;
			elem_map[s2] = e2;
			itr1->second->weight += weight;

			set_vec[set_idx].insert(s2);
			weight_vec[set_idx] += weight;
		}else{
			itr1->second->weight += weight;
			itr2->second->weight += weight;
			weight_vec[itr1->second->set_idx] += weight;
		}
	}
	int count = 0;
	vector<pair<string, int> > res;
	for(int i = 0; i < idx; ++i){
		if(set_vec[i].size() > 2 && weight_vec[i] > k){
			count++;
			string str = *set_vec[i].begin();
			int maxweight = elem_map[str]->weight;
			for(auto itr = set_vec[i].begin(); itr != set_vec[i].end(); ++itr){
				if(elem_map[*itr]->weight > maxweight){
					str = *itr;
					maxweight = elem_map[*itr]->weight;
				}
			}
			res.push_back(pair<string, int>(str, set_vec[i].size()));
		}
	}
	cout << count << endl;
	if(count){
		for(auto itr = res.begin(); itr != res.end(); ++itr){
			cout << itr->first << " " << itr->second << endl;
		}
	}
	system("pause");
}