#include "Candidate.h"
#include "Voter.h"

int Candidate::numCandidates = 0;

//构造函数
Candidate::Candidate(char *cName, int cAge, double cSalary) : Person(cName, cAge, cSalary){
    ++ numCandidates;	//总竞选者人数
}

//析构函数
Candidate::~Candidate(){
    cout << "Candidate析构函数" << endl;
}

//修改年龄
void Candidate::setAge(int newAge){
    Person::setAge(newAge);
}
//修改薪水
void Candidate::setSalary(double newSalary){
    Person::setSalary(newSalary);
}


//返回竞争者人数
int Candidate::getNumCandidates(){
    return numCandidates;
}

//添加选民到容器
void Candidate::addVoter(Voter &v){
    voterSet.add(v);
}


//获取ID
int Candidate::getID() const{
    return Person::getID();
}

//获取选民平均年龄
int Candidate::getAverageVotersAge() const{
    if (voterSet.getSize() == 0)
        return 0;
    int count = 0;
    for (int i = 0; i < voterSet.getSize(); ++i){
        count += static_cast<Voter&>(voterSet.element(i)).getAge();
    }
    return count/(voterSet.getSize());
}

//获取选民平均薪水
double Candidate::getAverageVotersSalary() const{
    if (voterSet.getSize() == 0)
        return 0;
    double count = 0;
    for (int i = 0; i < voterSet.getSize(); ++i){
        count += static_cast<Voter&>(voterSet.element(i)).getSalary();
    }
    return count / (voterSet.getSize());
}

//获取总选票
int Candidate::getNumVoters() const{
    return voterSet.getSize();
}

//获取容器
PersonSet& Candidate::getVoteSet(){
    return voterSet;
}


//清空容器
void Candidate::emptySet(){
    voterSet.reset();
}