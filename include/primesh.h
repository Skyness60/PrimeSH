/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primesh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:33:21 by sperron           #+#    #+#             */
/*   Updated: 2025/06/02 13:23:47 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMESH_H
# define PRIMESH_H

// Standard C library headers
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
#include <errno.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>
// POSIX library headers
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

// This header file is the lib extern
# include "../lib/ultimatelib.h"

// This header file is part of the PrimeSH project.
# include "data.h"
# include "chain.h"

#endif