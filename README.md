# push_swap

> Este projeto foi criado como parte do currículo da **42**, por **nde-mace** e **jumoreir**.

---

# 📋 Descrição

O **push_swap** é um projeto de algoritmos de ordenação cujo objetivo é ordenar uma pilha de dados (**Pilha A**) utilizando um conjunto limitado de instruções, minimizando o número total de operações realizadas.

Esta versão do projeto implementa um **motor adaptativo personalizado** integrado a seletores de controle operacionais, que calcula o grau de desordem inicial da entrada e escolhe automaticamente a estratégia de ordenação ideal para maximizar a eficiência de tempo e espaço, respeitando limites teóricos assintóticos rigorosos.

---

# 🛠️ Instruções

## Compilação

Para compilar o binário principal, utilize:

```bash
make
```

Regras adicionais do Makefile:

```bash
make clean
make fclean
make re
```

---

# 🚀 Execução e Sinalizadores

O programa aceita uma lista de inteiros e suporta seletores de estratégia opcionais que sobrepõem o comportamento automático.

## Modo Adaptativo (Padrão)

Escolhe automaticamente a estratégia com base no cálculo de desordem.

```bash
./push_swap 3 4 1 2 7 8 5 6 10 9
```

---

## Forçar Estratégia Simples — $O(n^2)$

```bash
./push_swap --simple 10 9 8 7 6 5 4 3 2 1
```

---

## Forçar Estratégia Média — $O(n\sqrt{n})$

```bash
./push_swap --medium 1 2 3 4 5 6 7 9 8 10
```

---

## Forçar Estratégia Complexa — $O(n \log n)$

```bash
./push_swap --complex 1 2 3 4 5 7 6
```

---

## Modo Benchmark

Exibe métricas detalhadas de desempenho na saída de erro (**stderr**).

Pode ser combinado com qualquer seletor de estratégia.

```bash
./push_swap --bench --adaptivo 3 4 1 2 7 8 5 6 10 9
```

---

# 🔬 Justificativa dos Limites e Análise de Complexidade

O motor adaptativo calcula o coeficiente de caos e desordem da pilha antes de iniciar a ordenação, direcionando a execução para três regimes distintos.

---

## 1. Baixa Desordem

**Desordem < 0,2**

### Complexidade Teórica

$$
O(n^2)
$$

### Técnica Utilizada

**Insertion Sort adaptado para pilhas.**

### Justificativa

Quando a lista está muito próxima da ordenação, o custo de inicializar estruturas mais sofisticadas supera o benefício obtido. Um algoritmo de inserção adaptado posiciona diretamente os poucos elementos fora de ordem utilizando poucas movimentações, mantendo complexidade espacial auxiliar:

$$
O(1)
$$

---

## 2. Desordem Média

**0,2 ≤ Desordem < 0,5**

### Complexidade Teórica

$$
O(n\sqrt{n})
$$

### Técnica Utilizada

**Chunk Sort**, baseado em subconjuntos de tamanho:

$$
\sqrt{n}
$$

### Justificativa

Para níveis intermediários de desordem, dividir a Pilha A em blocos reduz significativamente o custo das rotações.

Os elementos são enviados para a Pilha B em intervalos ordenados e posteriormente reinseridos na Pilha A em ordem crescente, equilibrando o número de operações.

---

## 3. Alta Desordem

**Desordem ≥ 0,5**

### Complexidade Teórica

$$
O(n \log n)
$$

### Técnica Utilizada

**Radix Sort** utilizando indexação binária.

### Justificativa

Listas altamente caóticas exigem comportamento assintótico previsível.

O algoritmo percorre os bits dos índices normalizados, distribuindo temporariamente os elementos entre as pilhas A e B conforme o valor de cada bit.

Dessa forma, obtém-se:

$$
O(n \times \text{número de bits})
$$

eliminando casos patológicos e mantendo crescimento controlado.

---

# 🧠 Descrição das Funções do Projeto

## main.c

### `main`

Ponto de entrada do programa.

Inicializa a estrutura de benchmark, gerencia a interceptação das flags e escolhe o fluxo adequado de processamento.

---

### `parse_flags`

Intercepta argumentos iniciados por `-`.

Configura as variáveis internas responsáveis por selecionar:

- modo adaptativo;
- estratégia simples;
- estratégia média;
- estratégia complexa;
- benchmark.

---

### `process_arguments`

Responsável por:

- medir a quantidade de argumentos válidos;
- inicializar as pilhas A e B;
- preencher as estruturas com os inteiros;
- iniciar a ordenação;
- liberar toda a memória alocada.

---

### `run_sorting`

Orquestra toda a estratégia de ordenação.

Responsável por:

- calcular a desordem inicial;
- indexar os valores;
- executar o algoritmo selecionado;
- emitir o relatório de benchmark (quando ativado).

---

### `get_matrix_len`

Função auxiliar que percorre matrizes terminadas em `NULL`, retornando sua quantidade de elementos.

---

# bench_operations.c

## `init_bench`

Inicializa e zera todos os campos da estrutura `t_bench`.

---

## `increment_op`

Intercepta cada operação executada (`sa`, `pb`, `ra`, `rra`, etc.), incrementando:

- contador total;
- contador específico daquela operação.

---

## `print_bench_report`

Imprime no **stderr**:

- número total de operações;
- percentual de desordem;
- estratégia utilizada.

---

# bench_utils.c

## `ft_dprintf`

Implementação simplificada de `dprintf`, utilizando um descritor de arquivo explícito.

---

## `print_format`

Processa especificadores como:

- `%d`
- `%s`
- `%.2f`
- `%%`

encaminhando cada um para sua função correspondente.

---

## `ft_putfloat_fd`

Imprime valores de ponto flutuante.

---

## `ft_putnbr_fd`

Imprime números inteiros.

---

## `ft_strcmp`

Realiza comparação determinística entre duas strings.

Utilizada principalmente para identificar flags e comandos.

---

#  Uso de Inteligência Artificial

Em conformidade com as diretrizes do regulamento da **42**, a Inteligência Artificial foi utilizada como ferramenta de apoio técnico nas seguintes atividades:

## Refatoração e Otimização para Norminette

Auxílio na redução de funções para obedecer rigorosamente aos limites de:

- até **25 linhas por função**;
- até **80 caracteres por linha**.

---

## Arquitetura de Tratamento de Erros

Suporte na modelagem do fluxo de validação de argumentos, tratamento de offsets de strings e prevenção de:

- vazamentos de memória;
- falhas de segmentação;
- inconsistências ao combinar múltiplas flags.

---

## Estruturação da Documentação

Auxílio na elaboração da documentação técnica e da justificativa teórica das estratégias assintóticas implementadas.

## Contribuições

Algorithms: Simples e Médio (Nathalia), Complexo (Julia), Adaptativo (Nathalia e Julia)
Operations: Nathalia e Julia
Parsing: Nathalia
Stack: Julia