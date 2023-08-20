#include<stdio.h>

void main(){
    int year,month;
    printf("Enter year and month :");
    scanf("%d%d",&year,&month);
    if(year%4==0 && year%100!=0 || year%400==0){
        if(month == 2){
            printf("This month have 29 days");
        }
    }
    if(month == 1||3||5||7||8||10||12){
        printf("this month have 31 days");
    }
    else if(month == 2){
        printf("This month have 28 days");
    }
    else{
        printf("this month have 30 days");
    }
}