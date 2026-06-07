# Flightium

> 20/20

## Português

Este repositório destina-se à plataforma de gestão e análise de tráfego aéreo Flightium, desenvolvida no âmbito da unidade curricular “Laboratórios de Informática III”. Esta aplicação interativa por terminal e em modo batch foi concebida para processar, indexar e consultar grandes volumes de dados da indústria de aviação, abrangendo passageiros, voos, aeroportos, companhias aéreas e reservas de viagens. O sistema aplica conceitos avançados de estruturação de dados em memória, algoritmos de ordenação eficientes e técnicas de indexação em linguagem C para processar e analisar milhões de registos com alta performance.

A integridade do ecossistema assenta num subsistema de parsing robusto que valida e processa ficheiros CSV de grande escala. Cada entidade — como passageiros (perfis de utilizadores), voos (origem, destino, companhia aérea, aeronave e horários) e reservas (datas, preços e classificações) — é submetida a validações estritas de formato de datas, integridade de referências e consistência de dados. A arquitetura de armazenamento utiliza tabelas de dispersão (hash tables) e estruturas genéricas da biblioteca GLib, garantindo tempos de procura próximos de $O(1)$ para pesquisas chave-valor e travessias rápidas sobre os registos associados.

### Funcionalidades e Motor de Queries (Queries Engine)

O motor de pesquisa disponibiliza 6 queries essenciais para extração de estatísticas e inteligência de dados sobre a base de dados de aviação carregada:

* Query 1 (Informação de Aeroporto): Identifica um aeroporto pelo seu código IATA (ex: `LIS`) e retorna os dados de localização (nome, cidade, país e tipo) juntamente com o volume acumulado de tráfego (voos de partida e voos de chegada).
* Query 2 (Aeronaves mais Ativas): Lista as `N` aeronaves com maior registo de voos efetuados. O utilizador pode opcionalmente aplicar um filtro por fabricante (ex: `Boeing`). Retorna a lista ordenada decrescentemente por voos contendo ID da aeronave, fabricante, modelo e número de voos.
* Query 3 (Aeroporto com Maior Tráfego Temporal): Encontra o aeroporto que obteve o maior número de visitas totais (chegadas + partidas) durante um intervalo de datas específico (formato `YYYY-MM-DD YYYY-MM-DD`). Retorna os dados do aeroporto e o número total de voos.
* Query 4 (Passageiro com Maior Despesa): Determina o utilizador/passageiro que gastou a quantia mais elevada no acumulado de voos e reservas no período temporal fornecido (formato `YYYY-MM-DD YYYY-MM-DD`). Devolve o documento do passageiro, nome, apelido, data de nascimento, nacionalidade e o valor total em formato financeiro.
* Query 5 (Companhias com Maiores Atrasos Médios): Identifica as `N` companhias aéreas (airlines) com o maior atraso médio nos seus voos (calculado a partir dos minutos de atraso à partida). Retorna a listagem ordenada contendo o nome da companhia aérea, quantidade de voos com atraso e média exata de atraso.
* Query 6 (Aeroporto Predileto por Nacionalidade): Recebe uma nacionalidade (ex: `Portugal`) e determina qual o aeroporto que recebeu o maior número de voos onde passageiros dessa nacionalidade viajaram. Devolve o código IATA do aeroporto e o contador correspondente.

### Sintaxe de Comando (Formatos de Output)

Ao executar as queries, a aplicação suporta duas variações de formatação de resultados baseadas no comando fornecido:
1. Formato Padrão (Sem Suffix): Os comandos são representados apenas pelo número da query (ex: `1 LIS`). O output gerado separa os campos usando o delimitador ponto e vírgula (`;`).
2. Formato Alternativo (Com Suffix `S`): Os comandos incluem um `S` após o identificador (ex: `1S LIS`). O output correspondente formata as respostas separando os campos com o símbolo de igualdade (`=`).

Made with ❤️ by Diogo Azevedo, Bruno Magalhães & Vera Almeida

---

## English

This repository is intended for the air traffic management and analysis platform Flightium, developed as part of the academic course “Software Labs III”. This interactive terminal and batch-mode application was designed to process, index, and query massive volumes of aviation industry datasets, covering passengers, flights, airports, airlines, and travel reservations. The system applies advanced concepts of in-memory data structures, efficient sorting algorithms, and indexing techniques in C to process and analyze millions of records with high performance.

The integrity of the ecosystem relies on a robust parsing subsystem that validates and processes large-scale CSV files. Each entity—such as passengers (user profiles), flights (origin, destination, airline, aircraft, and schedules), and reservations (dates, prices, and ratings)—is subjected to strict validation of date formats, reference integrity, and data consistency. The storage architecture utilizes hash tables and search structures from the GLib library, guaranteeing lookup times close to $O(1)$ for key-value searches and rapid traversals over associated records.

### Features and Queries Engine

The search core implements 6 essential queries designed to extract statistics and data insights from the loaded aviation database:

* Query 1 (Airport Information): Looks up an airport by its IATA code (e.g., `LIS`) and returns its localization details (name, city, country, and type) alongside the total accumulated volume of departure and arrival flights.
* Query 2 (Most Active Aircraft): Lists the top `N` aircraft with the highest count of registered flights. Users can optionally filter by manufacturer name (e.g., `Boeing`). Returns the list sorted in descending order of flights containing the aircraft ID, manufacturer, model, and flight count.
* Query 3 (Most Visited Airport in Time Range): Finds the airport with the highest total visits (arrivals + departures) within a specified date range (format `YYYY-MM-DD YYYY-MM-DD`). Returns the airport info and flight counter.
* Query 4 (Highest Spending Passenger): Determines the passenger/user who spent the most money overall on flights and reservations during a given time window (format `YYYY-MM-DD YYYY-MM-DD`). Returns the document number, name, surname, date of birth, nationality, and total expenditure.
* Query 5 (Airlines with Highest Average Delays): Lists the top `N` airlines with the largest average flight delays (calculated from departure delay minutes). Returns the sorted list including the airline name, count of delayed flights, and average delay.
* Query 6 (Favorite Airport by Nationality): Takes a nationality (e.g., `Portugal`) and calculates which airport received the most flights carrying passengers of that nationality. Returns the airport IATA code and passenger count.

### Command Syntax (Output Formatting)

When executing queries, the application supports two output formatting variations depending on the command syntax:
1. Standard Format (No Suffix): Command is specified with only the query number (e.g., `1 LIS`). The output file separates values using the semicolon (`;`) delimiter.
2. Alternative Format (With `S` Suffix): Command includes an `S` after the number (e.g., `1S LIS`). The output file separates values using the equals (`=`) delimiter.

Made with ❤️ by Diogo Azevedo, Bruno Magalhães & Vera Almeida

---

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

Controlos da Interface (TUI Controls):
* Navegação de Menus: Utilize as setas direcionais (Cima / Baixo) para navegar pelas opções do menu principal e das queries. Pressione ENTER para confirmar a seleção.
* Seleção de Delimitadores: Escolha interativamente entre o delimitador `;` ou `=` para ver os resultados.
* Caixa de Texto Interativa: Digite os parâmetros da query (ex: datas ou códigos de aeroportos) diretamente na caixa de entrada de texto e prima ENTER para executar.
* Visualizador de Resultados: O ecrã de resultados suporta scroll vertical e horizontal. Use as setas direcionais (Cima / Baixo / Esquerda / Direita) ou as teclas Page Up / Page Down para navegar por outputs longos.
* Sair / Voltar: Pressione a tecla `q` para sair do visualizador de resultados e voltar ao menu anterior, ou para fechar a aplicação interativa.

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
