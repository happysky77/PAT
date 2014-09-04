#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
struct Player{
	int hour, minute, sec, play, tag;
	int time, servTime, wait;
	bool operator< (const Player& p) const{
		return time < p.time;
	}
};
struct Table{
	int tag;
	int server;
	int time;
};
bool cmp(const Player& p1, const Player& p2){
	return p1.servTime < p2.servTime;
}
vector<Player> player_vec;
vector<Table> tables;
void UpdateInfo(int u, int t){
	player_vec[u].servTime = max(player_vec[u].time, tables[t].time);
	player_vec[u].wait = player_vec[u].servTime - player_vec[u].time;
	tables[t].server++;
	tables[t].time = player_vec[u].servTime + min(player_vec[u].play, 7200);
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		Player p;
		scanf("%d:%d:%d", &p.hour, &p.minute, &p.sec);
		scanf("%d%d", &p.play, &p.tag);
		p.play *= 60;
		p.time = p.hour * 3600 + p.minute * 60 + p.sec;
		p.servTime = INT_MAX;
		p.wait = INT_MAX;
		player_vec.push_back(p);
	}
	sort(player_vec.begin(), player_vec.end());
	int k, m;
	scanf("%d%d", &k, &m);
	tables.resize(k);
	for(int i = 0; i < k; ++i){
		tables[i].time = 8*3600;
		tables[i].tag = 0;
		tables[i].server = 0;
	}
	int t;
	for(int i = 0; i < m; ++i){
		scanf("%d", &t);
		tables[t-1].tag = 1;
	}
	int finish = 21*3600;
	for(int i = 0; i < n; ++i){
		// player i is not sure serviced at loop i
		if(player_vec[i].servTime != INT_MAX) continue;
		// the fast process table
		int minFreeTime = INT_MAX;
		for(int j = 0; j < k; ++j)
			minFreeTime = min(minFreeTime, tables[j].time);
		int timePoint = max(player_vec[i].time, minFreeTime);
		if(timePoint >= finish)
			break;
		vector<int> userList;
		vector<int> tableList;
		// users who are waiting in queue
		for(int j = i; j < n; ++j){
			if(player_vec[j].servTime == INT_MAX && player_vec[j].time <= timePoint)
				userList.push_back(j);
		}
		// available tables
		for(int j = 0; j < k; ++j){
			if(tables[j].time <= timePoint)
				tableList.push_back(j);
		}
		bool flag = false;
		/*
		if(userList.size() == 1 && tableList.size() > 1){ // choose vip table for vip user
			if(player_vec[userList[0]].tag == 1){
				for(int j = 0; j < tableList.size(); ++j){
					if(tables[tableList[j]].tag == 1){
						flag = true;
						UpdateInfo(userList[0], tableList[j]);  
						break;
					}
				}
			}
		}else if(tableList.size() == 1 && userList.size() > 1){ // choose vip user for vip table
			if(tables[tableList[0]].tag == 1){
				for(int j = 0; j < userList.size(); ++j){
					if(player_vec[userList[j]].tag == 1){
						flag = true;
						UpdateInfo(userList[j], tableList[0]);
						break;
					}
				}
			}
		}else */
		if(userList.size() >= 1 && tableList.size() >= 1){ // vip tables for vip user first
			for(int j = 0; j < tableList.size(); ++j){
				if(tables[tableList[j]].tag == 1){
					for(int k = 0; k < userList.size(); ++k){
						if(player_vec[userList[k]].tag == 1){
							flag = true;
							UpdateInfo(userList[k], tableList[j]);
							break;
						}
					}
				}
			}
		}
		if(!flag) UpdateInfo(userList[0], tableList[0]);
		i--;
	}
	sort(player_vec.begin(), player_vec.end(), cmp);
	for(auto itr = player_vec.begin(); itr != player_vec.end(); ++itr){
		if(itr->servTime >= finish)
			break;
		printf("%02d:%02d:%02d ", itr->hour, itr->minute, itr->sec);
		int h = itr->servTime / 3600;
		int m = (itr->servTime%3600) / 60;
		int s = itr->servTime % 60;
		printf("%02d:%02d:%02d ", h, m, s);
		printf("%d\n", (itr->wait+30)/60);
	}
	printf("%d", tables[0].server);
	for(int i = 1; i < k; ++i){
		printf(" %d", tables[i].server);
	}
	printf("\n");
	system("pause");
}