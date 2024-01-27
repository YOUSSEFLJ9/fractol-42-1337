/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:50:35 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/27 09:40:34 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_and_exit(char *s, int exite)
{
	if (exite == -9)
	{
		write(2, s, ft_strlen(s));
		exit(1);
	}
	perror(s);
	if (exite != 0)
		exit(exite);
}

int	end_fracts(t_facral *fract)
{
	mlx_destroy_image(fract->mlx_ptr,fract->img.img);
	mlx_destroy_window(fract->mlx_ptr, fract->mlx_win);
	exit(0);
}
