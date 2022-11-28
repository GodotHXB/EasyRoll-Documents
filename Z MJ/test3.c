#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <sys/shm.h>
#define PRO 1
#define CON 0
#define P -1
#define V +1
typedef int MySem;
MySem empty,full,mutex1,mutex2;
int *buf;
MySem newsem(int intVal)	// 新建信号量 
{
  int semID;
  int x;
  semID=semget(0,1,IPC_CREAT|0666); 
  x=semctl(semID,0,SETVAL,intVal); 	//对指定信号量赋intVal值 返回值：如果成功，则为一个正数；如果失败，则为-1
    return semID;
}
void psem(MySem semID){		//对ID为semID的信号量做p
   struct sembuf se;
   se.sem_num=0;
   se.sem_op=P;
   se.sem_flg=0;
   int r=semop(semID,&se,1);	//对指定的信号量执行P操作
}
void vsem(MySem semID){		//对ID为semID的信号量做v
   struct sembuf se;
   se.sem_num=0;
   se.sem_op=V;
   se.sem_flg=0;
   int r=semop(semID,&se,1);		//对指定的信号量执行V操作
}
void freesem(MySem semID){		//注销ID为semID的信号量
   int r;
   r=semctl(semID,0,IPC_RMID);	//IPC_RMID：注销（删除）信号量集，无需参数
}
int init(int n){
  int shpid;
  shpid=shmget(0,sizeof(int)*(n+2),IPC_CREAT|0666);		
  buf=(int *)shmat(shpid,0,0);	//将共享存储区映射到用户进程空间
  empty=newsem(n);		//缓冲区单元格有n个，可以执行最大次数k 
  full=newsem(0);  		//置初值 
  mutex1=newsem(1);	   
  mutex2=newsem(1);   //互斥 
  buf[n]=0;          
  buf[n+1]=0;        	//	缓冲区 
  return shpid;       //存储区               
}
void pro(pid_t pid,int n){ 
  printf("<P> <%d> started\n",getpid());	//取得进程识别码 旧版 新_getpid();
  int index=buf[n];  
  psem(empty);  		
  psem(mutex1);
  buf[n]=(buf[n]+1)%n;
  buf[ buf[n]]=1;		//模拟存入，置1
  printf("P <%d> put an item to <%d>\n",getpid(),index);
  vsem(mutex1);		//回调p函数，取出队首，
  vsem(full);
}
void con(pid_t pid,int n){ 
  printf("<C> <%d> started\n",getpid());
  int index=buf[n+1];
  psem(full);
  psem(mutex2);
  buf[n+1]=(buf[n+1]+1)%n;
  buf[buf[n+1]]=0;		//模拟取出，置0
  printf("C <%d> got an item from <%d>\n",getpid(),index);
  vsem(mutex2);
  vsem(empty);
}
int main(){ 
   int t,k,n;
   printf("Please input n:\n");
   scanf("%d",&n);
   int shpid=init(n);
   k=rand()%1+1;
   pid_t pid;  //定义进程标示符 
   while(1){ 
     srand((unsigned)time(NULL));	//每次置随机数种子 
     pid=fork();	 //建立一个新进程（子进程）
     if(pid==0)  	 //子线程  
     {                                                                                                     
       t=rand()%2;	//0，1 
       if(t==PRO)
         pro(pid,n);
       else if(t==CON)
         con(pid,n);
       return 0;  
      }
     else  		//父进程 
       sleep(k);
    }
    int x1=shmdt(0);	//断开已有的映射
	int x2=shmctl(shpid,IPC_RMID,0);
    return 0;
}

