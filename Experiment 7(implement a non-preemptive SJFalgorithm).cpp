#include <stdio.h>
int main() {
    int at[10], bt[10], pr[10], rt[10]; 
    int n, i, j, temp, current_time = 0, completed = 0;
    int sum_wait = 0, sum_turnaround = 0;
    int wt[10], tat[10], end_time[10], start_time[10];
    float avgwait, avgturn;
    printf("Enter the number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 10) return 1;
    for (i = 0; i < n; i++) {
        pr[i] = i + 1; 
        printf("Enter Arrival Time and Burst Time for Process P[%d]: ", pr[i]);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; 
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
            }
        }
    }
    int is_completed[10] = {0};
    printf("\nProcess\t| Arrival\t| Start\t\t| End\t\t| Waiting\t| Turnaround\n");
    printf("-----------------------------------------------------------------------------------\n");
    while (completed < n) {
        int idx = -1;
        int min_burst = 1e9; 
        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && is_completed[i] == 0) {
                if (bt[i] < min_burst) {
                    min_burst = bt[i];
                    idx = i;
                }
                else if (bt[i] == min_burst) {
                    if (at[i] < at[idx]) {
                        idx = i;}   }} }
        if (idx != -1) {
            start_time[idx] = current_time;
            end_time[idx] = start_time[idx] + bt[idx];
            tat[idx] = end_time[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            sum_wait += wt[idx];
            sum_turnaround += tat[idx];
            current_time = end_time[idx];
            is_completed[idx] = 1;
            completed++;
            printf("p[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", 
                   pr[idx], at[idx], start_time[idx], end_time[idx], wt[idx], tat[idx]);
        } else {
            current_time++;
        }
    }
    avgwait = (float)sum_wait / n;
    avgturn = (float)sum_turnaround / n;
    printf("-----------------------------------------------------------------------------------\n");
    printf("Average waiting time is: %.6f\n", avgwait);
    printf("Average turnaround time is: %.6f\n", avgturn);
    return 0;
}
