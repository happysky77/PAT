#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> units(24, 0);
string month;
struct Call{
	string name, status;
	int month, date, hour, minute, total;
	bool operator< (const Call& c) const{
		if(name != c.name)
			return name < c.name;
		return total < c.total;
	}
};
double calCost(const Call& c1, const Call& c2){
	int money = 0;
	int h1 = c1.hour;
	int h2 = c2.hour;
	int d1 = c1.date;
	int d2 = c2.date;
	int m1 = c1.minute;
	int m2 = c2.minute;
	while(h1 != h2 || d1 != d2){
		money += units[h1] * (60 - m1);
		h1++;
		m1 = 0;
		if(h1 == 24){
			h1 = 0;
			d1++;
		}
	}
	money += units[h2] * (m2 - m1);
	return 1.0*money/100;
}
int main(){
	for(int i = 0; i < 24; ++i)
		scanf("%d", &units[i]);
	int num;
	scanf("%d", &num);
	string name, time, flag;
	vector<Call> call_vec;
	for(int i = 0; i < num; ++i){
		Call c;
		cin >> c.name;
		cin >> c.month;
		getchar();  
        cin >> c.date;  
        getchar();  
        cin >> c.hour;  
        getchar();  
        cin >> c.minute;  
        c.total = c.minute + 60*c.hour + 24*60*c.date;  
        cin>>c.status;  
		call_vec.push_back(c);
	}
	sort(call_vec.begin(), call_vec.end());
	
	string curname;
	double totalcost = 0.0f;
	int on = -1;
	for(int i = 0; i < call_vec.size(); ++i){
		if(curname.empty() || call_vec[i].name != curname){
			on = -1;
			if(!curname.empty()){
				printf("Total amount: $%.2f\n",totalcost);
			}
			printf("%s %02d\n", call_vec[i].name.c_str(), call_vec[i].month);
			totalcost = 0.0f;
			curname = call_vec[i].name;
		}
		if(call_vec[i].status == "on-line"){
			on = i;
		}else{
			if(on != -1){
				double money = calCost(call_vec[on], call_vec[i]);
				totalcost += money;
				int duration = call_vec[i].total - call_vec[on].total;
				printf("%02d:%02d:%02d ", call_vec[on].date, call_vec[on].hour, call_vec[on].minute);
				printf("%02d:%02d:%02d %d $%.2f\n", call_vec[i].date, call_vec[i].hour, call_vec[i].minute, duration, money);
			}
			on = -1;
		}
	}
	printf("Total amount: $%.2f\n", totalcost);
	
	/*
	vector<Call> format_calls;
	bool haveonline = false;  
    string curname;  
    for(int i=0;i<call_vec.size();i++)  
    {  
        if(haveonline == false && call_vec[i].status =="on-line" )  
        {  
            format_calls.push_back(call_vec[i]);  
            haveonline = true;  
            curname = call_vec[i].name;  
        }  
        else if(haveonline == true && call_vec[i].status =="on-line")  
        {  
            format_calls.pop_back();  
            format_calls.push_back(call_vec[i]);  
            haveonline = true;  
            curname = call_vec[i].name;  
        }  
        else if(haveonline == true && call_vec[i].status =="off-line"&&call_vec[i].name ==curname)  
        {  
            format_calls.push_back(call_vec[i]);  
            haveonline = false;  
        }  
    }  
    //the last must be offline  
    if((*(format_calls.end()-1)).status == "on-line")  
        format_calls.pop_back();  
  
    //output  
    double totalcost = 0;  
    curname = "";  
    for(int i=0;i<format_calls.size();i+=2)  
    {  
  
        if(format_calls[i].name != curname)  
        {  
            if(curname!="")  
            {  
                printf("Total amount: $%.2f\n",totalcost);  
                totalcost = 0;  
                printf("%s %02d\n",format_calls[i].name.c_str(),format_calls[i].month);  
            }  
            else  
            {  
                printf("%s %02d\n",format_calls[i].name.c_str(),format_calls[i].month);  
            }  
            curname = format_calls[i].name;  
        }  
        printf("%02d:%02d:%02d",format_calls[i].date,format_calls[i].hour,format_calls[i].minute);  
        printf(" ");  
        printf("%02d:%02d:%02d",format_calls[i+1].date,format_calls[i+1].hour,format_calls[i+1].minute);  
        printf(" ");  
		printf("%d",format_calls[i+1].total - format_calls[i].total);  
        printf(" ");  
        printf("$%.2f\n",calCost(format_calls[i],format_calls[i+1]));  
        totalcost+=calCost(format_calls[i],format_calls[i+1]); 
    }  
    printf("Total amount: $%.2f\n",totalcost);  
	*/
	system("pause");
}