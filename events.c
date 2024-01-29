/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 02:43:56 by ymomen            #+#    #+#             */
/*   Updated: 2024/01/29 16:17:44 by ymomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keybord_press(int keycode, t_facral *fract)
{
	if (keycode == 53)
		end_fracts(fract);
	else if (keycode == 124)
		fract->shift_x += (0.5 * fract->zoom);
	else if (keycode == 123)
		fract->shift_x -= (0.5 * fract->zoom);
	else if (keycode == 126)
		fract->shift_y += (0.5 * fract->zoom);
	else if (keycode == 125)
		fract->shift_y -= (0.5 * fract->zoom);
	else if (keycode == 69)
		fract->etration += 10;
	else if (keycode == 78)
		fract->etration -= 10;
	else if (keycode == 49)
	{
		fract->color.b += 11;
		fract->color.g += 31;
		fract->color.r += 21;
	}
	math(fract);
	return (0);
}
// void    zoom_in(t_facral *fc, t_number mouse)
// {
//     double    z_factor;

//     z_factor = 0.5;
//     fc->strt.r = (fc->strt.r - mouse.r) + z_factor + mouse.r;
//     fc->strt.i = (fc->strt.i - mouse.i) + z_factor + mouse.i;
//     fc->end.r = (fc->end.r - mouse.r) + z_factor + mouse.r;
//     fc->end.i = (fc->end.i - mouse.i) + z_factor + mouse.i;
//     // fc->mx_iter += 7;
//     // render(fc);
// }

// int	mouse_press(int button, int x, int y, t_facral *fract)
// {
// 	t_number mouse;

// 	if (button == 5 || button == 4)
// 	{
// 		mouse.i = y;
// 		mouse.r = x;

// 		if (button == 5) // Scroll Down (Zoom Out)
// 			fract->zoom *= 1.3;
// 		else if (button == 4) // Scroll Up (Zoom In)
// 			fract->zoom *= 0.8;

// 		// Adjust shift using the mouse coordinates
// 		fract->shift_x += scale(0, (x - WIDTH / 2), -2, 2, x) * fract->zoom;
// 		fract->shift_y += (y - HEIGHT / 2) * fract->zoom;

// 		math(fract);
// 	}
// 	return (0);
// }


int	mouse_press(int button, int x, int y, t_facral *fract)
{
	static t_number prev;

	t_number mouse;

	if (button == 5 || button == 4)
	{
		mouse.i = y;
		mouse.r = x;
		if (button == 5)
		{
			fract->zoom *= 0.8;
		}	
		else if (button == 4)
			fract->zoom *= 1.3;

		if (prev.r != x || prev.i != y)
		{
			prev.r = x;
			prev.i = y;
			fract->shift_x += (scale(0, WIDTH, fract->str.r, fract->end.r, x)) * fract->zoom;
			fract->shift_y += (scale(0, HEIGHT, fract->str.i, fract->end.i, y)) * fract->zoom;
		// 	        mouse_x_scaled = scale(x, 0, WIN_WIDTH, program->left_x,
        //         		program->right_x);
        // 			mouse_y_scaled = scale(y, 0, WIN_HEIGHT, program->top_y,
        //         		program->bottom_y);
        // 			if (keycode == 4)
        //     		zoom_factor = 0.85;
        // 			else
        //     		zoom_factor = 1.15;
        // 			program->left_x = mouse_x_scaled + zoom_factor * (
        //         		program->left_x - mouse_x_scaled);
        // 			program->right_x = mouse_x_scaled + zoom_factor * (
        //         		program->right_x - mouse_x_scaled);
        // 			program->top_y = mouse_y_scaled + zoom_factor * (
        //         		program->top_y - mouse_y_scaled);
        // 			program->bottom_y = mouse_y_scaled + zoom_factor * (
        //         		program->bottom_y - mouse_y_scaled);
		}
		math(fract);
	}
	return (0);
}





void	events(t_facral *fract)
{
	mlx_hook(fract->mlx_win, 02, 0, keybord_press, fract);
	mlx_hook(fract->mlx_win, 04, 0, mouse_press, fract);
	mlx_hook(fract->mlx_win, 17, 0, end_fracts, fract);
}