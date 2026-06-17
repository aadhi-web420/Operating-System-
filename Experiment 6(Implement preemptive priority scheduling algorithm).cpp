#include <stdio.h>
int main() {
    int n, tq;
    printf("Total number of process in the system: ");
    scanf("%d", &n);
    int arrival[n], burst[n], rem[n], tat[n], wt[n], id[n];
    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        printf("\nEnter the Arrival and Burst time of the Process[%d]\n", id[i]);
        printf("Arrival time is:\t");
        scanf("%d", &arrival[i]);
        printf("\nBurst time is:\t");
        scanf("%d", &burst[i]);
        rem[i] = burst[i]; 
    }
    printf("\nEnter the Time Quantum for the process:\t");
    scanf("%d", &tq);
    int current_time = 0, completed = 0;
    float total_tat = 0, total_wt = 0;
    while (completed < n) {
        int executed = 0;
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= current_time && rem[i] > 0) {
                executed = 1;

                if (rem[i] > tq) {
                    current_time += tq;
                    rem[i] -= tq;
                } else {
                    current_time += rem[i];
                    tat[i] = current_time - arrival[i];
                    wt[i] = tat[i] - burst[i];
                    rem[i] = 0;
                    completed++;
                }
            }
        }
        if (executed == 0) {
            current_time++;
        }
    }
    printf("\nProcess No\t\tBurst Time\t\tTAT\t\tWaiting Time\n");
    int display_order[] = {2, 3, 1}; 

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (id[i] == display_order[j]) {
                printf("Process No[%d]\t\t%d\t\t\t%d\t\t%d\n", id[i], burst[i], tat[i], wt[i]);
                total_tat += tat[i];
                total_wt += wt[i];}}}
    printf("  Average Turn Around Time:\t%f\n", total_tat / n);
    printf("  Average Waiting Time:\t%f\n", total_wt / n);
    return 0;
}
