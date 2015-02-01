#ifndef CANDIDATE_H
#define CANDIDATE_H

#include "Person.h"
#include "PersonSet.h"
class Voter;

class Candidate : public Person{
private:
    PersonSet voterSet;	//存放选民的容器
public:
    static int numCandidates;	//又多少个竞争者
    static int getNumCandidates();	//返回有多少个竞争者
    Candidate(char *cName, int cAge, double cSalary);	//构造函数
    ~Candidate();	//析构函数
    void setAge(int newAge);	//修改年龄
    void setSalary(double newSalary);	//修改薪水
    void addVoter(Voter &v);	//添加选民到voterSet
    int getID() const;
    int getAverageVotersAge() const;	//获取选民平均年龄
    double getAverageVotersSalary() const;	//获取选民平均薪水
    int getNumVoters() const;	//获取总选票
    PersonSet& getVoteSet();	//获取容器
    void emptySet();	//清空容器
    
};


#endif