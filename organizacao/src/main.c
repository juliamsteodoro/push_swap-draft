/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/07/05 18:20:32 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/* Função estática interna para evitar o uso da proibida strcmp */
static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/* Mostra o estado atual das pilhas de forma visual */
static void	print_status(char *label, t_stack *a, t_stack *b)
{
	t_stack	*curr;

	printf("\n--- 🔍 %s ---\n", label);
	printf("Pilha A (Top->Bottom): ");
	curr = a;
	if (!curr)
		printf("(vazia)");
	while (curr)
	{
		printf("[%d Idx:%d] -> ", curr->value, curr->index);
		curr = curr->next;
	}
	printf("NULL\nPilha B (Top->Bottom): ");
	curr = b;
	if (!curr)
		printf("(vazia)");
	while (curr)
	{
		printf("[%d] -> ", curr->value);
		curr = curr->next;
	}
	printf("NULL\n--------------------------------\n");
}

/* Converte os argumentos de texto em array de inteiros */
static int	*popular_numbers(char **args, int start, int len)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * len);
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < len)
	{
		numbers[i] = (int)ft_atol(args[start + i]);
		i++;
	}
	return (numbers);
}

static void	print_strategy_name(int strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		printf("»» FORÇADA: Simples O(n²)\n");
	else if (strategy == STRATEGY_MEDIUM)
		printf("»» FORÇADA: Média O(n√n)\n");
	else if (strategy == STRATEGY_COMPLEX)
		printf("»» FORÇADA: Complexa O(n log n)\n");
	else
		printf("»» AUTOMÁTICA: Adaptativa (Baseada em Caos)\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*numbers;
	int		len;
	int		strategy;
	int		start;

	if (argc < 2)
		return (0);
	strategy = STRATEGY_ADAPTIVE;
	start = 1;
	if (argc > 2 && argv[1] != NULL && argv[1][0] == '-' && argv[1][1] == '-')
	{
		if (ft_strcmp(argv[1], "--simple") == 0)
			strategy = STRATEGY_SIMPLE;
		else if (ft_strcmp(argv[1], "--medium") == 0)
			strategy = STRATEGY_MEDIUM;
		else if (ft_strcmp(argv[1], "--complex") == 0)
			strategy = STRATEGY_COMPLEX;
		else if (ft_strcmp(argv[1], "--adaptive") == 0)
			strategy = STRATEGY_ADAPTIVE;
		else
			return (ft_error(), 1);
		start = 2;
	}
	if (!validar_argumentos(argv, start))
		return (ft_error(), 1);
	a = NULL;
	b = NULL;
	len = argc - start;
	numbers = popular_numbers(argv, start, len);
	if (!numbers || !ft_init_stack(&a, numbers, len))
		return (free(numbers), 1);
	ft_index_stack(&a);

	printf("\n=========================================\n");
	printf("       📊 PAINEL DE CONTROLE PUSH_SWAP    \n");
	printf("=========================================\n");
	printf("• Total de elementos recebidos: %d\n", len);
	printf("• Taxa de Caos / Desordem: %.2f%%\n", ft_chaos(numbers, len) * 100);
	print_strategy_name(strategy);
	
	print_status("ESTADO INICIAL DAS PILHAS", a, b);
	printf("\n🚀 [Iniciando a execução dos movimentos de ordenação...]\n\n");

	orchestration_sorting(&a, &b, len, numbers, strategy);

	printf("\n🏁 [Execução concluída!]\n");
	print_status("ESTADO FINAL DAS PILHAS", a, b);

	if (ft_is_sorted(a) && b == NULL)
		printf("✅ RESULTADO: Pilha A ordenada com sucesso e Pilha B vazia!\n");
	else
		printf("❌ RESULTADO: Falha na ordenação ou nós perdidos em B!\n");

	free(numbers);
	ft_free_stack(&a);
	ft_free_stack(&b);
	printf("🧹 Memória completamente liberada. Pronta para avaliação!\n");
	return (0);
}