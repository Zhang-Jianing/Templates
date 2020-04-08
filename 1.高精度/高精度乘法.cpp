//高精A*B模板
//张家宁

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>

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
	memset(ans,0,sizeof(ans));
	int lena,lenb,lenans;
	readin(a,lena);
	readin(b,lenb);
	lenans=lena+lenb-1;
	for (int i=0;i<lena;i++)
		for (int j=0;j<lenb;j++)
			ans[i+j]+=a[i]*b[j];
	for (int i=0;i<lenans;i++)
		for (;;)
		{
			if (ans[i]>=10)
			{
				ans[i+1]+=ans[i]/10;
				ans[i]%=10;
			}
			else
				break;
		}
	while (ans[lenans])
		lenans++;
	for (int i=lenans-1;i>=0;i--)
		printf("%d",ans[i]);
	return 0;
} 
