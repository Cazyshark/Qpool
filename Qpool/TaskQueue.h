//
// Created by sirwang on 2021/1/14.
//
#include <queue>
#include "Task.h"
#include <pthread.h>
#ifndef QPOOL_TASKQUEUE_H
#define QPOOL_TASKQUEUE_H

using namespace std;



class TaskQueue {
public:
    TaskQueue();
    ~TaskQueue();
    void addTask(Task* task);
    void addTask(callback f, void *arg);
    Task* takeTask();

    inline int  taskNumber()const{
        return m_taskQ.size();
    }                                //spcal


private:
    queue<Task> m_taskQ;

    pthread_mutex_t mutexlock;
    pthread_cond_t  plock;
};


#endif //QPOOL_TASKQUEUE_H
