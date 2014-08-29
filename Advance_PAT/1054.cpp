#include <iostream>
using namespace std;
//题解：
//因为题目说明了要找的数大于总数的一半，因此可以拿两个不同的数进行相抵消，这样剩下的数就是要求的数。
//并且要用scanf和printf，否则又有case超时。。。
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	int color, maxcolor, num;
	color = maxcolor = num = 0;
	for(int i = 0; i < m*n; ++i){
		scanf("%d", &color);
		if(num == 0){
			maxcolor = color;
			num = 1;
		}else{
			if(color == maxcolor){
				num++;
			}else{
				--num;
			}
		}
	}
	printf("%d\n", maxcolor);
	system("pause");
}