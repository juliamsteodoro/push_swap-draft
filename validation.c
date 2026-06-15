/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:23:17 by marvin            #+#    #+#             */
/*   Updated: 2026/06/15 19:23:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_error(void)
{
	write(2, "Error\n", 6);
}

int is_valid_format(char **args, int start)
{
    int i;
    int j;
    long valor;

    i = start;
    while (args[i] != NULL)
    {
        j = 0;
        if (args[i][j] == '-' || args[i][j] == '+')
            j++;
        if (!args[i][j])
            return (0);
        while (args[i][j])
        {
            if (!ft_isdigit(args[i][j]))
                return (0);
            j++;
        }
        valor = ft_atol(args[i]);
        if (valor > 2147483647 || valor < -2147483648)
            return (0);
        i++;
    }
    return (1);
}

int has_duplicates(char **args, int start)
{
    int i;
    int j;

    i = start;
    while (args[i] != NULL)
    {
        j = i + 1;
        while (args[j] != NULL)
        {
            if (ft_atol(args[i]) == ft_atol(args[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int validar_argumentos(char **args, int start)
{
    if (!is_valid_format(args, start))
        return (0);
    if (has_duplicates(args, start))
        return (0);
    return (1);
}