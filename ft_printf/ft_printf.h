/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:30:21 by keteo             #+#    #+#             */
/*   Updated: 2025/01/02 14:56:25 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putchr_count(char c, int *count);
void	ft_putstr_count(char *args, int *count);
void	ft_putnbr_count(int nb, int *count);
void	ft_putunnbr_count(unsigned int nb, int *count);
void	ft_putptr_count(size_t ptr, int *count);
void	ft_puthex_count(unsigned int hex, int *count, char x_or_x);

int		ft_printf(const char *format, ...);

#endif