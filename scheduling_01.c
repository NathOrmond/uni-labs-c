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

/*Common Functions*/
void printLineBreak();
void createData(int menuOption);
void clearData();
void printOutcomeSummary();
int round_robin_menu();
int get_shortest_remaining_time_index();
int * get_arrived_processes(int current_time_slice);

/*Scheduling*/
void first_come_first_served();
void shortest_job_first();
void round_robin();
void shortest_remaining_time_first();



/**
 * Global Vars
 **/
Process processes[6];
int processes_num;
int sumOfBurstTimes;

/**
 * Main Class
 **/
int main(){ 
    int menuOption;
    while(run_prg()){ 
        menuOption = prg_menu();
        createData(menuOption);
        switch(menuOption){ 
            case 1:
                first_come_first_served();
                break;

            case 2:
                shortest_job_first();
                break; 


            case 3:
                round_robin();
                break;

            case 4:
                shortest_remaining_time_first();
                break;    

            default: 
                printf("\nERROR : invalid menu input!\n");            
        }

        printOutcomeSummary();
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
    printf("\n\tSELECT RUN MODE:\n");
    printf("\n\t1 | First Come First Served\n");
    printf("\n\t2 | Shortest Job First\n");
    printf("\n\t3 | Round Robin\n");
    printf("\n\t4 | Shortest Remaining Time First\n");
    

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


    if(input_char == '4'){ 
        return 4;
    }

    return 0;
}


/************************************************
 * Generic functions
 ************************************************/

void printLineBreak(){ 
    printf("\n=============================================\n");
}

/**
 * TODO
 * Change class in order to read/parse data from file (cmd line arg? see requirements)
 **/
void createData(int menuOption){ 
    int array_size;

    if((menuOption == 1) || (menuOption == 2)){ 
        array_size = 5;
    }else if ((menuOption == 3) ){ 
        array_size = 6;
    }

    Process local_processes[array_size];

      switch(menuOption){ 
        case 1: //FCFS
            local_processes[0]._name[0] = 'P';
            local_processes[0]._name[1] = '1';
            local_processes[0].arrival_time = 0;
            local_processes[0].burst_time = 4;
            local_processes[0].remaining_time = local_processes[0].burst_time;

            local_processes[1]._name[0] = 'P';
            local_processes[1]._name[1] = '2';
            local_processes[1].arrival_time = 1;
            local_processes[1].burst_time = 3;
            local_processes[1].remaining_time = local_processes[1].burst_time;

            local_processes[2]._name[0] = 'P';
            local_processes[2]._name[1] = '3';
            local_processes[2].arrival_time = 2;
            local_processes[2].burst_time = 1;
            local_processes[2].remaining_time = local_processes[2].burst_time;

            local_processes[3]._name[0] = 'P';
            local_processes[3]._name[1] = '4';
            local_processes[3].arrival_time = 3;
            local_processes[3].burst_time = 2;
            local_processes[3].remaining_time = local_processes[3].burst_time;

            local_processes[4]._name[0] = 'P';
            local_processes[4]._name[1] = '5';
            local_processes[4].arrival_time = 5;
            local_processes[4].burst_time = 5;
            local_processes[4].remaining_time = local_processes[4].burst_time;
            break;

        case 2: //SJF

            local_processes[0]._name[0] = 'P';
            local_processes[0]._name[1] = '1';
            local_processes[0].arrival_time = 1;
            local_processes[0].burst_time = 7;
            local_processes[0].remaining_time = local_processes[0].burst_time;

            local_processes[1]._name[0] = 'P';
            local_processes[1]._name[1] = '2';
            local_processes[1].arrival_time = 2;
            local_processes[1].burst_time = 5;
            local_processes[1].remaining_time = local_processes[1].burst_time;

            local_processes[2]._name[0] = 'P';
            local_processes[2]._name[1] = '3';
            local_processes[2].arrival_time = 3;
            local_processes[2].burst_time = 1;
            local_processes[2].remaining_time = local_processes[2].burst_time;

            local_processes[3]._name[0] = 'P';
            local_processes[3]._name[1] = '4';
            local_processes[3].arrival_time = 4;
            local_processes[3].burst_time = 2;
            local_processes[3].remaining_time = local_processes[3].burst_time;

            local_processes[4]._name[0] = 'P';
            local_processes[4]._name[1] = '5';
            local_processes[4].arrival_time = 5;
            local_processes[4].burst_time = 10;
            local_processes[4].remaining_time = local_processes[4].burst_time;
            
            break;

        case 3: //RR

            local_processes[0]._name[0] = 'P';
            local_processes[0]._name[1] = '0';
            local_processes[0].arrival_time = 0;
            local_processes[0].burst_time = 4;
            local_processes[0].remaining_time = local_processes[0].burst_time;

            local_processes[1]._name[0] = 'P';
            local_processes[1]._name[1] = '1';
            local_processes[1].arrival_time = 1;
            local_processes[1].burst_time = 5;
            local_processes[1].remaining_time = local_processes[1].burst_time;

            local_processes[2]._name[0] = 'P';
            local_processes[2]._name[1] = '2';
            local_processes[2].arrival_time = 2;
            local_processes[2].burst_time = 2;
            local_processes[2].remaining_time = local_processes[2].burst_time;

            local_processes[3]._name[0] = 'P';
            local_processes[3]._name[1] = '3';
            local_processes[3].arrival_time = 3;
            local_processes[3].burst_time = 1;
            local_processes[3].remaining_time = local_processes[3].burst_time;

            local_processes[4]._name[0] = 'P';
            local_processes[4]._name[1] = '4';
            local_processes[4].arrival_time = 4;
            local_processes[4].burst_time = 6;
            local_processes[4].remaining_time = local_processes[4].burst_time;

            local_processes[5]._name[0] = 'P';
            local_processes[5]._name[1] = '5';
            local_processes[5].arrival_time = 6;
            local_processes[5].burst_time = 3;
            local_processes[5].remaining_time = local_processes[4].burst_time;
            
            break;        
    } 


    printLineBreak();
    printf("INPUT DATA LOCAL PROCESSES: \n\n");
    
    int i;
    for(i = 0; i <= 4; i++){
         printf("%d | Process Name: %c%c | Arrival Time: %d | Burst Time: %d |\n", i, local_processes[i]._name[0],local_processes[i]._name[1] , local_processes[i].arrival_time, local_processes[i].burst_time);
    }


    printLineBreak();


    sumOfBurstTimes = 0;

    i = 0; 
    while(i < sizeof(local_processes)/(sizeof(Process))){ 
        sumOfBurstTimes += local_processes[i].burst_time;
        i++;
    }

    printf("\nSum of Burst Times: %d \n", sumOfBurstTimes);
    printLineBreak();

    // copy local processes into processes
    memcpy(&processes, &local_processes, sizeof(local_processes));

    printLineBreak();
    printf("INPUT DATA GLOBAL PROCESSES: \n\n");
    printf("\n\tPS\t|\tAT\t|\tBT\t|\n\n");
    for(i = 0; i <= 4; i++){
         printf("\t%c%c\t|\t%d\t|\t%d\t|\n", processes[i]._name[0],processes[i]._name[1] , processes[i].arrival_time, processes[i].burst_time);
    }
    printLineBreak();
    printf("\nDATA INITIALISED\n");
    processes_num = array_size; // after memcpy (to avoid mem overwrite of int accidentily)
}

void clearData(){ 
    sumOfBurstTimes = 0;
    processes_num = 0;
}


void printOutcomeSummary(){ 
    int sumTAT = 0;
    int sumWT = 0;

    printf("\nProcess | Arrival Time | Burst Time | Completion Time | Turn Around Time | Wait Time\t|\n");

    int index;
    for(index = 0; index < processes_num; index++){ 
        processes[index].turn_around_time = processes[index].completion_time - processes[index].arrival_time;
        processes[index].wait_time = processes[index].turn_around_time - processes[index].burst_time;
    
        sumTAT += processes[index].turn_around_time;
        sumWT += processes[index].wait_time;

        printf("\n%c%c\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", processes[index]._name[0], processes[index]._name[1],processes[index].arrival_time,processes[index].burst_time,processes[index].completion_time,processes[index].turn_around_time,processes[index].wait_time);
        
    }

    printf("\nAverage Turn Around Time: %.2d \n", (sumTAT/index));
    printf("\nAverage Wait Time: %.2d \n", (sumWT/index));

    printLineBreak();
}



/**
 *
 **/
int * get_arrived_processes(int current_time_slice){ 
    int arrived_processes[];


    return arrived_processes;
}


/**
 *
 **/
int get_shortest_remaining_time_index(){
    
    int shortest_remaining_time_index;

    int index;
    for(index = 0; index < processes_num; index++){ 
        if(index == 0){
            shortest_remaining_time_index = index; 
        }

        if(((processes[index].remaining_time) < (processes[shortest_remaining_time_index].remaining_time)) && (processes[index].remaining_time != 0)){ 
            shortest_remaining_time_index = index;
        }
    }

    return shortest_remaining_time_index;
}


 /**
 * TQ Selection
 **/

int round_robin_menu(){ 
    char input_char; 
    printf("\nSet Time Quantum\n");
    printf("\n\t2 | 2\n");
    printf("\n\t4 | 4\n");
    scanf("%s", &input_char);

    if(input_char == '2'){ 
        return 2;
    }

    if(input_char == '4'){ 
        return 4;
    }

    return 0;
}

/************************************************
 * SCHEDULING METHODS
 ************************************************/

/**
 * First Come First Served
 * Non Preemptive
 **/
void first_come_first_served(){ 

    int time_slice;
    int working_process_index;
    int index;

    for(time_slice = 1; time_slice <= sumOfBurstTimes; time_slice++){ 
       
        for(index = 0; index < processes_num; index++){ 
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

}





/**
 * Shortest Job First
 * Non Prememptive
 **/
void shortest_job_first(){ 
    int time_slice;
    int working_process_index = 0, this_qualifying_index = 0, last_qualifying_index = 0;
    bool isWorkingProcessIndexSet = false;

    int *p_arrived_processes;
    int j;
    for(time_slice = 1; time_slice < sumOfBurstTimes; time_slice++){ 
        p_arrived_processes = get_arrived_processes;

        for(j = 0; j < ){ 

        }
    }

}





/**
 * Round Robin Algorithm
 **/
void round_robin(){ 

    int tq = round_robin_menu();

    // Check for valid TQ input
    if((tq != 2) && (tq != 4)){ 
        printf("\nERROR : invalid menu input!\n"); 
        printLineBreak();
        return;
    }

    int time_slice;
    int working_process_index = 0, this_qualifying_index = 0, last_qualifying_index = 0;
    bool isWorkingProcessIndexSet = false;

    for(time_slice = 1; time_slice < sumOfBurstTimes; time_slice++){ 
        printf("not yet implemented");
    }

}





/**
 * Shortest Remaining Time First
 **/
void shortest_remaining_time_first(){ 
    printf("NOT YET IMPLEMENTED");
}



