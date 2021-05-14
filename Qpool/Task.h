//
// Created by sirwang on 2021/5/14.
//

#ifndef QPOOL_TASK_H
#define QPOOL_TASK_H
using  callback =  void(*)(void* arg);
class Task{
public:
    Task():functionP(nullptr),arg(nullptr){}
    Task(callback f,void* i_arg):functionP(f),arg(i_arg){}
private:
    callback functionP;
    void* arg;
};


#endif //QPOOL_TASK_H
