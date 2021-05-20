#include "strings.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_PATH 260

void input(char* str, char* delim)
{
    printf("delim: ");
    scanf("%c", delim);
    printf("paths: ");
    scanf("%s", str);
    printf("\n");
}

void output(int n)
{
    switch (n)
    {
    case 1:
        printf("Incorrect way\n");
        break;
    case 2:
        printf("Length too long\n");
        break;
    case 3:
        printf("Incorrect way in this lab\n");
        break;
    case 4:
        printf("Correct way\n");
        break;
    }
}

int check_ip(char* str)
{
    char strcopy[100];
    scpy(str, strcopy);
    char* ptr[10];
    int num_of_str;
    int num;
    // printf("strcopy_ip = %s\n", strcopy);
    num_of_str = stok(strcopy, '.', ptr);
    if (num_of_str != 4)
    {
        return 1;
    }
    for (int i = 0; i < num_of_str; i++)
    {
        num = atoi(ptr[i]);
        // printf("number = %d\n", num);
        if ((num < 0) || (num > 255))
        {
            return 1;
        }
    }
    return 4;
}

int check_domain(char* str)
{
    char strcopy[100];
    char substr[50];
    scpy(str, strcopy);
    char* ptr[10];
    int num_of_str;
    int length;
    // printf("strcopy_ip = %s\n", strcopy);
    num_of_str = stok(strcopy, '.', ptr);
    if (num_of_str > 4)
    {
        return 3;
    }
    for (int i = 0; i < num_of_str; i++)
    {
        scpy(ptr[i], substr);
        length = slen(substr);
        for (int j = 0; j < length; j++)
        {
            if ((isLowCase(substr[j]) == 1) && (isTallCase(substr[j]) == 1))
            {
                return 3;
            }
        }
    }
    if ((scmp(ptr[num_of_str - 1], "com") == 1) || (scmp(ptr[num_of_str - 1], "org") == 1) || (scmp(ptr[num_of_str - 1], "ru") == 1))
    {
        return 4;
    }
    return 3;
}

int check(char* substr)
{
    int domain = 0, ip = 0;
    int length;
    char firstletter;
    char ip_domain[100];
    if (slen(substr) > MAX_PATH)
    {
        return 2;
    }
    if (sspn(substr, ":*?<>|") == 1)
    {
        return 1;
    }
    substring(substr, ip_domain);
    // printf("ip_domain = %s\n", ip_domain);
    length = slen(ip_domain);
    firstletter = ip_domain[0];
    for (int i = 0; i < length; i++)
    {
        if ((isLowCase(ip_domain[i]) == 0) || (isTallCase(ip_domain[i]) == 0))
        {
            domain = 1;
        }
        if (isDigit(ip_domain[i]) == 0)
        {
            ip = 1;
        }
        if ((ip == 0) && (domain == 0) && (ip_domain[i] != '.'))
        {
            return 3;
        }
    }
    if (isDigit(firstletter) == 0)
    {
        return check_ip(ip_domain);
    }
    else
    {
        return check_domain(ip_domain);
    }
}

void process(char* str)
{
    char ip_domain[270];
    char* suf = (str + 2);
    int i;
    int idx_of_end, idx_of_second_part;
    idx_of_second_part = schr(suf, '\\');
    suf = (suf + idx_of_second_part);
    substring(str, ip_domain);
    idx_of_end = schr(ip_domain, '\0');
    ip_domain[idx_of_end] = ':';
    ip_domain[idx_of_end + 1] = '\0';
    strconcat(ip_domain, suf);
    scpy(ip_domain, str);
    while ((i = schr(str, '\\')) >= 0)
    {
        str[i] = '/';
    }
}

int main()
{
    char str[270];
    char newstr[270];
    newstr[0] = '\0';
    char delim;
    char delim_str[2];
    char* ptr[10];
    int num_of_str, result_of_check;
    input(str, &delim);
    delim_str[0] = delim;
    num_of_str = stok(str, delim, ptr);
    for (int i = 0; i < num_of_str; i++)
    {
        if ((result_of_check = check(ptr[i])) == 4)
        {
            if (newstr[0] != '\0')
            {
                strconcat(newstr, delim_str);
            }
            process(ptr[i]);
            strconcat(newstr, ptr[i]);
        }
        printf("%d. ", i + 1);
        output(result_of_check);
    }
    printf("\nnew paths: %s\n", newstr);
    return 0;
}