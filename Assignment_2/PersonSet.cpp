#include"PersonSet.h"

PersonSet::PersonSet(int capacity)
{
    this->capacity = capacity;
    elements = new Person*[this->capacity];
    size = 0;
}

PersonSet::~PersonSet()
{
    cout << "PersonSet析构函数" << endl;
    delete [] elements;
}

//获取容器大小
int PersonSet::getSize() const
{
    return size;
}

void PersonSet::add(Person& person)
{
    if(size == capacity)
    {
        //	cout<<"存储空间不足，容器扩容一半！"<<endl;
        Person** temp = elements;
        elements = new Person*[capacity * 2];
        for(int i = 0; i < size; i++)
        {
            elements[i] = temp[i];
        }
        capacity = capacity * 2;
        delete [] temp;
    }
    elements[size++] = &person;
}

//删除掉第index个person
Person& PersonSet::removeElement(int index)
{
    if(index <= 0 || index > size)
    {
        cout<<"要删除的元素不存在！"<<endl;
        exit(1);
    }
    
    Person *p = elements[index-1];
    if((size-1) < capacity / 2){
        Person **temp = elements;
        elements = new Person*[capacity / 2];
        capacity /= 2;
        
        for(int i = 0;i < index - 1; ++i){
            elements[i] = temp[i];
        }
        for(int i = index;i < size; ++i){
            elements[i-1] = temp[i];
        }
        
        delete [] temp;
    }else{
        for(int i = index - 1; i < size; ++i){
            elements[i] = elements[i+1];
        }
    }
    
    size--;
    return *p;
}

//遍历person
Person& PersonSet::element(int index) const
{
    if(index < 0)
    {
        cout<<"要遍历的元素不存在！"<<endl;
        exit(1);
    }
    else
    {
        return *elements[index % size];
    }
}



//重置容器
void PersonSet::reset()
{
    for(int i = 0; i < size; i++)
        elements[i] = NULL;
    size = 0;
}
