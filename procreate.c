#include "pcpy.h"



int procreate(const char* SFile , const char* DFile ,int pronum , int blocksize)
{
	int pos;

	int flag;
	pid_t pid;

	char cblock[10];     //整形转成char* 用sprintf
	char cpos[10];
    bzero(cblock,sizeof(cblock));
	bzero(cpos,sizeof(cpos));

	for(flag = 0;flag < pronum; flag++) //循环创建
	{

		pid = fork();
		if(pid == 0)
		{
			break;
		}
	}
	if(pid > 0 )
	{
		printf("Parent Pro pid [%d] 非阻塞回收...\n",getpid());
		pid_t zpid;

		while((zpid = waitpid(-1,NULL,WNOHANG))!= -1)
		{
			if(zpid > 0)
				printf("Parent Wait Success: zombie pid [%d]\n",zpid);
		}
	}else if(pid == 0)
	{   //偏移量计算
		pos = flag*blocksize;
		sprintf(cblock,"%s",blocksize);  //把blocksize写成字符串写入cblock
		sprintf(cpos,"%s",pos);
execl("/home/colin/0322晚班三阶段/PROCESS/processcpy/Copy","./Copy",SFile,DFile,cblock,cpos,NULL);
	}else
	{
		perror("FORK CALL FAILED");
		exit(-1);
	}
	return 0;
}
