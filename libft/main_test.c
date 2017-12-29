/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:10:15 by apakhomo          #+#    #+#             */
/*   Updated: 2017/10/25 12:10:16 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int a);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strcpy (char *dst, const char *src);
char		*ft_strdup(const char *s1);
char		*ft_strncpy(char *dst, const char *src, size_t n);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, char *s2, size_t n);
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *str, int ch);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		striteri_test(unsigned int a, char *c);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
char		*ft_itoa(int n);
void		ft_putendl(char const *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);

void		striter_test(char *c)
{
    if (*c != '-')
    {
        *c = '-';
    }
}

void		striteri_test(unsigned int a, char *c)
{
    if ((a % 2) == 0)
        *c = '-';
}

char		strmap_test(char c)
{
    if (c != '-')
    {
        return ('-');
    }
    return (c);
}

char		strmapi_test(unsigned int a, char c)
{
    if ((a % 2) == 0)
    {
        return ('-');
    }
    return (c);
}

/*
static size_t ft_strsplit_count_len(char *s, char c)
{
    size_t countc;

    countc = 0;
    while (*s != c)
    {
        countc++;
        s++;
    }
    return (countc);
}
*/
int			main(int argc, char **argv)
{
    //first part
    ft_putstr("\n ___________PART 1___________\n");
    if (argc == 1 && **argv)
    {
        char *src = "Helloo\n";
        char *dst;
        // test *memset
        unsigned char memtest[15] = "1234567890";
        unsigned char memtest2[15] = "1234567890";
        if (strcmp(memset(memtest, '1', 10), ft_memset(memtest2, '1', 10)) == 0)
            ft_putstr("void     *ft_memset   -> test:    OK\n");
        else
            ft_putstr("void     *ft_memset   -> test:      KO\n");

        // test bzero
        unsigned int zt[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        unsigned int zta[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        bzero(zt, 20);
        ft_bzero(zta, 20);
        if (zt[0] == 0 && zt[1] == 0 && zt[2] == 0 && zt[3] == 0 && zt[4] == 0 && zta[0] == 0 && zta[1] == 0 && zta[2] == 0 && zta[3] == 0 && zt[4] == 0)
            ft_putstr("void     ft_bzero     -> test:    OK\n");
        else
            ft_putstr("void     ft_bzero     -> test:      KO\n");

        // test memcpy
        char srcmmcp[15] = "1234567890";
        char srcm[15] = "1234567890";
        char srcmmcpm[15] = "1234567890";
        char srcmm[15] = "1234567890";
        memcpy(srcmmcp, srcm, 8);
        ft_memcpy(srcmmcpm, srcmm, 8);
        if (strcmp(srcmmcp, srcmmcpm) == 0)
            ft_putstr("char     *ft_memcpy   -> test1:   OK\n");
        else
            ft_putstr("char     *ft_memcpy   -> test1:     KO\n");
        char srcmmcp1o[15] = "1234567890";
        char srcm1o[15] = "";
        char srcmmcp1[15] = "1234567890";
        char srcm1[15] = "";
        memcpy(srcmmcp1o, srcm1o, 8);
        ft_memcpy(srcmmcp1, srcm1, 8);
        if (strcmp(srcmmcp1o, srcmmcp1) == 0)
            ft_putstr("char     *ft_memcpy   -> test2:   OK\n");
        else
            ft_putstr("char     *ft_memcpy   -> test2:     KO\n");


        // test memccpy
        char source[] = "source";
        char destination[] = "destination";
        if (strcmp(memccpy(destination, source, 'u', 6), ft_memccpy(destination, source, 'u', 6)) == 0)
            ft_putstr("char     *ft_memccpy  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_memccpy  -> test1:     KO\n");
        if (memccpy(destination, source, 'z', 6) == NULL && ft_memccpy(destination, source, 'z', 6) == NULL)
            ft_putstr("char     *ft_memccpy  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_memccpy  -> test2:     KO\n");


        // test memmove
        char memmvtest[] = "1234567890";
        char ftmemmvtest[] = "1234567890";

        if (strcmp(memmove(&memmvtest[4], &memmvtest[3], 3), ft_memmove(&ftmemmvtest[4], &ftmemmvtest[3], 3)) == 0)
            ft_putstr("char     *ft_memmove  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_memmove  -> test1:     KO\n");
        char fmemmvtest[] = "1234567890";
        char fftmemmvtest[] = "1234567890";
        //printf("o: %s\nm: %s\n", memmove(&fmemmvtest[4], &fmemmvtest[3], 4), ft_memmove(&fftmemmvtest[4], &fftmemmvtest[3], 4));
        if (strcmp(memmove(&fmemmvtest[3], &fmemmvtest[4], 4), ft_memmove(&fftmemmvtest[3], &fftmemmvtest[4], 4)) == 0)
            ft_putstr("char     *ft_memmove  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_memmove  -> test2:     KO\n");


        // test memchr
        char *memchrres;
        char testmmch[] = "1234567890";
        memchrres = memchr(testmmch, '4', 10);
        if (memchrres != NULL)
            memchrres[0] = '!';
        char *ftmemchrres;
        char fttestmmch[] = "1234567890";
        ftmemchrres = ft_memchr(fttestmmch, '4', 10);
        if (ftmemchrres != NULL)
            ftmemchrres[0] = '!';
        if (strcmp(testmmch, fttestmmch) == 0)
            ft_putstr("char     *ft_memchr   -> test:    OK\n");
        else
            ft_putstr("char     *ft_memchr   -> test:      KO\n");

        // test memcmp
        char memcmptst[] = "1234567890";
        char ftmemcmptst[] = "1234567890";
        char *memcmptest = memcmptst;
        char *ftmemcmptest = ftmemcmptst;
        if ((memcmp(memcmptest, ftmemcmptest, 5)) == 0 && (ft_memcmp(memcmptest, ftmemcmptest, 5)) == 0)
            ft_putstr("char     *ft_memcmp   -> test1:   OK\n");
        else
            ft_putstr("char     *ft_memcmp   -> test1:     KO\n");
        char testmemcmp1[] = "\0";
        char testmemcmp2[] = "\0";
        char testmemcmp12[] = "TEST";
        char testmemcmp22[] = "TEST\0";
        char testmemcmp13[] = "TEST";
        char testmemcmp23[] = "test";
        char testmemcmp14[] = "";
        char testmemcmp24[] = "test";
        char testmemcmp15[] = "";
        char testmemcmp25[] = "test";
        if (ft_memcmp(testmemcmp1, testmemcmp2, 25) == memcmp(testmemcmp1, testmemcmp2, 25))
            ft_putstr("char     *ft_memcmp   -> test2:   OK\n");
        else
            ft_putstr("char     *ft_memcmp   -> test2:     KO\n");
        if (ft_memcmp(testmemcmp12, testmemcmp22, 5) == memcmp(testmemcmp12, testmemcmp22, 5))
            ft_putstr("char     *ft_memcmp   -> test3:   OK\n");
        else
            ft_putstr("char     *ft_memcmp   -> test3:     KO\n");
        if (ft_memcmp(testmemcmp13, testmemcmp23, 2) != 0 && memcmp(testmemcmp13, testmemcmp23, 2) != 0)
            ft_putstr("char     *ft_memcmp   -> test4:   OK\n");
        else
            ft_putstr("char     *ft_memcmp   -> test4:     KO\n");
        if (ft_memcmp(testmemcmp14, testmemcmp24, 3) != 0 && memcmp(testmemcmp14, testmemcmp24, 3) != 0)
            ft_putstr("char     *ft_memcmp   -> test5:   OK\n");
        else
            ft_putstr("char     *ft_memcmp   -> test5:     KO\n");
        if (ft_memcmp(testmemcmp15, testmemcmp25, 0) == memcmp(testmemcmp15, testmemcmp25, 0))
            ft_putstr("char     *ft_memcmp   -> test6:   OK\n");
        else
            ft_putstr("char     *ft_memcmp   -> test6:     KO\n");


        // test strlen
        if (ft_strlen(src) == strlen(src))
            ft_putstr("size_t   ft_strlen    -> test:    OK\n");
        else
            ft_putstr("size_t   ft_strlen    -> test:      KO\n");


        // test *strdup
        char *strduptesta;
        char *strduptestb;
        strduptesta = ft_strdup(src);
        strduptestb = strdup(src);
        if (strcmp(strduptesta, strduptestb) == 0)
            ft_putstr("char     *ft_strdup   -> test:    OK\n");
        else
            ft_putstr("char     *ft_strdup   -> test:      KO\n");


        // test ft_strcpy
        dst = (char*)malloc(sizeof(char) * ft_strlen(src));
        dst = ft_strcpy(dst, src);
        if (strcmp(dst, src) == 0)
            ft_putstr("char     *ft_strcpy   -> test:    OK\n");
        else
            ft_putstr("char     *ft_strcpy   -> test:      KO\n");

        // test strncpy
        free(dst);
        dst = (char*)malloc(sizeof(char) * ft_strlen(src) + 2);
        dst = ft_strncpy(dst, src, ft_strlen(src) + 2);
        if (dst[ft_strlen(src) + 1] == '\0' && dst[ft_strlen(src) + 2] == '\0' && dst[ft_strlen(src)] == '\0' )
            ft_putstr("char     *ft_strncpy  -> test:    OK\n");
        else
            ft_putstr("char     *ft_strncpy   -> test:      KO\n");
        free(dst);

        // test strcat
        char s1strcat[20] = "";
        char s2strcat[20] = "Hello, world";
        char s1strcato[20] = "";
        char s2strcato[20] = "Hello, world";
        if (strcmp(ft_strcat(s1strcat, s2strcat), strcat(s1strcato, s2strcato)) == 0)
            ft_putstr("char     *ft_strcat   -> test:    OK\n");
        else
            ft_putstr("char     *ft_strcat   -> test:      KO\n");

        //test strncat
        char s1strcat2[20] = "";
        char s2strcat2[20] = "Hello, world";
        char s1strcato2[20] = "";
        char s2strcato2[20] = "Hello, world";
        if (strcmp(ft_strncat(s1strcat2, s2strcat2, 3), strncat(s1strcato2, s2strcato2, 3)) == 0)
            ft_putstr("char     *ft_strncat  -> test:    OK\n");
        else
            ft_putstr("char     *ft_strncat  -> test:      KO\n");

        //test strlcat
        char dststrlcat1[20] = "";
        char srcstrlcat1[20] = "";
        char dststrlcat11[20] = "";
        char srcstrlcat11[20] = "";
        char dststrlcat2[20] = "";
        char srcstrlcat2[20] = "1";
        char dststrlcat21[20] = "";
        char srcstrlcat21[20] = "1";
        char dststrlcat3[20] = "1";
        char srcstrlcat3[20] = "";
        char dststrlcat31[20] = "1";
        char srcstrlcat31[20] = "";
        char dststrlcat4[20] = "1";
        char srcstrlcat4[20] = "1";
        char dststrlcat41[20] = "1";
        char srcstrlcat41[20] = "1";
        char dststrlcat5[20] = "hello";
        char srcstrlcat5[20] = "1";
        char dststrlcat51[20] = "hello";
        char srcstrlcat51[20] = "1";
        char dststrlcat6[20] = "1";
        char srcstrlcat6[20] = "hello";
        char dststrlcat61[20] = "1";
        char srcstrlcat61[20] = "hello";
        char dststrlcat7[30] = "source&";
        char srcstrlcat7[30] = "destination";
        char dststrlcat71[30] = "source&";
        char srcstrlcat71[30] = "destination";
        if (ft_strlcat(dststrlcat1, srcstrlcat1, 10) == strlcat(dststrlcat11, srcstrlcat11, 10))
            ft_putstr("size_t   ft_strlcat   -> test1:   OK\n");
        else
            ft_putstr("size_t   ft_strlcat   -> test1:     KO\n");

        if (ft_strlcat(dststrlcat2, srcstrlcat2, 0) == strlcat(dststrlcat21, srcstrlcat21, 0))
            ft_putstr("size_t   ft_strlcat   -> test2:   OK\n");
        else
            ft_putstr("size_t   ft_strlcat   -> test2:     KO\n");

        if (ft_strlcat(dststrlcat3, srcstrlcat3, 10) == strlcat(dststrlcat31, srcstrlcat31, 5))
            ft_putstr("size_t   ft_strlcat   -> test3:   OK\n");
        else
            ft_putstr("size_t   ft_strlcat   -> test3:     KO\n");

        if (ft_strlcat(dststrlcat4, srcstrlcat4, 1) == strlcat(dststrlcat41, srcstrlcat41, 1))
            ft_putstr("size_t   ft_strlcat   -> test4:   OK\n");
        else
            ft_putstr("size_t   ft_strlcat   -> test4:     KO\n");

        if (ft_strlcat(dststrlcat5, srcstrlcat5, 5) == strlcat(dststrlcat51, srcstrlcat51, 5))
            ft_putstr("size_t   ft_strlcat   -> test5:   OK\n");
        else
            ft_putstr("size_t   ft_strlcat   -> test5:     KO\n");

        if (ft_strlcat(dststrlcat6, srcstrlcat6, 8) == strlcat(dststrlcat61, srcstrlcat61, 8))
            ft_putstr("size_t   ft_strlcat   -> test6:   OK\n");
        else
            ft_putstr("size_t   ft_strlcat   -> test6:     KO\n");

        if (ft_strlcat(dststrlcat7, srcstrlcat7, 18) == strlcat(dststrlcat71, srcstrlcat71, 18))
            ft_putstr("size_t   ft_strlcat   -> test7:   OK\n");
        else
            ft_putstr("size_t   ft_strlcat   -> test7:     KO\n");
        // test strchr
        if (strcmp(strchr("_-=Ð’Ð»Ð°ÑÑ‚ÐµÐ»Ð¸Ð½ Ðº0Ð»ÐµÑ†=-_", '='), ft_strchr("_-=Ð’Ð»Ð°ÑÑ‚ÐµÐ»Ð¸Ð½ Ðº0Ð»ÐµÑ†=-_", '=')) == 0)
            ft_putstr("char     *ft_strchr   -> test1:   OK\n");
        else
            ft_putstr("char     *ft_strchr   -> test1:     KO\n");
        if (strcmp(strchr("_-=Ð’Ð»Ð°ÑÑ‚ÐµÐ»Ð¸Ð½ Ðº0Ð»ÐµÑ†=-_\0", '\0'), ft_strchr("_-=Ð’Ð»Ð°ÑÑ‚ÐµÐ»Ð¸Ð½ Ðº0Ð»ÐµÑ†=-_\0", '\0')) == 0)
            ft_putstr("char     *ft_strchr   -> test2:   OK\n");
        else
            ft_putstr("char     *ft_strchr   -> test2:     KO\n");

        // test strrchr
        if (strcmp(strrchr("_-=Ð’Ð»Ð°ÑÑ‚ÐµÐ»Ð¸Ð½ Ðº0Ð»ÐµÑ†=-_", '='), ft_strrchr("_-=Ð’Ð»Ð°ÑÑ‚ÐµÐ»Ð¸Ð½ Ðº0Ð»ÐµÑ†=-_", '=')) == 0)
            ft_putstr("char     *ft_strrchr  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_strrchr  -> test1:     KO\n");
        if (strcmp(strrchr("_-=Ð’Ð»Ð°ÑÑ‚ÐµÐ»Ð¸Ð½ Ðº0Ð»ÐµÑ†=-_\0", '\0'), ft_strrchr("_-=Ð’Ð»Ð°ÑÑ‚ÐµÐ»Ð¸Ð½ Ðº0Ð»ÐµÑ†=-_\0", '\0')) == 0)
            ft_putstr("char     *ft_strrchr  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_strrchr  -> test2:     KO\n");


        //test strstr
        char haystack1 []="0123456789";
        char needle1 []="345";
        char haystack2 []="0123456789";
        char needle2 []="453";
        char haystack3 []="0123456789";
        char needle3 []="";
        if (strcmp(ft_strstr(haystack1, needle1), strstr(haystack1, needle1)) == 0)
            ft_putstr("char     *ft_strstr   -> test1:   OK\n");
        else
            ft_putstr("char     *ft_strstr   -> test1:     KO\n");

        if (ft_strstr(haystack2, needle2) == 0 && strstr(haystack2, needle2) == 0)
            ft_putstr("char     *ft_strstr   -> test2:   OK\n");
        else
            ft_putstr("char     *ft_strstr   -> test2:     KO\n");
        if (strcmp(ft_strstr(haystack3, needle3), strstr(haystack3, needle3)) == 0)
            ft_putstr("char     *ft_strstr   -> test3:   OK\n");
        else
            ft_putstr("char     *ft_strstr   -> test3:     KO\n");

        //test strnstr
        char nhaystack1 []="0123456789";
        char nneedle1 []="345";
        char nhaystack2 []="0123456789";
        char nneedle2 []="453";
        char nhaystack3 []="0123456789";
        char nneedle3 []="";
        if (strcmp(ft_strnstr(nhaystack1, nneedle1, 21), strnstr(nhaystack1, nneedle1, 21)) == 0)
            ft_putstr("char     *ft_strnstr  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_strnstr  -> test1:     KO\n");
        if (ft_strnstr(nhaystack2, nneedle2, 1) == 0 && strnstr(nhaystack2, nneedle2, 1) == 0)
            ft_putstr("char     *ft_strnstr  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_strnstr  -> test2:     KO\n");
        if (strcmp(ft_strnstr(nhaystack3, nneedle3, 1), strnstr(nhaystack3, nneedle3, 1)) == 0)
            ft_putstr("char     *ft_strnstr  -> test3:   OK\n");
        else
            ft_putstr("char     *ft_strnstr  -> test3:     KO\n");

        //test strcmp
        char teststrcmp1[] = "";
        char teststrcmp2[] = "";
        char teststrcmp12[] = "TEST";
        char teststrcmp22[] = "TEST\0";
        char teststrcmp13[] = "TEST";
        char teststrcmp23[] = "test";
        char teststrcmp14[] = "";
        char teststrcmp24[] = "test";
        char teststrcmp15[] = "";
        char teststrcmp25[] = "test";
        if (ft_strcmp(teststrcmp1, teststrcmp2) == 0 && strcmp(teststrcmp1, teststrcmp2) == 0)
            ft_putstr("char     *ft_strcmp   -> test1:   OK\n");
        else
            ft_putstr("char     *ft_strcmp   -> test1:     KO\n");
        if (ft_strcmp(teststrcmp12, teststrcmp22) == 0 && strcmp(teststrcmp12, teststrcmp22) == 0)
            ft_putstr("char     *ft_strcmp   -> test2:   OK\n");
        else
            ft_putstr("char     *ft_strcmp   -> test2:     KO\n");
        if (ft_strcmp(teststrcmp13, teststrcmp23) != 0 && strcmp(teststrcmp13, teststrcmp23) != 0)
            ft_putstr("char     *ft_strcmp   -> test3:   OK\n");
        else
            ft_putstr("char     *ft_strcmp   -> test3:     KO\n");
        if (ft_strcmp(teststrcmp14, teststrcmp24) != 0 && strcmp(teststrcmp14, teststrcmp24) != 0)
            ft_putstr("char     *ft_strcmp   -> test4:   OK\n");
        else
            ft_putstr("char     *ft_strcmp   -> test4:     KO\n");
        if (ft_strcmp(teststrcmp15, teststrcmp25) != 0 && strcmp(teststrcmp15, teststrcmp25) != 0)
            ft_putstr("char     *ft_strcmp   -> test5:   OK\n");
        else
            ft_putstr("char     *ft_strcmp   -> test5:     KO\n");

        //test strncmp
        char teststrncmp1[] = "";
        char teststrncmp2[] = "";
        char teststrncmp12[] = "TEST";
        char teststrncmp22[] = "TEST\0";
        char teststrncmp13[] = "TEST";
        char teststrncmp23[] = "test";
        char teststrncmp14[] = "";
        char teststrncmp24[] = "test";
        char teststrncmp15[] = "";
        char teststrncmp25[] = "test";
        char teststrncmp16[] = "abc";
        char teststrncmp26[] = "abaaa";
        char teststrncmp17[] = "abc";
        char teststrncmp27[] = "bac";
        if (ft_strncmp(teststrncmp1, teststrncmp2, 11) == 0 && strncmp(teststrncmp1, teststrncmp2, 11) == 0)
            ft_putstr("char     *ft_strncmp  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_strncmp  -> test1:     KO\n");
        if (ft_strncmp(teststrncmp12, teststrncmp22, 6) == 0 && strncmp(teststrncmp12, teststrncmp22, 6) == 0)
            ft_putstr("char     *ft_strncmp  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_strncmp  -> test2:     KO\n");
        if (ft_strncmp(teststrncmp13, teststrncmp23, 2) != 0 && strncmp(teststrncmp13, teststrncmp23, 2) != 0)
            ft_putstr("char     *ft_strncmp  -> test3:   OK\n");
        else
            ft_putstr("char     *ft_strncmp  -> test3:     KO\n");
        if (ft_strncmp(teststrncmp14, teststrncmp24, 4) != 0 && strncmp(teststrncmp14, teststrncmp24, 4) != 0)
            ft_putstr("char     *ft_strncmp  -> test4:   OK\n");
        else
            ft_putstr("char     *ft_strncmp  -> test4:     KO\n");
        if (ft_strncmp(teststrncmp15, teststrncmp25, 3) != 0 && strncmp(teststrncmp15, teststrncmp25, 3) != 0)
            ft_putstr("char     *ft_strncmp  -> test5:   OK\n");
        else
            ft_putstr("char     *ft_strncmp  -> test5:     KO\n");
        if (ft_strncmp(teststrncmp16, teststrncmp26, 3) != 0 && strncmp(teststrncmp16, teststrncmp26, 3) != 0)
            ft_putstr("char     *ft_strncmp  -> test6:   OK\n");
        else
            ft_putstr("char     *ft_strncmp  -> test6:     KOn\n");
        if (ft_strncmp(teststrncmp17, teststrncmp27, 0) == 0 && strncmp(teststrncmp17, teststrncmp27, 0) == 0)
            ft_putstr("char     *ft_strncmp  -> test7:   OK\n");
        else
            ft_putstr("char     *ft_strncmp  -> test7:     KOn\n");


        //test atoi

        if (atoi("-2147483648") == ft_atoi("-2147483648"))
            ft_putstr("char     *ft_atoi     -> test1:   OK\n");
        else
            ft_putstr("char     *ft_atoi     -> test1:     KO\n");
        if (atoi("2147483647") == ft_atoi("2147483647"))
            ft_putstr("char     *ft_atoi     -> test2:   OK\n");
        else
            ft_putstr("char     *ft_atoi     -> test2:     KO\n");
        if (atoi("21474836479") == ft_atoi("21474836479"))
            ft_putstr("char     *ft_atoi     -> test3:   OK\n");
        else
            ft_putstr("char     *ft_atoi     -> test3:     KO\n");
        if (atoi("-121474836479") == ft_atoi("-121474836479"))
            ft_putstr("char     *ft_atoi     -> test4:   OK\n");
        else
            ft_putstr("char     *ft_atoi     -> test4:     KO\n");
        if (atoi("- 2147483648") == ft_atoi("- 2147483648"))
            ft_putstr("char     *ft_atoi     -> test5:   OK\n");
        else
            ft_putstr("char     *ft_atoi     -> test5:     KO\n");
        if (atoi("-+2147483648") == ft_atoi("-+2147483648"))
            ft_putstr("char     *ft_atoi     -> test6:   OK\n");
        else
            ft_putstr("char     *ft_atoi     -> test6:     KO\n");
        if (atoi("- +2147483648") == ft_atoi("- +2147483648"))
            ft_putstr("char     *ft_atoi     -> test7:   OK\n");
        else
            ft_putstr("char     *ft_atoi     -> test7:     KO\n");
        if (atoi("- -2147483648") == ft_atoi("- -2147483648"))
            ft_putstr("char     *ft_atoi     -> test8:   OK\n");
        else
            ft_putstr("char     *ft_atoi     -> test8:     KO\n");
        if (atoi(" - - ") == ft_atoi(" - - "))
            ft_putstr("char     *ft_atoi     -> test9:   OK\n");
        else
            ft_putstr("char     *ft_atoi     -> test9:     KO\n");
        if (atoi("0") == ft_atoi("0"))
            ft_putstr("char     *ft_atoi     -> test10:  OK\n");
        else
            ft_putstr("char     *ft_atoi     -> test10:    KO\n");
        if (atoi("-0") == ft_atoi("-0"))
            ft_putstr("char     *ft_atoi     -> test11:  OK\n");
        else
            ft_putstr("char     *ft_atoi     -> test11:    KO\n");


        // test isalpha
        if (ft_isalpha('\0') == isalpha('\0'))
            ft_putstr("char     *ft_isalpha  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_isalpha  -> test1:     KO\n");
        if (ft_isalpha('\0') != isalpha('a'))
            ft_putstr("char     *ft_isalpha  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_isalpha  -> test2:     KO\n");
        if (ft_isalpha('a') == isalpha('Z'))
            ft_putstr("char     *ft_isalpha  -> test3:   OK\n");
        else
            ft_putstr("char     *ft_isalpha  -> test3:     KO\n");
        if (ft_isalpha('Z') == isalpha('A'))
            ft_putstr("char     *ft_isalpha  -> test4:   OK\n");
        else
            ft_putstr("char     *ft_isalpha  -> test4:     KO\n");
        if (ft_isalpha('Z') == isalpha('Z'))
            ft_putstr("char     *ft_isalpha  -> test5:   OK\n");
        else
            ft_putstr("char     *ft_isalpha  -> test5:     KO\n");
        if (ft_isalpha('Z') != isalpha('1'))
            ft_putstr("char     *ft_isalpha  -> test6:   OK\n");
        else
            ft_putstr("char     *ft_isalpha  -> test6:     KO\n");
        if (ft_isalpha('Z') != isalpha('\222'))
            ft_putstr("char     *ft_isalpha  -> test7:   OK\n");
        else
            ft_putstr("char     *ft_isalpha  -> test7:     KO\n");
        if (ft_isalpha(-1) == isalpha('0'))
            ft_putstr("char     *ft_isalpha  -> test8:   OK\n");
        else
            ft_putstr("char     *ft_isalpha  -> test8:     KO\n");


        // test isdigit
        if (ft_isdigit('\0') == isdigit('\0'))
            ft_putstr("char     *ft_isdigit  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_isdigit  -> test1:     KO\n");

        if (ft_isdigit('1') == isdigit('0'))
            ft_putstr("char     *ft_isdigit  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_isdigit  -> test2:     KO\n");

        if (ft_isdigit(1) == isdigit(1))
            ft_putstr("char     *ft_isdigit  -> test3:   OK\n");
        else
            ft_putstr("char     *ft_isdigit  -> test3:     KO\n");

        if (ft_isdigit(-1) == isdigit(-1))
            ft_putstr("char     *ft_isdigit  -> test4:   OK\n");
        else
            ft_putstr("char     *ft_isdigit  -> test4:     KO\n");
        if (ft_isdigit('9') == isdigit('9'))
            ft_putstr("char     *ft_isdigit  -> test5:   OK\n");
        else
            ft_putstr("char     *ft_isdigit -> test5:     KO\n");

        // test isalnum
        if (ft_isalnum('\0') == isalnum('\0'))
            ft_putstr("char     *ft_isalnum  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_isalnum  -> test1:     KO\n");
        if (ft_isalnum('\0') != isalnum('a'))
            ft_putstr("char     *ft_isalnum  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_isalnum  -> test2:     KO\n");
        if (ft_isalnum('a') == isalnum('Z'))
            ft_putstr("char     *ft_isalnum  -> test3:   OK\n");
        else
            ft_putstr("char     *ft_isalnum  -> test3:     KO\n");
        if (ft_isalnum('Z') == isalnum('A'))
            ft_putstr("char     *ft_isalnum  -> test4:   OK\n");
        else
            ft_putstr("char     *ft_isalnum  -> test4:     KO\n");
        if (ft_isalnum('Z') == isalnum('Z'))
            ft_putstr("char     *ft_isalnum  -> test5:   OK\n");
        else
            ft_putstr("char     *ft_isalnum  -> test5:     KO\n");
        if (ft_isalnum('Z') == isalnum('1'))
            ft_putstr("char     *ft_isalnum  -> test6:   OK\n");
        else
            ft_putstr("char     *ft_isalnum  -> test6:     KO\n");
        if (ft_isalnum('Z') != isalnum('\222'))
            ft_putstr("char     *ft_isalnum  -> test7:   OK\n");
        else
            ft_putstr("char     *ft_isalnum  -> test7:     KO\n");
        if (ft_isalnum(-1) != isalnum('0'))
            ft_putstr("char     *ft_isalnum  -> test8:   OK\n");
        else
            ft_putstr("char     *ft_isalnum  -> test8:     KO\n");
        if (ft_isalnum('\0') == isalnum('\0'))
            ft_putstr("char     *ft_isalnum  -> test9:   OK\n");
        else
            ft_putstr("char     *ft_isalnum  -> test9:     KO\n");

        if (ft_isalnum('1') == isalnum('0'))
            ft_putstr("char     *ft_isalnum  -> test10:  OK\n");
        else
            ft_putstr("char     *ft_isalnum  -> test10:    KO\n");

        if (ft_isalnum(1) == isalnum(1))
            ft_putstr("char     *ft_isalnum  -> test11:  OK\n");
        else
            ft_putstr("char     *ft_isalnum  -> test11:    KO\n");

        if (ft_isalnum(-1) == isalnum(-1))
            ft_putstr("char     *ft_isalnum  -> test12:  OK\n");
        else
            ft_putstr("char     *ft_isalnum  -> test12:    KO\n");
        if (ft_isalnum('9') == isalnum('9'))
            ft_putstr("char     *ft_isalnum  -> test13:  OK\n");
        else
            ft_putstr("char     *ft_isalnum -> test13:    KO\n");

        // test isascii
        if (ft_isascii('\0') == isascii('\0'))
            ft_putstr("char     *ft_isascii  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_isascii  -> test1:     KO\n");
        if (ft_isascii('\0') == isascii('a'))
            ft_putstr("char     *ft_isascii  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_isascii  -> test2:     KO\n");
        if (ft_isascii('a') == isascii('Z'))
            ft_putstr("char     *ft_isascii  -> test3:   OK\n");
        else
            ft_putstr("char     *ft_isascii  -> test3:     KO\n");
        if (ft_isascii('Z') == isascii('A'))
            ft_putstr("char     *ft_isascii  -> test4:   OK\n");
        else
            ft_putstr("char     *ft_isascii  -> test4:     KO\n");
        if (ft_isascii('Z') == isascii('Z'))
            ft_putstr("char     *ft_isascii  -> test5:   OK\n");
        else
            ft_putstr("char     *ft_isascii  -> test5:     KO\n");
        if (ft_isascii('Z') == isascii('1'))
            ft_putstr("char     *ft_isascii  -> test6:   OK\n");
        else
            ft_putstr("char     *ft_isascii  -> test6:     KO\n");
        if (ft_isascii('Z') != isascii('\222'))
            ft_putstr("char     *ft_isascii  -> test7:   OK\n");
        else
            ft_putstr("char     *ft_isascii  -> test7:     KO\n");
        if (ft_isascii(-1) != isascii('0'))
            ft_putstr("char     *ft_isascii  -> test8:   OK\n");
        else
            ft_putstr("char     *ft_isascii  -> test8:     KO\n");

        // test isprint
        if (ft_isprint('\0') == isprint('\0'))
            ft_putstr("char     *ft_isprint  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_isprint  -> test1:     KO\n");
        if (ft_isprint('\0') != isprint('a'))
            ft_putstr("char     *ft_isprint  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_isprint  -> test2:     KO\n");
        if (ft_isprint('a') == isprint('Z'))
            ft_putstr("char     *ft_isprint  -> test3:   OK\n");
        else
            ft_putstr("char     *ft_isprint  -> test3:     KO\n");
        if (ft_isprint('Z') == isprint('A'))
            ft_putstr("char     *ft_isprint  -> test4:   OK\n");
        else
            ft_putstr("char     *ft_isprint  -> test4:     KO\n");
        if (ft_isprint(' ') != isprint('	'))
            ft_putstr("char     *ft_isprint  -> test5:   OK\n");
        else
            ft_putstr("char     *ft_isprint  -> test5:     KO\n");
        if (ft_isprint('Z') == isprint('1'))
            ft_putstr("char     *ft_isprint  -> test6:   OK\n");
        else
            ft_putstr("char     *ft_isprint  -> test6:     KO\n");
        if (ft_isprint('Z') != isprint('\222'))
            ft_putstr("char     *ft_isprint  -> test7:   OK\n");
        else
            ft_putstr("char     *ft_isprint  -> test7:     KO\n");
        if (ft_isprint(' ') == isprint('0'))
            ft_putstr("char     *ft_isprint  -> test8:   OK\n");
        else
            ft_putstr("char     *ft_isprint  -> test8:     KO\n");

        // test toupper
        if (ft_toupper('\0') == toupper('\0'))
            ft_putstr("char     *ft_toupper  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_toupper  -> test1:     KO\n");
        if (ft_toupper('\0') != toupper('a'))
            ft_putstr("char     *ft_toupper  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_toupper  -> test2:     KO\n");
        if (ft_toupper('a') == toupper('a'))
            ft_putstr("char     *ft_toupper  -> test3:   OK\n");
        else
            ft_putstr("char     *ft_toupper  -> test3:     KO\n");
        if (ft_toupper('Z') == toupper('Z'))
            ft_putstr("char     *ft_toupper  -> test4:   OK\n");
        else
            ft_putstr("char     *ft_toupper  -> test4:     KO\n");
        if (ft_toupper(' ') != toupper('	'))
            ft_putstr("char     *ft_toupper  -> test5:   OK\n");
        else
            ft_putstr("char     *ft_toupper  -> test5:     KO\n");
        if (ft_toupper('Z') != toupper('1'))
            ft_putstr("char     *ft_toupper  -> test6:   OK\n");
        else
            ft_putstr("char     *ft_toupper  -> test6:     KO\n");
        if (ft_toupper('Z') != toupper('\222'))
            ft_putstr("char     *ft_toupper  -> test7:   OK\n");
        else
            ft_putstr("char     *ft_toupper  -> test7:     KO\n");
        if (ft_toupper('a') == 'A')
            ft_putstr("char     *ft_toupper  -> test8:   OK\n");
        else
            ft_putstr("char     *ft_toupper  -> test8:     KO\n");
        if (ft_toupper('z') == 'Z')
            ft_putstr("char     *ft_toupper  -> test9:   OK\n");
        else
            ft_putstr("char     *ft_toupper  -> test9:     KO\n");

        // test tolower
        if (ft_tolower('\0') == tolower('\0'))
            ft_putstr("char     *ft_tolower  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_tolower  -> test1:     KO\n");
        if (ft_tolower('\0') != tolower('a'))
            ft_putstr("char     *ft_tolower  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_tolower  -> test2:     KO\n");
        if (ft_tolower('a') == tolower('a'))
            ft_putstr("char     *ft_tolower  -> test3:   OK\n");
        else
            ft_putstr("char     *ft_tolower  -> test3:     KO\n");
        if (ft_tolower('Z') == tolower('Z'))
            ft_putstr("char     *ft_tolower  -> test4:   OK\n");
        else
            ft_putstr("char     *ft_tolower  -> test4:     KO\n");
        if (ft_tolower(' ') != tolower('	'))
            ft_putstr("char     *ft_tolower  -> test5:   OK\n");
        else
            ft_putstr("char     *ft_tolower  -> test5:     KO\n");
        if (ft_tolower('Z') != tolower('1'))
            ft_putstr("char     *ft_tolower  -> test6:   OK\n");
        else
            ft_putstr("char     *ft_tolower  -> test6:     KO\n");
        if (ft_tolower('Z') != tolower('\222'))
            ft_putstr("char     *ft_tolower  -> test7:   OK\n");
        else
            ft_putstr("char     *ft_tolower  -> test7:     KO\n");
        if (ft_tolower('A') == 'a')
            ft_putstr("char     *ft_tolower  -> test8:   OK\n");
        else
            ft_putstr("char     *ft_tolower  -> test8:     KO\n");
        if (ft_tolower('Z') == 'z')
            ft_putstr("char     *ft_tolower  -> test9:   OK\n");
        else
            ft_putstr("char     *ft_tolower  -> test9:     KO\n");
    }

    // second part
    ft_putstr("\n ___________PART 2___________\n");
    int a = 0;
    /*
    if (argc == 1&& **argv)
    {


        //test ft_memalloc
        char *testftmemalloc1 = ft_memalloc(5);
        char *testftmemalloc2 = ft_memalloc(0);
        int a = 0;
        while (a != 4)
        {
            testftmemalloc1[a] = 'X';
            a++;
        }
        testftmemalloc1[a] = 0;
        if (strcmp(testftmemalloc1, "XXXX") == 0)
            ft_putstr("char     *ft_memalloc -> test1:   OK\n");
        else
            ft_putstr("char     *ft_memalloc -> test1:     KO\n");
        if (testftmemalloc2 == NULL)
            ft_putstr("char     *ft_memalloc -> test2:   OK\n");
        else
            ft_putstr("char     *ft_memalloc -> test2:     KO\n");

        // test ft_memdel
        char *ap;
        ap = ft_memalloc(5);
        ap[0] = '0';
        ap[1] = '1';
        ap[2] = '2';
        ap[3] = '3';
        ap[4] = 0;
        ft_memdel((void**)ap);
        char *app;
        app = ft_memalloc(5);
        app[0] = 'z';
        app[1] = 'z';
        app[2] = 'z';
        app[3] = 'z';
        app[4] = 0;
        if (strcmp(ap, app) == 0)
            ft_putstr("char     *ft_memdel   -> test1:   OK\n");
        else
            ft_putstr("char     *ft_memdel   -> test1:     KO\n");
        ft_memdel((void**)app);
        if (app[0] == 0 && app[0] == 0)
            ft_putstr("char     *ft_memdel   -> test2:   OK\n");
        else
            ft_putstr("char     *ft_memdel   -> test2:     KO\n");

        */
        // test ft_strnew
        char *strnew;
        strnew = ft_strnew(5);
        a = 0;
        while (strnew[a] == '\0' && a != 6)
            a++;

        if (a == 6)
            ft_putstr("char     *ft_strnew   -> test1:   OK\n");
        else
            ft_putstr("char     *ft_strnew   -> test1:     KO\n");
        if (ft_strnew(0) == NULL)
            ft_putstr("char     *ft_strnew   -> test2:   OK\n");
        else
            ft_putstr("char     *ft_strnew   -> test2:     KO\n");

        // test ft_strdel
        ft_strdel((void*)&strnew);
        if (strnew == NULL)
            ft_putstr("char     *ft_strnew   -> test3:   OK\n");
        else
            ft_putstr("char     *ft_strnew   -> test3:     KO\n");


        // test ft_strclr
        char strclr[] = "012345678";
        ft_strclr(strclr);
        a = 0;
        while (strclr[a] == '\0' && a != 10)
            a++;
        if (a == 10)
            ft_putstr("char     *ft_strclr   -> test:    OK\n");
        else
            ft_putstr("char     *ft_strclr   -> test:      KO\n");

        //test ft_striter
        char striter[] = "akjlfjgrjldfgfg";
        ft_striter(striter, &striter_test);
        if (strcmp(striter,"---------------") == 0)
            ft_putstr("char     *ft_striter  -> test:    OK\n");
        else
            ft_putstr("char     *ft_striter  -> test:      KO\n");

        //test ft_striteri
        char striteri[] = "akjlfjgrjldfgfg";
        ft_striteri(striteri, &striteri_test);
        if (strcmp(striteri,"-k-l-j-r-l-f-f-") == 0)
            ft_putstr("char     *ft_striteri -> test:    OK\n");
        else
            ft_putstr("char     *ft_striteri -> test:      KO\n");

        //test ft_strmap
        char strmap[] = "akjlfjgrjldfgfg";
        char *strmapt;
        strmapt = ft_strmap(strmap, &strmap_test);
        if (strcmp(strmapt,"---------------") == 0)
            ft_putstr("char     *ft_strmap   -> test:    OK\n");
        else
            ft_putstr("char     *ft_strmap   -> test:      KO\n");

        //test ft_strmapi
        char strmapi[] = "akjlfjgrjldfgfg";
        char *strmapit;
        strmapit = ft_strmapi(strmapi, &strmapi_test);
        if (strcmp(strmapit,"-k-l-j-r-l-f-f-") == 0)
            ft_putstr("char     *ft_strmapi  -> test:    OK\n");
        else
            ft_putstr("char     *ft_strmapi  -> test:      KO\n");

        //test ft_strequ
        char strequ1[] = "";
        char strequ2[] = "";
        char strequ12[] = "TEST";
        char strequ22[] = "TEST\0";
        char strequ13[] = "TEST";
        char strequ23[] = "test";
        char strequ14[] = "";
        char strequ24[] = "test";
        char strequ15[] = "";
        char strequ25[] = "test";
        if (ft_strequ(strequ1, strequ2) == 1 && strcmp(strequ1, strequ2) == 0)
            ft_putstr("char     *ft_strequ   -> test1:   OK\n");
        else
            ft_putstr("char     *ft_strequ   -> test1:     KO\n");
        if (ft_strequ(strequ12, strequ22) == 1 && strcmp(strequ12, strequ22) == 0)
            ft_putstr("char     *ft_strequ   -> test2:   OK\n");
        else
            ft_putstr("char     *ft_strequ   -> test2:     KO\n");
        if (ft_strequ(strequ13, strequ23) == 0 && strcmp(strequ13, strequ23) != 0)
            ft_putstr("char     *ft_strequ   -> test3:   OK\n");
        else
            ft_putstr("char     *ft_strequ   -> test3:     KO\n");
        if (ft_strequ(strequ14, strequ24) == 0 && strcmp(strequ14, strequ24) != 0)
            ft_putstr("char     *ft_strequ   -> test4:   OK\n");
        else
            ft_putstr("char     *ft_strequ   -> test4:     KO\n");
        if (ft_strequ(strequ15, strequ25) == 0 && strcmp(strequ15, strequ25) != 0)
            ft_putstr("char     *ft_strequ   -> test5:   OK\n");
        else
            ft_putstr("char     *ft_strequ   -> test5:     KO\n");

        //test ft_strnequ
        char strnequ1[] = "";
        char strnequ2[] = "";
        char strnequ12[] = "TEST";
        char strnequ22[] = "TEST\0";
        char strnequ13[] = "TEST";
        char strnequ23[] = "test";
        char strnequ14[] = "";
        char strnequ24[] = "test";
        char strnequ15[] = "";
        char strnequ25[] = "test";
        char strnequ16[] = "abc";
        char strnequ26[] = "abaaa";
        char strnequ17[] = "abc";
        char strnequ27[] = "bac";
        if (ft_strnequ(strnequ1, strnequ2, 11) == 1 && strncmp(strnequ1, strnequ2, 11) == 0)
            ft_putstr("char     *ft_strnequ  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_strnequ  -> test1:     KO\n");
        if (ft_strnequ(strnequ12, strnequ22, 6) == 1 && strncmp(strnequ12, strnequ22, 6) == 0)
            ft_putstr("char     *ft_strnequ  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_strnequ  -> test2:     KO\n");
        if (ft_strnequ(strnequ13, strnequ23, 2) == 0 && strncmp(strnequ13, strnequ23, 2) != 0)
            ft_putstr("char     *ft_strnequ  -> test3:   OK\n");
        else
            ft_putstr("char     *ft_strnequ  -> test3:     KO\n");
        if (ft_strnequ(strnequ14, strnequ24, 4) == 0 && strncmp(strnequ14, strnequ24, 4) != 0)
            ft_putstr("char     *ft_strnequ  -> test4:   OK\n");
        else
            ft_putstr("char     *ft_strnequ  -> test4:     KO\n");
        if (ft_strnequ(strnequ15, strnequ25, 3) == 0 && strncmp(strnequ15, strnequ25, 3) != 0)
            ft_putstr("char     *ft_strnequ  -> test5:   OK\n");
        else
            ft_putstr("char     *ft_strnequ  -> test5:     KO\n");
        if (ft_strnequ(strnequ16, strnequ26, 3) == 0 && strncmp(strnequ16, strnequ26, 3) != 0)
            ft_putstr("char     *ft_strnequ  -> test6:   OK\n");
        else
            ft_putstr("char     *ft_strnequ  -> test6:     KOn\n");
        if (ft_strnequ(strnequ17, strnequ27, 0) == 1 && strncmp(strnequ17, strnequ27, 0) == 0)
            ft_putstr("char     *ft_strnequ  -> test7:   OK\n");
        else
            ft_putstr("char     *ft_strnequ  -> test7:     KOn\n");

        //test ft_strsub
        char strsub1[] = "Test String\0";
        char *substr1;
        char strsub12[] = "Tost Strong\0";
        char *substr12;
        char strsub13[] = "z\0";
        char *substr13;
        substr1 = ft_strsub(strsub1, 5, 6);
        if (strcmp(ft_strsub(strsub1, 5, 6), &strsub1[5]) == 0)
            ft_putstr("char     *ft_strsub   -> test1:   OK\n");
        else
            ft_putstr("char     *ft_strsub   -> test1:     KO\n");
        substr12 = ft_strsub(strsub12, 0, 11);
        if (strcmp(ft_strsub(strsub12, 0, 11), &strsub12[0]) == 0)
            ft_putstr("char     *ft_strsub   -> test2:   OK\n");
        else
            ft_putstr("char     *ft_strsub   -> test2:     KO\n");
        substr13 = ft_strsub(strsub13, 0, 1);
        if (strcmp(ft_strsub(strsub13, 0, 1), &strsub13[0]) == 0)
            ft_putstr("char     *ft_strsub   -> test3:   OK\n");
        else
            ft_putstr("char     *ft_strsub   -> test3:     KO\n");
        if (strcmp(ft_strsub(strsub13, 1, 1), &strsub13[1]) == 0)
            ft_putstr("char     *ft_strsub   -> test4:   OK\n");
        else
            ft_putstr("char     *ft_strsub   -> test4:     KO\n");
        if (ft_strsub(strsub13, 1, 220) == 0)
            ft_putstr("char     *ft_strsub   -> test4:   OK\n");
        else
            ft_putstr("char     *ft_strsub   -> test4:     KO\n");

        // test ft_strjoin
        if (strcmp(ft_strjoin("Test", "String"), "TestString") == 0)
            ft_putstr("char     *ft_strjoin  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_strjoin  -> test1:     KO\n");
        if (ft_strjoin("\0", "\0") == 0)
            ft_putstr("char     *ft_strjoin  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_strjoin  -> test2:     KO\n");
        if (strcmp(ft_strjoin("", "Test String"), "Test String") == 0)
            ft_putstr("char     *ft_strjoin  -> test3:   OK\n");
        else
            ft_putstr("char     *ft_strjoin  -> test3:     KO\n");
        if (strcmp(ft_strjoin("Test", ""), "Test\0") == 0)
            ft_putstr("char     *ft_strjoin  -> test4:   OK\n");
        else
            ft_putstr("char     *ft_strjoin  -> test4:     KO\n");
        if (strcmp(ft_strjoin("Test\0", "\0"), "Test\0") == 0)
            ft_putstr("char     *ft_strjoin  -> test5:   OK\n");
        else
            ft_putstr("char     *ft_strjoin  -> test5:     KO\n");
        // test ft_strtrim
        if (strcmp(ft_strtrim("                "), "") == 0)
            ft_putstr("char     *ft_strtrim  -> test1:   OK\n");
        else
            ft_putstr("char     *ft_strtrim  -> test1:     KO\n");
        if (strcmp(ft_strtrim("        2 \t \n        "), "2") == 0)
            ft_putstr("char     *ft_strtrim  -> test2:   OK\n");
        else
            ft_putstr("char     *ft_strtrim  -> test2:     KO\n");
        if (strcmp(ft_strtrim("3   \n     2          "), "3   \n     2") == 0)
            ft_putstr("char     *ft_strtrim  -> test3:   OK\n");
        else
            ft_putstr("char     *ft_strtrim  -> test3:     KO\n");
        if (strcmp(ft_strtrim("3        2           4"), "3        2           4") == 0)
            ft_putstr("char     *ft_strtrim  -> test4:   OK\n");
        else
            ft_putstr("char     *ft_strtrim  -> test4:     KO\n");
        if (strcmp(ft_strtrim("3        2        45  "), "3        2        45") == 0)
            ft_putstr("char     *ft_strtrim  -> test5:   OK\n");
        else
            ft_putstr("char     *ft_strtrim  -> test5:     KO\n");
        if (strcmp(ft_strtrim(""), "") == 0)
            ft_putstr("char     *ft_strtrim  -> test6:   OK\n");
        else
            ft_putstr("char     *ft_strtrim  -> test6:     KO\n");
        if (strcmp(ft_strtrim("\n \t"), "") == 0)
            ft_putstr("char     *ft_strtrim  -> test7:   OK\n");
        else
            ft_putstr("char     *ft_strtrim  -> test7:     KO\n");
        // test ft_strsplit
        char **newstrsplit;
        newstrsplit = ft_strsplit("***", '\0');
        if ((strcmp(newstrsplit[0], "***") == 0) && (newstrsplit[1] == NULL))
            ft_putstr("char     *t_strsplit  -> test1:   OK\n");
        else
            ft_putstr("char     *t_strsplit  -> test1:     KO\n");
        char **newstrsplit1;
        newstrsplit1 = ft_strsplit("***", '*');
        if (newstrsplit1[0] == NULL)
            ft_putstr("char     *t_strsplit  -> test2:   OK\n");
        else
            ft_putstr("char     *t_strsplit  -> test2:     KO\n");
        char **newstrsplit2;
        newstrsplit2 = ft_strsplit("*1*2*", '*');
        if ((strcmp(newstrsplit2[0], "1") == 0) && (strcmp(newstrsplit2[1], "2") == 0) && (newstrsplit2[2] == NULL))
            ft_putstr("char     *t_strsplit  -> test3:   OK\n");
        else
            ft_putstr("char     *t_strsplit  -> test3:     KO\n");
        char **newstrsplit3;
        newstrsplit3 = ft_strsplit("1*****2", '*');
        if ((strcmp(newstrsplit3[0], "1") == 0) && (strcmp(newstrsplit3[1], "2") == 0) && (newstrsplit3[2] == NULL))
            ft_putstr("char     *t_strsplit  -> test3:   OK\n");
        else
            ft_putstr("char     *t_strsplit  -> test3:     KO\n");
        char **newstrsplit4;
        newstrsplit4 = ft_strsplit("1*****2", '\0');
        if ((strcmp(newstrsplit4[0], "1*****2") == 0) && (newstrsplit4[1] == NULL))
            ft_putstr("char     *t_strsplit  -> test4:   OK\n");
        else
            ft_putstr("char     *t_strsplit  -> test4:     KO\n");
        char **newstrsplit5;
        newstrsplit5 = ft_strsplit("1*****2", ' ');
        if ((strcmp(newstrsplit5[0], "1*****2") == 0) && (newstrsplit5[1] == NULL))
            ft_putstr("char     *t_strsplit  -> test5:   OK\n");
        else
            ft_putstr("char     *t_strsplit  -> test5:     KO\n");
        // test ft_itoa
        if (strcmp(ft_itoa(-2147483648), "-2147483648") == 0)
            ft_putstr("char     *ft_itoa     -> test1:   OK\n");
        else
            ft_putstr("char     *ft_itoa     -> test1:     KO\n");
        if (strcmp(ft_itoa(2147483647), "2147483647") == 0)
            ft_putstr("char     *ft_itoa     -> test2:   OK\n");
        else
            ft_putstr("char     *ft_itoa     -> test2:     KO\n");
        if (strcmp(ft_itoa(-0), "0") == 0)
            ft_putstr("char     *ft_itoa     -> test3:   OK\n");
        else
            ft_putstr("char     *ft_itoa     -> test3:     KO\n");

        // test ft_putchar
        char *putchar = "void     *ft_putchar  -> test:    OK\n\0";
        while (*putchar)
        {
            ft_putchar(*putchar);
            putchar++;
        }

        // test ft_putstr(char *str)
        ft_putstr("void     *ft_putstr   -> test:    OK\n");

    return (0);
}



    // printf("%s\n", newstrsplit[1]);
    // printf("%s\n", newstrsplit[2]);
    // printf("%s\n", newstrsplit[3]);
    // printf("%s\n", newstrsplit[4]);
    // printf("%s\n", newstrsplit[5]);
    // printf("%s\n", newstrsplit[6]);
    // printf("%s\n", newstrsplit[7]);
    // printf("%s\n", newstrsplit[8]);
    // printf("%s\n", newstrsplit[9]);

    // printf("%s\n", newstrsplit[1]);
    //
    // printf("or: 9223372036854775807 %d\n",     atoi("	\t \r \v \n \f    9223372036854775807"));
    // printf("or: -9223372036854775807 %d\n",   atoi("-9223372036854775807"));
    // printf("or: 9223372036854775808 %d\n",     atoi("9223372036854775808"));
    // printf("or: -9223372036854775808 %d\n",   atoi("-9223372036854775808"));
    // printf("or: 9223372036854775809 %d\n",     atoi("9223372036854775809"));
    // printf("or: -9223372036854775809 %d\n",   atoi("-9223372036854775809"));
    // printf("or: 9223372036854775809 %d\n",     atoi("9223372036854775809"));
    // printf("or: 9223372036854775810 %d\n",     atoi("9223372036854775810"));
    // printf("or: 0000009223372036854775810 %d\n",     atoi("0000009223372036854775810"));
    // printf("\n");
    // printf("ft: 9223372036854775807 %d\n",  ft_atoi("	\t \r \v \n \f    9223372036854775807"));
    // printf("ft: -9223372036854775807 %d\n",ft_atoi("-9223372036854775807"));
    // printf("ft: 9223372036854775808 %d\n",  ft_atoi("9223372036854775808"));
    // printf("ft: -9223372036854775808 %d\n",ft_atoi("-9223372036854775808"));
    // printf("ft: 9223372036854775809 %d\n",  ft_atoi("9223372036854775809"));
    // printf("ft: -9223372036854775809 %d\n",ft_atoi("-9223372036854775809"));
    // printf("ft: 9223372036854775809 %d\n",  ft_atoi("9223372036854775809"));
    // printf("ft: 9223372036854775810 %d\n",  ft_atoi("9223372036854775810"));
    // printf("ft: 0000009223372036854775810 %d\n",  ft_atoi("0000009223372036854775810"));



// char testmemmove1[] = "abcdefgjklmnoprstq\0";
// char *testmemmove2;

// testmemmove2 = &testmemmove1[5];
// printf("o1: %s\no2: %s\n", testmemmove1, testmemmove2);
// memcpy(testmemmove2, testmemmove1, 10);
// printf("o1: %s\no2: %s\n", testmemmove1, testmemmove2);

// char testmemmove12[] = "abcdefgjklmnoprstq\0";
// char *testmemmove22;

// testmemmove22 = &testmemmove12[5];
// printf("m1: %s\nm2: %s\n", testmemmove12, testmemmove22);
// ft_memcpy(testmemmove22, testmemmove12, 10);
// printf("m1: %s\nm2: %s\n", testmemmove12, testmemmove22);
