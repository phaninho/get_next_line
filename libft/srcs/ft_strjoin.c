/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Creted:  2015/12/02 16:48:09 by stmartin          #+#    #+#             */
/*   Updated: 2016/03/03 11:38:31 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	
	str = NULL;
	if (!s1 && !s2)
		return (str);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	if ((str = (char *)ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		str = ft_strcpy(str, s1);
		str = ft_strcat(str, s2);
	}
	return (str);
}
