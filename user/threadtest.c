#include "kernel/types.h"
#include "user/user.h"

volatile int a = 0, b = 0, c = 0;

void *
my_thread(void *arg)
{
  int *num = (int *) arg;
  for(int i = 0; i < 100; i++){
    (*num)++;
  }
  uint64 result = *num * 10;
  return (void *)result;
}

int
main(int argc, char *argv[])
{
  int ta = create_thread(my_thread, (void *)&a);
  int tb = create_thread(my_thread, (void *)&b);
  int tc = create_thread(my_thread, (void *)&c);

  join_thread(ta);
  join_thread(tb);
  join_thread(tc);

  printf("a = %d, b = %d, c = %d\n", a, b, c);

  exit(0);
}
