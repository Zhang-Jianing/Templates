//线性表的基本操作
//张家宁 

#include<cstdio>
#include<iostream> 

typedef int DataType;

const int LISTSIZE=100;

struct SeqList{
	DataType data[LISTSIZE];
	int nLength;
};

//初始化一个线性表 
void initList(SeqList *list) 
{
	list->nLength=0;
} 

//判断一个线性表是否为空 
bool listEmpty(SeqList *list)
{
	return list->nLength==0;
}

//将线性表中的所有元素删除 
void clearList(SeqList *list)
{
	list->nLength=0;
} 

//获取线性表中元素的个数
int listLength(SeqList *list)
{
	return list->nLength;
} 

//获取表中下表为i的元素
DataType* getNode(SeqList *list,int i)
{
	if (i<0 || i>list->nLength-1)
		return NULL;
	return &list->data[i];
} 

//在线性表中查找指定元素 
int locateNode(SeqList *list,DataType x)
{
	for (int i=0;i<list->nLength;i++)
		if (list->data[i]==x)
			return i;
	return -1;
} 

//在线性表下标为i的位置插入元素
bool insert(SeqList *list,int i,DataType x)
{
	if (list->nLength==LISTSIZE)
		return false;
	int insertPosition=i;
	if (i<0)
		insertPosition=0;
	if (i>list->nLength-1)
		insertPosition=list->nLength;
	for (int j=list->nLength-1;j>=insertPosition;j--)
		list->data[j+1]=list->data[j];
	list->data[insertPosition]=x;
	list->nLength++;
	return true;
}

//将线性表中下标为i的元素删除
bool DeleteList(SeqList *list,int i)
{
	if (i<0||i>=list->nLength)
		return false;
	for (int j=i;j<list->nLength-1;j++)
		list->data[j]=list->data[j+1];
	list->nLength--;
	return false;
}

//将两个线性表合并
void unionList(SeqList *a,SeqList *b)
{
	if (a->nLength+b->nLength>LISTSIZE)
		return;
	for (int i=0;i<b->nLength;i++)
	{
		DataType e=b->data[i];
		if (locateNode(a,e)==-1)
			insert(a,a->nLength,e); 
	}
} 

//将线性表倒置 
void reverseList(SeqList *list)
{
	for (int i=0;i<list->nLength/2;i++)
	{
		DataType t=list->data[i];
		list->data[i]=list->data[list->nLength-1-i];
		list->data[list->nLength-1-i]=t;
	}
}

//线性表遍历
void print(DataType d)
{
	std::cout<<d<<std::endl;
}
void travel(SeqList *list,void(*visitFun)(DataType))
{
	for (int i=0;i<list->nLength;i++)
		visitFun(list->data[i]);
} 

int main()
{
	SeqList sl,a,b;
	initList(&sl);
	bool empty=listEmpty(&sl);
	clearList(&sl);
	DataType *pNode=getNode(&sl,3);
	int index=locateNode(&sl,6); 
	bool insert_flag=insert(&sl,5,10);
	bool delete_flag=DeleteList(&sl,2);
	unionList(&a,&b);
	travel(&sl,print);
	//...
	return 0;
}
