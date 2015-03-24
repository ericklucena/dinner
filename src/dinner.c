/* 
* @Author: Erick Lucena Palmeira Silva
* @Date:   2015-03-23 19:33:54
* @Last Modified by:   Erick Lucena Palmeira Silva
* @Last Modified time: 2015-03-23 19:46:07
*/

#include "philosopher.h"
#include <stdio.h>

int main(int argc, char* argv[]) {

    int seats;
    int meals;

    if (argc < 3)
    {
        printf("Wrong number of arguments.\nUsage: dinner [number of philosophers] [number of meals]\n");
    }
    else
    {
        sscanf(argv[1], "%d", &seats);
        sscanf(argv[2], "%d", &meals);
        setTable(seats, meals);
    }

    return 0;
}