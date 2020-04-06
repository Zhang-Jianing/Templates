//高精A+B模板 
//张家宁

#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

const int MAXN=505;
int a[MAXN], b[MAXN], ans[MAXN];

void readin(int *a,int &l)
{
	string s;
	cin>>s;
	l=s.length();
	for (int i=0;i<l;i++)
		a[i]=s[i]-'0';
	reverse(a,a+l);
}

int main()
{
	memset(ans,0,sizeof(ans));
	int lena,lenb,lenans,flag=0;
	readin(a,lena);
	readin(b,lenb);
	lenans=max(lena,lenb);
	for (int i=0;i<=lenans;i++)
	{
		ans[i]=a[i]+b[i]+flag;
		flag=0;
		if (ans[i]>=10)
		{
			ans[i]%=10;
			flag=1;
		}
	}
	if (ans[lenans]!=0)
		lenans++;
	for (int i=lenans-1;i>=0;i--)
		printf("%d",ans[i]);
	return 0;
} 
