#include <iostream>
#include <string>
using namespace std;
const char weeks[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
	string strs[4];
	for(int i = 0; i < 4; ++i){
		cin >> strs[i];
	}
	int firstSize = min(strs[0].size(), strs[1].size());
	char ch[2];
	int idx = 0;
	for(int i = 0; i < firstSize; ++i){
		if(strs[0][i] == strs[1][i]){
			if(strs[0][i] >= 'A' && strs[0][i] <= 'G' && idx == 0){
				ch[idx++] = strs[0][i];
			}else{
				if((isdigit(strs[0][i]) || (strs[0][i] >= 'A' && strs[0][i] <= 'N')) && idx == 1){
					ch[idx++] = strs[0][i];
					break;
				}
			}
		}
	}
	idx = 0;
	int secondSize = min(strs[2].size(), strs[3].size());
	for(int i = 0; i < secondSize; ++i){
		if(strs[2][i] == strs[3][i] && isalpha(strs[2][i])){
			idx = i;
			break;
		}
	}
	printf("%s ", weeks[ch[0]-'A']);
	if(ch[1] >= 'A'){
		printf("%02d:", ch[1]-'A'+10);
	}else{
		printf("%02d:", ch[1]-'0');
	}
	printf("%02d\n", idx);
	system("pause");
}