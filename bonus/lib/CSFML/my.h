/*
** my.h for my.h in /home/lblanchard/CPool_Day09/include
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Thu Oct 13 09:19:01 2016 Leandre Blanchard
** Last update Mon Apr 10 02:18:31 2017 Léandre Blanchard
*/

#ifndef MY_H_
# define MY_H_

# include <unistd.h>
# include <stdlib.h>

int	rm_ascii(char *);

char	*my_catalloc(const char *, const char *);

void	shift_left(char *, int);

void	shift_right(char *, int);

char	*get_next_line(int);

void	my_clear();

char	*my_realloc(const char *, int);

char	*my_calloc(int);

int	term_width();

char	*int_char(int);

int	my_total_len(char **);

char	*my_tab_to_str(char **);

int	my_intlen(int);

void	free_tab(char **);

char	**my_alloc_tab(int, int);

float	my_get_float(const char *);

char	*convert_endian_str(int);

int	convert_endian(int);

int	epur_str(char *);

int	total_name(const char *);

void	zeros(char *, int);

void	my_putchar(char);

int	my_isneg(int);

int	my_put_nbr(long long);

void	my_putnbr_base(int, const char *);

int	my_swap(int *, int *);

int	my_putstr(const char *);

int	my_strlen(const char *);

int	my_getnbr(const char *);

void	my_sort_int_tab(int *, int);

int	my_power_rec(int, int);

int	my_square_root(int);

int	my_is_prime(int);

int	my_find_prime(int);

char	*my_strcpy(char *, const char *);

char	*my_strncpy(char *, const char *, int);

char	*my_revstr(char *);

char	*my_strstr(char *, char *);

int	my_strcmp(const char *, const char *);

int	my_strncmp(const char *, const char *, int);

char	*my_strupcase(char *);

char	*my_strlowcase(char *);

char	*my_strcapitalize(char *);

int	my_str_isalpha(const char *);

int	my_str_isnum(const char *, char);

int	my_str_islower(char *);

int	my_str_isupper(char *);

int	my_str_isprintable(const char *);

int	my_showstr(char *);

int	my_showmem(char *, int);

char	*my_strcat(char *, const char *);

char	*my_strncat(char *, const char *, int);

int	my_fact_rec(int);

int	my_find_prime_sup(int);

char	*my_strdup(const char *);

int	my_power_rec(int, int);

char	*my_revstr(char *);

char	*int_to_char(int);

char	*my_putstr_error(const char *);

int	my_printf(const char *, ...);

int	my_tablen(char **);

int	my_int_len(int);

void	my_put_tab(char **);

#endif /* !MY_H_ */
