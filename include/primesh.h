/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primesh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:33:21 by sperron           #+#    #+#             */
/*   Updated: 2025/06/03 16:54:27 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMESH_H
# define PRIMESH_H

// Standard C library headers
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/stat.h>
# include <string.h>
# include <unistd.h>
# include <termios.h>
# include <stdbool.h>
# include <errno.h>
# include <wchar.h>
# include <locale.h>
// This header file is the lib extern
# include "../lib/ultimatelib.h"

// This header file is part of the PrimeSH project.
# include "data.h"
# include "chain.h"
# include "signals.h"
# include "exit_code.h"
# include "prompt.h"
# include "git.h"
# include "utils.h"

#endif