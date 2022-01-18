/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:08:49 by lutsiara          #+#    #+#             */
/*   Updated: 2022/01/18 18:03:18 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "favicon-mod.h"

int     main(int ac, char **av)
{
    unsigned char   *png;
    int             width;
    int             height;
    unsigned int    png_size;

    if (ac != 3)
        return (exit_error_16x16());
    if (!strisdigit(av[ac - 1]) || !strisdigit(av[ac - 2]))
        return (exit_error_16x16());
    png = 0;
    width = atoi(av[ac - 1]);
    height = atoi(av[ac - 2]);
    png_size = 0;
    if (!(png = (unsigned char *)malloc(sizeof(unsigned char) * png_size)));
        return (exit_error_16x16());
    compose_png(png, png_size);
    write(1, png, png_size);
    free(png);
    return (0);
}
