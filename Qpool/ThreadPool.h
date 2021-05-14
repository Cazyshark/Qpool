//
// Created by sirwang on 2021/1/14.
//
#include "TaskQueue.h"
#ifndef QPOOL_THREADPOOL_H
#define QPOOL_THREADPOOL_H


class ThreadPool {
public:
    ThreadPool()=delete;
    ThreadPool(int min,int max);
    ~ThreadPool();
    void addTask(Task task);
    size_t  getBusyNum();
    size_t getAliveNum();

private:
    TaskQueue*  taskQ;
    pthread_t managerID;
    pthread_t* threadID;
    size_t minNum;
    size_t maxNum;
    size_t busyNum;
    size_t liveNum;
    size_t exitNum;
    pthread_cond_t mutexPool;
    pthread_cond_t notEmpty;
    bool shutdown;

    void*  worker(void* arg);
    void*  manager(void* arg);
    void  threadExit();
};


#endif //QPOOL_THREADPOOL_H
