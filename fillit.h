/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:10:03 by ichubare          #+#    #+#             */
/*   Updated: 2016/12/25 15:05:55 by mhlukhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_putchar(char c);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strrev(char const *str);
void			ft_lstpush_back(t_list **lst, t_list *elem);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strnew(size_t size);
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
void			ft_putendl(char const *s);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			*bpoint(char *str, int len);
char			*ft_read_file(char *str);
int				ft_open_file(char *str);
char			*ft_get_input(int fd);
t_list			*ft_split_input(char *input);
int				ft_validate(int fd);
void			ft_replace(char *str, int rep, int ned);
int				ft_check(const char *str);
char			**cut_arr(char **fig);
char			**fig_norm(char **fig);
char			**arr_all();
void			putin(char **arr, char **fig, int tshift, int lshift);
int				check(char **arr, t_list *first, int countf);
int				min_arr(int count_f);
void			w_l(int *wide, int *length, char **fig);
void			fillit(int count_f, char **arr, t_list *figs);
char			**erase(char **arr, t_list *elem);
char			**delete(char **arr, int letter);
int				find_fig(char **fig);
int				ft_lstlen(t_list *s);
void			show(char **d);
char			**cut_final(char **arr);

#endif
