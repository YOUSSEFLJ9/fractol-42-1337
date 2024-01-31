/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lj9 <lj9@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:51:42 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/31 22:24:44 by lj9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void ff(void)
// {
// 	system("leaks fractol");
// }

int	main(int ac, char **av)
{
	t_facral	fract;

	// atexit(ff);
	fract.av = av;
	if ((ac == 2 && !ft_strncmp(fract.av[1], "Mandelbrot", 11)))
	{
		init_windo(&fract, fract.av[1]);
		fract.is_julia = 0;
		math(&fract);
		mlx_loop(fract.mlx_ptr);
	}
	else if (ac == 4 && !ft_strncmp(fract.av[1], "Julia", 6))
	{
		init_windo(&fract, fract.av[1]);
		fract.is_julia = 1;
		math(&fract);
		mlx_loop(fract.mlx_ptr);
	}
	else
		error_and_exit(
			"USAGE:\n./fractol Mandelbrot.\n./fractol Julia x y.\n", -9);
	return (0);
}
