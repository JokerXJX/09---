#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��Ա���� �� ��Ա���� �Ƿֿ��洢��

//class Person
//{
//	int m_A;//�Ǿ�̬��Ա���� ������Ķ����ϵ�
//
//	static int m_B;//��̬��Ա���� ��������Ķ�����
//
//	void func(){}//�Ǿ�̬��Ա���� ��������Ķ�����
//
//	static void func2() {}//��̬��Ա���� ��������Ķ�����
//};
//int Person::m_B = 0;
//
//void test01()
//{
//	Person p;
//	//�ն���ռ���ڴ�ռ�Ϊ��1
//	//C++���������ÿ���ն������һ���ֽڿռ���Ϊ�����ֿն���ռ�ڴ��λ��
//	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
//	cout << "size of p =" << sizeof(p) << endl;
//}
//
//void test02()
//{
//	Person p;
//	cout << "size of p =" << sizeof(p) << endl;
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//1.������Ƴ�ͻ
//class Person
//{
//public:
//	Person(int age)
//	{
//		//thisָ��ָ��  �����õĳ�Ա����  �����Ķ���
//		this->age = age;
//	}
//	Person& PersonAddAge(Person& p)
//	{
//		this->age += p.age;
//		//thisָ��p2,��*thisָ�����p2����
//		return *this;
//	}
//	int age;
//};
//
//void test01()
//{
//	Person p1(18);//thisָ��p1
//	cout << "p1������Ϊ��" << p1.age << endl;
//}
//
////2.���ض�������*this
//void test02()
//{
//	Person p1(10);
//	Person p2(10);
//	//��ʽ���˼��
//	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
//	cout << "p2�����䣺" << p2.age << endl;
//}
//
//int main()
//{
//	//test01();
//	test02();
//	system("pause");
//	return 0;
//}


//��ָ����ó�Ա����
//class Person
//{
//public:
//	void showClassName()
//	{
//		cout << "this is Person class" << endl;
//	}
//
//	void showPersonAge()
//	{
//		//����ԭ������Ϊ�����ָ����NULL
//		if (this == NULL)
//		{
//			return;
//		}
//		cout << "age=" << m_Age << endl;//m_Age=this->m_Age
//	}
//	int m_Age;
//};
//
//void test01()
//{
//	Person* p = NULL;
//	//p->showClassName();
//	p->showPersonAge();
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//������
//class Person
//{
//public:
//
//	//thisָ�뱾����ָ�볣��  ָ��ָ�򲻿��޸�
//	//const Person* const this;
//	//�ڳ�Ա���������const�����ε�thisָ�룬��ָ��ָ���ֵҲ�����޸�
//	void showPerson() const
//	{
//		//this->m_A = 100;
//		m_B = 100;//this->m_B 
//	}
//
//	void func() {}
//	int m_A;
//	mutable int m_B;//�����������ʹ�ڳ�������Ҳ���޸�ֵ
//	
//};
//
//void test01()
//{
//	Person p;
//	p.showPerson();
//}
//
////������
//void test02()
//{
//	const Person p;//�ڶ���ǰ��const����Ϊ������
//	//p.m_A = 100;
//	p.m_B = 100;
//
//	//������ֻ�ܵ��ó�����
//	p.showPerson();
//	//p.func();�������ܵ�����ͨ��Ա��������Ϊ��ͨ��Ա�������Ըı�����
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

#include<string.h>
//��Ԫ

//��������
//class Building
//{
//	//goodGay��Building�����ѣ��ɷ���Building˽�г�Ա
//	friend void goodGay(Building* building);
//public:
//	Building()
//	{
//		m_SittingRoom = "����";
//		m_Bedroom = "����";
//	}
//public:
//	string m_SittingRoom;//����
//
//private:
//	string m_Bedroom;
//};
//
////1.ȫ�ֺ�������Ԫ
//void goodGay(Building *building)
//{
//	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building->m_SittingRoom << endl;
//	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building->m_Bedroom<< endl;
//}
//
//void test01()
//{
//	Building building;
//	goodGay(&building);
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//������Ԫ
//class Building;
//class GoodGay
//{
//public:
//	GoodGay();
//
//	void visit();//�ιۺ���  ����Building�е�����
//
//	Building* building;
//};
//
//class Building
//{
//	//GoodGay���Ǳ�������ѣ��ɷ���˽�г�Ա
//	friend class GoodGay;
//public:
//	Building();
//
//public:
//	string m_SettingRoom;
//
//private:
//	string m_BedRoom;
//};
//
////����ʵ�ֳ�Ա����
//Building::Building()
//{
//	m_SettingRoom = "����";
//	m_BedRoom = "����";
//}
//
//GoodGay::GoodGay()
//{
//	//�������������
//	building = new Building;
//}
//
//void GoodGay::visit()
//{
//	cout << "�û��������ڷ��ʣ�" << building->m_SettingRoom << endl;
//	cout << "�û��������ڷ��ʣ�" << building->m_BedRoom << endl;
//}
//
//void test01()
//{
//	GoodGay gg;
//	gg.visit();
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//class Building;
//class GoodGay
//{
//public:
//	GoodGay();
//	void visit();//���Է���Building�е�˽�г�Ա
//	void visit2();//�����Է���Building�е�˽�г�Ա
//
//	Building* building;
//};
//
//class Building
//{
//	//���߱�����GoodGay���visit��Ա�����Ǳ�������ѣ��ɷ���˽�г�Ա
//	friend void GoodGay::visit(); 
//public:
//	Building();
//public:
//	string m_SettingRoom;
//private:
//	string m_BedRoom;
//};
////����ʵ�ֳ�Ա����
//Building::Building()
//{
//	m_SettingRoom = "����";
//	m_BedRoom = "����";
//}
//GoodGay::GoodGay()
//{
//	//�������������
//	building = new Building;
//}
//
//void GoodGay::visit()
//{
//	cout << "visit�������ڷ��ʣ�" << building->m_SettingRoom << endl;
//	cout << "visit�������ڷ��ʣ�" << building->m_BedRoom << endl;
//}
//void GoodGay::visit2()
//{
//	cout << "visit�������ڷ��ʣ�" << building->m_SettingRoom << endl;
//
//}
//
//void test01()
//{
//	GoodGay gg;
//	gg.visit();
//	gg.visit2();
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//�Ӻ����������
//class Person
//{
//public:
//	//1.��Ա�������ؼӺ�
//	/*Person operator+(Person& p)
//	{
//		Person tmp;
//		tmp.m_A = this->m_A + p.m_A;
//		tmp.m_B = this->m_B + p.m_B;
//		return tmp;
//	}*/
//
//	int m_A;
//	int m_B;
//};
////2.ȫ�ֺ������ؼӺ�
//Person operator+(Person& p1, Person& p2)
//{
//	Person tmp;
//	tmp.m_A = p1.m_A + p2.m_A;
//	tmp.m_B = p1.m_B + p2.m_B;
//	return tmp;
//}
//
////�������ذ汾
//Person operator+(Person& p1, int num)
//{
//	Person tmp;
//	tmp.m_A = p1.m_A + num;
//	tmp.m_B = p1.m_B + num;
//	return tmp;
//}
//
//void test01()
//{
//	Person p1;
//	p1.m_A = 10;
//	p1.m_B = 10;
//	Person p2;
//	p2.m_A = 10;
//	p2.m_B = 10;
//	//��Ա�������ر��ʵ���
//	//Person p3 = p1.operator+(p2);
//
//	//ȫ�ֺ������ر��ʵ���
//	//Person p3 = operator+(p1, p2);
//	//��������� Ҳ���Է�����������
//
//	Person p4 = p1 + 2;//Person+int
//	//Person p3 = p1 + p2;
//	cout << "p4.m_A=" << p4.m_A << endl;
//	cout << "p4.m_B=" << p4.m_B << endl;
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//�������������
//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);
//public:
//	Person(int a, int b)
//	{
//		m_A = a;
//		m_B = b;
//	}
//private:
//	//���ó�Ա�����������������
//	//�������ó�Ա���������������������Ϊ�޷�ʵ��cout�����
//	/*void operator<<()
//	{
//
//	}*/
//	int m_A;
//	int m_B;
//};
//
////ֻ������ȫ�ֺ����������������
//ostream &operator<<(ostream &cout,Person &p)//����  cout << p
//{
//	cout << "m_A=" << p.m_A << " m_B=" << p.m_B;
//	return cout;
//}
//
//void test01()
//{
//	Person p(10,10);
//	//p.m_A = 10;
//	//p.m_B = 10;
//	cout << p << endl;
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//�������������
//�Զ�������
//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger myint);
//public:
//	MyInteger()
//	{
//		m_Num = 0;
//	}
//
//	//���������ǰ������
//	MyInteger &operator++()//����������Ϊ�˶�ͬһ�����ݽ��в���
//	{
//		//������
//		m_Num++;
//		//�ٽ�������
//		return *this;
//	}
//
//	//�����������������
//	//int ����ռλ��������������ǰ�úͺ���
//	MyInteger operator++(int)
//	{
//		//��  ��¼��ʱ���
//		MyInteger tmp = *this;
//		//�ٵ���
//		m_Num++;
//		//��󽫼�¼�Ľ������
//		return tmp;
//	}
//
//private:
//	int m_Num;
//};
//
////�������������
//ostream& operator<<(ostream& cout, MyInteger myint)
//{
//	cout << myint.m_Num;
//	return cout;
//}
//
//void test01()
//{
//	MyInteger myint;
//	cout << ++(++myint) << endl;
//	cout << myint << endl;
//}
//
//void test02()
//{
//	MyInteger myint;
//	cout << myint++ << endl;
//	cout << myint << endl;
//}
//
//int main()
//{
//	//test01();
//	test02();
//	system("pause");
//	return 0;
//}


//��ֵ���������
//class Person
//{
//public:
//	Person(int age)
//	{
//		m_Age = new int(age);//����,�ֶ������ͷ�
//	}
//
//	~Person()
//	{
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//	}
//
//	//���ظ�ֵ�����
//	Person &operator=(Person& p)
//	{
//		//�������ṩǳ���� m_Age=p.m_Age
//		//Ӧ�����ж��Ƿ��������ڶ����������Ҫ���ͷ�
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//		m_Age = new int(*p.m_Age);//���
//		//���ض�����
//		return *this;
//	}
//	int *m_Age;//����
//};
//
//void test01()
//{
//	Person p1(18);
//	Person p2(20);
//	Person p3(30);
//	//p2 = p1;//��ֵ����
//	p3 = p2 = p1;
//	cout << "p1�����䣺" << *p1.m_Age << endl;
//	cout << "p2�����䣺" << *p2.m_Age << endl;
//	cout << "p3�����䣺" << *p3.m_Age << endl;
//}
//int main()
//{
//	test01();
//	/*int a = 10;
//	int b = 20;
//	int c = 30;
//	c = b = a;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;*/
//	system("pause");
//	return 0;
//}


//��ϵ���������
//class Person
//{
//public:
//	Person(string name,int age)
//	{
//		m_Name = name;
//		m_Age = age;
//	}
//	//����==
//	bool operator==(Person &p)
//	{
//		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
//		{
//			return true;
//		}
//		return false;
//	}
//	bool operator!=(Person& p)
//	{
//		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
//		{
//			return false;
//		}
//		return true;
//	}
//
//	string m_Name;
//	int m_Age;
//};
//void test01()
//{
//	Person p1("Tom", 18);
//	Person p2("Jerry", 18);
//	if (p1 == p2)
//	{
//		cout << "p1��p2����ȵ�!" << endl;
//	}
//	else
//	{
//		cout << "p1��p2�ǲ���ȵ�!" << endl;
//	}
//	if (p1 != p2)
//	{
//		cout << "p1��p2�ǲ���ȵ�!" << endl;
//	}
//	else
//	{
//		cout << "p1��p2����ȵ�!" << endl;
//	}
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

#include<string.h>
//�����������������
//��ӡ�����
class MyPrint
{
public:
	//���غ������������
	void operator()(string test)
	{
		cout << test << endl;
	}
};
void MyPrint02(string test)
{
	cout << test << endl;
}
void test01()
{
	MyPrint myprint;
	myprint("world");//����ʹ���������ƺ������ã����Գ�Ϊ�º���
	MyPrint02("hello");
}
//�º�������û�й̶�д��
//�ӷ���
class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};
void test02()
{
	MyAdd myadd;
	int ret = myadd(100, 100);
	cout << "ret=" << ret << endl;
	//������������
	cout << MyAdd()(100, 100) << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}