#include <iostream>
using namespace std;
//��⣺
//��Ϊ��Ŀ˵����Ҫ�ҵ�������������һ�룬��˿�����������ͬ�������������������ʣ�µ�������Ҫ�������
//����Ҫ��scanf��printf����������case��ʱ������
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