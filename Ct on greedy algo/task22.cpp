/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   04-Apr-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: task22.cpp
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 04-Apr-2021
 */



#include <stdio.h>
#include <stdlib.h>


typedef struct Task {
        int task;
        int deadline;
        int profit;
} Task;

int cmpfunc(const void * a, const void * b) {
        return ( ((Task*)b)->profit -
                 ((Task*)a)->profit );
}

int main()
{
        int n=10;

        Task tasks[10] =
        {
                { 1, 9, 15 }, { 2, 2, 2 }, { 3, 5, 18 }, { 4, 7, 1 }, { 5, 4, 25 },
                { 6, 2, 20 }, { 7, 5, 8 }, { 8, 7, 10 }, { 9, 4, 12 }, { 10, 3, 5 }
        };

        qsort(tasks, 10, sizeof(Task), cmpfunc);



        Task slot[10];

        for (int i = 0; i < 10; i++)
                slot[i].task = -1;

        int total = 0;

        for(int i = 0; i < 10; i++)
        {
                for(int j = tasks[i].deadline-1; j >=0; j--)
                {
                        if (slot[j].task == -1 && j < 10)
                        {
                                slot[j].task = tasks[i].task;
                                slot[j].deadline = j;
                                slot[j].profit = tasks[i].profit;
                                total += tasks[i].profit;
                                break;
                        }
                }
        }

        for(int i=0; i<10; i++) {
                if (slot[i].task != -1)
                        printf("%d %d %d\n", slot[i].task, slot[i].deadline+1, slot[i].profit);
        }

        printf("Total profit %d\n", total);

}
