#include "PersonSet.h"
#include "Voter.h"
#include "Candidate.h"
#include "FunctionModels.h"

int main(){
    
    Candidate *c1 = new Candidate("Can1",50,55500);
    Candidate *c2 = new Candidate("Can2",45,19800);
    Candidate *c3 = new Candidate("Can3",55,15000);
    
    PersonSet candidates;
    candidates.add(*c1);
    candidates.add(*c2);
    candidates.add(*c3);
    
    Voter *v1 = new Voter("Vo1",20,6000,1);
    Voter *v2 = new Voter("Vo2",24,30000,1);
    Voter *v3 = new Voter("Vo3",37,8000,1);
    Voter *v4 = new Voter("Vo4",51,80000,1);
    Voter *v5 = new Voter("Vo5",22,5000,3);
    Voter *v6 = new Voter("Vo6",29,12000,2);
    Voter *v7 = new Voter("Vo7",26,10000,2);
    Voter *v8 = new Voter("Vo8",43,55000,3);
    Voter *v9 = new Voter("Vo9",17,4000,1);
    Voter *v10 = new Voter("Vo10",32,25000,2);
    
    PersonSet voters;
    
    voters.add(*v1);
    voters.add(*v2);
    voters.add(*v3);
    voters.add(*v4);
    voters.add(*v5);
    voters.add(*v6);
    voters.add(*v7);
    voters.add(*v8);
    voters.add(*v9);
    voters.add(*v10);
    
    srand (time(NULL));	//设定随机数种子
    
    //开始投票
    //for (int i = 0; i < Voter::getVoters(); ++i){
    //	static_cast<Voter&>(voters.element(i)).vote(candidates);
    //}
    //
    //for (i = 0; i < Candidate::getNumCandidates(); ++i){
    //static_cast<Candidate&>(candidates.element(i)).printVoters();
    //}
    
    
    /* -------------------------------------------------------  */
    
    cout << "###############欢迎进入投票系统################" << endl << endl;
    cout << "1.进行投票操作" << endl;
    cout << "2.显示竞选者的信息概览" << endl;
    cout << "3.显示投票者的信息概览" << endl;
    cout << "4.显示支持某一个竞选者的选民信息" << endl;
    cout << "5.添加一个选民" << endl;
    cout << "6.修改竞选者的年龄、月薪" << endl;
    cout << "7.Tell Me Who is WINNER！！！" << endl;
    cout << "8.若一人放弃竞选，票给其他" << endl;
    cout << "请输入功能序号：" << endl;
    int x;
    cin >> x;
    while(x > 0){
        switch(x){
            case 1: vote(candidates, voters,0);	  //第三个参数flag = 0，每次投票前清除候选人所有的选票信息，进行重投 、、 flag = 1,不清楚之前的选票信息
                break;
                
            case 2:
                printCandidates(candidates);
                break;
                
            case 3:
                printVoters(voters);
                break;
                
            case 4:
                printVatC(candidates);
                break;
            case 5:
                insertVoter(voters);
                break;
            case 6:
                modifyCandidate(candidates);
                break;
            case 7:
                winner(candidates);
                break;
            case 8:
                giveUp(candidates);
                break;
                
        }
        
        
        cout << "请输入主菜单序号:" << endl;
        cin >> x;
    }
    
    //析构所有的投票者
    for (int i = 0; i < voters.getSize(); ++i){
        Voter *q = static_cast<Voter*>(&(voters.element(i)));
        delete q;
    }
    
    //析构所有竞选者
    for (int i = 0; i < candidates.getSize(); ++i){
        Candidate *v = static_cast<Candidate*>(&(candidates.element(i)));
        delete v;
    }
    return 0;
}
