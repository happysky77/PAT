#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct people{
	int id;
	int virtue;
	int talent;
	int total;
	int type;
	people(int i, int v, int t):id(i), virtue(v), talent(t) {total = virtue + talent;}; 
};
int l, h;
int check_type(people a)
{
	if(a.virtue >= h && a.talent >= h){
		return 3;	
	} else if(a.virtue >= h){
		return 2;
	} else if(a.talent < h && a.virtue >= a.talent){
		return 1;
	} else{
		return 0;
	}
}
bool compare(const people a, const people b)
{
	if(a.type != b.type)
		return a.type > b.type;
	else {
		if(a.total != b.total)
			return a.total > b.total;
		else{
			if(a.virtue != b.virtue)
				return a.virtue > b.virtue;
			else
				return a.id < b.id;
		}
	}
}
void printVec(vector<people>& p)
{
	//cout会超时，printf不会。。。
	for(int i = 0; i < p.size(); ++i){
		printf("%08d %d %d\n", p[i].id, p[i].virtue, p[i].talent);
		//cout << p[i].id << " " << p[i].virtue << " " << p[i].talent << endl;
	}
}
int main()
{
	int n;
	cin >> n >> l >> h;
	int id;
	int virtue, talent;
	int count = 0;
	vector<people> peoples;
	for(int i = 0; i < n; ++i){
		cin >> id >> virtue >> talent;
		if(virtue >= l && talent >= l){
			count++;
			people p = people(id, virtue, talent);
			p.type = check_type(p);
			peoples.push_back(p);
		}
	}
	sort(peoples.begin(), peoples.end(), compare);
	cout << count << endl;
	printVec(peoples);
	system("pause");
}