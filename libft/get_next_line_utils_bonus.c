/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:54:02 by phijano-          #+#    #+#             */
/*   Updated: 2022/08/04 11:18:41 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoing(const char *s1, const char *s2)
{
	char	*pnt_str;
	int		length;
	char	*temp;

	if (!s1)
	{
		temp = (char *)malloc(sizeof(temp));
		if (!temp)
			return (NULL);
		temp[0] = '\0';
	}
	else
		temp = (char *)s1;
	if (!s2)
		return (NULL);
	length = ft_strlen(temp) + ft_strlen(s2);
	pnt_str = (char *)malloc(sizeof (*pnt_str) * (length + 1));
	if (!pnt_str)
		return (NULL);
	pnt_str[0] = '\0';
	ft_strlcat(pnt_str, temp, ft_strlen(temp) + 1);
	ft_strlcat(pnt_str, s2, length + 1);
	free (temp);
	return (pnt_str);
}
