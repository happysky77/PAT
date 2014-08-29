#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct Book{
	int id, year;
	string title, author, publisher;
	string keywords[5];
	int wordsize;
	bool operator< (const Book& b) const{
		return id < b.id;
	}
};
int main()
{
	int n;
	scanf("%d", &n);
	vector<Book> b_vec;
	string keywords_line;
	while(n--){
		Book b;
		scanf("%d", &b.id); getchar();
		getline(cin, b.title);
		getline(cin, b.author);
		getline(cin, keywords_line);
		stringstream ss(keywords_line);
		int idx = 0;
		do{
			ss >> b.keywords[idx++];
		}while(ss);
		b.wordsize = idx-1;
		getline(cin, b.publisher);
		scanf("%d", &b.year);
		b_vec.push_back(b);
	}
	sort(b_vec.begin(), b_vec.end());
	unordered_map<string, vector<int> > book_maps[4];
	unordered_map<int, vector<int> > year_map;
	for(auto itr = b_vec.begin(); itr != b_vec.end(); ++itr){
		book_maps[0][itr->title].push_back(itr->id);
		book_maps[1][itr->author].push_back(itr->id);
		for(int i = 0; i < itr->wordsize; ++i){
			book_maps[2][itr->keywords[i]].push_back(itr->id);
		}
		book_maps[3][itr->publisher].push_back(itr->id);
		year_map[itr->year].push_back(itr->id);
	}
	int num;
	scanf("%d", &num); getchar();
	string query;
	while(num--){
		getline(cin, query);
		cout << query << endl;
		int idx = query[0] - '0';
		query = query.substr(3, query.size()-3);
		if(idx < 5){
			auto itr = book_maps[idx-1].find(query);
			if(itr != book_maps[idx-1].end()){
				vector<int> res = itr->second;
				for(int i = 0; i < res.size(); ++i){
					printf("%07d\n", res[i]);
				}
			}else{
				printf("Not Found\n");
			}
		}else{
			auto itr = year_map.find(atoi(query.c_str()));
			if(itr != year_map.end()){
				vector<int> res = itr->second;
				for(int i = 0; i < res.size(); ++i){
					printf("%07d\n", res[i]);
				}
			}else{
				printf("Not Found\n");
			}
		}
	}
	system("pause");
}