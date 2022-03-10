/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:16:54 by jkong             #+#    #+#             */
/*   Updated: 2022/03/08 03:01:13 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

/*
**	Begin Mandatory ctype function region
**
*/

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
**
**	End Mandatory ctype function region
*/

/*
**	Begin Mandatory string function region
**
*/

size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/**
 * @see malloc
 */
char	*ft_strdup(const char *s1);

/*
**
**	End Mandatory string function region
*/

/*
**	Begin Mandatory stdlib function region
**
*/

int		ft_atoi(const char *str);
/**
 * @see malloc
 */
void	*ft_calloc(size_t count, size_t size);

/*
**
**	End Mandatory stdlib function region
*/

/*
**	Begin Mandatory Additional function region
**
*/

/**
 * Allocates (with malloc(3)) and returns a substring @n
 from the string ’s’. @n
 The substring begins at index ’start’ and is of @n
 maximum size ’len’.
 * @param #1 The string from which to create the substring.
 * @param #2 The start index of the substring in the string @n
 ’s’.
 * @param #3 The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * Allocates (with malloc(3)) and returns a new @n
 string, which is the result of the concatenation @n
 of ’s1’ and ’s2’.
 * @param #1 The prefix string.
 * @param #2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * Allocates (with malloc(3)) and returns a copy of @n
 ’s1’ with the characters specified in ’set’ removed @n
 from the beginning and the end of the string.
 * @param #1 The string to be trimmed.
 * @param #2 The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * Allocates (with malloc(3)) and returns an array @n
 of strings obtained by splitting ’s’ using the @n
 character ’c’ as a delimiter. The array must be @n
 ended by a NULL pointer.
 * @param #1 The string to be split.
 * @param #2 The delimiter character.
 * @return The array of new strings resulting from the split. @n
 NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * Allocates (with malloc(3)) and returns a string @n
 representing the integer received as an argument. @n
 Negative numbers must be handled.
 * @param #1 the integer to convert.
 * @return The string representing the integer. NULL if the @n
 allocation fails.
 */
char	*ft_itoa(int n);

/**
 * Applies the function ’f’ to each character of @n
 the string ’s’ , and passing its index as first @n
 argument to create a new string (with malloc(3)) @n
 resulting from successive applications of ’f’.
 * @param #1 The string on which to iterate.
 * @param #2 The function to apply to each character.
 * @return The string created from the successive applications @n
 of ’f’. Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * Applies the function f to each character of the @n
 string passed as argument, and passing its index @n
 as first argument. Each character is passed by @n
 address to f to be modified if necessary
 * @param #1 The string on which to iterate.
 * @param #2 The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * Outputs the character ’c’ to the given file @n
 descriptor.
 * @param #1 The character to output.
 * @param #2 The file descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * Outputs the string ’s’ to the given file @n
 descriptor.
 * @param #1 The string to output.
 * @param #2 The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * Outputs the string ’s’ to the given file @n
 descriptor, followed by a newline.
 * @param #1 The string to output.
 * @param #2 The file descriptor on which to write.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * Outputs the integer ’n’ to the given file @n
 descriptor.
 * @param #1 The integer to output.
 * @param #2 The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd);

/*
**
**	End Mandatory Additional function region
*/

/*
** Begin Bonus part regeion
**
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * Allocates (with malloc(3)) and returns a new @n
 element. The variable ’content’ is initialized @n
 with the value of the parameter ’content’. The @n
 variable ’next’ is initialized to NULL.
 * @param #1 The content to create the new element with.
 * @return The new element.
 */
t_list	*ft_lstnew(void *content);

/**
 * Adds the element ’new’ at the beginning of the @n
 list.
 * @param #1 The address of a pointer to the first link of @n
 a list.
 * @param #2 The address of a pointer to the element to be @n
 added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * Counts the number of elements in a list.
 * @param #1 The beginning of the list.
 * @return Length of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * Returns the last element of the list.
 * @param #1 The beginning of the list.
 * @return Last element of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * Adds the element ’new’ at the end of the list.
 * @param #1 The address of a pointer to the first link of @n
 a list.
 * @param #2 The address of a pointer to the element to be @n
 added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * Takes as a parameter an element and frees the @n
 memory of the element’s content using the function @n
 ’del’ given as a parameter and free the element. @n
 The memory of ’next’ must not be freed.
 * @param #1 The element to free.
 * @param #2 The address of the function used to delete the @n
 content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * Deletes and frees the given element and every @n
 successor of that element, using the function ’del’ @n
 and free(3). @n
 Finally, the pointer to the list must be set to @n
 NULL.
 * @param #1 The address of a pointer to an element.
 * @param #2 The address of the function used to delete the @n
 content of the element.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * Iterates the list ’lst’ and applies the function @n
 ’f’ to the content of each element.
 * @param #1 The string on which to iterate.
 * @param #2 The function to apply to each character.
 * @return The string created from the successive applications @n
 of ’f’. Returns NULL if the allocation fails.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * Iterates the list ’lst’ and applies the function @n
 ’f’ to the content of each element. Creates a new @n
 list resulting of the successive applications of @n
 the function ’f’. The ’del’ function is used to @n
 delete the content of an element if needed.
 * @param #1 The adress of a pointer to an element.
 * @param #2 The adress of the function used to iterate on @n
 the list.
 * @param #3 The adress of the function used to delete the @n
 content of an element if needed.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
**
** End Bonus part regeion
**
*/

#endif
