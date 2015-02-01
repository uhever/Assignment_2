#ifndef VOTER_H
#define VOTER_H

#include "Person.h"
#include "time.h"
#include "PersonSet.h"
#include "Candidate.h"
class Voter : public Person{
private:
    int polingStation;		//投票站ID
public:
    static int totalNumVoters;	//static变量存储投票者人数
    Voter(char *vName, int vAge, double vSalary, int vPolingStation);	//构造函数
    ~Voter();	//析构函数
    static int getVoters();		//获取选民总人数
    Person& select(PersonSet &candidates);	//随机选取一个竞争者
    bool vote(Person &candidate);	//!!!!选民进行投票操作!!!!!
    int getAge() const;	//获取选民年龄
    double getSalary() const;	//获取选民薪水
    int getID() const;	//获取ID
    
    
    
};


#endif