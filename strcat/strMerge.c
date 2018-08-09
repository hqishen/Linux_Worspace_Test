/*
 * =====================================================================================
 *
 *       Filename:  strMerge.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017年12月20日 19时53分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
int main(void) {

    char a[1014] = "abcdd";
    char b[1024] = "hhhhhkk";

    printf("%s %s \r\n", a, b);

    strcat(a, b);

    printf("%s \r\n", a);
    return 0;
}
