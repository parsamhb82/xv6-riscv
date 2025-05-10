#include "user/user.h"
#include "kernel/types.h"

void thread_func(void *arg) {
  int id = *(int *)arg;
  printf("Thread %d is running\n", id);
  thread_exit();
}

int main() {
  int arg1 = 1, arg2 = 2;
  int tid1 = thread_create(thread_func, &arg1);
  int tid2 = thread_create(thread_func, &arg2);

  thread_join(tid1);
  thread_join(tid2);

  printf("All threads joined\n");
  exit(0);
}
