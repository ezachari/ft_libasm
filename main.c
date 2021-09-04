/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <ezachari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:34:19 by ezachari          #+#    #+#             */
/*   Updated: 2021/04/13 19:32:25 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int     main(void)
{
    test_strlen();
    test_strcpy();
    test_strcmp();
    test_read();
    test_write();
    test_strdup();
    return (0);
}

void    test_strlen(void)
{
    printf("\n" ANSI_COLOR_YELLOW "[STRLEN]" ANSI_COLOR_RESET "\n");
    int     len1;
    int     len2;
    char    *test1;
    char    *test2;
    int     count;

    count = 0;
    while (count < 3)
    {
        switch (count)
        {
        case 0:
            len1 = strlen("Hello World!");
            len2 = ft_strlen("Hello World!");
            if (len1 == len2)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %d\n Assembly: %d\n" ANSI_COLOR_RESET, len1, len2);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %d\n Assembly: %d\n" ANSI_COLOR_RESET, len1, len2);
            break;
        case 1:
            len1 = strlen("");
            len2 = ft_strlen("");
            if (len1 == len2)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %d\n Assembly: %d\n" ANSI_COLOR_RESET, len1, len2);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %d\n Assembly: %d\n" ANSI_COLOR_RESET, len1, len2);
        case 2:
            test1 = strdup("Hello World!!!");
            test2 = strdup("Hello World!!!");
            len1 = strlen(test1);
            len2 = ft_strlen(test2);
            free(test1);
            free(test2);
            if (len1 == len2)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %d\n Assembly: %d\n" ANSI_COLOR_RESET, len1, len2);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %d\n Assembly: %d\n" ANSI_COLOR_RESET, len1, len2);
        default:
            count++;
            break;
        }
        count++;
    }
}

void    test_strcpy(void)
{
    printf("\n" ANSI_COLOR_YELLOW "[STRCPY]" ANSI_COLOR_RESET "\n");
    char     buf1[100];
    char     buf2[100];
    char    *test1;
    char    *test2;
    int     count;

    bzero(buf1, 100);
    bzero(buf2, 100);
    count = 0;
    while (count < 3)
    {
        switch (count)
        {
        case 0:
            strcpy(buf1, "Hello World!");
            ft_strcpy(buf2, "Hello World!");
            if (strcmp(buf1, buf2) == 0)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %s\n Assembly: %s\n" ANSI_COLOR_RESET, buf1, buf2);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %s\n Assembly: %s\n" ANSI_COLOR_RESET, buf1, buf2);
            bzero(buf1, 100);
            bzero(buf2, 100);
            break;
        case 1:
            strcpy(buf1, "");
            ft_strcpy(buf2, "");
            if (strcmp(buf1, buf2) == 0)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %s\n Assembly: %s\n" ANSI_COLOR_RESET, buf1, buf2);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %s\n Assembly: %s\n" ANSI_COLOR_RESET, buf1, buf2);
            bzero(buf1, 100);
            bzero(buf2, 100);
            break;
        case 2:
            test1 = strdup("Hello world!!!");
            test2 = strdup("Hello world!!!");
            strcpy(buf1, test1);
            ft_strcpy(buf2, test2);
            if (strcmp(buf1, buf2) == 0)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %s\n Assembly: %s\n" ANSI_COLOR_RESET, buf1, buf2);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %s\n Assembly: %s\n" ANSI_COLOR_RESET, buf1, buf2);
            bzero(buf1, 100);
            bzero(buf2, 100);
            free(test1);
            free(test2);
            break;
        default:
            count++;
            break;
        }
        count++;
    }
}

void    test_strcmp(void)
{
    printf("\n" ANSI_COLOR_YELLOW "[STRCMP]" ANSI_COLOR_RESET "\n");
    int     ret1;
    int     ret2;
    char    *test1;
    char    *test2;
    int     count;

    count = 0;
    while (count < 3)
    {
        switch (count)
        {
        case 0:
            ret1 = strcmp("Hello World", "Hello World!");
            ret2 = ft_strcmp("Hello World", "Hello World!");
            if (ret1 == ret2 || (ret1 < 0 && ret2 < 0) || (ret1 > 0 && ret2 > 0))
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %d\n Assembly: %d\n" ANSI_COLOR_RESET, ret1, ret2);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %d\n Assembly: %d\n" ANSI_COLOR_RESET, ret1, ret2);
            break;
        case 1:
            ret1 = strcmp("", "1");
            ret2 = ft_strcmp("", "1");
            if (ret1 == ret2 || (ret1 < 0 && ret2 < 0) || (ret1 > 0 && ret2 > 0))
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %d\n Assembly: %d\n" ANSI_COLOR_RESET, ret1, ret2);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %d\n Assembly: %d\n" ANSI_COLOR_RESET, ret1, ret2);
            break;
        case 2:
            test1 = strdup("Hello World!!");
            test2 = strdup("Hello World!!!");
            ret1 = strcmp(test1, test2);
            ret2 = ft_strcmp(test1, test2);
            free(test1);
            free(test2);
            if (ret1 == ret2 || (ret1 < 0 && ret2 < 0) || (ret1 > 0 && ret2 > 0))
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %d\n Assembly: %d\n" ANSI_COLOR_RESET, ret1, ret2);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %d\n Assembly: %d\n" ANSI_COLOR_RESET, ret1, ret2);
            break;
        default:
            count++;
            break;
        }
        count++;
    }
}

void    test_read(void)
{
    printf("\n" ANSI_COLOR_YELLOW "[READ]" ANSI_COLOR_RESET "\n");
    int     ret1;
    int     ret2;
    int     ret3;
    int     ret4;
    char    buf1[1024];
    char    buf2[1024];
    int     count;
    int     fd;
    
    count = 0;
    while (count < 3)
    {
        bzero(buf1, 1024);
        bzero(buf2, 1024);
        switch (count)
        {
        case 0:
            fd = open("test.txt", O_RDWR);
            errno = 0;
            ret1 = read(fd, buf1, 10);
            ret3 = errno;
            close(fd);
            fd = open("test.txt", O_RDWR);
            errno = 0;
            ret2 = ft_read(fd, buf2, 10);
            ret4 = errno;
            if (ret1 == ret2 && ret3 == ret4 && strcmp(buf1, buf2) == 0)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %d\n Assembly: %d\n errno: %d\n" ANSI_COLOR_RESET, ret1, ret2, errno);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %d\n Assembly: %d\n errno: %d\n" ANSI_COLOR_RESET, ret1, ret2, errno);
            close(fd);
            break;
        case 1:
            fd = open("test.txt", O_RDWR);
            errno = 0;
            ret1 = read(-1, buf1, 10);
            ret3 = errno;
            close(fd);
            fd = open("test.txt", O_RDWR);
            errno = 0;
            ret2 = ft_read(-1, buf2, 10);
            ret4 = errno;
            if (ret1 == ret2 && ret3 == ret4 && strcmp(buf1, buf2) == 0)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %d\n Assembly: %d\n errno: %d\n" ANSI_COLOR_RESET, ret1, ret2, errno);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %d\n Assembly: %d\n errno: %d\n" ANSI_COLOR_RESET, ret1, ret2, errno);
            close(fd);
            break;
        case 2:
            fd = open("test.txt", O_RDWR);
            errno = 0;
            ret1 = read(fd, NULL, 10);
            ret3 = errno;
            close(fd);
            fd = open("test.txt", O_RDWR);
            errno = 0;
            ret2 = ft_read(fd, NULL, 10);
            ret4 = errno;
            if (ret1 == ret2 && ret3 == ret4 && strcmp(buf1, buf2) == 0)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %d\n Assembly: %d\n errno: %d\n" ANSI_COLOR_RESET, ret1, ret2, errno);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %d\n Assembly: %d\n errno: %d\n" ANSI_COLOR_RESET, ret1, ret2, errno);
            close(fd);
            break;
        default:
            count++;
            break;
        }
        count++;
    }
}

void    test_write(void)
{
    printf("\n" ANSI_COLOR_YELLOW "[WRITE]" ANSI_COLOR_RESET "\n");
    int     ret1;
    int     ret2;
    int     ret3;
    int     ret4;
    int     count;

    count = 0;
    while (count < 3)
    {
        switch (count)
        {
        case 0:
            errno = 0;
            ret1 = write(1, "Hello", strlen("Hello"));
            ret3 = errno;
            errno = 0;
            ret2 = ft_write(1, "Hello", strlen("Hello"));
            ret4 = errno;
            if (ret1 == ret2 && ret3 == ret4)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %d\n Assembly: %d\n errno: %d\n" ANSI_COLOR_RESET, ret1, ret2, errno);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %d\n Assembly: %d\n errno: %d\n" ANSI_COLOR_RESET, ret1, ret2, errno);
            break;
        case 1:
            errno = 0;
            ret1 = write(-1, "Hello", strlen("Hello"));
            ret3 = errno;
            errno = 0;
            ret2 = ft_write(-1, "Hello", strlen("Hello"));
            ret4 = errno;
            if (ret1 == ret2 && ret3 == ret4)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %d\n Assembly: %d\n errno: %d\n" ANSI_COLOR_RESET, ret1, ret2, errno);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %d\n Assembly: %d\n errno: %d\n" ANSI_COLOR_RESET, ret1, ret2, errno);
            break;
        case 2:
            errno = 0;
            ret1 = write(1, NULL, strlen("Hello"));
            ret3 = errno;
            errno = 0;
            ret2 = ft_write(1, NULL, strlen("Hello"));
            ret4 = errno;
            if (ret1 == ret2 && ret3 == ret4)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %d\n Assembly: %d\n errno: %d\n" ANSI_COLOR_RESET, ret1, ret2, errno);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %d\n Assembly: %d\n errno: %d\n" ANSI_COLOR_RESET, ret1, ret2, errno);
            break;
        default:
            count++;
            break;
        }
        count++;
    }
}

void    test_strdup(void)
{
    printf("\n" ANSI_COLOR_YELLOW "[STRDUP]" ANSI_COLOR_RESET "\n");
    char    *ret1;
    char    *ret2;
    char    *test1;
    char    *test2;
    int     count;

    count = 0;
    while (count < 3)
    {
        switch (count)
        {
        case 0:
            ret1 = strdup("Hello World");
            ret2 = ft_strdup("Hello World");
            if (strcmp(ret1, ret2) == 0)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %s\n Assembly: %s\n" ANSI_COLOR_RESET, ret1, ret2);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %s\n Assembly: %s\n" ANSI_COLOR_RESET, ret1, ret2);
            free(ret1);
            free(ret2);
            break;
        case 1:
            ret1 = strdup("");
            ret2 = ft_strdup("");
            if (strcmp(ret1, ret2) == 0)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %s\n Assembly: %s\n" ANSI_COLOR_RESET, ret1, ret2);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %s\n Assembly: %s\n" ANSI_COLOR_RESET, ret1, ret2);
            free(ret1);
            free(ret2);
            break;
        case 2:
            test1 = strdup("LOL");
            test2 = strdup("LOL");
            ret1 = strdup(test1);
            ret2 = ft_strdup(test2);
            if (strcmp(ret1, ret2) == 0)
                printf(ANSI_COLOR_GREEN " [OK]\n Original: %s\n Assembly: %s\n" ANSI_COLOR_RESET, ret1, ret2);
            else
                printf(ANSI_COLOR_RED " [KO]\n Original: %s\n Assembly: %s\n" ANSI_COLOR_RESET, ret1, ret2);
            free(ret1);
            free(ret2);
            free(test1);
            free(test2);
            break;
        default:
            count++;
            break;
        }
        count++;
    }
}