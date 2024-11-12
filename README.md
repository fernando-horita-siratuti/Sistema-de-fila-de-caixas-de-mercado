# Sistema-de-fila-de-caixas-de-mercado

Este programa em C implementa um sistema de gerenciamento de filas para um supermercado com três caixas de atendimento, permitindo a inserção, atendimento e movimentação de clientes entre caixas abertos e fechados.

## Funcionalidades

O sistema permite as seguintes operações:

- Inserir um cliente com preferência: Um cliente com prioridade (nível 1 a 3) pode ser inserido em qualquer caixa aberto.

- Inserir um cliente sem preferência: Um cliente comum pode ser adicionado no final da fila de qualquer caixa aberto.

- Atender um cliente: Remove o cliente atual da fila de atendimento de um caixa específico.

- Abrir/Fechar um caixa: Possibilita o fechamento de um caixa, com a realocação dos clientes para outro caixa aberto, ou a reabertura de um caixa fechado.

- Consultar dados dos clientes: Exibe as informações dos clientes presentes na fila de um caixa selecionado.

- Consultar fila de caixas: Exibe a situação atual da fila de um caixa específico.

## Estrutura do Código

O programa utiliza três filas para representar cada caixa do supermercado, controlando as listas de clientes e suas preferências. 

A estrutura principal é baseada nas seguintes funções e módulos:

- Listas e Operações de Filas: criarLista(), inserirIni(), inserirFin(), desenfileirar(), e outras funções para manipulação de filas.

- Contagem e Alocação: Variáveis tam para cada caixa e tipo de cliente ajudam a rastrear o número de clientes por fila.

- Controle de Caixa: Variáveis abfecaixa indicam o status de cada caixa (aberto ou fechado).

## Conclusão

Portanto, esse projeto tem como objetivo simular um sistema de caixa de mercado, utilizando lista de preferência considerando clientes com prioridades(gestantes, idosos, etc.) ou um sistema de caixa rápido(clientes com até 15 produtos, por exemplo).