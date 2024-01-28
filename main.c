/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:51:42 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/28 03:34:32 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ff(void)
{
	system("leaks fractol");
}
int main(int ac, char **av)
{
	t_facral	fract;

	// atexit(ff);
	fract.av = av;
	init_windo(&fract, fract.av[1]);
	if ((ac == 2 && !ft_strncmp(fract.av[1], "Mandelbrot", 11)))
	{
		fract.is_julia = 0;
		math(&fract);
		mlx_loop(fract.mlx_ptr);
	}
	else if (ac == 4 && !ft_strncmp(fract.av[1], "Julia", 6))
	{
		fract.is_julia = 1;
		math(&fract);
		mlx_loop(fract.mlx_ptr);
	}
	else
		error_and_exit("USAGE:\n./fractol Mandelbrot.\n./fractol Julia x y.\n", -9);
	return (0);
}