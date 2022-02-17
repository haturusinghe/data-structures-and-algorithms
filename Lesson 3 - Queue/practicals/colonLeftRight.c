
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

#define LIMIT 50

int main(void)
{
    bool end = false;
    do {
        Queue left, right;
        char prompt = 'X';
        bool colon = false;
        char input[LIMIT];
        printf("Input Line: ");
        scanf("%s", input);

        for (int i = 0; input[i] != '\0'; i++)
        {
            if (input[i] == ':')
            {
                colon = true;
            }
        }

        if (!colon)
        {
            printf("N");
        }
        else
        {
            CreateQueue(&left);
            CreateQueue(&right);
            int j;

            for (j = 0; input[j] != ':'; j++)
            {
                Append(&left, input[j]);
            }

            for (j = j + 1; input[j] != '\0'; j++)
            {
                Append(&right, input[j]);
            }

            if (left.count > right.count)
            {
                printf("L");
            }
            else if (left.count < right.count)
            {
                printf("R");
            }
            else if (left.count == right.count)
            {
                bool different = false;
                char charLeft, charRight;

                while (!isQueueEmpty(&left) && !isQueueEmpty(&right))
                {
                    Serve(&charLeft, &left);
                    Serve(&charRight, &right);

                    if (charLeft != charRight)
                    {
                        different = true;
                        break;
                    }
                }

                if (different)
                {
                    printf("D");
                }
                else
                {
                    printf("S");
                }
            }
        }

        do {
            printf("\n\tContinue? (Y/N): ");
            scanf(" %c", &prompt);
        } while (prompt != 'Y' && prompt != 'N');

        if(prompt == 'N'){
            end = true;
        }
    } while (!end);
}