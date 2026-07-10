/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 09:59:52 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 09:59:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int validate_arg(char **args, int start)
{
    if (!is_valid_format(args, start))
        return (0);
    if (has_duplicates(args, start))
        return (0);
    return (1);
}

int is_valid_format(char **args, int start)
{
    int i;
    int j;
    long value;

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
        value = ft_atol(args[i]);
        if (value > 2147483647 || value < -2147483648)
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