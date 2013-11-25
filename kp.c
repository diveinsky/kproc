/******
 * Author: shiva shankar aradi
 * Code is available for use and modification
 * it's a c programme with shell commands
 * 
 ********/


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<getopt.h>

void callkproc();
char* argument[1];
int argc=0,i=0;
int main( int argc,char* argv[] )
{

	int next_option;
	//char* argument=argv[1];
	const char* program_name;
	const char* short_option="hv";
	const struct option long_option[]={
		{"help",0,NULL,'h'},
		{"version",0,NULL,'v'},
		{NULL,0,NULL,0}};
	program_name=argv[0];
do {
	next_option=getopt_long(argc,argv,short_option,long_option,NULL);
	switch(next_option)
	    {
		case 'h': printf("\n -h   --help  Display Options\n -v  --version  Display version \nSyntax --->  kproc <processName>");break;
		case 'v': printf("kproc v.0\n");break;
		case '?':
			 fprintf(stderr,"Wrong Option");
//			 fprintf(stderr,"Wrongaaaaaaa");
				//exit(1);	
		printf("\nTry option -h or --help \n");
		exit(1);break;
		case -1: break;//option completed
		default :abort();
	   }
    }while(next_option != -1);
i=optind;
printf("optind val: %d\n",optind);
printf("argc  :%d\n",argc);
//argument[1]=argv[1];
for(i=optind;i<argc;++i)
{
printf("Argumenttssss %s\n",argv[i]);
}
//argument=argv;
//printf("wwwwwfwfw:%s"argument[1]);
if( 1 == optind )
{
	printf("Process Name : %s\n",argv[1]);
	if (argc > 1){  
	char buf[200]="O";
sprintf(buf,"if [ \" $(ps -e | grep %s | grep -v grep)\" != \" \" ]; then echo \"Killing Process\" ;kill -9 `ps -e | grep %s | grep -v grep | awk '{ print $1 }'` ;fi",argv[1],argv[1]);

	  system(buf);
	}

if(argc=1)
{printf("Syntax --->  kproc <processName>\n");}
}
return (0);
}
