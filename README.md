# Jantar dos Filósofos
Trabalho 2 - Disciplina Sistema Operacionais

Um conjunto N de filósofos está sentado em torno de uma mesa circular. Cada filósofo tem um prato de espaguete. O espaguete está tão escorregadio que o filósofo precisa de dois garfos para comê-lo. Entre cada par de pratos está um garfo. A vida de um filósofo consiste em alternar períodos de comer e pensar. Quando o filósofo fica com fome, ele tenta pegar os garfos a sua esquerda e a sua direita, um de cada vez. Se ele conseguir pegar os dois garfos, ele comerá durante um determinado tempo e, então, colocará os garfos na mesa novamente e continuará a pensar.

[Descrição completa do trabalho](docs/Descricao_Projeto_2.pdf)

## Compilcação do projeto

O projeto utiliza [cmake](https://cmake.org) como sistema gerador de build. Para você gerar o executável do projeto basta executar os comandos abaixo:
 
```
mkdir build
cd build
cmake ../
make
```
