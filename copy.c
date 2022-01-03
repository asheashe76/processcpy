#include "pcpy.h"



int main(int argc, char** argv)
{
	int pos = atoi(argv[4]);
	int blocksize = atoi(argv[3]);
	char buffer[blocksize];   //拷贝任务量
	bzero(buffer,sizeof(buffer));      //置字节字符串前n个字节为零且包括‘\0’
	//argv[1] = SFile argv[2] = DesFile arg[3] = blocksize argv[4] = pos
	int sfd = open(argv[1],O_RDONLY);
	int dfd = open(argv[2],O_WRONLY|O_CREAT,0664);

	lseek(sfd,pos,SEEK_SET);
	lseek(dfd,pos,SEEK_SET);
	int rsize;
	rsize = read(sfd,buffer,sizeof(buffer));
	write(dfd,buffer,rsize);

	return 0;
	
}
