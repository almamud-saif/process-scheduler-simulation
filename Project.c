#include<stdio.h>
#include<conio.h>
#include <stdbool.h>

void option();
int input();
int FCFS();
int SJF();
int Priority();
int Round_Robin();
int Compare();
void multilvel();

int choice;
int p[20], bt[20], wt[20],tat[20],rem_bt[20], i=0,j=0, k=0, n, temp;
float wtavgF = 9990.00, wtavgP = 9991.00,wtavgS = 9992.00,wtavgR = 9993.00;
float tatavgF=9994.00,tatavgP=9995.00,tatavgS=9996.00,tatavgR=9997.00;

int main()
{
    printf("\t#Welcome to the Process Scheduler Simulation!!#\n");
    printf("--------------------------------------------------------------\n");
    printf("--------------------------------------------------------------\n\n");

    input();
    return 0;
}



int input()
{
    printf("\n Enter the number of processes: ");
    scanf("%d", &n);

    // Taking input for each process
    for (i = 0; i < n; i++)
    {
        p[i] = i;
        printf(" Enter Burst Time Process P%d: ", i+1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    option();

}



void option()
{
    do
    {
        printf("\n\n");
        printf("\n Press 1 for FCFS\n");
        printf(" Press 2 for SJF\n");
        printf(" Press 3 for Priority\n");
        printf(" Press 4 for Round Robin\n");
        printf(" Press 5 for Comparing\n");
        printf(" Press 6 for new Input\n");
        printf(" Press 7 for Multilevel queue\n");
        printf(" Press 8 for Exit\n");
        printf(" Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            FCFS();
            break;
        case 2:
            SJF();
            break;
        case 3:
            Priority();
            break;
        case 4:
            Round_Robin();
            break;
        case 5:
            Compare();
            break;
        case 6:
            input();
            break;
        case 7:
            multilvel();
            break;
        case 8:
            printf("\n Exiting... Goodbye!\n");
            break;
        default:
            printf("\n You entered an invalid option. Please try again.\n\n");
            option();
        }
    }
    while (choice != 8);
}




// FCFS scheduling function
int FCFS()
{

    printf("\n FCFS Algorithm");
    // Calculate waiting time and turnaround time
    wt[0] = wtavgF = 0;
    tat[0] = tatavgF = bt[0];

    for (i=1; i<n; i++)
    {
        wt[i] = tat[i-1];
        tat[i] = wt[i] + bt[i];
        wtavgF += wt[i];
        tatavgF += tat[i];
    }

    // Display process details
    printf("\n PROCESS \tBURST TIME \tWAITING TIME\tTURNAROUND TIME\n");
    for (i=0; i<n; i++)
    {
        printf("\n P%d \t\t %d \t\t %d \t\t %d", p[i]+1, bt[i], wt[i], tat[i]);
    }

    // Display average waiting time and turnaround time
    printf("\n\n Average Waiting Time = %.2f\n", wtavgF / n);
    printf(" Average Turnaround Time = %.2f\n\n\n", tatavgF / n);


    printf("\n\n Are you want to repeat"
           "\n 1 for again show this FCFS"
           "\n 2 for again New input"
           "\n Any number for main menu.\n");
    scanf("%d",&choice);

    if(choice==1)
        FCFS();
    else if(choice==2)
        input();
    else
        option();


    return 0;
}

// SJF scheduling function
int SJF()
{
    printf("\n SJF Algorithm");
    // Sorting based on Burst Time
    for (i=0; i<n; i++)
    {
        for (k=i+1; k<n; k++)
        {
            if (bt[i] > bt[k])
            {
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    wt[0] = wtavgS = 0;
    tat[0] = tatavgS = bt[0];

    for (i=1; i<n; i++)
    {
        wt[i] = tat[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavgS += wt[i];
        tatavgS += tat[i];
    }

    printf("\n PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for (i=0; i<n; i++)
    {
        printf("\n P%d \t\t %d \t\t %d \t\t %d", p[i]+1, bt[i], wt[i], tat[i]);
    }


    printf("\n\n Average Waiting Time = %.2f\n", wtavgS / n);
    printf(" Average Turnaround Time = %.2f\n\n\n", tatavgS / n);

    printf("\n\n Are you want to repeat"
           "\n 1 for again show this SJF"
           "\n 2 for again New input"
           "\n Any number for main menu.\n");
    scanf("%d",&choice);

    if(choice==1)
        SJF();
    else if(choice==2)
        input();
    else
        option();

    return 0;
}

// Priority scheduling function
int Priority()
{
    printf("\n Priority Algorithm");
    int  prio[20];
    for (i = 0; i < n; i++)
    {
        printf(" Enter Priority for Process P%d: ", i+1);
        scanf("%d", &prio[i]);
    }
    // Sorting based on priority
    for (i=0; i<n; i++)
    {
        for (k=i+1; k<n; k++)
        {
            if (prio[i] > prio[k])
            {
                temp = prio[i];
                prio[i] = prio[k];
                prio[k] = temp;

                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    wt[0] = wtavgP = 0;
    tat[0] = tatavgP = bt[0];

    for (i=1; i<n; i++)
    {
        wt[i] = tat[i-1];
        tat[i] = wt[i] + bt[i];
        wtavgP += wt[i];
        tatavgP += tat[i];
    }

    // Display process details
    printf("\n PROCESS \tBURST TIME \tPriority \t WAITING TIME\t TURNAROUND TIME\n");
    for (i=0; i<n; i++)
    {
        printf("\n P%d \t\t %d \t\t %d \t\t %d \t\t %d", p[i]+1, bt[i],prio[i], wt[i], tat[i]);
    }

    //Average waiting time and turnaround time
    printf("\n\n Average Waiting Time = %.2f\n", wtavgP / n);
    printf(" Average Turnaround Time = %.2f\n", tatavgP / n);

    printf("\n\n Are you want to repeat"
           "\n 1 for again show this Priority"
           "\n 2 for again New input"
           "\n Any number for main menu.\n");
    scanf("%d",&choice);

    if(choice==1)
        Priority();
    else if(choice==2)
        input();
    else
        option();

    return 0;
}

// Round Robin scheduling function
int Round_Robin()
{

    int quantum, time = 0;
    printf(" Enter the quantum time: ");
    scanf("%d", &quantum);
    wtavgR=0;
    tatavgR=0;
    printf("\n Round Robin Algorithm");
    bool done;
    do
    {
        done = true;
        for (i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false;
                if (rem_bt[i] > quantum)
                {
                    time += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    tat[i] = wt[i] + bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
    }
    while (!done);


    printf("\n PROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf(" P%d\t   \t%d\t\t   %d\t\t   %d\n", p[i] + 1, bt[i], wt[i], tat[i]);
        wtavgR += wt[i];
        tatavgR += tat[i];
    }


    printf("\n Average Waiting Time =%.2f\n", wtavgR / n);
    printf(" Average Turnaround Time = %.2f\n", tatavgR / n);

    printf("\n\n Are you want to repeat"
           "\n 1 for again show this FCFS"
           "\n 2 for again New input"
           "\n Any number for main menu.\n");
    scanf("%d",&choice);

    if(choice==1)
        Round_Robin();
    else if(choice==2)
        input();
    else
        option();

    return 0;
}
int Compare()
{
    float avgW[4],indexW[4];
    indexW[0]=avgW[0]=wtavgF/n;
    indexW[1]=avgW[1]=wtavgS/n;
    indexW[2]=avgW[2]=wtavgP/n;
    indexW[3]=avgW[3]=wtavgR/n;
    float tmp;

    printf(" Comparing.....");
    for (i = 0; i < 4; i++)
    {
        for (j = i + 1; j < 4; j++)
        {
            if (avgW[i] > avgW[j])
            {
                tmp = avgW[i];
                avgW[i] = avgW[j];
                avgW[j] = tmp;
            }
        }
    }

    printf("\n\n");
    printf("\n For this scenario best Algorithm based on Waiting:\n");
    for (i = 0; i < 4; ++i)
    {
        if(avgW[i]==indexW[0])
            printf(" FCFS avg time= %.2f\n",avgW[i]);
        else if(avgW[i]==indexW[1])
            printf(" SJF avg time= %.2f\n",avgW[i]);
        else if(avgW[i]==indexW[2])
            printf(" Priority avg time= %.2f\n",avgW[i]);
        else if(avgW[i]==indexW[3])
            printf(" Round Robin avg time= %.2f",avgW[i]);
    }


    float avgT[4],indexT[4];
    indexT[0]=avgT[0]=tatavgF/n;
    indexT[1]=avgT[1]=tatavgS/n;
    indexT[2]=avgT[2]=tatavgP/n;
    indexT[3]=avgT[3]=tatavgR/n;


    for (i = 0; i < 4; i++)
    {
        for (j = i + 1; j < 4; j++)
        {
            if (avgT[i] > avgT[j])
            {
                tmp = avgT[i];
                avgT[i] = avgT[j];
                avgT[j] = tmp;
            }
        }
    }

    printf("\n\n\n For this scenario best Algorithm based on Turnaround Time:\n");
    for (i = 0; i < 4; ++i)
    {
        if(avgT[i]==indexT[0])
            printf(" FCFS avg time= %.2f\n",avgT[i]);
        else if(avgT[i]==indexT[1])
            printf(" SJF avg time= %.2f\n",avgT[i]);
        else if(avgT[i]==indexT[2])
            printf(" Priority avg time= %.2f\n",avgT[i]);
        else if(avgT[i]==indexT[3])
            printf(" Round Robin avg time= %.2f",avgT[i]);
    }



}

void multilvel()
{
    printf("No code implement here");
}
