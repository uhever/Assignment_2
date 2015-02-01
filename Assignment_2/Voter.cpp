#include "Voter.h"

//static变量存储投票者人数
int Voter::totalNumVoters = 0;

//构造函数
Voter::Voter(char *vName, int vAge, double vSalary, int vPolingStation) : Person(vName, vAge, vSalary), polingStation(vPolingStation){
    ++ totalNumVoters;
}

//析构函数
Voter::~Voter(){
    cout << "Voter析构函数" << endl;
}


//获取选民总人数
int Voter::getVoters(){
    return totalNumVoters;
}


//-------随机选取一个竞争者--------

Person& Voter::select(PersonSet &candidates){
    int num = (rand() % candidates.getSize());
    Person &p = candidates.element(num);
    return p;
}

//--------选民投票操作----------

bool Voter::vote(Person &candidate){
    static_cast<Candidate&>(candidate).addVoter(*this);
    return true;
}

//获取选民年龄
int Voter::getAge() const{
    return Person::getAge();
}

//获取选民薪水
double Voter::getSalary() const{
    return Person::getSalary();
}


//获取ID

int Voter::getID() const{
    return Person::getID();
}
