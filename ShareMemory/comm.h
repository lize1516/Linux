//#pragma once

#ifndef _COMM_H__
#define _COMM_H__

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define PATHNAME "."     //����ǰĿ¼
#define PROJ_ID 0x6666    //Ȩ��

int createShm(int size);
int destoryShm(int shmid);
int getShm(int size);

#endif
