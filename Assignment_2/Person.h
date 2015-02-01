#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person{
private:
    char *name;
    int age;
    double salary;
    int id;//投票者id
public:
    static int totalPerson;		//记录总人数
    Person(char *pName, int pAge, double pSalary);
    ~Person();	//析构函数
    int getAge() const;	//获取年龄
    void setAge(int newAge);	//修改年龄
    void setSalary(double newSalary);	//修改月薪
    int getID() const;	//获取ID
    double getSalary() const;	//获取薪水
    char *getName() const;		//获取姓名
};

#endif