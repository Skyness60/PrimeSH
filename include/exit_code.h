/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:10:00 by sperron           #+#    #+#             */
/*   Updated: 2025/06/03 14:08:46 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_CODE_H
# define EXIT_CODE_H

# define SUCCESS 0
# define FAILURE 1
# define COMMAND_NOT_FOUND 127
# define SYNTAX_ERROR 258
# define PERMISSION_DENIED 126
# define EXIT_SIGNAL 130
# define EXIT_QUIT 131
# define EXIT_CTRL_C 130
# define EXIT_CTRL_D 0
# define EXIT_CTRL_Z 20
# define EXIT_SIGINT 130
# define EXIT_SIGQUIT 131
# define EXIT_SIGTERM 143
# define EXIT_SIGKILL 137
# define EXIT_SIGSEGV 139

#endif