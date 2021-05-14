//
// Created by sirwang on 2021/5/14.
//

#include "TaskQueue.h"

TaskQueue::TaskQueue() {
    pthread_mutex_init(&mutexlock, nullptr);
}

TaskQueue::~TaskQueue() {
    pthread_mutex_destroy(&mutexlock);
}

void TaskQueue::addTask(Task *task) {
    pthread_mutex_lock(&mutexlock);
    m_taskQ.push(*task);
    pthread_mutex_unlock(&mutexlock);
}


void TaskQueue::addTask(callback f, void *arg) {
    pthread_mutex_lock(&mutexlock);
    m_taskQ.push(Task(f,arg));
    pthread_mutex_unlock(&mutexlock);
}

Task *TaskQueue::takeTask() {

    Task* t;
    pthread_mutex_lock(&mutexlock);
    if (m_taskQ.empty()){
        t=&m_taskQ.front();
        m_taskQ.pop();
    }
    pthread_mutex_unlock(&mutexlock);
    return t;
}


