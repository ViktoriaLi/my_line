/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:21:37 by nkolosov          #+#    #+#             */
/*   Updated: 2017/12/04 15:50:07 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <libc.h>

/*
 ** gcc -Wall -Wextra -Werror -o e -L. -lft main.c
 */

static int kk;

void	prnt_c(int *c)
{
    if (*c == 0)
        printf("\x1b[32m""   OK.\n""\x1b[0m");
    else
        printf("\x1b[31m""   KO:(\n""\x1b[0m");
    *c = 0;
}

void	print_test_name(char *name)
{
    printf(" =================\\\\ [%s]\n", name);
}

void	print_skip(void)
{
    printf("\x1b[32m"" --- SKIP --- \n""\x1b[0m");
}

void	print_none(void)
{
    printf("\x1b[35m"" --- NO TEST YET --- \n""\x1b[0m");
}

void	print_string_arr(char **ar)
{
    int i;
    
    i = 0;
    if (!(*ar))
        return ;
    while (ar[i])
    {
        printf("  %s\n", ar[i]);
        i++;
    }
}

int		ft_atoi_check(char *test)
{
    if (ft_atoi(test) != atoi(test))
    {
        printf("[Test fail \"%s\"]\n", test);
        printf(" > My  %d\n", ft_atoi(test));
        printf(" > Lib %d\n", atoi(test));
        return (1);
    }
    return (0);
}

int		ft_itoa_check(int n, const char *ans)
{
    char *res;
    
    res = ft_itoa(n);
    if (strcmp((const char*)res, ans) != 0)
    {
        printf("[Test fail %d]\n", n);
        printf(" > My  %s\n", res);
        printf(" > Cor %s\n", ans);
        return (1);
    }
    return (0);
}

void	ft_strsplit_check(char *test, char s)
{
    printf(" ------\n  Try \"%s\" split by'%c'\n", test, s);
    print_string_arr(ft_strsplit(test, s));
}

void	ft_putnbr_check(int num)
{
    printf(" ------\n  Try %d\n", num);
    ft_putstr("  ");
    ft_putnbr(num);
    ft_putchar('\n');
}

void	ft_putstr_check(char *test)
{
    printf(" ------\n  Try \"%s\"\n", test);
    ft_putstr("  ");
    ft_putstr(test);
    ft_putchar('\n');
}

void	ft_putendl_check(char *test)
{
    printf(" ------\n  Try \"%s\"\n", test);
    ft_putstr("  ");
    ft_putendl(test);
    ft_putchar('\n');
}

int		ft_strlen_check(const char *test)
{
    if (ft_strlen(test) != strlen(test))
    {
        printf("[Test fail \"%s\"]\n", test);
        printf(" > My  %zu\n", ft_strlen(test));
        printf(" > Lib %lu\n", strlen(test));
        return (1);
    }
    return (0);
}

int		ft_strdup_check(const char *test)
{
    char	*str1;
    char	*str2;
    
    str1 = ft_strdup(test);
    if (!str1)
    {
        printf("[Probably malloc failure]\n");
        return (1);
    }
    str2 = strdup(test);
    if (strcmp((const char*)str1, (const char*)str2) != 0)
    {
        printf("[Test fail \"%s\"]\n", test);
        printf(" > My  %s\n", str1);
        printf(" > Lib %s\n", str2);
        return (1);
    }
    return (0);
}

int		ft_strchr_check(const char *test, char s)
{
    char	*str1;
    char	*str2;
    
    str1 = ft_strchr(test, s);
    str2 = ft_strchr(test, s);
    if (strcmp((const char*)str1, (const char*)str2) != 0)
    {
        printf("[Test fail \"%s\", %c]\n", test, s);
        printf(" > My  %s\n", str1);
        printf(" > Lib %s\n", str2);
        return (1);
    }
    return (0);
}

int		ft_strcpy_check(const char *test)
{
    char	*str1;
    char	*str2;
    
    str1 = (char*)malloc(sizeof(char) * (strlen(test) + 1));
    str2 = (char*)malloc(sizeof(char) * (strlen(test) + 1));
    str1 = ft_strcpy(str1, test);
    str2 = strcpy(str2, test);
    if (strcmp((const char*)str1, (const char*)str2) != 0)
    {
        printf("[Test fail \"%s\"]\n", test);
        printf(" > My  %s\n", str1);
        printf(" > Lib %s\n", str2);
        return (1);
    }
    return (0);
}

int		ft_strncpy_check(const char *test, size_t len)
{
    (void)test;
    (void)len;
    return (0);
}

int		ft_strstr_check(const char *big, const char *small)
{
    char	*ptr1;
    char	*ptr2;
    
    ptr1 = ft_strstr(big, small);
    ptr2 = strstr(big, small);
    if ((ptr1 && !ptr2) || (ptr2 && !ptr1))
    {
        printf("[Test fail \"%s\" , \"%s\"", big, small);
        printf(". One of the results is equal to NULL when the other one is not]\n");
        if (!ptr1)
        {
            printf(" > My is NULL\n");
            printf(" > Lib str is %s\n", ptr2);
        }
        else
        {
            printf(" > My str is %s\n", ptr1);
            printf(" > Lib is NULL\n");
        }
        return (1);
    }
    else if ((!ptr1) && (!ptr2))
        return (0);
    else if (strcmp((const char*)ptr1, (const char*)ptr2) != 0)
    {
        printf("[Test fail \"%s\" , \"%s\". Strings: \"%s\" , \"%s\"]\n", big, small, ptr1, ptr2);
        return (1);
    }
    return (0);
}

int		ft_strnstr_check(const char *big, const char *small, size_t len)
{
    char	*ptr1;
    char	*ptr2;
    
    ptr1 = ft_strnstr(big, small, len);
    ptr2 = strnstr(big, small, len);
    if ((ptr1 && !ptr2) || (ptr2 && !ptr1))
    {
        printf("[Test fail \"%s\" , \"%s\", %zu", big, small, len);
        printf(". One of the results is equal to NULL when the other one is not]\n");
        if (!ptr1)
        {
            printf(" > My is NULL\n");
            printf(" > Lib str is %s\n", ptr2);
        }
        else
        {
            printf(" > My str is %s\n", ptr1);
            printf(" > Lib is NULL\n");
        }
        return (1);
    }
    else if ((!ptr1) && (!ptr2))
        return (0);
    else if (strcmp((const char*)ptr1, (const char*)ptr2) != 0)
    {
        printf("[Test fail \"%s\" , \"%s\", %zu. Strings: \"%s\" , \"%s\"]\n", big, small, len, ptr1, ptr2);
        return (1);
    }
    return (0);
}

int		ft_strcat_check(const char *test)
{
    char	buff1[20] = "hi there hey ho";
    char	buff2[20] = "hi there hey ho";
    char	*s1;
    char	*s2;
    
    s1 = strcat(buff1, test);
    s2 = ft_strcat(buff2, test);
    if (strcmp((const char*)s1, (const char*)s2) != 0)
    {
        printf("[Test fail \"%s\" , \"%s\".\n Strings: \"%s\" , \"%s\"]\n", buff1, test, s1, s2);
        return (1);
    }
    return (0);
}

int		ft_strncat_check(const char *test, size_t n)
{
    char	buff1[20] = "hi there hey ho";
    char	buff2[20] = "hi there hey ho";
    char	*s1;
    char	*s2;
    
    s1 = strncat(buff1, test, n);
    s2 = ft_strncat(buff2, test, n);
    if (strcmp((const char*)s1, (const char*)s2) != 0)
    {
        printf("[Test fail \"%s\" , \"%s\", %zu.\n Strings: \"%s\" , \"%s\"]\n", buff1, test, n, s1, s2);
        return (1);
    }
    return (0);
}

int		ft_strequ_check(char const *s1, char const *s2)
{
    if (strcmp(s1, s2) == 0 && ft_strequ(s1, s2) == 1)
        return (0);
    if (strcmp(s1, s2) != 0 && ft_strequ(s1, s2) == 0)
        return (0);
    printf("[Test fail \"%s\" , \"%s\"]\n", s1, s2);
    return (1);
}

int		ft_strnequ_check(char const *s1, char const *s2, size_t n)
{
    if (strncmp(s1, s2, n) == 0 && ft_strnequ(s1, s2, n) == 1)
        return (0);
    if (strncmp(s1, s2, n) != 0 && ft_strnequ(s1, s2, n) == 0)
        return (0);
    printf("[Test fail \"%s\" , \"%s\" , %zu]\n", s1, s2, n);
    return (1);
}

int		ft_isalpha_check(int n)
{
    if (ft_isalpha(n) == isalpha(n))
        return (0);
    printf("[Test fail %d My : %d | Lib : %d]\n", n, ft_isalpha(n), isalpha(n));
    return (1);
}

int		ft_isdigit_check(int n)
{
    if (ft_isdigit(n) == isdigit(n))
        return (0);
    printf("[Test fail %d My : %d | Lib : %d]\n", n, ft_isdigit(n), isdigit(n));
    return (1);
}

int		ft_isalnum_check(int n)
{
    if (ft_isalnum(n) == isalnum(n))
        return (0);
    printf("[Test fail %d My : %d | Lib : %d]\n", n, ft_isalnum(n), isalnum(n));
    return (1);
}

int		ft_isascii_check(int n)
{
    if (ft_isascii(n) == isascii(n))
        return (0);
    printf("[Test fail %d My : %d | Lib : %d]\n", n, ft_isascii(n), isascii(n));
    return (1);
}

int		ft_isprint_check(int n)
{
    if (ft_isprint(n) == isprint(n))
        return (0);
    printf("[Test fail %d My : %d | Lib : %d]\n", n, ft_isprint(n), isprint(n));
    return (1);
}

int		ft_toupper_check(int n)
{
    if (ft_toupper(n) == toupper(n))
        return (0);
    printf("[Test fail %d My : %d | Lib : %d]\n", n, ft_toupper(n), toupper(n));
    return (1);
}

int		ft_tolower_check(int n)
{
    if (ft_tolower(n) == tolower(n))
        return (0);
    printf("[Test fail %d My : %d | Lib : %d]\n", n, ft_tolower(n), tolower(n));
    return (1);
}

int		ft_strtrim_check(char const *test, char const *ans)
{
    char *res;
    
    res = ft_strtrim(test);
    if (strcmp((const char*)res, ans) != 0)
    {
        printf("[Test fail \"%s\"]\n", test);
        printf(" > My  %s\n", res);
        printf(" > Cor %s\n", ans);
        return (1);
    }
    return (0);
}

int		ft_strjoin_check(char const *test1, char const *test2, char const *ans)
{
    char *res;
    
    res = ft_strjoin(test1, test2);
    if (strcmp(res, ans) != 0)
    {
        printf("[Test fail \"%s\" + \"%s\"]\n", test1, test2);
        printf(" > My  %s\n", res);
        printf(" > Cor %s\n", ans);
        return (1);
    }
    return (0);
}

int		ft_strsub_check(char const *test, unsigned int start, size_t len, char const *ans)
{
    char *res;
    
    res = ft_strsub(test, start, len);
    if (strcmp((const char*)res, ans) != 0)
    {
        printf("[Test fail \"%s\" subtring at %d of length %zu]\n", test, start, len);
        printf(" > My  %s\n", res);
        printf(" > Cor %s\n", ans);
        return (1);
    }
    return (0);
}

int		ft_strcmp_check(char const *s1, char const *s2)
{
    if (ft_strcmp(s1, s2) != strcmp(s1, s2))
    {
        printf("[Test fail \"%s\", \"%s\"]\n", s1, s2);
        printf(" > My  %d\n", ft_strcmp(s1, s2));
        printf(" > Lib %d\n", strcmp(s1, s2));
        return (1);
    }
    return (0);
}

int		ft_strncmp_check(char const *s1, char const *s2, size_t n)
{
    if (ft_strncmp(s1, s2, n) != strncmp(s1, s2, n))
    {
        printf("[Test fail \"%s\", \"%s\", %zu]\n", s1, s2, n);
        printf(" > My  %d\n", ft_strncmp(s1, s2, n));
        printf(" > Lib %d\n", strncmp(s1, s2, n));
        return (1);
    }
    return (0);
}

char	toup(char c)
{
    return((char)toupper(c));
}

char	toup2(unsigned int i, char c)
{
    if (i % 2 == 1)
        return((char)toupper(c));
    return (c);
}

void	iter_test(char *c)
{
    *c = *c + 1;
}

void	iteri_test(unsigned int i, char *c)
{
    if (i % 2 == 1)
        *c = *c + 1;
}

int		ft_strmap_check(char const *s)
{
    char	*ans;
    int		i;
    
    ans = ft_strmap(s, &toup);
    i = -1;
    if (!s && !ans)
        return (0);
    while (ans[++i])
        if (ans[i] >= 'a' && ans[i] <= 'z')
        {
            printf("[Test fail \"%s\"]\n", s);
            printf(" > My  %s\n", ans);
            return (1);
        }
    return (0);
}

int		ft_strmapi_check(char const *s)
{
    char	*ans;
    int		i;
    
    ans = ft_strmap(s, &toup);
    i = -1;
    if (!s && !ans)
        return (0);
    while (ans[++i])
        if (i % 2 == 1 && ans[i] >= 'a' && ans[i] <= 'z')
        {
            printf("[Test fail \"%s\"]\n", s);
            printf(" > My  %s\n", ans);
            return (1);
        }
    return (0);
}

void	del_test(void *data, size_t i)
{
    (void)data;
    (void)i;
    kk++;
}

void	list_iter_func(t_list *elem)
{
    int		num;
    
    num = *(int*)elem->content;
    num += 5;
    elem->content = ft_memalloc(elem->content_size);
    elem->content = ft_memcpy(elem->content, (void const *)&num, elem->content_size);
}

t_list	*list_map_func(t_list *elem)
{
    int		num;
    t_list	*ans;
    
    num = *(int*)elem->content;
    num -= 3;
    ans = ft_lstnew(&num, sizeof(num));
    return (ans);
}

int		main(void)
{
    int		c;
    char	*s1;
    int		i;
    int		is_correct;
    void	*mem1;
    void	*mem2;
    
    c = 0;
    printf("\x1b[31m""\n||============================================================||\n");
    printf("||====================== LIBFT   TESTING =====================||\n");
    printf("||============================================================||\n\n""\x1b[0m");
    printf("\x1b[36m""\n||====================== MANDATORY  PART =====================||\n\n""\x1b[0m");
    print_test_name("01. ft_memset");
    {
        char	b1[100];
        ft_memset(b1, 42, 100);
        prnt_c(&c);
    }
    print_test_name("02. ft_bzero");
    {
        char	s[] = "123456789";
        
        ft_bzero(s, 10);
        prnt_c(&c);
    }
    print_test_name("03. ft_memcpy");
    {
        char	b1[100], b2[100];
        
        memset(b1, 33, 100);
        memset(b2, 63, 100);
        
        ft_memcpy(b1, b2, 100);
        prnt_c(&c);
    }
    print_test_name("04. ft_memccpy");
    {
        char	buf1[] = "1234 123 12 1234.";
        char	buf2[200];
        void	*p1;
        
        p1 = ft_memccpy(buf2, buf1, 'i', 10);
        prnt_c(&c);
    }
    print_test_name("05. ft_memmove");
    {
        char	testA1[] = "abcdef";
        
        ft_memmove(testA1 + 1, testA1, 5);
        ft_memmove(testA1 + 1, testA1, 0);
        prnt_c(&c);
    }
    print_test_name("06. ft_memchr");
    {
        ft_memchr("abcdef", 'a', 5);
        prnt_c(&c);
    }
    print_test_name("07. ft_memcmp");
    {
        memcmp(NULL, NULL, 0);
        ft_memcmp(NULL, NULL, 0);
        prnt_c(&c);
    }
    print_test_name("08. ft_strlen");
    {
        c += ft_strlen_check("");
        c += ft_strlen_check(" \n ");
        c += ft_strlen_check("gdjdgkokgfdlk");
        c += ft_strlen_check("jfklsd fjdlsjgdf dgh fkdghkldf ");
        prnt_c(&c);
    }
    print_test_name("09. ft_strdup");
    {
        c += ft_strdup_check("test word");
        c += ft_strdup_check("");
        c += ft_strdup_check("another test");
        c += ft_strdup_check("\n");
        prnt_c(&c);
    }
    print_test_name("10. ft_strcpy");
    {
        c += ft_strcpy_check("test word");
        c += ft_strcpy_check("");
        c += ft_strcpy_check("another test");
        c += ft_strcpy_check("\n");
        prnt_c(&c);
    }
    print_test_name("11. ft_strncpy");
    {
        char	buf[6];
        
        memset(buf, 33, 6);
        ft_strncpy(buf, "abcdefghi", 6);
        prnt_c(&c);
    }
    print_test_name("12. ft_strcat");
    {
        c += ft_strcat_check("test");
        c += ft_strcat_check("");
        prnt_c(&c);
    }
    print_test_name("13. ft_strncat");
    {
        c += ft_strncat_check("test", 5);
        c += ft_strncat_check("test", 3);
        c += ft_strncat_check("test", 0);
        c += ft_strncat_check("", 5);
        c += ft_strncat_check("", 0);
        prnt_c(&c);
    }
    print_test_name("14. ft_strlcat");
    {
        char	buf[10];
        
        bzero(buf, 10);
        ft_strlcat(buf, "abc", 10);
        ft_strlcat(buf, "def", 10);
        prnt_c(&c);
    }
    print_test_name("15. ft_strchr");
    {
        static char	buf[] = "Ururu some long test text.";
        if (strchr(buf, 's') != ft_strchr(buf, 's'))
            c++;
        if (strchr(buf, '\0') != ft_strchr(buf, '\0'))
            c++;
        if (strchr(buf, 'L') != ft_strchr(buf, 'L'))
            c++;
        prnt_c(&c);
    }
    print_test_name("16. ft_strrchr");
    {
        static char	buf[] = "Ururu some long test text.";
        if (strchr(buf, 's') != ft_strchr(buf, 's'))
            c++;
        if (strchr(buf, 't') != ft_strchr(buf, 't'))
            c++;
        if (strchr(buf, '\0') != ft_strchr(buf, '\0'))
            c++;
        if (strchr(buf, 'L') != ft_strchr(buf, 'L'))
            c++;
        prnt_c(&c);
    }
    print_test_name("17. ft_strstr");
    {
        c += ft_strstr_check("", "");
        c += ft_strstr_check("string", "");
        c += ft_strstr_check("string s", "s");
        c += ft_strstr_check("string m", "q");
        c += ft_strstr_check("string m", "m");
        c += ft_strstr_check("ssssstring m", "string");
        c += ft_strstr_check("string m", "stri");
        c += ft_strstr_check("string m", "striq");
        prnt_c(&c);
    }
    print_test_name("18. ft_strnstr");
    {
        c += ft_strnstr_check("", "", 0);
        c += ft_strnstr_check("", "", 5);
        c += ft_strnstr_check("string", "", 10);
        c += ft_strnstr_check("string s", "s", 10);
        c += ft_strnstr_check("string m", "q", 10);
        c += ft_strnstr_check("string m", "m", 10);
        c += ft_strnstr_check("string m", "m", 5);
        c += ft_strnstr_check("ssssstring m", "string", 10);
        c += ft_strnstr_check("ssssstring m", "string", 9);
        c += ft_strnstr_check("ssssstring m", "string", 5);
        c += ft_strnstr_check("string m", "stri", 2);
        c += ft_strnstr_check("string m", "striq", 10);
        prnt_c(&c);
    }
    print_test_name("19. ft_strcmp");
    {
        c += ft_strcmp_check("", "");
        c += ft_strcmp_check("a", "a");
        c += ft_strcmp_check("dfds", "dfds");
        c += ft_strcmp_check("dfdS", "dfds");
        c += ft_strcmp_check(" ", "  ");
        c += ft_strcmp_check("\200", "");
        prnt_c(&c);
    }
    print_test_name("20. ft_strncmp");
    {
        c += ft_strncmp_check("", "", 1);
        c += ft_strncmp_check("", "", 0);
        c += ft_strncmp_check("a", "a", 2);
        c += ft_strncmp_check("a", "a", 0);
        c += ft_strncmp_check("a", "b", 0);
        c += ft_strncmp_check("a", "", 0);
        c += ft_strncmp_check("stringgggg", "string", 6);
        c += ft_strncmp_check("stringgggg", "string", 7);
        prnt_c(&c);
    }
    print_test_name("21. ft_atoi");
    {
        c += ft_atoi_check("-2147483648");
        c += ft_atoi_check("0");
        c += ft_atoi_check("-2147483649");
        c += ft_atoi_check("2147483648");
        c += ft_atoi_check("546547547554465");
        c += ft_atoi_check("9223372036854775806");
        c += ft_atoi_check("9223372036854775807");
        c += ft_atoi_check("9223372036854775808");
        c += ft_atoi_check("-9223372036854775807");
        c += ft_atoi_check("-9223372036854775808");
        c += ft_atoi_check("-9223372036854775809");
        c += ft_atoi_check("21");
        c += ft_atoi_check("--21");
        c += ft_atoi_check("+21");
        c += ft_atoi_check("++21");
        c += ft_atoi_check("+-21");
        c += ft_atoi_check("-+21");
        prnt_c(&c);
    }
    print_test_name("22. ft_isalpha");
    {
        c += ft_isalpha_check(0);
        c += ft_isalpha_check('A');
        c += ft_isalpha_check(' ');
        c += ft_isalpha_check(500);
        c += ft_isalpha_check(-500);
        prnt_c(&c);
    }
    print_test_name("23. ft_isdigit");
    {
        c += ft_isdigit_check('0');
        c += ft_isdigit_check('8');
        c += ft_isdigit_check('9');
        c += ft_isdigit_check('A');
        c += ft_isdigit_check('@');
        c += ft_isdigit_check(0);
        c += ft_isdigit_check(500);
        c += ft_isdigit_check(-500);
        prnt_c(&c);
    }
    print_test_name("24. ft_isalnum");
    {
        c += ft_isalnum_check('0');
        c += ft_isalnum_check('7');
        c += ft_isalnum_check('A');
        c += ft_isalnum_check('z');
        c += ft_isalnum_check('@');
        c += ft_isalnum_check(' ');
        c += ft_isalnum_check(0);
        c += ft_isalnum_check(200);
        c += ft_isalnum_check(-200);
        prnt_c(&c);
    }
    print_test_name("25. ft_isascii");
    {
        c += ft_isascii_check(0);
        c += ft_isascii_check(100);
        c += ft_isascii_check(127);
        c += ft_isascii_check(128);
        c += ft_isascii_check(500);
        c += ft_isascii_check(-500);
        prnt_c(&c);
    }
    print_test_name("26. ft_isprint");
    {
        c += ft_isprint_check(0);
        c += ft_isprint_check(32);
        c += ft_isprint_check(126);
        c += ft_isprint_check(100);
        c += ft_isprint_check(127);
        c += ft_isprint_check(-5);
        c += ft_isprint_check(200);
        prnt_c(&c);
    }
    print_test_name("27. ft_toupper");
    {
        c += ft_toupper_check(0);
        c += ft_toupper_check(500);
        c += ft_toupper_check(-500);
        c += ft_toupper_check('a');
        c += ft_toupper_check('A');
        c += ft_toupper_check('z');
        c += ft_toupper_check('Z');
        prnt_c(&c);
    }
    print_test_name("28. ft_tolower");
    {
        c += ft_tolower_check(0);
        c += ft_tolower_check(500);
        c += ft_tolower_check(-500);
        c += ft_tolower_check('a');
        c += ft_tolower_check('A');
        c += ft_tolower_check('z');
        c += ft_tolower_check('Z');
        prnt_c(&c);
    }
    printf("\x1b[36m""\n||====================== ADDITIONAL PART =====================||\n\n""\x1b[0m");
    print_test_name("01. ft_memalloc");
    {
        mem1 = malloc(100);
        bzero(mem1, 100);
        mem2 = ft_memalloc(100);
        
        if (memcmp(mem1, mem2, 100) == 0)
            printf("\x1b[32m""   OK.\n""\x1b[0m");
        else
            printf("\x1b[31m""   KO:(\n""\x1b[0m");
    }
    print_test_name("02. ft_memdel");
    {
        if (!mem2)
            printf("Previous allocation failed\n");
        else
        {
            ft_memdel(&mem2);
            if (!mem2)
                printf("\x1b[32m""   OK.\n""\x1b[0m");
            else
                printf("\x1b[31m""   KO:(\n""\x1b[0m");
        }
    }
    print_test_name("03. ft_strnew");
    {
        s1 = ft_strnew(10);
        i = -1;
        is_correct = 1;
        if (!s1)
            printf("Allocation failed\n");
        else
        {
            while (is_correct && ++i <= 10)
                if (s1[i])
                    is_correct = 0;
            if (is_correct)
                printf("\x1b[32m""   OK.\n""\x1b[0m");
            else
                printf("\x1b[31m""   KO:(\n""\x1b[0m");
        }
    }
    print_test_name("04. ft_strdel");
    {
        if (!s1)
            printf("Previous allocation failed\n");
        else
        {
            ft_strdel(&s1);
            if (!s1)
                printf("\x1b[32m""   OK.\n""\x1b[0m");
            else
                printf("\x1b[31m""   KO:(\n""\x1b[0m");
        }
    }
    print_test_name("05. ft_strclr");
    {
        char *str;
        
        str = (char*)malloc(sizeof(char) * 21);
        i = -1;
        while (++i < 20)
            str[i] = 'a' + i % 4;
        str[21] = '\0';
        i = -1;
        ft_strclr(str);
        while (++i < 20)
            if (str[i] != '\0')
                c++;
        prnt_c(&c);
    }
    print_test_name("06. ft_striter");
    {
        char	str[] = "AbCdEf";
        
        ft_striter(str, &iter_test);
        if (strcmp((const char*)(str), "BcDeFg") == 0)
            printf("\x1b[32m""   OK.\n""\x1b[0m");
        else
            printf("\x1b[31m""   KO:(\n""\x1b[0m");
    }
    print_test_name("07. ft_striteri");
    {
        char	str[] = "AbCdEf";
        
        ft_striteri(str, &iteri_test);
        if (strcmp((const char*)(str), "AcCeEg") == 0)
            printf("\x1b[32m""   OK.\n""\x1b[0m");
        else
            printf("\x1b[31m""   KO:(\n""\x1b[0m");
    }
    print_test_name("08. ft_strmap");
    {
        c += ft_strmap_check("some test string");
        c += ft_strmap_check("yT^7t67N Fhfjsdfjsl $T^#&@*efi ");
        c += ft_strmap_check("");
        prnt_c(&c);
    }
    print_test_name("09. ft_strmapi");
    {
        c += ft_strmapi_check("some test string");
        c += ft_strmapi_check("yT^7t67N Fhfjsdfjsl $T^#&@*efi ");
        c += ft_strmapi_check("");
        c += ft_strmapi_check("");
        prnt_c(&c);
    }
    print_test_name("10. ft_strequ");
    {
        c += ft_strequ_check("", "");
        c += ft_strequ_check("dsad\0fds", "dsad");
        c += ft_strequ_check("aaB", "aaB");
        c += ft_strequ_check("4m32kl", "4m32kl");
        c += ft_strequ_check("fjdksd", "fjdksD");
        c += ft_strequ_check("dsf", "");
        prnt_c(&c);
    }
    print_test_name("11. ft_strnequ");
    {
        c += ft_strnequ_check("", "", 1);
        c += ft_strnequ_check("", "", 0);
        c += ft_strnequ_check("dsad\0fds", "dsad", 4);
        c += ft_strnequ_check("4m32kl", "4m32kl", 0);
        c += ft_strnequ_check("4m32kl", "", 0);
        c += ft_strnequ_check("fjdksd", "fjdksD", 5);
        c += ft_strnequ_check("fjdksd", "fjdksD", 6);
        c += ft_strnequ_check("dsf", "", 4);
        prnt_c(&c);
    }
    print_test_name("12. ft_strsub");
    {
        c += ft_strsub_check("Long string", 5, 6, "string");
        c += ft_strsub_check("Long string", 5, 1, "s");
        c += ft_strsub_check("Long string", 5, 0, "");
        c += ft_strsub_check("Long string", 0, 6, "Long s");
        prnt_c(&c);
    }
    print_test_name("13. ft_strjoin");
    {
        c += ft_strjoin_check("", "", "");
        c += ft_strjoin_check("A", "", "A");
        c += ft_strjoin_check("", "B", "B");
        c += ft_strjoin_check("A", "B", "AB");
        c += ft_strjoin_check("FJKLSA", "fds78@#", "FJKLSAfds78@#");
        prnt_c(&c);
    }
    print_test_name("14. ft_strtrim");
    {
        c += ft_strtrim_check("", "");
        c += ft_strtrim_check("   test", "test");
        c += ft_strtrim_check("  test  	t", "test  	t");
        c += ft_strtrim_check(" test t\t", "test t");
        c += ft_strtrim_check("   test     ", "test");
        c += ft_strtrim_check("    ", "");
        prnt_c(&c);
    }
    print_test_name("15. ft_strsplit");
    {
        printf("Splits a string into words split by a character\n");
        ft_strsplit_check("", '*');
        ft_strsplit_check("**", '*');
        ft_strsplit_check("hello", '*');
        ft_strsplit_check("***hello", '*');
        ft_strsplit_check("hello***", '*');
        ft_strsplit_check("***hello***", '*');
        ft_strsplit_check("*hello*fellow***students*", '*');
        ft_strsplit_check("hello*fellow***students", '*');
        ft_strsplit_check("word1*word2*wword3*w4*wwwwwww5*w6", '*');
    }
    print_test_name("16. ft_itoa");
    {
        c += ft_itoa_check(0, "0");
        c += ft_itoa_check(21, "21");
        c += ft_itoa_check(10101, "10101");
        c += ft_itoa_check(-2147483648, "-2147483648");
        c += ft_itoa_check(2147483647, "2147483647");
        prnt_c(&c);
    }
    print_test_name("17. ft_putchar");
    {
        ft_putstr("   ");
        ft_putchar('f');
        ft_putchar('\n');
    }
    print_test_name("18. ft_putstr");
    {
        ft_putstr_check("");
        ft_putstr_check("Test string.");
    }
    print_test_name("19. ft_putendl");
    {
        ft_putendl_check("");
        ft_putendl_check("Test string.");
    }
    print_test_name("20. ft_putnbr");
    {
        ft_putnbr_check(-2147483648);
        ft_putnbr_check(-5);
        ft_putnbr_check(0);
        ft_putnbr_check(21);
        ft_putnbr_check(10203);
        ft_putnbr_check(2147483647);
    }
    print_test_name("21. ft_putchar_fd");
    {
        ft_putstr("   ");
        ft_putchar_fd('f', 1);
        ft_putchar_fd('\n', 1);
    }
    print_test_name("22. ft_putstr_fd");
    {
        ft_putstr("   ");
        ft_putstr_fd("fd test string\n", 1);
    }
    print_test_name("23. ft_putendl_fd");
    {
        ft_putstr("   ");
        ft_putendl_fd("fd test string", 1);
    }
    print_test_name("24. ft_putnbr_fd");
    {
        ft_putstr("   ");
        ft_putnbr_fd(-2147483648, 1);
    }
    printf("\x1b[36m""\n||====================== BONUS      PART =====================||\n\n""\x1b[0m");
    
    t_list *list;
    t_list *nullist;
    
    nullist = NULL;
    
    print_test_name("01. ft_lstnew");
    {
        int a;
        
        a = 43;
        list = ft_lstnew(NULL, 25);
        if (!list || list->content || list->content_size != 0)
        {
            c++;
            printf("Test fail while trying to create list component with NULL\n");
        }
        list = ft_lstnew(&a, sizeof(a));
        a = 0;
        if (!list || memcmp(list->content, &a, sizeof(a)) != 0 || list->content_size != sizeof(a))
        {
            c++;
            printf("Test fail while trying to create list component with %d\n", a);
            printf("%d\n", (int)(list->content));
        }
        prnt_c(&c);
    }
    print_test_name("04. ft_lstadd");
    {
        t_list *list2;
        t_list *prev;		
        int b;
        
        b = 44;
        prev = list;		
        list2 = ft_lstnew(&b, sizeof(b));
        ft_lstadd(NULL, list2);
        ft_lstadd(&nullist, list2);
        ft_lstadd(&list, list2);
        b = 0;
        if (!list || list->next != prev)
            c++;
        prnt_c(&c);
    }	
    print_test_name("05. ft_lstiter");
    {
        ft_lstiter(NULL, &list_iter_func);
        ft_lstiter(list, NULL);
        ft_lstiter(list, &list_iter_func);
        if (*(int*)list->content != 49 || *(int*)list->next->content != 48)
            c++;
        prnt_c(&c);
    }
    print_test_name("06. ft_lstmap");
    {
        t_list *new;
        new = ft_lstmap(NULL, &list_map_func);
        new = ft_lstmap(list, NULL);
        new = ft_lstmap(list, &list_map_func);
        if (*(int*)new->content != 46 || *(int*)new->next->content != 45)
            c++;
        prnt_c(&c);
    }
    print_test_name("02. ft_lstdelone");
    {
        t_list *list2;
        int b = 44;
        
        kk = 0;
        list2 = ft_lstnew(&b, sizeof(b));
        ft_lstdelone(NULL, &del_test);
        ft_lstdelone(&nullist, &del_test);
        ft_lstdelone(&list2, NULL);
        ft_lstdelone(&list2, &del_test);
        if (list2 || kk == 0)
            c++;
        prnt_c(&c);
    }
    print_test_name("03. ft_lstdel");
    {
        t_list	*list1;
        int		a;
        
        kk = 0;
        a = 5;
        list1 = ft_lstnew(&a, sizeof(a));
        a = 7;
        ft_lstadd(&list1, ft_lstnew(&a, sizeof(a)));
        ft_lstdel(NULL, &del_test);
        ft_lstdel(&nullist, &del_test);
        ft_lstdel(&list1, NULL);
        ft_lstdel(&list1, &del_test);
        if (list1 || kk != 2)
            c++;
        prnt_c(&c);
    }
    return (0);
}
