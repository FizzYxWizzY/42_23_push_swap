/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:19:27 by mflury            #+#    #+#             */
/*   Updated: 2023/07/03 15:56:11 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate function.
//
void	ft_rotate(int *stack, char *msg)
{
	int	i;
	int	tmp1;
	int	tmp2;
	int	finish;

	i = 0;
	finish = 0;
	if (!stack[0])
		return ;
	tmp2 = stack[i];
	while (stack[i])
	{
		if (!stack[i + 1])
			break ;
		tmp1 = stack[i + 1];
		stack[i + 1] = tmp2;
		finish = tmp1;
		i++;
		if (!stack[i + 1])
			break ;
		tmp2 = stack[i + 1];
		stack[i + 1] = tmp1;
		finish = tmp2;
		i++;
	}
	stack[0] = finish;
	printf("%s\n", msg);
}

// push function.
// 
void	ft_push(int *stacka, int *stackb, char *msg)
{
	int	i;
	int	tmp1;
	int	tmp2;
	int	finish;

	i = 0;
	finish = 0;
	if (!stacka[0])
		return ;
	tmp2 = stackb[i];
	while (stackb[i])
	{
		tmp1 = stackb[i + 1];
		stackb[i + 1] = tmp2;
		finish = tmp1;
		i++;
		tmp2 = stackb[i + 1];
		stackb[i + 1] = tmp1;
		finish = tmp2;
		i++;
	}
	stackb[i + 1] = finish;
	stackb[0] = stacka[0];

	i = 1;
	while (stacka[i])
	{
		stacka[i - 1] = stacka[i];
		i++;
	}
	stacka[i - 1] = 0;
	printf("%s\n", msg);
}

// all the swaps,
// sa, sb, ss.
void	ft_swap(int *stacka, int *stackb, char *msg)
{
	int	tmp;

	if (msg[1] == 'a')
	{
		if (!stacka[1])
			return ;
		tmp = stacka[1];
		stacka[1] = stacka[0];
		stacka[0] = tmp;
	}
	else if (msg[1] == 'b')
	{
		if (!stackb[1])
			return ;
		tmp = stackb[1];
		stackb[1] = stackb[0];
		stackb[0] = tmp;
	}
	else
	{
		if (!stacka[1] || !stackb[1])
			return ;
		tmp = stacka[1];
		stacka[1] = stacka[0];
		stacka[0] = tmp;
		tmp = stackb[1];
		stackb[1] = stackb[0];
		stackb[0] = tmp;
	}
	printf("%s\n", msg);
}
