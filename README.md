# Flightium

> 20/20

## Português

Este repositório destina-se à plataforma de gestão e análise de tráfego aéreo **Flightium**, desenvolvida no âmbito da unidade curricular “Laboratórios de Informática III”. Esta aplicação interativa por terminal e em modo batch foi concebida para processar, indexar e consultar grandes volumes de dados da indústria de aviação, abrangendo passageiros, voos, aeroportos, companhias aéreas e reservas de viagens. O sistema aplica conceitos avançados de estruturação de dados em memória, algoritmos de ordenação eficientes e técnicas de indexação em linguagem C para processar e analisar milhões de registos com alta performance.

A integridade do ecossistema assenta num subsistema de parsing robusto que valida e processa ficheiros CSV de grande escala. Cada entidade — como passageiros (perfis de utilizadores), voos (origem, destino, companhia aérea, aeronave e horários) e reservas (datas, preços e classificações) — é submetida a validações estritas de formato de datas, integridade de referências e consistência de dados. A arquitetura de armazenamento utiliza tabelas de dispersão (hash tables) e estruturas genéricas da biblioteca GLib, garantindo tempos de procura próximos de $O(1)$ para pesquisas chave-valor e travessias rápidas sobre os registos associados.

As consultas sobre a base de dados são disponibilizadas através de um motor de interrogações (Queries) otimizado. O utilizador pode extrair informações sobre o tráfego de aeroportos, ocupação média de voos, perfis financeiros de passageiros, e estatísticas de atrasos, ordenados e filtrados dinamicamente. Para facilitar a utilização, o sistema divide-se em três programas: o batch (para processamento de ficheiros de entrada), o interativo (interface de terminal baseada em ncurses) e o de testes (que valida a corretidão e performance do motor de pesquisa comparando os resultados gerados com os esperados).

Made with ❤️ by Diogo Azevedo, Bruno Magalhães & Vera Almeida

## English

This repository is intended for the air traffic management and analysis platform **Flightium**, developed as part of the academic course “Software Labs III”. This interactive terminal and batch-mode application was designed to process, index, and query massive volumes of aviation industry datasets, covering passengers, flights, airports, airlines, and travel reservations. The system applies advanced concepts of in-memory data structures, efficient sorting algorithms, and indexing techniques in C to process and analyze millions of records with high performance.

The integrity of the ecosystem relies on a robust parsing subsystem that validates and processes large-scale CSV files. Each entity—such as passengers (user profiles), flights (origin, destination, airline, aircraft, and schedules), and reservations (dates, prices, and ratings)—is subjected to strict validation of date formats, reference integrity, and data consistency. The storage architecture utilizes hash tables and search structures from the GLib library, guaranteeing lookup times close to $O(1)$ for key-value searches and rapid traversals over associated records.

Queries on the database are made available through an optimized query engine. Users can extract information on airport traffic, average flight occupancy, financial profiles of passengers, and delay statistics, sorted and filtered dynamically. To facilitate usage, the system is divided into three programs: batch (for input file processing), interactive (an ncurses-based terminal UI), and testing (which validates the correctness and performance of the query engine against expected outputs).

Made with ❤️ by Diogo Azevedo, Bruno Magalhães & Vera Almeida

## Comandos - Commands

### Compilação - Build

[PT] Pode compilar todos os programas do projeto utilizando o utilitário `make` na raiz.\
[EN] You can compile all the programs of the project using the `make` utility in the root.

```bash
make
```

[PT] Para limpar os ficheiros objeto e executáveis gerados durante a compilação.\
[EN] To clean up object files and executables generated during compilation.

```bash
make clean
```

### Execução - Execution

[PT] O projeto gera três executáveis distintos para diferentes modos de funcionamento:\
[EN] The project generates three distinct executables for different operating modes:

#### 1. Programa Principal (Batch Mode)

[PT] Executa consultas de forma não-interativa a partir de um ficheiro de comandos.\
[EN] Executes queries non-interactively from a commands file.

```bash
./programa-principal <pasta_de_dados_csv> <ficheiro_de_queries>
```

#### 2. Programa Interativo (Interactive TUI)

[PT] Abre a interface interativa no terminal (TUI) desenvolvida com a biblioteca `ncurses`.\
[EN] Opens the interactive terminal user interface (TUI) developed with the `ncurses` library.

```bash
./programa-interativo <pasta_de_dados_csv>
```

#### 3. Programa de Testes (Testing Suite)

[PT] Executa a suite de testes automáticos comparando os outputs gerados com os resultados esperados.\
[EN] Runs the automatic testing suite comparing generated outputs with the expected results.

```bash
./programa-testes <pasta_de_dados_csv> <pasta_de_inputs> <pasta_de_resultados_esperados>
```

## Documentação - Documentation

[PT] A especificação do projeto e os relatórios de desenvolvimento de ambas as fases estão disponíveis na pasta `docs/`.\
[EN] The project specification and development reports for both phases are available in the `docs/` folder.
