/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <ezachari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:34:38 by ezachari          #+#    #+#             */
/*   Updated: 2021/04/13 19:22:32 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

size_t      ft_strlen(const char *s);
ssize_t     ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t     ft_read(int fildes, void *buf, size_t nbyte);
char        *ft_strdup(const char *s1);
int         ft_strcmp(const char *s1, const char *s2);
char        *ft_strcpy(char * dst, const char * src);
char        *ft_strdup(const char *s1);
/*
**  FOR TESTING
*/
void        test_strlen(void);
void        test_strcpy(void);
void        test_strcmp(void);
void        test_read(void);
void        test_write(void);
void        test_strdup(void);
#endif