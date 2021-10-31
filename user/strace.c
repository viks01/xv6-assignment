#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int 
main(int argc, char *argv[]) 
{
  if (argc <= 2){
    fprintf(2, "usage: strace mask command\n");
    exit(1);
  }

  int mask = atoi(argv[1]);

  if (trace(mask) < 0) {
    fprintf(2, "trace: error\n");
    exit(1);
  }

  exec(argv[2], &argv[2]);

  exit(0);
}