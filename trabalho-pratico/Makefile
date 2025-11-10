# Evita recompilações desnecessárias
.PHONY: all clean compare test docs

# Compilador e flags
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -pedantic -O2 -g $(shell pkg-config --cflags glib-2.0)
LIBS = $(shell pkg-config --libs glib-2.0) -lncurses -lm
DOXYFILE ?= Doxyfile
DOCDIR ?= docs

# ------------------------------
# Ficheiros comuns (sem main.c e testes.c)
COMMON_SRC := $(shell find src -type f -name "*.c" ! -path "src/mains/*.c")
COMMON_OBJ := $(COMMON_SRC:.c=.o)

# Programa principal
MAIN_SRC := src/mains/programa-principal.c
MAIN_OBJ := $(MAIN_SRC:.c=.o)
TARGET := programa-principal

# Programa de testes
TEST_SRC := src/mains/programa-testes.c
TEST_OBJ := $(TEST_SRC:.c=.o)
TEST_TARGET := programa-testes

# Programa interativo
INTERACTIVE_SRC := src/mains/programa-interativo.c
INTERACTIVE_OBJ := $(INTERACTIVE_SRC:.c=.o)
INTERACTIVE_TARGET := programa-interativo

# ------------------------------
# Alvo principal: compila ambos