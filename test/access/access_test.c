/***************************************************************************************
    > File Name:        access_test.c
	> Author:           Sundae
	> Mail:
	> Created Time:     2018年05月24日 星期四 19时15分20秒
	> Description:
	> Modification:
	> Version:          V0.01
 ***************************************************************************************/
#include<stdio.h>
#include <unistd.h>


int main(void) {

    if(access("/media/sundae/root", F_OK) == 0) {
        printf("/media/sundae/root/ exit \n");
    } else {
        printf("error");
    }

    return 0;
}
