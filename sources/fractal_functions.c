/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theinone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:53:43 by theinone          #+#    #+#             */
/*   Updated: 2020/02/20 15:44:30 by theinone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			mandelbrot(t_frac *frac)
{
	frac->pr = 2.0 * (frac->x - W_WIDTH / 2) / (0.5 * frac->zoom * W_WIDTH) + frac->movex;
	frac->pi = 2.0 * (frac->y - W_HEIGHT / 2) / (0.5 * frac->zoom * W_HEIGHT) + frac->movey;
	frac->new_re = 0;
	frac->new_im = 0;
	frac->old_re = 0;
	frac->old_im = 0;
	frac->iterations = 0;
	while (frac->iterations < frac->max_iter)
	{
		frac->old_re = frac->new_re;
		frac->old_im = frac->new_im;
		frac->new_re = frac->old_re * frac->old_re - frac->old_im * frac->old_im + frac->pr;
		frac->new_im = 2 * frac->old_re * frac->old_im + frac->pi;
		if ((frac->new_re * frac->new_re + frac->new_im * frac->new_im) > 4)
			break ;
		frac->iterations++;
	}
	return (frac->iterations);
}

int			mandelbar(t_frac *frac)
{
	frac->pr = 2.0 * (frac->x - W_WIDTH / 2) / (0.5 * frac->zoom * W_WIDTH) + frac->movex;
	frac->pi = 2.0 * (frac->y - W_HEIGHT / 2) / (0.5 * frac->zoom * W_HEIGHT) + frac->movey;
	frac->new_re = 0;
	frac->new_im = 0;
	frac->old_re = 0;
	frac->old_im = 0;
	frac->iterations = 0;
	while (frac->iterations < frac->max_iter)
	{
		frac->old_re = frac->new_re;
		frac->old_im = frac->new_im;
		frac->new_re = frac->old_re * frac->old_re - frac->old_im * frac->old_im + frac->pr;
		frac->new_im = -2 * frac->old_re * frac->old_im + frac->pi;
		if ((frac->new_re * frac->new_re + frac->new_im * frac->new_im) > 4)
			break ;
		frac->iterations++;
	}
	return (frac->iterations);
}

int julia_movement(int x, int y, t_frac *frac)
{
	if (x > 150 && x < 450 && y > 150 && y < 450)
	{
		frac->julia_re = 2.0 * (x - W_WIDTH / 2) / (0.5 * frac->zoom * W_WIDTH) + frac->movex;
		frac->julia_im = 2.0 * (y - W_HEIGHT / 2) / (0.5 * frac->zoom * W_HEIGHT) + frac->movey;
		draw(frac);
	}
	return (0);
}

int julia(t_frac *frac)
{
	frac->new_re = 2.0 * (frac->x - W_WIDTH / 2) / (0.5 * frac->zoom * W_WIDTH) + frac->movex;
	frac->new_im = 2.0 * (frac->y - W_HEIGHT / 2) / (0.5 * frac->zoom * W_HEIGHT) + frac->movey;

	mlx_hook(frac->win, 6, (1L << 6), julia_movement, frac);

	frac->iterations = 0;
	while (frac->iterations < frac->max_iter)
	{
		frac->old_re = frac->new_re;
		frac->old_im = frac->new_im;
		frac->new_re = frac->old_re * frac->old_re - frac->old_im * frac->old_im + frac->julia_re;
		frac->new_im = 2 * frac->old_re * frac->old_im + frac->julia_im;
		if ((frac->new_re * frac->new_re + frac->new_im * frac->new_im) > 4)
			break ;
		frac->iterations++;
	}
	return (frac->iterations);
}
