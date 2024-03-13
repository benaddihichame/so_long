/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:02:04 by hbenaddi          #+#    #+#             */
/*   Updated: 2023/11/30 15:20:39 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

# endif

void	ft_cut_buffer(char *buffer);
char	*ft_mod_join(char *line, char *buffer);
char	*get_next_line(int fd);
int		strchr_newline(char *buffer);
int		strlen_gnl(char *str);
char	*test_end(char *dest);
char	*ft_free(char *line);

#endif
