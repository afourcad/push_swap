/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:06:05 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/16 16:06:07 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# define BUFF_SIZE 1

int		get_next_line2(int const fd, char **line);
int		get_line_len(int const fd, char **dst);
int		checknewline(char *s);
char	*del_line(char *s, int i);
char	*ft_strjoin2(char *s1, char *s2);

#endif
