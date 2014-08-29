#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
struct Customer{
	string time;
	int arrival;
	int process;
	bool operator< (const Customer& c) const{
		return arrival < c.arrival;
	}
};
int calcTime(const string& str){
	int hour = (str[0]-'0')*10 + str[1] - '0';
	int mint = (str[3]-'0')*10 + str[4] - '0';
	int sec = (str[6]-'0')*10 + str[7] - '0';
	return hour*3600 + mint*60 + sec;
}
int main(){
	int n, k;
	cin >> n >> k;
	string last = "17:00:00";
	int start = 8*3600;
	vector<Customer> cus_vec;
	for(int i = 0; i < n; ++i){
		Customer cus;
		cin >> cus.time >> cus.process;
		cus.arrival = calcTime(cus.time);
		cus.process *= 60;
		if(cus.time <= last){
			cus_vec.push_back(cus);
		}
	}
	sort(cus_vec.begin(), cus_vec.end());
	int wait = 0;
	vector<Customer*> windows;
	vector<int> timebase(k, 0);
	int idx = 0;
	n = cus_vec.size();
	for(; idx < k && idx < n; ++idx){
		windows.push_back(&cus_vec[idx]);
		if(cus_vec[idx].arrival < start){
			wait += start - cus_vec[idx].arrival;
		}
		timebase[idx] = max(cus_vec[idx].arrival, start) + cus_vec[idx].process;	
	}
	for(; idx < n; ++idx){
		int mintime = INT_MAX;
		int tmp = 0;
		for(int j = 0; j < k; ++j){
			if(timebase[j] < mintime){
				mintime = timebase[j];
				tmp = j;
			}
		}
		windows[tmp] = &cus_vec[idx];
		if(cus_vec[idx].arrival < timebase[tmp]){
			wait += timebase[tmp] - cus_vec[idx].arrival;
		}
		timebase[tmp] =  max(cus_vec[idx].arrival, timebase[tmp]) + cus_vec[idx].process;
	}
	printf("%.1f\n", 1.0*wait/60/n);
	system("pause");
}