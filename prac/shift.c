#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

int main(void)
{

    int width = 3;
    int height = 3;
    int imagetemp[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
///////////////////////////////////////////////

    for(int i = 0; i < height; i++)
    {
        int temp = imagetemp[i][width - 1];
        for(int j = width - 1; j > 0; j--)
        {
            imagetemp[i][j] = imagetemp[i][j - 1];
        }
        imagetemp[i][0] = temp;
    }
    for(int j = 0; j < width; j++)
    {
        int temp = imagetemp[height - 1][j];
        for(int i = height - 1; i > 0; i--)
        {
            imagetemp[i][j] = imagetemp[i - 1][j];
        }
        imagetemp[0][j] = temp;
    }

///////////////////////////////////////////////
printf("Array after shift operation ...\n");
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            printf("%d", imagetemp[i][j]);
        }
        printf("\n");
    }
}