#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
#include<sys/utsname.h>
#include<libgen.h>
#include<sys/sysinfo.h>

int main(void) {
  // Getting information abt sys
  char *shell = getenv("SHELL");
  char *username = getenv("USER");
	if(username == NULL) return EXIT_FAILURE;
  char hostname[1024];
  char *wm = getenv("DESKTOP_SESSION");
	if(wm == NULL) return EXIT_FAILURE;
  gethostname(hostname, 1024);
	if(hostname == NULL) return EXIT_FAILURE;
  FILE *p;
	char ch;
	p = popen("lsb_release -sd", "r");
	if(p == NULL) return EXIT_FAILURE;
  FILE* model;
	char modelname[70];
	model = fopen("/sys/devices/virtual/dmi/id/product_name", "r");
  const long minute = 60;
 	const long hour = minute * 60;
 	const long day = hour * 24;
	struct sysinfo si;
	sysinfo(&si);
  struct utsname uName;
	uname(&uName);
  FILE* pak;
  char pk[7];
  pak = popen("pacman -Q | wc -l", "r");
  printf("%s@%s \n", username, hostname);
  int fw = 0;
	printf("os: ");
	while( (ch=fgetc(p)) != EOF)
	{
		if(isalpha(ch))
		{
			fw = 1;
			putchar(ch);
		}
		else
		{
			if(fw)
			{
				putchar(' ');
				fw = 0;
			}
		}
	}
	pclose(p);
	printf("\n");
  printf("host: ");
	while(fgets(modelname, sizeof(modelname), model))
	{
		printf("%s", modelname);
	}
	printf("kernel: %s %s\n", uName.sysname, uName.release);
  printf("uptime: %ld hours, %02ld minutes\n", (si.uptime % day) / 3600, (si.uptime % hour) / minute);
  printf("pkgs: ");
	while(fgets(pk, sizeof(pk), pak))
	{
		printf("%s", pk);
	}
	pclose(pak);
  printf("wm: %s\n", wm);
  printf("shell: %s\n", shell);
}
