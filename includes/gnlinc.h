/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlinc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:55:54 by stmartin          #+#    #+#             */
/*   Updated: 2016/02/02 18:56:44 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNLINC_H
# define GNLINC_H

# include "../../libft/libft.h"
# include <stdlib.h>

# define BUFF_SIZE  20

int				get_next_line(int fd, char **line);
#endif
