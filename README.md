# JogoDaVida

Exercício Programa do primeiro semestre de 2022 para a disciplina de Projeto e Análise de Algoritmos I sobre o Jogo da Vida. O jogo da vida é um autómato celular desenvolvido pelo matemático britânico John Horton Conway em 1970, criado com o intuito de reproduzir as alterações em grupos de seres vivos.

# Regras

A ideia inicial é começar com uma configuração simples de células vivas em uma matriz, constituindo a primeira geração. Então, com o passar das gerações, as regras de mudança são aplicadas. As regras são:

1. Uma célula viva com 2 ou 3 vizinhos vivos, permanece viva;
2. Uma célula viva com apenas 1 ou 0 vizinhos vivos, morre (solidão);
3. Uma célula viva com 4 ou mais vizinhos, morre (sufocada);
4. Uma célula morta com exatamente 3 vizinhos vivos, renasce.

# A atividade

Como atividade, deve-se criar um jogo da vida em linguagem C. Como entrada deve-se informar o tamanho da matriz. Após deve-se pedir ao usuário informar as posições que estarão vivas no início (valor 1), para isso peça que ele informe a linha e a coluna da célula. Deve-se parar de perguntar ao usuário qual a célula deve começar viva se este digitar um valor negativo.
