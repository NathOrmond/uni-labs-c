#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define EXIT_CODE 0
#define true 1
#define false 0

typedef int bool;

typedef struct { 
    char _name[2];
    int arrival_time, burst_time, remaining_time, completion_time, turn_around_time, wait_time;
}Process;



/*****************************************************
 * PROCESS SCHEDULING LAB AS C CODE:
 * Nathan Ormond
 */

/**
 * Function Definitions
 **/
int run_prg();
int prg_menu();
void first_come_first_served();
void shortest_job_first();
void round_robin();
int round_robin_menu();


/**
 * Global Vars
 **/
// NONE YET DEFINED

/**
 * Main Class
 **/
int main(){ 
    while(run_prg()){ 
        switch(prg_menu()){ 
            case 1:
                first_come_first_served();
                break;

            case 2:
                shortest_job_first();
                break; 


            case 3:
                round_robin();
                break;

            default: 
                printf("\nERROR : invalid menu input!\n");            
        }
    }
    printf("\n\n### Terminating with exit code: %d\n\n", EXIT_CODE);
    return EXIT_CODE;
}

/**
 * Continue to run programme
 **/
int run_prg(){
    char input_char; 
    printf("\n\nContunue to run programme? [y/n] : \n");
    scanf("%s", &input_char);
    return (input_char == 'y') ? 1 : 0;
}

/**
 * Choose Menu Option
 **/
int prg_menu(){ 
    char input_char; 
    printf("\nSELECT RUN MODE\n");
    printf("\n1 | First Come First Served\n");
    printf("\n2 | Shortest Job First\n");
    printf("\n3 | Round Robin\n");
    scanf("%s", &input_char);

    if(input_char == '1'){ 
        return 1;
    }

    if(input_char == '2'){ 
        return 2;
    }


    if(input_char == '3'){ 
        return 3;
    }

    return 0;
}

/**
 * First Come First Served
 **/
void first_come_first_served(){ 
    int process_num = 5;

    printf("\n=============================================\n");
    Process processes[process_num];

    processes[0]._name[0] = 'P';
    processes[0]._name[1] = '1';
    processes[0].arrival_time = 0;
    processes[0].burst_time = 4;
    processes[0].remaining_time = processes[0].burst_time;

    processes[1]._name[0] = 'P';
    processes[1]._name[1] = '2';
    processes[1].arrival_time = 1;
    processes[1].burst_time = 3;
    processes[1].remaining_time = processes[1].burst_time;

    processes[2]._name[0] = 'P';
    processes[2]._name[1] = '3';
    processes[2].arrival_time = 2;
    processes[2].burst_time = 1;
    processes[2].remaining_time = processes[2].burst_time;

    processes[3]._name[0] = 'P';
    processes[3]._name[1] = '4';
    processes[3].arrival_time = 3;
    processes[3].burst_time = 2;
    processes[3].remaining_time = processes[3].burst_time;

    processes[4]._name[0] = 'P';
    processes[4]._name[1] = '5';
    processes[4].arrival_time = 5;
    processes[4].burst_time = 5;
    processes[4].remaining_time = processes[4].burst_time;
   
    printf("INPUT DATA: \n\n");

    int i;
    for(i = 0; i <= 4; i++){
         printf("%d | Process Name: %c%c  Arrival Time: %d  Burst Time: %d \n", i, processes[i]._name[0],processes[i]._name[1] , processes[i].arrival_time, processes[i].burst_time);
    }

    printf("\n=============================================\n");
    int sumOfBurstTimes = 0;
    i = 0; 
    while(i < sizeof(processes)/(sizeof(Process))){ 
        sumOfBurstTimes += processes[i].burst_time;
        i++;
    }
    printf("\nSum of Burst Times: %d \n", sumOfBurstTimes);
    printf("\n=============================================\n");

    int time_slice;
    int working_process_index;
    int index;

    for(time_slice = 1; time_slice <= sumOfBurstTimes; time_slice++){ 
        for(index = 0; index < process_num; index++){ 
            if((processes[index].remaining_time > 0) && (processes[index].arrival_time <= time_slice)){ 
                working_process_index = index;
                break;
            }else{ 
                working_process_index = 0;
            }
        }

        processes[working_process_index].remaining_time--; 

        if(processes[working_process_index].remaining_time == 0){ 
            processes[working_process_index].completion_time = time_slice;
        }
    }

    int sumTAT = 0;
    int sumWT = 0;

    printf("\nProcess | Arrival Time | Burst Time | Completion Time | Turn Around Time | Wait Time\n");


    for(index = 0; index < process_num; index++){ 
        processes[index].turn_around_time = processes[index].completion_time - processes[index].arrival_time;
        processes[index].wait_time = processes[index].turn_around_time - processes[index].burst_time;
    
        sumTAT += processes[index].turn_around_time;
        sumWT += processes[index].wait_time;

        printf("\n%c%c\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\n", processes[index]._name[0], processes[index]._name[1],processes[index].arrival_time,processes[index].burst_time,processes[index].completion_time,processes[index].turn_around_time,processes[index].wait_time);
        
    }

    printf("\nAverage Turn Around Time: %.2d \n", (sumTAT/index));
    printf("\nAverage Wait Time: %.2d \n", (sumWT/index));

    printf("\n=============================================\n");

}


/**
 * Shortest Job First
 **/
void shortest_job_first(){ 
    int process_num = 5;

    printf("\n=============================================\n");
    Process processes[process_num];

    processes[0]._name[0] = 'P';
    processes[0]._name[1] = '1';
    processes[0].arrival_time = 1;
    processes[0].burst_time = 7;
    processes[0].remaining_time = processes[0].burst_time;

    processes[1]._name[0] = 'P';
    processes[1]._name[1] = '2';
    processes[1].arrival_time = 2;
    processes[1].burst_time = 5;
    processes[1].remaining_time = processes[1].burst_time;

    processes[2]._name[0] = 'P';
    processes[2]._name[1] = '3';
    processes[2].arrival_time = 3;
    processes[2].burst_time = 1;
    processes[2].remaining_time = processes[2].burst_time;

    processes[3]._name[0] = 'P';
    processes[3]._name[1] = '4';
    processes[3].arrival_time = 4;
    processes[3].burst_time = 2;
    processes[3].remaining_time = processes[3].burst_time;

    processes[4]._name[0] = 'P';
    processes[4]._name[1] = '5';
    processes[4].arrival_time = 5;
    processes[4].burst_time = 10;
    processes[4].remaining_time = processes[4].burst_time;

    printf("\n=============================================\n");
    printf("INPUT DATA: \n\n");
    int i;
    for(i = 0; i <= 4; i++){
         printf("%d | Process Name: %c%c  Arrival Time: %d  Burst Time: %d \n", i, processes[i]._name[0],processes[i]._name[1] , processes[i].arrival_time, processes[i].burst_time);
    }
    printf("\n=============================================\n");
    int sumOfBurstTimes = 0;

    i = 0; 
    while(i < process_num){ 
        sumOfBurstTimes += processes[i].burst_time;
        i++;
    }
    printf("\nSum of Burst Times: %d \n", sumOfBurstTimes);
    printf("\n=============================================\n");





    int time_slice;
    int working_process_index = 0, this_qualifying_index = 0, last_qualifying_index = 0;
    bool isWorkingProcessIndexSet = false;

    for(time_slice = 1; time_slice < sumOfBurstTimes; time_slice++){ 
        printf("not yet implemented");
    }

   



    int sumTAT = 0;
    int sumWT = 0;

    printf("\nProcess | Arrival Time | Burst Time | Completion Time | Turn Around Time | Wait Time\n");


    int index;
    for(index = 0; index < process_num; index++){ 
        processes[index].turn_around_time = processes[index].completion_time - processes[index].arrival_time;
        processes[index].wait_time = processes[index].turn_around_time - processes[index].burst_time;
    
        sumTAT += processes[index].turn_around_time;
        sumWT += processes[index].wait_time;

        printf("\n%c%c\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\n", processes[index]._name[0], processes[index]._name[1],processes[index].arrival_time,processes[index].burst_time,processes[index].completion_time,processes[index].turn_around_time,processes[index].wait_time);
        
    }

    printf("\nAverage Turn Around Time: %.2d \n", (sumTAT/index));
    printf("\nAverage Wait Time: %.2d \n", (sumWT/index));

    printf("\n=============================================\n");
}


 /**
 * Round Robin
 **/

int round_robin_menu(){ 
    char input_char; 
    printf("\nSELECT ROUND ROBIN DATASET\n");
    printf("\n1 | Q1\n");
    printf("\n2 | Q2\n");
    scanf("%s", &input_char);

    if(input_char == '1'){ 
        return 1;
    }

    if(input_char == '2'){ 
        return 2;
    }

    return 0;
}

void round_robin(){ 

    int process_num = 6;
    Process processes[process_num];
    
    processes[0]._name[0] = 'P';
    processes[0]._name[1] = '0';
    processes[0].arrival_time = 0;
    processes[0].burst_time = 4;
    processes[0].remaining_time = processes[0].burst_time;

    processes[1]._name[0] = 'P';
    processes[1]._name[1] = '1';
    processes[1].arrival_time = 1;
    processes[1].burst_time = 5;
    processes[1].remaining_time = processes[1].burst_time;

    processes[2]._name[0] = 'P';
    processes[2]._name[1] = '2';
    processes[2].arrival_time = 2;
    processes[2].burst_time = 2;
    processes[2].remaining_time = processes[2].burst_time;

    processes[3]._name[0] = 'P';
    processes[3]._name[1] = '3';
    processes[3].arrival_time = 3;
    processes[3].burst_time = 1;
    processes[3].remaining_time = processes[3].burst_time;

    processes[4]._name[0] = 'P';
    processes[4]._name[1] = '4';
    processes[4].arrival_time = 4;
    processes[4].burst_time = 6;
    processes[4].remaining_time = processes[4].burst_time;

    processes[5]._name[0] = 'P';
    processes[5]._name[1] = '5';
    processes[5].arrival_time = 6;
    processes[5].burst_time = 3;
    processes[5].remaining_time = processes[4].burst_time;

    int tq;

    printf("\n=============================================\n");
    

    switch(round_robin_menu()){ 
        case 1:
            tq = 2;
            break;

        case 2:
            tq = 4;
            break;

        default: 
            printf("\nERROR : invalid menu input!\n");  
            return;          
    }


    printf("\n=============================================\n");
    printf("INPUT DATA: \n\n");
    int i;
    for(i = 0; i <= 4; i++){
         printf("%d | Process Name: %c%c  Arrival Time: %d  Burst Time: %d \n", i, processes[i]._name[0],processes[i]._name[1] , processes[i].arrival_time, processes[i].burst_time);
    }
    printf("\n=============================================\n");
    int sumOfBurstTimes = 0;

    i = 0; 
    while(i < process_num){ 
        sumOfBurstTimes += processes[i].burst_time;
        i++;
    }
    printf("\nSum of Burst Times: %d \n", sumOfBurstTimes);
    printf("\n=============================================\n");





    int time_slice;
    int working_process_index = 0, this_qualifying_index = 0, last_qualifying_index = 0;
    bool isWorkingProcessIndexSet = false;

    for(time_slice = 1; time_slice < sumOfBurstTimes; time_slice++){ 
        printf("not yet implemented");
    }

   



    int sumTAT = 0;
    int sumWT = 0;

    printf("\nProcess | Arrival Time | Burst Time | Completion Time | Turn Around Time | Wait Time\n");


    int index;
    for(index = 0; index < process_num; index++){ 
        processes[index].turn_around_time = processes[index].completion_time - processes[index].arrival_time;
        processes[index].wait_time = processes[index].turn_around_time - processes[index].burst_time;
    
        sumTAT += processes[index].turn_around_time;
        sumWT += processes[index].wait_time;

        printf("\n%c%c\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\n", processes[index]._name[0], processes[index]._name[1],processes[index].arrival_time,processes[index].burst_time,processes[index].completion_time,processes[index].turn_around_time,processes[index].wait_time);
        
    }

    printf("\nAverage Turn Around Time: %.2d \n", (sumTAT/index));
    printf("\nAverage Wait Time: %.2d \n", (sumWT/index));

    printf("\n=============================================\n");

}



