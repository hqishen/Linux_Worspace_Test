/*
 * =====================================================================================
 *
 *       Filename:  timc.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017年12月17日 18时39分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>


void getNowTime();

int main(void) {

    getNowTime();
    /*  *
    time_t timer;
    struct tm *tblock;
    timer = time(NULL);
    tblock = localtime(&timer);

    printf("Local timeis :%s \r\n", asctime(tblock));
    */

    return 0;
}

void getNowTime()
{
    struct timespec time;
    struct tm nowTime;
    char current[1024];

    clock_gettime(CLOCK_REALTIME, &time);  //获取相对于1970到现在的秒数
    localtime_r(&time.tv_sec, &nowTime);
    sprintf(current, "%04d-%02d-%02d-%02d:%02d:%02d",  \
            nowTime.tm_year + 1900, nowTime.tm_mon+1, nowTime.tm_mday, \
            nowTime.tm_hour, nowTime.tm_min, nowTime.tm_sec);
    printf("now time :%s \r\n", current);
}
