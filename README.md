# 3DG

Autoria:
> Diego Guerra<br> 
> RA: 11201810534<br>
> Juan Oliveira de Carvalho<br> 
> RA: 11201810997<br>

## Objetivos

O objetivo deste projeto é desenvolver uma aplicação simples com gráficos 3D, utilizando-se de técnicas e bibliotecas de computação gráfica.

## Motivação

Este projeto foi desenvolvido tendo em mente o ensino de movimentos circulares e pêndulos, podendo ser utilizado para demonstrar o 
movimento circular de um pêndulo ligado a uma corda de comprimento variável.

## Live demo

Uma versão compilada em WebAssembly está disponível para ser executada em qualquer navegador web neste [link](https://diegoguerra00.github.io/3DG/pendulum/).

Também é possível compilar o projeto localmente, seguindo as instruções de [instalação do ABCg](https://hbatagelo.github.io/cg/config.html), clonando o repositório e executando os scripts
```build.sh``` ou ```build.bat```, caso esteja no Linux ou Windows respectivamente. Os scripts irão compilar o projeto e criar um executável no diretório ```build```.

Nos [releases]() do repositório providenciamos um binário já compilado para Linux.

![Alt text]()

## Como Usar

O programa foi pensado para ser utilizado apenas em tela cheia, devido à necessidade de captura de inputs de mouse e teclado na janela 
do ABCg. Com o programa em tela cheia é possível utilizar os seguintes controles:

-   ```W A S D``` para se movimentar para frente, trás e para os lados
-   ```Mouse``` para controlar a direção da câmera
-   ```Caps Lock``` para destravar o mouse da janela
-   ```ESC``` para sair de tela cheia no navegador

## Funcionalidades

O programa consiste em um simulador de um pêndulo preso a uma corda fixada em uma haste fixa. É possível utilizar os controles da tela
para alterar configurações do pêndulo, como:

-   Comprimento da corda
-   Velocidade angular
-   Velocidade da animação
-   Cor da esfera do pêndulo

## Implementação
A aplicação foi implementada utilizando a biblioteca [ABCg](https://github.com/hbatagelo/abcg), desenvolvida pelo professor Harlen Batagelo para o curso de Computação Gráfica na UFABC, e o pipeline gráfico do OpenGL.

## Desafios Enfrentados
