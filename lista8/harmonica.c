#include <stdio.h>
//
// Created by Luan on 16/07/2025.
//
int harmonica() {
    double harmonica[5];
    double fundamental;
    while (scanf("%lf",&fundamental)==1) {
        harmonica[0]=fundamental;
        harmonica[1]=fundamental + fundamental/2;
        harmonica[2]=fundamental + fundamental/8;
        harmonica[3]=harmonica[2]+harmonica[2]/2;
        harmonica[4]=harmonica[2]+harmonica[2]/8;

        for (int i =0;i<5;i++) {
            printf("%.2lf ", harmonica[i]-0.005+0.0005);
        }
        printf("\n");
    }
    return 0;
}

int main() {
    return harmonica();
}