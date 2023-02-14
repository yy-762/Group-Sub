//
// Created by 杨渊 on 2023/2/14.
//

#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pthread.h>
#include <thread>
using namespace std;

void *mythread(void *arg){
    cout<<"pthread id=="<<pthread_self()<<endl;
}
int main(){
    pid_t pid=fork();
    if(pid<0){
        cout<<"error";
    }
    else if(pid==0){
        cout<<"father pid=="<<getpid()<<endl;
    }
    else if(pid>0){
        cout<<"child pid=="<<getpid()<<endl;
        pthread_t thread;
        int ret;
        int arr[5];
        for(int i=0;i<5;i++){
            ret=pthread_create(&thread,NULL,mythread,&arr[i]);
            // thread mythread1(mythread,4);
        }
    }
    pthread_exit(NULL);
    return 0;

}
