/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:08:49 by lutsiara          #+#    #+#             */
/*   Updated: 2022/02/04 19:52:28 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "favicon-random.h"

int     main(int ac, char **av)
{
    void            *png;
    int             width;
    int             height;
    unsigned int    png_size;

    if (ac != 3)
        return (exit_error_16x16());
    if (!strisdigit(av[ac - 1]) || !strisdigit(av[ac - 2]))
        return (exit_error_16x16());
    width = atoi(av[ac - 1]);
    height = atoi(av[ac - 2]);
    png = 0;
    png_size = 0;
    if (!compose_png(&png, &png_size))
    {
        write(1, png, png_size);
        free(png);
    }
    return (0);
}
