//高精A/B模板（有余数）
//张家宁

#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=1000+5;
int a[MAXN],b[MAXN],ans[MAXN],yu[MAXN];

void readin(int *a)
{
    string s;
    cin>>s;
    a[0]=s.length();
    for (int i=1;i<=a[0];i++)
        a[i]=s[i-1]-'0';
    reverse(a+1,a+a[0]+1);
}

bool big() //比较余数 yu 与除数 b 的大小，如果 yu>=b，则返回 true，否则返回 false
{
    if (yu[0]>b[0])
        return true;
    if (yu[0]<b[0])
        return false;
    for (int i=yu[0];i>=1;i--)
    {
        if (yu[i]<b[i])
            return false;
        else
            if (yu[i]>b[i])
                return true;
    }
    return true;
}

void minuss() //从 yu 中减去 b
{
    int c=0;
    for (int i=1;i<=yu[0];i++)
    {
        yu[i]-=b[i]+c;
        if (yu[i]<0)
        {
            yu[i]+=10;
            c=1;
        }
        else
            c=0;
    }
    while (yu[0]>1 && yu[yu[0]]==0)
        yu[0]--;
}

void output(int *a)
{
    for (int j=a[0];j>=1;j--)
        printf("%d",a[j]);
    cout<<endl;
}

int main()
{
    memset(ans,0,sizeof(ans));
    memset(yu,0,sizeof(yu));
    int lena,lenb,lenans;
    readin(a);
    readin(b);
    yu[0]=0;
    for (int i=a[0];i>=1;i--)
    {
        for (int j=yu[0];j>=1;j--)
            yu[j+1]=yu[j];
        yu[1]=a[i];
        yu[0]++;
        while(big())
        {
            minuss();
            ans[i]++;
        }
    }
    ans[0]=a[0];
    while (ans[0]>1 && ans[ans[0]]==0)
        ans[0]--;
    output(ans);
    output(yu);
    return 0;
}
