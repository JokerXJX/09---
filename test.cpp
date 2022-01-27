#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//成员变量 和 成员函数 是分开存储的

//class Person
//{
//	int m_A;//非静态成员变量 属于类的对象上的
//
//	static int m_B;//静态成员变量 不属于类的对象上
//
//	void func(){}//非静态成员函数 不属于类的对象上
//
//	static void func2() {}//静态成员函数 不属于类的对象上
//};
//int Person::m_B = 0;
//
//void test01()
//{
//	Person p;
//	//空对象占用内存空间为：1
//	//C++编译器会给每个空对象分配一个字节空间是为了区分空对象占内存的位置
//	//每个空对象也应该有一个独一无二的内存地址
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


//1.解决名称冲突
//class Person
//{
//public:
//	Person(int age)
//	{
//		//this指针指向  被调用的成员函数  所属的对象
//		this->age = age;
//	}
//	Person& PersonAddAge(Person& p)
//	{
//		this->age += p.age;
//		//this指向p2,而*this指向的是p2本体
//		return *this;
//	}
//	int age;
//};
//
//void test01()
//{
//	Person p1(18);//this指向p1
//	cout << "p1的年龄为：" << p1.age << endl;
//}
//
////2.返回对象本身用*this
//void test02()
//{
//	Person p1(10);
//	Person p2(10);
//	//链式编程思想
//	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
//	cout << "p2的年龄：" << p2.age << endl;
//}
//
//int main()
//{
//	//test01();
//	test02();
//	system("pause");
//	return 0;
//}


//空指针调用成员函数
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
//		//报错原因是因为传入的指针是NULL
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


//常函数
//class Person
//{
//public:
//
//	//this指针本质是指针常量  指针指向不可修改
//	//const Person* const this;
//	//在成员函数后面加const是修饰的this指针，让指针指向的值也不可修改
//	void showPerson() const
//	{
//		//this->m_A = 100;
//		m_B = 100;//this->m_B 
//	}
//
//	void func() {}
//	int m_A;
//	mutable int m_B;//特殊变量，即使在常函数中也可修改值
//	
//};
//
//void test01()
//{
//	Person p;
//	p.showPerson();
//}
//
////常对象
//void test02()
//{
//	const Person p;//在对象前加const，变为常对象
//	//p.m_A = 100;
//	p.m_B = 100;
//
//	//常对象只能调用常函数
//	p.showPerson();
//	//p.func();常对象不能调用普通成员函数，因为普通成员函数可以改变属性
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

#include<string.h>
//友元

//建筑物类
//class Building
//{
//	//goodGay是Building好朋友，可访问Building私有成员
//	friend void goodGay(Building* building);
//public:
//	Building()
//	{
//		m_SittingRoom = "客厅";
//		m_Bedroom = "卧室";
//	}
//public:
//	string m_SittingRoom;//客厅
//
//private:
//	string m_Bedroom;
//};
//
////1.全局函数做友元
//void goodGay(Building *building)
//{
//	cout << "好基友全局函数 正在访问：" << building->m_SittingRoom << endl;
//	cout << "好基友全局函数 正在访问：" << building->m_Bedroom<< endl;
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

//类做友元
//class Building;
//class GoodGay
//{
//public:
//	GoodGay();
//
//	void visit();//参观函数  访问Building中的属性
//
//	Building* building;
//};
//
//class Building
//{
//	//GoodGay类是本类好朋友，可访问私有成员
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
////类外实现成员函数
//Building::Building()
//{
//	m_SettingRoom = "客厅";
//	m_BedRoom = "卧室";
//}
//
//GoodGay::GoodGay()
//{
//	//创建建筑物对象
//	building = new Building;
//}
//
//void GoodGay::visit()
//{
//	cout << "好基友类正在访问：" << building->m_SettingRoom << endl;
//	cout << "好基友类正在访问：" << building->m_BedRoom << endl;
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
//	void visit();//可以访问Building中的私有成员
//	void visit2();//不可以访问Building中的私有成员
//
//	Building* building;
//};
//
//class Building
//{
//	//告诉编译器GoodGay类的visit成员函数是本类好朋友，可访问私有成员
//	friend void GoodGay::visit(); 
//public:
//	Building();
//public:
//	string m_SettingRoom;
//private:
//	string m_BedRoom;
//};
////类外实现成员函数
//Building::Building()
//{
//	m_SettingRoom = "客厅";
//	m_BedRoom = "卧室";
//}
//GoodGay::GoodGay()
//{
//	//创建建筑物对象
//	building = new Building;
//}
//
//void GoodGay::visit()
//{
//	cout << "visit函数正在访问：" << building->m_SettingRoom << endl;
//	cout << "visit函数正在访问：" << building->m_BedRoom << endl;
//}
//void GoodGay::visit2()
//{
//	cout << "visit函数正在访问：" << building->m_SettingRoom << endl;
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

//加号运算符重载
//class Person
//{
//public:
//	//1.成员函数重载加号
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
////2.全局函数重载加号
//Person operator+(Person& p1, Person& p2)
//{
//	Person tmp;
//	tmp.m_A = p1.m_A + p2.m_A;
//	tmp.m_B = p1.m_B + p2.m_B;
//	return tmp;
//}
//
////函数重载版本
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
//	//成员函数重载本质调用
//	//Person p3 = p1.operator+(p2);
//
//	//全局函数重载本质调用
//	//Person p3 = operator+(p1, p2);
//	//运算符重载 也可以发生函数重载
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


//左移运算符重载
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
//	//利用成员函数重载左移运算符
//	//不会利用成员函数重载左移运算符，因为无法实现cout在左侧
//	/*void operator<<()
//	{
//
//	}*/
//	int m_A;
//	int m_B;
//};
//
////只能运用全局函数重载左移运算符
//ostream &operator<<(ostream &cout,Person &p)//本质  cout << p
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

//递增运算符重载
//自定义整型
//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger myint);
//public:
//	MyInteger()
//	{
//		m_Num = 0;
//	}
//
//	//递增运算符前置重载
//	MyInteger &operator++()//返回引用是为了对同一个数据进行操作
//	{
//		//先运算
//		m_Num++;
//		//再将自身返回
//		return *this;
//	}
//
//	//递增运算符后置重载
//	//int 代表占位参数，用于区分前置和后置
//	MyInteger operator++(int)
//	{
//		//先  记录当时结果
//		MyInteger tmp = *this;
//		//再递增
//		m_Num++;
//		//最后将记录的结果返回
//		return tmp;
//	}
//
//private:
//	int m_Num;
//};
//
////重载左移运算符
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


//赋值运算符重载
//class Person
//{
//public:
//	Person(int age)
//	{
//		m_Age = new int(age);//堆区,手动开辟释放
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
//	//重载赋值运算符
//	Person &operator=(Person& p)
//	{
//		//编译器提供浅拷贝 m_Age=p.m_Age
//		//应该先判断是否有属性在堆区，如果有要先释放
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//		m_Age = new int(*p.m_Age);//深拷贝
//		//返回对象本身
//		return *this;
//	}
//	int *m_Age;//堆区
//};
//
//void test01()
//{
//	Person p1(18);
//	Person p2(20);
//	Person p3(30);
//	//p2 = p1;//赋值操作
//	p3 = p2 = p1;
//	cout << "p1的年龄：" << *p1.m_Age << endl;
//	cout << "p2的年龄：" << *p2.m_Age << endl;
//	cout << "p3的年龄：" << *p3.m_Age << endl;
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


//关系运算符重载
//class Person
//{
//public:
//	Person(string name,int age)
//	{
//		m_Name = name;
//		m_Age = age;
//	}
//	//重载==
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
//		cout << "p1和p2是相等的!" << endl;
//	}
//	else
//	{
//		cout << "p1和p2是不相等的!" << endl;
//	}
//	if (p1 != p2)
//	{
//		cout << "p1和p2是不相等的!" << endl;
//	}
//	else
//	{
//		cout << "p1和p2是相等的!" << endl;
//	}
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

#include<string.h>
//函数调用运算符重载
//打印输出类
class MyPrint
{
public:
	//重载函数调用运算符
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
	myprint("world");//由于使用起来类似函数调用，所以称为仿函数
	MyPrint02("hello");
}
//仿函数很灵活，没有固定写法
//加法类
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
	//匿名函数对象
	cout << MyAdd()(100, 100) << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}