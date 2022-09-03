#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MY_PRINTF(...) printf("[%d] ", getpid());\
(printf(__VA_ARGS__))


int main()
{
	int stat = 0;
	pid_t par, ch;
	par = getpid();
	ch = fork();
	if (ch == -1)
	{
		perror("error with ch");
   		exit(1);
	}
	if (ch == 0)
	{
		MY_PRINTF("Я ребенок, мой PID: \n");
		execl("exec", "hello", "15", "15", NULL);
		exit(stat);
	}
	else
	{
		wait(NULL);
		MY_PRINTF("Я родитель, мой PID: \n");
		if (WIFEXITED(stat) != 0)
		{
			MY_PRINTF("exit status: %d\n", WEXITSTATUS(stat));
		}
		else
		{
			printf("something went wrong\n");
		}
	}
	return 0;
}