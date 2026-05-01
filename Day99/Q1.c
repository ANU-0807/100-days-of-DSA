#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

int cmp(const void *a, const void *b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int main() {
    int target = 12;
    int position[] = {10,8,0,5,3};
    int speed[] = {2,4,1,1,3};
    int n = 5;

    Car cars[5];

    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double prev = 0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > prev) {
            fleets++;
            prev = cars[i].time;
        }
    }

    printf("Car Fleets = %d\n", fleets);
    return 0;
}
