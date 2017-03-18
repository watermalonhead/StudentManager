#include<iostream>
#include <Windows.h>
using namespace std;
const int N = 10;  //N表示系统最多能记录多少个学生的信息
const int courseNum = 3;  //三门课程
const char courseTitle[3][10] = { "数学", "英语", "体育" }; //三门课程名
struct Student
{
	int id;
	char name[10]; // 假设每个人的姓名长度不超过9个字符
	char sex; // 性别，'M'表示男，'F'表示女
	int score[courseNum]; // 每人有三门成绩
};
int n = 0;  //n表示系统记录了多少个学生的信息，初始化为0
Student stu[N];
int getChoice();  
bool add();
void showAllInfo();
void showInfo(int p);
int findByName(char* queryName);
int findById(int queryId);
void modify(int p);
void removeAt(int p);
void sort();

int main()
{
	while (true)
	{
		int choice = getChoice();
		if (choice == 1)  //新增记录
		{
			if (add())
			{
				cout << "添加成功！" << endl;
			}
			else
			{
				cout << "数组已满，添加失败!" << endl;
			}
			system("pause");
		}
		else if (choice == 2) //  显示所有记录
		{
			showAllInfo();
			system("pause");
		}
		else if (choice == 3) // 按姓名查询
		{
			char queryName[10];
			cout << "输入要查询的姓名：";
			cin >> queryName;
			int p = findByName(queryName);
			if (p < 0)
			{
				cout << "无记录!" << endl;
			}
			else
			{
				showInfo(p);
			}
			system("pause");
		}
		else if (choice == 4)  // 按学号查询
		{
			int queryId;
			cout << "输入要查询的学号：";
			cin >> queryId;
			int p = findById(queryId);
			if (p < 0)
			{
				cout << "无记录!" << endl;
			}
			else
			{
				showInfo(p);
			}
			system("pause");
		}
		else if (choice == 5) // 按姓名修改某条记录
		{
			char queryName[10];
			cout << "输入姓名：";
			cin >> queryName;
			int p = findByName(queryName);
			if (p < 0)
			{
				cout << "输入该记录不存在!" << endl;
			}
			else
			{
				modify(p);
				cout << "修改成功" << endl;
			}
			system("pause");
		}
		else if (choice == 6) // 按学号删除某条记录
		{
			int queryId;
			cout << "输入要删除记录的学号：";
			cin >> queryId;
			int p = findById(queryId);
			if (p < 0)
			{
				cout << "无记录" << endl;
			}
			else
			{
				removeAt(p);
				cout << "删除成功" << endl;
			}
			system("pause");
		}
		else if (choice == 7) //  排序
		{
			sort();
			showAllInfo();
			system("pause");
		}
		else
		{
			break;
		}
	}
	return 0;
}

int getChoice()
{
	int choice;
	system("cls");
	cout << "1. 添加学生信息" << endl;
	cout << "2. 显示所有学生信息" << endl;
	cout << "3. 按姓名查询某个学生的信息" << endl;
	cout << "4. 按学号查询某个学生的信息" << endl;
	cout << "5. 按姓名修改某个学生的信息" << endl;
	cout << "6. 按学号删除某个学生的信息" << endl;
	cout << "7. 按平均分排序" << endl;
	cout << "8. 退出系统" << endl;
	do
	{
		cin >> choice;
	} while (choice < 1 || choice > 8);
	return choice;
}
bool add()
{
	if (n == N) return false;
	// 新信息存放在第n条记录中
	cout << "学号(1~100)：";
	cin >> stu[n].id; // 思考：如何添加代码，判断输入学号不重复
	for (int i = 0; i < n; i++)
	{
		if (stu[n].id == stu[i].id)
		{
			cout << "输入学号重复,请重新输入：" << endl;
			cin >> stu[n].id;
			break;
		}
	}
	cout << "姓名：";
	cin >>stu[n].name ;
	cout << "性别(M-男，F-女)：";
	cin >> stu[n].sex;
	cout << courseNum << "门课程成绩：" << endl;
	for (int i = 0; i < courseNum; i++)
	{
		cout << courseTitle[i] << ":";
		cin >> stu[n].score[i];
	}
	n++;  //记录人数+1
	return true;
}
void showAllInfo()
{
	cout << "学号" << '\t'
		<< "姓名" << '\t'
		<< "性别" << '\t';
	for (int i = 0; i < courseNum; i++)
	{
		cout << courseTitle[i] << '\t';
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		showInfo(i);
	}
	cout << "一共" << n << "人" << endl;
}
void showInfo(int p)
{
	cout << stu[p].id << '\t'
		<< stu[p].name << '\t'
		<< stu[p].sex << '\t';
	for (int i = 0; i < courseNum; i++)
	{
		cout << stu[p].score[i] << '\t';
	}
	cout << endl;
}
int findByName(char* queryName)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(stu[i].name, queryName) == 0)  //字符串比较
		{
			return i;
		}
	}
	return -1;
}
int findById(int queryId)
{
	for (int i = 0; i < n; i++)
	{
		if (stu[i].id == queryId)
		{
			return i;
		}
	}
	return -1;
}
void modify(int p) // 修改第p条记录
{
	cout << "学号(1~100)：" << stu[p].id << endl;
	cout << "输入新学号：";
	cin >> stu[p].id; 
	for (int i = 0; i < N; i++)
	{
		if (i == p)
		{
			continue;
		}
		if (stu[p].id == stu[i].id)
		{
			cout << "输入学号重复,请重新输入：" << endl;
			cin >> stu[p].id;
			break;
		}
	}
	cout << "姓名：" << stu[p].name << endl;
	cout << "输入新姓名：";
	cin >> stu[p].name;
	cout << "性别：" << stu[p].sex << endl;
	cout << "输入新性别：";
	cin >> stu[p].sex;
	cout << courseNum << "门课程成绩：" << endl;
	for (int i = 0; i < courseNum; i++)
	{
		cout << courseTitle[i] << ":" << stu[p].score[i] << endl;
		cout << "输入新成绩;";
		cin >> stu[p].score[i];
	}
	return;
}
void removeAt(int p) // 删除第p条记录
{
	// 第p+1条记录起逐条记录往前移动
	for (int i = p + 1; i < n; i++)
	{
		stu[i - 1].id = stu[i].id;
		strcpy(stu[i - 1].name, stu[i].name);
		stu[i - 1].sex = stu[i].sex;
		for (int j = 0; j < courseNum; j++)
		{
			stu[i - 1].score[j] = stu[i].score[j];
		}
	}
	n--;
}
void sort()
{
	int sum[N]; // sum[i]记录第i个学生的三门成绩总和
	for (int i = 0; i < n; i++)
	{
		sum[i] = 0;
		for (int j = 0; j < courseNum; j++)
		{
			sum[i] += stu[i].score[j];
		}
	}
	// 用选择法排序
	for (int i = 0; i < n; i++)
	{
		// 查找sum[i]...s[n-1]中最大的值sum[p]
		int p = i;
		for (int j = p + 1; j < n; j++)
		{
			if (sum[j] > sum[p]) p = j;
		}
		if (i != p)
		{
			// 交换第i个和第p个人的信息
			// 交换总分
			int tempSum = sum[i]; sum[i] = sum[p]; sum[p] = tempSum;
			// 交换学号
			int tempId = stu[i].id; stu[i].id = stu[p].id; stu[p].id = tempId;
			// 交换姓名
			char tempName[10];
			strcpy(tempName, stu[i].name); strcpy(stu[i].name, stu[p].name); strcpy(stu[p].name, tempName);
			// 交换性别
			char tempSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tempSex;
			// 交换分数
			for (int j = 0; j < courseNum; j++)
			{
				int tempScore = stu[i].score[j]; stu[i].score[j] = stu[p].score[j]; stu[p].score[j] = tempScore;
			}
		}
	}
}
