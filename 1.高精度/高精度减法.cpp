//高精A-B模板
//张家宁

#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN=1000+5;
int a[MAXN],b[MAXN],ans[MAXN];

void readin(int *a,int &len)
{
	string s;
	cin>>s;
	len=s.length();
	for (int i=0;i<len;i++)
		a[i]=s[i]-'0';
	reverse(a,a+len);
}

int main()
{
	int lena,lenb,lenans,flag=0;
	readin(a,lena);
	readin(b,lenb);
	lenans=max(lena,lenb);
	for (int i=0;i<lenans;i++)
	{
		ans[i]=a[i]-b[i]-flag;
		if (ans[i]<0)
		{
			flag=1;
			ans[i]+=10;
		}
	}
	while (lenans>1 && ans[lenans-1]==0)
		lenans--;
	for (int i=lenans-1;i>=0;i--)
		printf("%d",ans[i]);
	return 0;
} 
