/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:33:45 by eavilov           #+#    #+#             */
/*   Updated: 2022/09/24 17:04:07 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/*	Never even thought about using those  */

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Rarely use it so idc
char			*ft_strchr(const char *str, int character);
// Rarely use it so idc
char			*ft_my_strrchr(const char *s, int c, int index);
// Rarely use it so idc

/*	String modifications  */

char			*ft_strdup(char *src);
// Allocates and dups a string
char			*ft_substr(char const *src, unsigned int start, size_t len);
// Allocates and dups 'len' characters from start of src
char			*ft_strtrim(char const *s1, char const *set);
// Trims "set" chars of s1
char			**ft_split(char const *s, char c);
// Split a string into a array with 'c' as delimiter
char			*ft_strjoin(char const *s1, char const *s2);
// Allocates and joins two string together

/*	Useful and cool stuff	*/

size_t			ft_strlen(const char *str);
// Returns the length of a string
long int		ft_atoi(const char *str);
// Like itoa, but the other way around
char			*ft_itoa(int n);
// Like atoi, but the other way around
int				ft_putstr(char *s);
// Prints a string
int				ft_strncmp(char *s1, char *s2, size_t n);
// Compares 'n' first characters and returns the difference
int				ft_freesbee(char **string);
// Frees an array of strings

/*	Might be useful later idk	*/

int				ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
// Compares 'size' bites and returns the difference
char			*ft_strnstr(const char *str, const char *word, size_t len);
// Looks for a specific string in the 'len' first characters

/*	File descriptors bullshit	*/

void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);

/*	Those are just here to make it look like I got tons of functions	*/

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
// Rarely use it so idc
size_t			ft_strlcat(char *dest, const char *src, size_t dstsize);
// Rarely use it so idc
int				ft_isalnum(int character);
// Checks if the character is a digit or alphabetical
int				ft_isalpha(int character);
// Checks if the character is alphabetical
int				ft_isdigit(int character);
// Checks if the character is a digit
int				ft_isprint(int character);
// Checks if the character is printable
int				ft_isascii(int character);
// Checks if the character is from the ascii table
int				ft_tolower(int character);
// Lowercases a character
int				ft_toupper(int character);
// Uppercarses a character

/*	Some other stuff I never bother to use	*/

void			*ft_memchr(const void *mem, int character, size_t size);
void			*ft_memmove(void *dest, const void *src, size_t size);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memset(void *p, int value, size_t count);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *str, size_t len);
void			ft_swap(int *a, int *b); // Swaps two elements
void			ft_putchar(int c); // prints a character
void			ft_putnbr(long int nb); // prints an int

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*	Chained lists	*/

void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));

#endif