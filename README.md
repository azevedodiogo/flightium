# Flightium

> 20/20

## Português

Este repositório destina-se à plataforma de gestão e análise de tráfego aéreo Flightium, desenvolvida no âmbito da unidade curricular “Laboratórios de Informática III”. Esta aplicação interativa por terminal e em modo batch foi concebida para processar, indexar e consultar grandes volumes de dados da indústria de aviação, abrangendo passageiros, voos, aeroportos, companhias aéreas e reservas de viagens. O sistema aplica conceitos avançados de estruturação de dados em memória, algoritmos de ordenação eficientes e técnicas de indexação em linguagem C para processar e analisar milhões de registos com alta performance.

A integridade do ecossistema assenta num subsistema de parsing robusto que valida e processa ficheiros CSV de grande escala. Cada entidade, como passageiros que representam perfis de utilizadores, voos com origem, destino, companhia aérea, aeronave e horários, e reservas que guardam informações sobre hotéis e custos, é submetida a validações estritas de formato de datas, integridade de referências e consistência de dados. A arquitetura de armazenamento utiliza tabelas de dispersão e estruturas da biblioteca GLib, garantindo tempos de procura próximos de O(1) para pesquisas chave-valor e travessias rápidas sobre os registos associados.

As consultas sobre a base de dados são disponibilizadas através de um motor de interrogações otimizado que executa seis tipos de queries. A Query 1 identifica um aeroporto pelo seu código IATA e retorna a sua localização e volume acumulado de tráfego. A Query 2 lista as N aeronaves mais ativas com maior registo de voos efetuados, permitindo um filtro opcional por fabricante. A Query 3 encontra o aeroporto que obteve o maior número de visitas totais durante um intervalo de datas. A Query 4 determina o passageiro que gastou a quantia mais elevada no acumulado de voos e reservas no período temporal fornecido. A Query 5 identifica as N companhias aéreas com o maior atraso médio nos seus voos. A Query 6 determina qual o aeroporto que recebeu o maior número de voos de passageiros de uma determinada nacionalidade. Todas as queries suportam uma variação de sintaxe onde o caracter S após o identificador altera o delimitador padrão de ponto e vírgula para o símbolo de igualdade no ficheiro de saída.

Para facilitar a utilização, o sistema divide-se em três programas executáveis principais. O programa-principal funciona em modo batch e processa consultas a partir de um ficheiro de comandos gerando outputs na pasta de resultados. O programa-interativo oferece uma interface textual TUI baseada em ncurses onde a navegação de menus é feita com as setas direcionais e ENTER, os parâmetros são inseridos numa caixa de texto e o ecrã de resultados suporta scroll vertical e horizontal com as setas ou Page Up e Page Down, regressando com a tecla q. O programa-testes executa de forma automática as queries de teste e compara os ficheiros gerados com respostas esperadas de referência para validar a corretidão e medir o tempo de execução exato.

Made with ❤️ by Diogo Azevedo, Bruno Magalhães & Vera Almeida

## English

This repository is intended for the air traffic management and analysis platform Flightium, developed as part of the academic course “Software Labs III”. This interactive terminal and batch-mode application was designed to process, index, and query massive volumes of aviation industry datasets, covering passengers, flights, airports, airlines, and travel reservations. The system applies advanced concepts of in-memory data structures, efficient sorting algorithms, and indexing techniques in C to process and analyze millions of records with high performance.

The integrity of the ecosystem relies on a robust parsing subsystem that validates and processes large-scale CSV files. Each entity, such as passengers representing user profiles, flights with origin, destination, airline, aircraft, and schedules, and reservations storing hotel and cost details, is subjected to strict validation of date formats, reference integrity, and data consistency. The storage architecture utilizes hash tables and search structures from the GLib library, guaranteeing lookup times close to O(1) for key-value searches and rapid traversals over associated records.

Queries on the database are made available through an optimized query engine that runs six core queries. Query 1 looks up an airport by its IATA code and returns its location and accumulated traffic volume. Query 2 lists the top N aircraft with the highest count of registered flights, allowing an optional filter by manufacturer name. Query 3 finds the airport with the highest total visits within a specified date range. Query 4 determines the passenger who spent the most overall on flights and reservations during a given time window. Query 5 lists the top N airlines with the largest average flight delays. Query 6 calculates which airport received the most flights carrying passengers of a given nationality. All queries support a syntax variant where an S character after the query number changes the standard semicolon separator to an equals separator in the output files.

To facilitate usage, the system is divided into three main executable programs. The programa-principal works in batch mode and processes input query files, generating formatted output text in the results directory. The programa-interativo offers an interactive terminal user interface powered by ncurses where menus are navigated using arrow keys and ENTER, parameters are typed into a text box, and the results view supports scrolling with arrow keys or Page Up and Page Down, returning with the q key. The programa-testes automatically executes test inputs and compares the outputs with expected reference files to validate correctness and measure exact execution times.

Made with ❤️ by Diogo Azevedo, Bruno Magalhães & Vera Almeida

## Comandos - Commands

### Compilação - Build

[PT] Pode compilar todos os programas do projeto utilizando o utilitário `make` na raiz. A compilação gera automaticamente os três binários da aplicação.\
[EN] You can compile all the programs of the project using the `make` utility in the root. The compilation process automatically generates all three binaries.

```bash
make
```

[PT] Para apagar todos os ficheiros objeto (`.o`), ficheiros auxiliares de compilação e os executáveis gerados:\
[EN] To delete all object files (`.o`), compiler build artifacts, and compiled executables:

```bash
make clean
```

### Execução - Execution

O projeto dispõe de três executáveis correspondentes a três modos distintos de operação:

#### 1. Programa Principal (Batch Mode)

[PT] Processa consultas sequencialmente a partir de um ficheiro de comandos de entrada, sem qualquer intervenção do utilizador. Escreve os resultados na pasta `resultados/` com o nome `commandN_output.txt` (onde N é o número da linha da query).\
[EN] Processes queries sequentially from an input command file, without user intervention. Outputs are written in the `resultados/` directory under the filename `commandN_output.txt` (where N corresponds to the query line number).

```bash
./programa-principal <pasta_de_dados_csv> <ficheiro_de_queries.txt>
```

*Exemplo de ficheiro de queries (`queries.txt`):*
```text
1 LIS
1S OPO
2 10 Boeing
3 2023-01-01 2023-12-31
4 2023-06-01 2023-08-31
5 5
6 Portugal
```

#### 2. Programa Interativo (Interactive TUI Mode)

[PT] Executa uma interface textual baseada em janelas de terminal (TUI) utilizando a biblioteca `ncurses`. Fornece uma navegação dinâmica e fluida pelos dados e consultas:\
[EN] Runs a terminal window user interface (TUI) powered by the `ncurses` library. Provides dynamic navigation through the dataset and queries:

```bash
./programa-interativo <pasta_de_dados_csv>
```

#### 3. Programa de Testes (Testing Suite)

[PT] Executa de forma automatizada todas as queries de teste fornecidas, comparando os outputs resultantes com as respostas esperadas (arquivos de referência) para validar a corretidão do motor. Mede e imprime o tempo gasto no parsing dos ficheiros e no cálculo das queries.\
[EN] Runs all provided test queries automatically, comparing output files against reference results to validate correctness. Measures and displays the exact time taken for parsing dataset files and executing queries.

```bash
./programa-testes <pasta_de_dados_csv> <pasta_de_inputs_queries> <pasta_de_resultados_esperados>
```

---

## Documentação - Documentation

[PT] A especificação oficial do projeto, bem como os relatórios científicos detalhados correspondentes à Fase 1 e à Fase 2 (descrevendo a modelação do domínio, estruturas de dados e otimização das queries) encontram-se disponíveis em formato PDF na pasta `docs/`.\
[EN] The official project specification and detailed scientific reports for Phase 1 and Phase 2 (describing domain modeling, data structures, and query optimizations) are available as PDF files in the `docs/` folder.
