/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:41:12 by lutsiara          #+#    #+#             */
/*   Updated: 2022/02/04 19:44:44 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "favicon-random.h"

int     strisdigit(char *str)
{
    while (str && *str)
    {
        if (!isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}
