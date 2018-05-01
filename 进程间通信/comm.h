//#pragma once

#ifndef _COMM_H__
#define _COMM_H__

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

#define PATHNAME "."
#define PROJ_ID 0x6666

union semun
{
    int val;
    struct semid_ds* buf;
    unsigned short* array;
    struct seminfo* _buf;
};

int createSemSet(int nums);
int initSem(int semid,int nums,int initval);
int getSemSet(int nums);
int P(int semid,int who);
int V(int semid,int who);
int destorySemSet(int semid);

#endif
