/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:08:49 by lutsiara          #+#    #+#             */
/*   Updated: 2022/02/11 21:19:26 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DEFINE_RESSOURCES_PATHS
#include "favicon-random.h"

int     main(void)
{
    unsigned int        i;
    unsigned int        num;
    unsigned int        max_number;
    MagickBooleanType   status;
    MagickWand          *result_wand;
    MagickWand          *layer_wand;
    DIR                 *dirp;
    struct dirent       *dp;
    char                path[4096];

    MagickWandGenesis();
    srand(time((void *)0));
    memset(path, 0, 4096);
    result_wand = NewMagickWand();
    layer_wand = NewMagickWand();
    i = 0;
    while (i < DIR_NB)
    {
        dirp = opendir(g_paths[i]);
        if (dirp == NULL)
        {
            layer_wand = DestroyMagickWand(layer_wand);
            result_wand = DestroyMagickWand(result_wand);
            MagickWandTerminus();
            return (1);
        }
        max_number = 0;
        while ((dp = readdir(dirp)) != NULL)
            max_number++;
        (void)closedir(dirp);
        max_number -= 2;
        num = rand() % max_number + 1;
        snprintf(path, 4096, "%s%u%s", g_paths[i], num, FILE_EXT);
        if (i == 0)
            status = MagickReadImage(result_wand, path);
        else
            status = MagickReadImage(layer_wand, path);
        if (status == MagickFalse)
        {
            layer_wand = DestroyMagickWand(layer_wand);
            result_wand = DestroyMagickWand(result_wand);
            MagickWandTerminus();
            return (1);
        }
        if (i == 0)
        {
            i++;
            continue;
        }
        status = MagickCompositeImage(result_wand, layer_wand,
                OverCompositeOp, MagickTrue, 0, 0);
        if (status == MagickFalse)
        {
            layer_wand = DestroyMagickWand(layer_wand);
            result_wand = DestroyMagickWand(result_wand);
            MagickWandTerminus();
            return (1);
        }
        i++;
    }
    MagickWriteImagesFile(result_wand, stdout);
    layer_wand = DestroyMagickWand(layer_wand);
    result_wand = DestroyMagickWand(result_wand);
    MagickWandTerminus();
    return (0);
}
