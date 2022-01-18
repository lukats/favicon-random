/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   favicon-mod.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:30:02 by lutsiara          #+#    #+#             */
/*   Updated: 2022/01/18 18:02:40 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FAVICON_MOD_H
# define FAVICON_MOD_H

# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>

int     strisdigit(char *str);
int     exit_error_16x16(void);
void    compose_png(unsigned char *png, unsigned int png_size);

#endif
