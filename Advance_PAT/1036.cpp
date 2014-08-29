#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	string name, id, fname, fid, mname, mid;
	int score, fscore, mscore;
	fscore = -1;
	mscore = 101;
	char gender;
	cin >> n;
	while(n--){
		cin >> name >> gender >> id >> score;
		if(gender == 'M'){
			if(score < mscore){
				mname = name;
				mid = id;
				mscore = score;
			}
		} else {
			if(score > fscore){
				fname = name;
				fid = id;
				fscore = score;
			}
		}
	}
	if(!fname.empty()){
		cout << fname << " " << fid << endl;
	}else{
		cout << "Absent" << endl;
	}
	if(!mname.empty()){
		cout << mname << " " << mid << endl;
	}else{
		cout << "Absent" << endl;
	}
	if((!fname.empty()) && (!mname.empty())){
		cout << fscore - mscore << endl;
	}else{
		cout << "NA" << endl;
	}
	system("pause");
}