#include "kernel/types.h"
#include "user/user.h"

static void
burn(char tag)
{
  volatile unsigned long x = 0;
  int last = uptime();
  int slices = 0;
  while (slices < 6) {
    x++;
    int now = uptime();
    if (now != last) {
      printf("%c(pid %d) corre en tick %d\n", tag, getpid(), now);
      last = now;
      slices++;
    }
  }
  exit(0);
}

int
main(void)
{
  if (fork() == 0) burn('A');
  if (fork() == 0) burn('B');
  wait(0);
  wait(0);
  printf("rrdemo: fin\n");
  exit(0);
}
