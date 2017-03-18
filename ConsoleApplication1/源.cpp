#include<iostream>
#include <Windows.h>
using namespace std;
const int N = 10;  //N��ʾϵͳ����ܼ�¼���ٸ�ѧ������Ϣ
const int courseNum = 3;  //���ſγ�
const char courseTitle[3][10] = { "��ѧ", "Ӣ��", "����" }; //���ſγ���
struct Student
{
	int id;
	char name[10]; // ����ÿ���˵��������Ȳ�����9���ַ�
	char sex; // �Ա�'M'��ʾ�У�'F'��ʾŮ
	int score[courseNum]; // ÿ�������ųɼ�
};
int n = 0;  //n��ʾϵͳ��¼�˶��ٸ�ѧ������Ϣ����ʼ��Ϊ0
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
		if (choice == 1)  //������¼
		{
			if (add())
			{
				cout << "��ӳɹ���" << endl;
			}
			else
			{
				cout << "�������������ʧ��!" << endl;
			}
			system("pause");
		}
		else if (choice == 2) //  ��ʾ���м�¼
		{
			showAllInfo();
			system("pause");
		}
		else if (choice == 3) // ��������ѯ
		{
			char queryName[10];
			cout << "����Ҫ��ѯ��������";
			cin >> queryName;
			int p = findByName(queryName);
			if (p < 0)
			{
				cout << "�޼�¼!" << endl;
			}
			else
			{
				showInfo(p);
			}
			system("pause");
		}
		else if (choice == 4)  // ��ѧ�Ų�ѯ
		{
			int queryId;
			cout << "����Ҫ��ѯ��ѧ�ţ�";
			cin >> queryId;
			int p = findById(queryId);
			if (p < 0)
			{
				cout << "�޼�¼!" << endl;
			}
			else
			{
				showInfo(p);
			}
			system("pause");
		}
		else if (choice == 5) // �������޸�ĳ����¼
		{
			char queryName[10];
			cout << "����������";
			cin >> queryName;
			int p = findByName(queryName);
			if (p < 0)
			{
				cout << "����ü�¼������!" << endl;
			}
			else
			{
				modify(p);
				cout << "�޸ĳɹ�" << endl;
			}
			system("pause");
		}
		else if (choice == 6) // ��ѧ��ɾ��ĳ����¼
		{
			int queryId;
			cout << "����Ҫɾ����¼��ѧ�ţ�";
			cin >> queryId;
			int p = findById(queryId);
			if (p < 0)
			{
				cout << "�޼�¼" << endl;
			}
			else
			{
				removeAt(p);
				cout << "ɾ���ɹ�" << endl;
			}
			system("pause");
		}
		else if (choice == 7) //  ����
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
	cout << "1. ���ѧ����Ϣ" << endl;
	cout << "2. ��ʾ����ѧ����Ϣ" << endl;
	cout << "3. ��������ѯĳ��ѧ������Ϣ" << endl;
	cout << "4. ��ѧ�Ų�ѯĳ��ѧ������Ϣ" << endl;
	cout << "5. �������޸�ĳ��ѧ������Ϣ" << endl;
	cout << "6. ��ѧ��ɾ��ĳ��ѧ������Ϣ" << endl;
	cout << "7. ��ƽ��������" << endl;
	cout << "8. �˳�ϵͳ" << endl;
	do
	{
		cin >> choice;
	} while (choice < 1 || choice > 8);
	return choice;
}
bool add()
{
	if (n == N) return false;
	// ����Ϣ����ڵ�n����¼��
	cout << "ѧ��(1~100)��";
	cin >> stu[n].id; // ˼���������Ӵ��룬�ж�����ѧ�Ų��ظ�
	for (int i = 0; i < n; i++)
	{
		if (stu[n].id == stu[i].id)
		{
			cout << "����ѧ���ظ�,���������룺" << endl;
			cin >> stu[n].id;
			break;
		}
	}
	cout << "������";
	cin >>stu[n].name ;
	cout << "�Ա�(M-�У�F-Ů)��";
	cin >> stu[n].sex;
	cout << courseNum << "�ſγ̳ɼ���" << endl;
	for (int i = 0; i < courseNum; i++)
	{
		cout << courseTitle[i] << ":";
		cin >> stu[n].score[i];
	}
	n++;  //��¼����+1
	return true;
}
void showAllInfo()
{
	cout << "ѧ��" << '\t'
		<< "����" << '\t'
		<< "�Ա�" << '\t';
	for (int i = 0; i < courseNum; i++)
	{
		cout << courseTitle[i] << '\t';
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		showInfo(i);
	}
	cout << "һ��" << n << "��" << endl;
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
		if (strcmp(stu[i].name, queryName) == 0)  //�ַ����Ƚ�
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
void modify(int p) // �޸ĵ�p����¼
{
	cout << "ѧ��(1~100)��" << stu[p].id << endl;
	cout << "������ѧ�ţ�";
	cin >> stu[p].id; 
	for (int i = 0; i < N; i++)
	{
		if (i == p)
		{
			continue;
		}
		if (stu[p].id == stu[i].id)
		{
			cout << "����ѧ���ظ�,���������룺" << endl;
			cin >> stu[p].id;
			break;
		}
	}
	cout << "������" << stu[p].name << endl;
	cout << "������������";
	cin >> stu[p].name;
	cout << "�Ա�" << stu[p].sex << endl;
	cout << "�������Ա�";
	cin >> stu[p].sex;
	cout << courseNum << "�ſγ̳ɼ���" << endl;
	for (int i = 0; i < courseNum; i++)
	{
		cout << courseTitle[i] << ":" << stu[p].score[i] << endl;
		cout << "�����³ɼ�;";
		cin >> stu[p].score[i];
	}
	return;
}
void removeAt(int p) // ɾ����p����¼
{
	// ��p+1����¼��������¼��ǰ�ƶ�
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
	int sum[N]; // sum[i]��¼��i��ѧ�������ųɼ��ܺ�
	for (int i = 0; i < n; i++)
	{
		sum[i] = 0;
		for (int j = 0; j < courseNum; j++)
		{
			sum[i] += stu[i].score[j];
		}
	}
	// ��ѡ������
	for (int i = 0; i < n; i++)
	{
		// ����sum[i]...s[n-1]������ֵsum[p]
		int p = i;
		for (int j = p + 1; j < n; j++)
		{
			if (sum[j] > sum[p]) p = j;
		}
		if (i != p)
		{
			// ������i���͵�p���˵���Ϣ
			// �����ܷ�
			int tempSum = sum[i]; sum[i] = sum[p]; sum[p] = tempSum;
			// ����ѧ��
			int tempId = stu[i].id; stu[i].id = stu[p].id; stu[p].id = tempId;
			// ��������
			char tempName[10];
			strcpy(tempName, stu[i].name); strcpy(stu[i].name, stu[p].name); strcpy(stu[p].name, tempName);
			// �����Ա�
			char tempSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tempSex;
			// ��������
			for (int j = 0; j < courseNum; j++)
			{
				int tempScore = stu[i].score[j]; stu[i].score[j] = stu[p].score[j]; stu[p].score[j] = tempScore;
			}
		}
	}
}
