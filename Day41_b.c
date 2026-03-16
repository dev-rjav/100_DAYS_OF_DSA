
#include<stdio.h>

int main()
{
  int task[10];
  int schedule[10];
  int n;
  int i;
  int j;
  int k;
  int max;
  int temp;
  int count;
  int sum;
  int max_slot;

  printf("Enter the number of tasks: ");
  scanf("%d", &n);

  printf("Enter the tasks: ");
  for(i=0; i<n; i++)
  {
    scanf("%d", &task[i]);
  }

  printf("Enter the schedule: ");
  for(i=0; i<n; i++)
  {
    scanf("%d", &schedule[i]);
  }

  for(i=0; i<n; i++)
  {
    sum = 0;
    for(j=i; j<n; j++)
    {
      if(task[j] >= task[i])
      {
        sum += task[j];
      }
    }
    if(sum > max)
    {
      max = sum;
    }
  }

  printf("The maximum sum is: %d", max);

  return 0;
}
