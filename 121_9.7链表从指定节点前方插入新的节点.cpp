//// 121_9.7链表从指定节点前方插入新的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

struct Test
{
	int data;
	struct Test* next;
};

void printLink(struct Test* head)
{
	struct  Test* point = head;
	while (point != NULL)
	{
		printf("%d ", point->data);
		point = point->next;
	}
	putchar('\n');
}
int getLinkTotalNumber(struct Test* head)
{
	int count = 0;
	struct  Test* point = head;
	while (point != NULL)
	{
		count++;
		point = point->next;
	}
	return count;
}
struct Test* insertFromer(struct Test* head, int data, struct Test* niu)
{
	struct  Test* point = head;
	if (point->data == data)
	{
		niu->next = head;
		return niu;
	}
	while (point->next != NULL)
	{
		printf("data=%d  point=%d\n\n", data, point->next->data);
		if (point->next->data == data)
		{
			niu->next = point->next;
			point->next = niu;
			printf("找到了data，插入成功");
			return head;
		}
		point = point->next;
	}
	printf("没有找到data插入失败");
	return head;
}
int main()
{
	int i;

	int find;
	struct Test t1 = { 1,NULL };
	struct Test t2 = { 2,NULL };
	struct Test t3 = { 3,NULL };
	struct Test t4 = { 4,NULL };
	struct Test t5 = { 5,NULL };
	struct Test t6 = { 6,NULL };


	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t4;
	t4.next = &t5;
	t5.next = &t6;
	t6.next = NULL;//不写这一行也可以，因为t6的next不存在，所以，pointer成为了悬空指针指向了空，所以没必要写这一行
	struct Test niu = { 100,NULL };
	
	printf("你想插到哪个数字前面 1 2 3 4 5 6\n\n");
	scanf_s("%d", &find);
	struct Test* head = insertFromer(&t1,find, &niu);

	printf("成功在链表里面添加了%d个数字\n", getLinkTotalNumber(head) - 6);

	printLink(head);


	return 0;
}

//#include "stdio.h"
//
//struct Test
//{
//	int data;
//	struct Test* next;
//};
//
//struct Test* addInfront(struct Test* head, int data, struct Test* new1)
//{
//	struct Test* p = head;
//
//	if (data == head->data)
//	{
//		new1->next = head;
//		head = new1;
//		return head;
//	}
//	while (p->next != NULL)
//	{
//		if (data == p->next->data)
//		{
//			new1->next = p->next;
//			p->next = new1;
//			return head;
//		}
//		p = p->next;//让链表遍历起来
//	}
//}
//
//void printLink(struct Test* head)
//{
//	struct Test* p = head;
//
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	putchar('\n');
//}
//
//int main()
//{
//	struct Test t1 = { 1,NULL };
//	struct Test t2 = { 2,NULL };
//	struct Test t3 = { 3,NULL };
//	struct Test t4 = { 4,NULL };
//
//	t1.next = &t2;//t1的指针指向了t2的地址
//	t2.next = &t3;
//	t3.next = &t4;
//
//	struct Test new1 = { 5,NULL };
//	struct Test* head = &t1;
//
//	head = addInfront(head, 1, &new1);
//	printLink(head);
//
//	return 0;
//}