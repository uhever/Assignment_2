#include "Person.h"

int Person::totalPerson = 0; //初始化静态成员变量

//Person构造函数
Person::Person(char *pName, int pAge, double pSalary) : name(NULL), age(pAge), salary(pSalary) {
    if(pName != NULL){
        name = new char[strlen(pName) + 1];
        strcpy(name, pName);
        ++ totalPerson;
        id = totalPerson;
    }
}

//析构函数
Person::~Person(){
    delete [] name;
}


//获取年龄
int Person::getAge() const{
    return age;
}

//修改年龄
void Person::setAge(int newAge){
    age = newAge;
}

//获取ID
int Person::getID() const{
    return id;
}

//获取薪水
double Person::getSalary() const{
    return salary;
}

//修改月薪
void Person::setSalary(double newSalary){
    salary = newSalary;
}

//获取姓名
char *Person::getName() const{
    return name;
}