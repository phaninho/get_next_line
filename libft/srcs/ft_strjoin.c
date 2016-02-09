/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Creted:  2015/12/02 16:48:09 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/09 12:30:50 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cp_str(char *s1, char *str, int j)
{
	while (s1[j])
	{
		str[j] = s1[j];
		j++;
	}
	return (j);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss1;
	char	*str;
	int		j;
	int		k;

	ss1 = (char *) s1;
	str = NULL;
	if (!s1 && !s2)
		return (str);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	else
	{
		str = (char *)ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (str)
		{
			j = 0;
			k = 0;
			j = cp_str(ss1, str, j);
			while (s2[k])
			{
				str[j] = s2[k];
				k++;
				j++;
			}
			str[j] = '\0';
		}
		return (str);
	}
	/*	len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		len = len1 + len2;
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		str[len] = '\0';
		ft_strcat(str, s1);
		ft_strcat(str, s2);
	}
	return (str);*/
}
