#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct Applicant{
	int id, ge, gi;
	double fg;
	vector<int> schools;
	bool operator< (const Applicant& app) const{
		if(fg != app.fg){
			return fg > app.fg;
		}
		return ge > app.ge;
	}
	bool operator == (const Applicant& app) const{
		if(ge == app.ge && gi == app.gi && schools == app.schools){
			return true;
		}
		return false;
	}
};
int n, m, l;
int main()
{
	cin >> n >> m >> l;
	vector<int> school_quota(m, 0);
	for(int i = 0; i < m; ++i){
		cin >> school_quota[i];
	}
	vector<Applicant> app_vec;
	int school;
	for(int i = 0; i < n; ++i){
		Applicant app;
		app.id = i;
		cin >> app.ge >> app.gi;
		app.fg = (app.ge + app.gi) * 0.5;
		for(int j = 0; j < l; ++j){
			cin >> school;
			app.schools.push_back(school);
		}
		app_vec.push_back(app);
	}
	sort(app_vec.begin(), app_vec.end());
	unordered_map<int, vector<int> > res;
	for(auto itr = app_vec.begin(); itr != app_vec.end(); ++itr){
		for(int i = 0; i < l; ++i){
			int school_id = itr->schools[i];
			if(school_quota[school_id]){
				res[school_id].push_back(itr->id);
				school_quota[school_id]--;
				// equal applicants
				if(school_quota[school_id] == 0){
					auto next = itr;
					next++;
					while((*next) == (*itr)){
						res[school_id].push_back(next->id);
						next++;
					}
					next--;
					itr = next;
				}
				break;
			}
		}
	}
	for(int i = 0; i < m; ++i){
		vector<int> tmp = res[i];
		if(tmp.empty()){
			cout << endl;
		}else{
			sort(tmp.begin(), tmp.end());
			cout << tmp[0];
			for(int j = 1; j < tmp.size(); ++j){
				cout << " " << tmp[j];
			}
			cout << endl;
		}
	}
	system("pause");
}