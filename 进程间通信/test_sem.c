#include"comm.h"

int main()
{
    int semid=createSemSet(1);
    printf("se=%d\n",semid);
    initSem(semid,0,1);
    pid_t id=fork();
    if(id==0)
    {
        //child
        int _semid=getSemSet(0);
        printf("_semid=%d\n",_semid);
        while(1)
        {
            P(_semid,0);
            printf("A");
            fflush(stdout);
            usleep(200000);
            printf("A ");
            fflush(stdout);
            usleep(200000);
            V(_semid,0);
        }
    }
    else
    {
        //father
        while(1)
        {
            P(semid,0);
            printf("B");
            fflush(stdout);
            usleep(200000);
            printf("B ");
            fflush(stdout);
            usleep(200000);
            V(semid,0);
        }
        wait(NULL);
    }
    destorySemSet(semid);
    return 0;
}
