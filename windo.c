/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:53:22 by ymomen            #+#    #+#             */
/*   Updated: 2024/02/04 12:32:39 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_values(t_fractol *fract)
{
	fract->etration = 40;
	fract->range = 4;
	fract->shift_x = 0.0;
	fract->shift_y = 0.0;
	fract->zoom = 1.00;
	fract->color.b = 9;
	fract->color.g = 3;
	fract->color.r = 5;
	if ((double)WIDTH / HEIGHT >= 1)
	{
		fract->str.r = -2 * ((double)WIDTH / HEIGHT);
		fract->end.r = 2 * ((double)WIDTH / HEIGHT);
		fract->str.i = 2;
		fract->end.i = -2;
	}
	else
	{
		fract->str.r = -2;
		fract->end.r = 2;
		fract->str.i = 2 * ((double)HEIGHT / WIDTH);
		fract->end.i = -2 * ((double)HEIGHT / WIDTH);
	}
}

void	init_windo(t_fractol *fract, char *name)
{
	fract->mlx_ptr = mlx_init();
	if (fract->mlx_ptr == NULL)
		error_and_exit("init_mlx", 1);
	fract->mlx_win = mlx_new_window(fract->mlx_ptr, WIDTH, HEIGHT, name);
	if (fract->mlx_win == NULL)
	{
		free(fract->mlx_ptr);
		error_and_exit("mlx_new_win", 1);
	}
	fract->img.img = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
	if (fract->img.img == NULL)
	{
		mlx_destroy_window(fract->mlx_ptr, fract->mlx_win);
		error_and_exit("mlx_new_img", 1);
	}
	fract->img.addr = mlx_get_data_addr(fract->img.img,
			&fract->img.bits_per_pixel,
			&fract->img.line_length, &fract->img.endian);
	init_values(fract);
	events(fract);
}

void	check_resolution(void)
{
	if (WIDTH <= 0 || HEIGHT <= 0 || HEIGHT > 3500 || WIDTH > 3500)
		error_and_exit("please update the resolution"
			"to be a Valid WIDTH and HEIGHT ;).\n", -9);
}
