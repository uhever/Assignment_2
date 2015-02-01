#ifndef PersonSet_Header
#define PersonSet_Header

#include "Person.h"

class PersonSet
{
public:
    PersonSet(int capacity = 4);			//构造函数
    ~PersonSet();						//析构函数
    int getSize() const;
    void add(Person& person);			//增加一个person
    Person& removeElement(int index);	//删除第index个person
    Person& element(int index) const;			//查找第index个person（从0开始）
    void reset();	//重置容器
private:
    Person** elements;		//存储指针的指针
    int capacity;			//容器总共能存储的容量
    int size;				//存储的Person的个数
};
#endif