#include "queue_c.h"
#include <stdbool.h>
#include <string.h>

int main(){
    Queue lane;
    Queue holdup;
    Queue tempLane;

    CreateQueue(&lane);
    CreateQueue(&holdup);
    CreateQueue(&tempLane);

    char status;
    char prompt;
    int parkCount = 0;
    Car car;
    bool flag = true;
    do{

        printf("Input: ");
        scanf("%c %[^\n]s",&status,car.name);
        // printf("Status: %c UI: %s\n",status,plate);

        if(status == 'A' && parkCount < 10){
            parkCount++;
            printf("Parking Car %s in Lane\n",car.name);
            Append(&lane,car);
            printf("Car Park (%d):\n",parkCount);
            PrintQueue(&lane);

        }else if(status == 'A' && isQueueFull(&lane)){
            printf("Car %s is waiting in Holding Lane\n",car.name);
            Append(&holdup,car);
            printf("Wait Lane:\n");
            PrintQueue(&holdup);

        }else if(status == 'D'){
            
            if(!isQueueEmpty(&lane) && FindCar(&lane,car)){

                while(!isQueueEmpty(&lane)){
                    parkCount--;
                    Car out = Serve(&lane);
                    if(strcmp(out.name,car.name) != 0){
                        Append(&tempLane,out);
                    }
                }
                printf("TempLane\n");
                PrintQueue(&tempLane); 

                while(!isQueueEmpty(&tempLane)){
                    parkCount++;
                    printf("Move from Temp Lane to Park Lane\n");
                    Car out = Serve(&tempLane);
                    Append(&lane,out);
                }

                while(!isQueueEmpty(&holdup) && parkCount < 10){
                    parkCount++;
                    printf("Move from Holding Lane to Park Lane\n");
                    Car out = Serve(&holdup);
                    Append(&lane,out);
                }
                
                printf("Car Park (%d):\n",parkCount);
                PrintQueue(&lane);
                printf("Wait Lane:\n");
                PrintQueue(&holdup); 
            }
        }

        printf("\nContinue (Y|N) ?: ");
        getchar();
        prompt = getchar();
        getchar();
        if(prompt == 'N'){
            flag = false;
        }
        printf("\n");

    }while(flag);
}