#ifndef FUNCTIONMODEL_H
#define FUNCTIONMODEL_H

#include "PersonSet.h"
#include "Candidate.h"
#include "Voter.h"
void printCandidates(PersonSet& candidates);

//1.进行投票操作
void vote(PersonSet &candidates, PersonSet &voters, int flag = 0){
    
    if (flag == 0){
        for (int j = 0; j < candidates.getSize(); ++j){
            static_cast<Candidate&>(candidates.element(j)).emptySet();
        }
    }
    
    static int hoop = 1;
    cout << "请选择投票方式：\t1.全部随机\t2.指定投票" << endl;
    int getA;
    cin >> getA;
    cout << "进行第" << hoop++ << "轮投票" << endl;
    if (getA == 1){
        for (int i = 0; i < voters.getSize(); ++i){
            static_cast<Voter&>(voters.element(i)).vote((static_cast<Voter&>(voters.element(i)).select(candidates)));
        }
    }
    if (getA == 2){
        for (int i = 0; i < voters.getSize(); ++i){
            cout << static_cast<Voter&>(voters.element(i)).getName() << "开始投票.	请选择:1.指定投一个\t2.随机投一个\t3.弃权" << endl;
            int getC;
            cin >> getC;
            if (getC == 1){
                cout << "选择竞争者序号：" ;
                int getD;
                cin >> getD;
                static_cast<Voter&>(voters.element(i)).vote(candidates.element(getD));
            }
            if (getC == 2){
                static_cast<Voter&>(voters.element(i)).vote((static_cast<Voter&>(voters.element(i)).select(candidates)));
            }
            if (getC == 3){
                //cout << "弃权!" << endl;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < candidates.getSize(); ++i){
        if (static_cast<Candidate&>(candidates.element(i)).getNumVoters() > max)
            max = static_cast<Candidate&>(candidates.element(i)).getNumVoters();
    }
    PersonSet temp;
    for (int i = 0; i < candidates.getSize(); ++i){
        if (static_cast<Candidate&>(candidates.element(i)).getNumVoters() == max){
            temp.add(static_cast<Candidate&>(candidates.element(i)));
        }
    }
    printCandidates(candidates);
    if (temp.getSize() >1){
        cout << "第一轮投票最高票者大于等于2人，开始下轮投票！" << endl;
        for (int i = 0; i < candidates.getSize(); ++i){
            static_cast<Candidate&>(candidates.element(i)).emptySet();
        }
        vote(temp,voters);
    }
    else return;
}

//2.显示竞争者

void printCandidates(PersonSet &candidates){
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "序号\tID\t姓名  \t年龄\t薪水\t  票数\t平均薪水   平均年龄"  << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < candidates.getSize(); ++i){
        cout << i+1 <<  "\t";
        cout << static_cast<Candidate&>(candidates.element(i)).getID() << "\t";
        cout << static_cast<Candidate&>(candidates.element(i)).getName() << "  \t";
        cout << static_cast<Candidate&>(candidates.element(i)).getAge() << "\t";
        cout << static_cast<Candidate&>(candidates.element(i)).getSalary() << "\t";
        cout << static_cast<Candidate&>(candidates.element(i)).getNumVoters() << "\t";
        cout << static_cast<Candidate&>(candidates.element(i)).getAverageVotersSalary() << "\t\t";
        cout << static_cast<Candidate&>(candidates.element(i)).getAverageVotersAge() << endl;
    }
    cout << "--------------------------------------------------------------------------------" << endl;
    return;
    
}


//3.显示投票者

void printVoters(PersonSet &voters){
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "序号\tID\t姓名\t\t年龄\t薪水\t"  << endl;
    cout << "----------------------------------------------------" << endl;
    for (int i = 0; i < voters.getSize(); ++i){
        cout << i+1 <<  "\t";
        cout << static_cast<Voter&>(voters.element(i)).getID() << "\t";
        cout << static_cast<Voter&>(voters.element(i)).getName() << "\t\t";
        cout << static_cast<Voter&>(voters.element(i)).getAge() << "\t";
        cout << static_cast<Voter&>(voters.element(i)).getSalary() << endl;
        
    }
    cout << "----------------------------------------------------" << endl;
    return;
}


//4.显示支持某一个竞选者的选民信息

void printVatC(PersonSet &candidates){
    cout << "请输入竞选者序号：" << endl;
    int getA;
    cin >> getA;
    if (getA > 0 && getA < 4){
        cout << "支持竞选者" << static_cast<Candidate&>(candidates.element(getA-1)).getName() << "的选民是： " << endl;
        printVoters(static_cast<Candidate&>(candidates.element(getA-1)).getVoteSet());
    }
    return ;
    
}


//5.添加一个投票者

void insertVoter(PersonSet &voters){
    cout << "请输入姓名、年龄、薪水、投票站ID" << endl;
    char name[20];
    int age;
    double salary;
    int polingStation;
    cin >> name >> age >> salary >> polingStation;
    voters.add(*(new Voter(name, age, salary, polingStation)));
    
    cout << "添加成功！ " << endl;
    
    return ;
}


//6.修改竞争者的年龄，月薪

void modifyCandidate(PersonSet &candidates){
    cout << "请输入要修改的竞选者序号：" << endl;
    int getA;
    cin >> getA;
    if (getA > 0 && getA < 4){
        cout << "请输入要修改的年龄、月薪" << endl;
        int age;
        double salary;
        cin >> age >> salary;
        static_cast<Candidate&>(candidates.element(getA-1)).setAge(age);
        static_cast<Candidate&>(candidates.element(getA-1)).setSalary(salary);
    }
    cout << "修改成功！ " << endl;
    return ;
    
}


//7.显示竞选成功者

void winner(PersonSet &candidates){
    int max = 0, maxNum = 0;
    for (int i = 0; i < candidates.getSize(); ++i){
        if(static_cast<Candidate&>(candidates.element(i)).getNumVoters() > max){
            max = static_cast<Candidate&>(candidates.element(i)).getNumVoters();
            maxNum = i;
        }
    }
    PersonSet temp;
    temp.add(static_cast<Candidate&>(candidates.element(maxNum)));
    cout << "竞选成功者是： " << endl;
    printCandidates(temp);
}

//8.若一人放弃竞选，票给他人
void giveUp(PersonSet &candidates){
    cout << "请输入放弃竞选者序号： " << endl;
    int getA;
    cin >> getA;
    if (getA > 0 && getA < 4){
        Candidate *c = static_cast<Candidate*>(&candidates.removeElement(getA));
        //for (int i = 0; i < (c->getVoteSet()).getSize(); ++i){
        vote(candidates, c->getVoteSet(), 1);
        //}
        delete c;
    }
}

#endif