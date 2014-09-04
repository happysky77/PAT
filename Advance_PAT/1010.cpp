#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int charToInt(char x)//�ַ�ת����
{
    if('0'<=x&&x<='9')
        return x-'0';
    else
        return x-'a'+10;
}
long long charToDecimal(char* x,long long radix)//�ַ���ת��Ӧ��������
{
    int len=strlen(x);
    long long ans=0;
    for(int i=0;i<len;++i)
    {
        ans*=radix;
        ans+=charToInt(x[i]);
		//����Խ���ж�
        if(ans<0)
            return -1;
    }
    return ans;
}
int main()
{
    char as[15],bs[15],temp[15];
    long long tag,radix,aimNum;
    int lenA,lenB;
    scanf("%s%s%lld%lld",as,bs,&tag,&radix);
    if(tag==1)
    {
        strcpy(temp,as);
        strcpy(as,bs);
        strcpy(bs,temp);
        tag=2;
    }
    lenA=strlen(as);
    lenB=strlen(bs);
    aimNum=charToDecimal(bs,radix);
    long long low=2;//��������
    for(int i=0,j;i<lenA;++i)
    {
        j=charToInt(as[i]);
        if(j>=low)
            low=j+1;
    }
    long long high=aimNum+1;//��������
    long long aimRadix;
    long long tempAns;
    bool flag=false;
    for(;low<=high;)//��������
    {
        aimRadix=(high+low)/2;
        tempAns=charToDecimal(as,aimRadix);
        if(tempAns==-1||tempAns>aimNum)
            high=aimRadix-1;
        else if(tempAns<aimNum)
            low=aimRadix+1;
        else
        {
            flag=true;
            break;
        }
    }
    if(flag)
        printf("%lld\n",aimRadix);
    else
        printf("Impossible\n");
	system("pause");
    return 0;
}