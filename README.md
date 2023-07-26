# Auxiliar de Redação

<div style="display: inline-block;">    
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
</a> 
</div>

<p> </p>
<p> </p>

# Introdução
<p align="justify">
A publicação dos resultados de pesquisa é uma etapa crucial do trabalho científico. Geralmente, esses resultados são compartilhados na forma de artigos em congressos e periódicos, após passarem por uma revisão rigorosa quanto à forma e conteúdo. Infelizmente, é comum encontrar artigos na academia que apresentam dificuldades de leitura, além de conter erros de
ortografia e gramática.

<p align="justify">
Para lidar com a questão acima apresentada, existem diversas ferramentas de auxílio disponíveis. Por exemplo, no Unix, o utilitário "ispell" pode ser utilizado para verificar a ortografia de textos em inglês. Já para outras línguas e ambientes, há outras opções de ferramentas específicas. Além disso, existem ferramentas comerciais baseadas em técnicas de inteligência artificial, que buscam detectar erros gramaticais, analisar o estilo literário e fornecer estatísticas sobre parágrafos. O grammarly e o chatgpt são dois exemplos disso.

<p align="justify">
O objetivo deste trabalho é especificar, projetar e implementar um sistema que ajude no processo de redação. Para realizar essa tarefa, foi essencial escolher cuidadosamente as estruturas de dados e os respectivos algoritmos, visando a utilização eficiente do sistema na prática

<p align="justify">
O programa ira ler um arquivo contento um texto sem nenhuma formatação onde cada sentença termina por um sinal de pontuação. Cada parágrafo é separado por pelo menos uma linha em branco. Ao decorrer no texto existem palavras que nao possuem conteudo semantico, como artigos e conjunções denominadas "stop words". A lista de "stop words" foi fornecida atraves de um arquivo criado por nós.

|          Sinais de pontuação  | Stop words                                      |
|-------------------------------|-------------------------------------------------|
| `.`,   `!`,   `?`                   |   `artigos(a, o, as,os) ou conjunções(e, ou) `  |
               

<p align="justify">
A saida do programa contem diversas infomações, sendo elas: 

Para cada paragrafo do texto deve conter o numero da linha do arquivo fonte onde o paragrafo inicia e termina, o numero de sentenças existentes no paragrafo e o número de palavras de cada sentença incluindo e descartando as "stop words". A razão para inclusão dessas informações se deve ao fato de que existem em redações, parágrafos formados por uma única sentença (o que deve ser evitado), sentenças muito longas ou curtas de mais, ou mesmo uma mistura dessas situações.

As palavras que não são stop word listadas em ordem alfabéticas com a requência de sua ocorrência no texto, indicando as linhas do arquivo onde essas surgem. No caso em que a palavra aparece mais de uma vez em um mesmo parágrafo, foi indicado a sua ocorrência e a distância entre elas incluindo as stop words. Isso se deve ao fato de que é comum na escrita, principalmente científica, repetirmos palavras várias vezes ao longo do texto ou em um mesmo parágrafo.

A ocorrência de certas expressões sendo que para cada expressão foi indicado a linha no arquivo fonte onde aparece. O conjunto de expressões a serem analisadas foi lido de um arquivo txt criado por nós. Isso se deve ao fato de que existem certas expressões ou palavras que são frequentemente usadas mas não existem ou deixam o texto confuso ou pobre devido a sua inclusão. O exemplo mais comum é "em nível de" ou "a nível de" como é bem discutido pelo filólogo Vianney Mesquita, professor da Universidade Federal do Ceará em um de seus livros. Também temos exemplos de palavras que não existem ou são usadas com sentidos inadequados como "deletar" no sentido de remover, e "suportar" no sentido de ter uma funcionalidade. 


# Arquivos e Funções                                                       

O projeto é dividido entre três arquivos de códigos própriamente ditos: `leitura.hpp`, `leitura.cpp` e `main.cpp`.

|  Arquivo                        |   Função                                                                                          |
| ------------------------------- | ------------------------------------------------------------------------------------------------- |
|  `main.c`                       | Arquivo principal para iniciar e chamar as funções do código                                                    |
|  `leitura.hpp`                  | Define as funções e as estruturas que foram utilizadas no código |
|  `leitura.cpp`                  | Contém o escopo de todas as funções que foram utilizadas |
|  `expressoes.txt`               | arquivo de entrada que contem as expressões |
| `stopwords.txt` | arquivo que contem as stop words|
| `arquivo de leitura .txt` | arquivo de entrada principal no qual será feita toda a análise |

> Como saída, o programa irá gerar no terminal apenas o tempo gasto para o mesmo ser executado. Os demais resultados da análise serão exibidos em um arquivo de saida *.txt* criado à partir da execução do código.

# Lógica Implementada
 O arquivo principal, `main.cpp`, inicializa o tempo de execução, chama a função `readPrincipal()` e marca o tempo ao fim do programa, respectivamente. A função citada é a responsável por todo o funcionamento do código propriamente dito. Definida no `leitura.hpp` e trabalhada no `leitura.cpp`, ela é a que processa todas as demais funções presentes no projeto.

### Estruturas utilizadas
Na função `readPrincipal()` a primeira coias a ser feita é a declaração das principais estruturas de dados que foram utilizadas no algoritmno, no caso as estrutruras `map` e `unordered_map`. Essas estruras vão armazenar todas as infomações necessarias para construir o arquivo de saida, sendo algumas estruturas servindo apenas para auxiliar a manipular os dados. 

Para entender como a logica foi construida, é necessario entender como essas estruturas de dados funcionam, no caso o `map` é um contêiner associativo da biblioteca padrão que armazena pares de chave-valor, onde cada chave é única. É uma implementação da estrutura de dados chamada "árvore de pesquisa binária equilibrada" (também conhecida como árvore AVL) que mantém as chaves em ordem. Já o `unordered_map` é outro contêiner associativo da biblioteca padrão que armazena pares de chave-valor, assim como o `map`. No entanto, ao contrário do `map`, o `unordered_map` não mantém as chaves em ordem, mas sim os organiza em uma estrutura de tabala hash. Resumindo, o `map` é uma implementação de arvore binaria que oredena os dados, ja o `unordered_map` é uma implementação de tabela hash que só insere e não ordena.

<p align="center">
<img src="/img/AVL.png" alt="árvore AVL">
</p>

A escolha do `unodered_map` foi devido ao processo de encontrar um elemento que é feito em um tempo médio constante de (O(1)), já que a tabela hash divide os elementos em buckets com base em sua função hash, o que permite um acesso eficiente aos dados. Foram utilizadas ao total 5 estruturas de dadps sendo 4 `unordered_map` e uma `map`, são elas : `mapPrintGeral`que armazena todas as palavras do texto e suas informações, `stopWords` que armazena as stop words lidas de um arquivo .txt, `expressoes` que armazena as expressões tambem lidas de um arquivo .txt, `pontos` que armazena as pontuações, (esse `map` é preenchido manualmente na função `preencheMapPontos`), sendo essas 4 estruturas um `unodered_map`, e `mapPrintPorParagrafo` que é um `map` que armazena apenas as palavras de um determinado paragrafo, razão disso será explicada mais a frente. Alem disso existe um vector que armazenas em cada posição um `map` `mapPrintPorParagrafo`.

<p align="center">
<img src="/img/hash.png" alt="Exemplo de HASH">
</p>

### Funcionamento da função readPrincipal()
O loop principal dessa função, repete enquanto não chegar no final do arquivo de entrada inserido. Partindo disso é analisado linha por linha do texto e verificando se existe as expressões que estão no `map` de expressões. O base desse loop é feita em cima de um if que verifica se a linha que está sendo lida não é uma linha em branco, nesse caso se for uma linha em branco significa que a proxima linha já é outro parágrafo. Dentro desse if existe outro loop que pega palavra por palavra da linha e pega todas as informações da palavra, como a posição dela na paragrafo. Além disso existem dois contadores de palavras na sentança, um que conta com as stop word e outro sem. Existe uma condição que verifica se é sentença, caso essa condição seja satisfeita, o algorítmo guarda as informações da sentença em um vector de sentença (`vector<Senteca> sentecas`).

Após esse processo, existe uma estrutura condicional que verifica se a palavra adicionada no `map` é uma stop word ou não. Essa verificação se dá utilizando a função `find()`, que certifica se a palavra já está no map de stop-word.

Após todo esse processo, são salva as palavras em duas estruturas, uma de `unordered_map`, para fazer o print geral (`mapPrintGeral`) e outra de `map`, para fazer o print por parágrafo(`mapPrintPorParagrafo`). Nesse caso, é salvo as informações desse `map`em um vector, já que depois de salvar no vector o `mapPrintPorParagrafo` será limpado para poder pegar as informações de outro paragrafo. Nesse loop tambem é calculada a distância entre duas palavras iguais no mesmo parágrafo.

Ao final da função é chamado duas funções de print a `outputParagrafos` e `outputGeral`. A função  `outputParagrafos` printa no arquivo de saida as informações de cada paragrafo, como a linha que ele começa e a linha que ele termina, a quantidade de palavras com e sem stop word, alem de printar as informações de cada palavra do paragrafo, como a quantidade de vez que ela aparece e sua posição. Já o `outputGeral` printa todas as palavras do texto em ordem alfabetica e suas respectivas informações, para isso foi necessario copiar todas as informações do unoderd_map para um vector, esse preocedmento é necessario para que possamos ordenar com sort, ele ordena o vetor com base nas chaves do map. Ele printa tambem ao final do arquivo, as expressões. 

> Existe uma situação no qual o ultimo paragrafo do texto não é lido, isso depende da formatação dele. Para resolver este problema, foi criado um booleano decisão que é responsável por tomar a decisão se o último paragrafo foi lido ou não. Este booleano é iniciado com false, e recebe falso toda vez que uma linha é tokenizada. O true só é atribuído à variável no else.
Então, por meio de um if após o loop de leitura, no caso onde o input do programa tivesse dois \n, a variável booleana iria impedir o paragrafo de ser lido duas vezes, e no caso de apenas um \n, ele seria percorrida dentro do if, finalizando a leitura de todas as linhas corretamente. 

# Testes Realizados
- Os testes que serão apresentados abaixo foram feitos em um Notebook Acer Nitro 5 (intel i5 10300H - gtx 1650 - 8gb ram).
- O tempo médio foi feito à partir de uma média simples do tempo de 8 execuções do algorítmo.

|  Arquivo                        |   Tempo Médio                                                                                          |   Quantidade de Palavras |
| ------------------------------- | ------------------------------------------------------------------------------------------------- | ------------------------------ |
|  `DomCasmurro.txt`                       | 2,62 segundos                                   | 9152 |
| `Biblia.txt`      | 21,43 segundos | 28736 |
| `Semana_Machado_Assis.txt` | 27,1262 segundos | 25021 |

- Os exemplos de *output* apresentados abaixo foram retirados da execução do algorítmo analisando o arquivo `Semana_Machado_Assis.txt`.

<img src="/img/redacao2.jpeg">

- Todo incício de um novo parágrafo, o arquivo `outputt.txt` apresenta um resumo como esse, exibindo as seguintes informações:
  - Linha inicial
  - Linha final
  - Sentença
  - Stop-Word
  - Não stop-word

 <img src="/img/redacao1.jpeg">

- As palavras contidas em cada parágrafo são identificadas, separadas e analisadas uma a uma. Cada palavra possui um atributo único de características básicas:
  - Número do parágrafo que está localizada
  - Sentença
  - Linha
  - Número de aparições
  - Posição no parágrafo
  - Distância entre aparições (caso tenha mais de uma aparição)
 
> Cada parágrafo do texto é exibido da forma apresentada acima. A análise de cada palavra permite fazer uma distinção única uma a uma, auxiliando na observação da redação.

- Após o print por parágrafos, é exibido, em ordem alfabética, todas as palavras presentes no texto analisado:

<img src="/img/redacao5.jpeg">

- Um outro tipo de print do `outputt.txt` apresenta um resumo, por parágrafo, de:
  - Número de sentenças
  - Número de palavras com stop-word
  - Número de palavras sem stop-word

 <img src="/img/redacao6.jpeg">

- Por fim, um último tipo de print do arquivo de texto de saída, faz um resumo por expressão, apresentando a linha em que cada uma expressão aparece na obra literária tida como base na análise do algorítmo.

<img src="/img/redacao7.jpeg">

O terminal *WSL* apresenta, apenas, o número de palavras totais do texto analisado e o tempo em segundos que o algorítmo demorou para ser executado.

<img src="/img/redacao4.jpeg">

# Conclusão
<p align="justify">
  Em conclusão, o projeto "Auxiliar de Redação" cumpre seu papel com êxito. A estrutura "unordered_map", utilizada para fazer o armazenamento de palavras, tem como base de funcionamento uma tabela hash, feito em um tempo médio constante (O(1)), pois os elementos são dividos em "baldes", permitindo um acesso eficiente à eles. Entretanto, em algum caso raro de colisão de posição, a complexidade pode se aproximar de (O(n)), devido à nova ordenação de nova seleção de posição dos elementos. Como base de comparação, a estrutura "map" simples, tem custo médio (O(logn)), logo, a escolha do "unordered_map" se mostrou bastante favorável.
  <br><br>
  A funcionalidade e praticidade do algorítmo pode ser provada à partir da "análise de resultados" apresentada acima, já que ele investiga palavra por palavra de um arquivo de texto extremamente extenso, com uma variedade enorme de palavras em um tempo relativamente pequeno, se comparar com todas as verificações feitas por ele.
<p> </p>

# Compilação e Execução

Esse pequeno exemplo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

<p> </p>

# Contatos

#### Felipe Werneck
<div style="display: inline-block;">
<a href="https://t.me/felipewom">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/felipe-werneck-93520a209">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

#### Felipe Parreiras
<div style="display: inline-block;">
<a href="https://t.me/fparreiras">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/felipe-parreiras-56b075277/">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

#### José Marconi Almeida
<div style="display: inline-block;">
<a href="https://t.me/jmarconia">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/jmarconi-almeida/">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

#### Lucas Fernandes
<div style="display: inline-block;">
<a href="https://t.me/lucas_fba">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/lucas-fernandes-381091204/">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

<p> </p>
