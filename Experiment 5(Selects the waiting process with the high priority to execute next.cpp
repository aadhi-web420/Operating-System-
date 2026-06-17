#include <stdio.h>
struct priority_scheduling
{
char process_name;
int burst_time;
int waiting_time;
int turn_around_time;
int priority;
};
int main()
{ int number_of_process;
 int total_waiting = 0, total_turnaround = 0;int ASCII_number = 65; int position;
    float average_waiting_time;
    float average_turnaround_time;
    printf("Enter the total number of Processes: ");
    scanf("%d", &number_of_process);
    struct priority_scheduling process[number_of_process], temp_process;
    printf("\nPlease Enter the Burst Time and Priority of each process:\n");
    for (int i = 0; i < number_of_process; i++)
    { process[i].process_name = (char)ASCII_number++;
  printf("\nEnter the details of the process %c\n",  process[i].process_name);
     printf("Enter the burst time: ");
	  scanf("%d", &process[i].burst_time);
  printf("Enter the priority: ");
        scanf("%d", &process[i].priority);
    } 
	  for (int i = 0; i < number_of_process - 1; i++)
    { position = i;
        for (int j = i + 1; j < number_of_process; j++)
        { if (process[j].priority > process[position].priority)
   position = j;
        }
        temp_process = process[i];
        process[i] = process[position];
        process[position] = temp_process;
    }
    process[0].waiting_time = 0;
    for (int i = 1; i < number_of_process; i++)
    { process[i].waiting_time =
            process[i - 1].waiting_time + process[i - 1].burst_time;
    }
    for (int i = 0; i < number_of_process; i++)
    {
        process[i].turn_around_time =
            process[i].burst_time +
            process[i].waiting_time;

        total_waiting += process[i].waiting_time;
        total_turnaround += process[i].turn_around_time;
    }
    average_waiting_time =
        (float)total_waiting / number_of_process;
    average_turnaround_time =
        (float)total_turnaround / number_of_process;
 printf("\n\nProcess_name\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < number_of_process; i++)
    { printf("%c\t\t%d\t\t%d\t\t%d\n",  process[i].process_name, process[i].burst_time, process[i].waiting_time, process[i].turn_around_time);
    }
    printf("-------------------------------------------------------------\n");
    printf("\nAverage Waiting Time : %.6f",
           average_waiting_time);
    printf("\nAverage Turnaround Time : %.6f\n",
           average_turnaround_time);
    return 0;
}
