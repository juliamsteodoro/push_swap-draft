/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:36:44 by marvin            #+#    #+#             */
/*   Updated: 2026/06/15 20:36:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long    ft_atol(const char *str)
{
    long sign;
    long result;
    int i;

    sign = 1;
    result = 0;
    i = 0;
    while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i]>= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        if (result > 2147483648L) 
            return (result * sign);
        i++;
    }
    return(result * sign);
}