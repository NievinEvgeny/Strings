int isDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return 0;
    }
    return 1;
}

int isLowCase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return 0;
    }
    return 1;
}

int isTallCase(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return 0;
    }
    return 1;
}

int schr(char* suf, char delim)
{
    int i, idx = -1;
    for (i = 0; (suf[i] != '\0') && (suf[i] != delim); i++)
        ;
    if (suf[i] == delim)
    {
        idx = i;
    }
    return idx;
}

int slen(char* str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}

void scpy(char* str1, char* str2)
{
    int i;
    for (i = 0; str1[i] != '\0'; i++)
    {
        str2[i] = str1[i];
    }
    str2[i] = '\0';
}

int scmp(char* str1, char* str2)
{
    int i, flg = 1;
    for (i = 0; flg && (str1[i] != '\0' || str2[i] != '\0'); i++)
    {
        if (str1[i] != str2[i])
        {
            flg = 0;
        }
    }
    return flg;
}

int stok(char* str, char delim, char* ptr[])
{
    char* suf = str;
    ptr[0] = str;
    int i, j = 1;
    while ((i = schr(suf, delim)) >= 0)
    {
        suf[i] = '\0';
        suf = suf + i + 1;
        ptr[j] = suf;
        j++;
    }
    return j;
}

int sspn(char* str, char* forbidden)
{
    int i, j;
    for (i = 0; i < slen(str); i++)
    {
        for (j = 0; j < slen(forbidden); j++)
        {
            if (str[i] == forbidden[j])
            {
                return 1;
            }
        }
    }
    return 0;
}

void strconcat(char* str1, char* str2)
{
    int len = slen(str1);
    char* suf = str1 + len;
    scpy(str2, suf);
}

void suntok(char newDelim, char* ptr[], int num_of_str)
{
    int i;
    for (i = 1; i < num_of_str; i++)
    {
        *(ptr[i] - 1) = newDelim;
    }
}

void substring(char* str, char* substr)
{
    int i, j, end;
    char* suf = (str + 2);
    end = schr(suf, '\\');
    for (i = 2, j = 0; i <= end + 1; i++, j++)
    {
        substr[j] = str[i];
    }
    substr[j] = '\0';
}
