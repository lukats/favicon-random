/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   favicon-random.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:30:02 by lutsiara          #+#    #+#             */
/*   Updated: 2022/02/11 22:30:39 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FAVICON_MOD_H
# define FAVICON_MOD_H

# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <time.h>
# include <string.h>
# include <dirent.h>
# include <fcntl.h>

# include <MagickWand/MagickWand.h>

# ifdef DEFINE_RESSOURCES_PATHS

const char * const g_paths[] = {
    "./ressources/body/",
    "./ressources/eyes/",
    "./ressources/mouth/",
    "./ressources/noz/",
    "./ressources/left-ear/",
    "./ressources/right-ear/",
    "./ressources/eye-brow/",
    "./ressources/head-top/",
    0
};

# else

extern const char * const g_paths[];

# endif

# define DIR_NB 8
# define FILE_EXT ".png"

#endif
