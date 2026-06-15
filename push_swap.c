/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:20:49 by marvin            #+#    #+#             */
/*   Updated: 2026/06/15 19:20:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    char    **args;
    int     i;
    t_stack *new_node;
    t_stack *stack_a;
    t_stack *last;

    // Inicializa os ponteiros como NULL para não começarem com lixo de memória
    stack_a = NULL;
    last = NULL;

    if (argc < 2)
        return (0);
    if (argc == 2)
    {
       args = ft_split(argv[1], ' ');
        if (args == NULL)
        {
            ft_error();
            return (0);
        }
        i = 0;
    }
    else
    {
        args = argv;
        i = 1;
    }

if (validar_argumentos(args, i) == 0) // DAR FREE!!!
{
    ft_error();
    if (argc == 2)
        free_split(args);
    return (0);
}
while (args[i] != NULL)
    {
        new_node = ft_newstack(ft_atol(args[i]));
        if (new_node == NULL)
        {
            ft_error();
            if (argc == 2)
                free_split(args);
            return (0);
        }
        if (stack_a == NULL)
        {
            stack_a = new_node;
            last = new_node;
        }
        else
        {
            last->next = new_node;
            new_node->prev = last;
            last = new_node;
        }
        i++;
    }
    return (0);
}
