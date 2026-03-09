#!/bin/bash

# Script para compilar e testar soluções de programação competitiva
# Uso: ./compile_and_run.sh arquivo.cpp [caso_teste.txt]

if [ $# -eq 0 ]; then
    echo "❌ Uso: $0 arquivo.cpp [arquivo_entrada.txt]"
    exit 1
fi

SOURCE_FILE="$1"
BASENAME="${SOURCE_FILE%.cpp}"
OUTPUT_FILE="${BASENAME}"

echo "🔨 Compilando $SOURCE_FILE..."

# Compilar com flags de competição
g++ -std=c++17 -O2 -Wall -Wextra "$SOURCE_FILE" -o "$OUTPUT_FILE" 2>&1

if [ $? -ne 0 ]; then
    echo "❌ Erro na compilação!"
    exit 1
fi

echo "✅ Compilação bem-sucedida!"
echo ""
echo "🚀 Executando..."
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

# Se passar arquivo de entrada, usa ele. Senão, lê do stdin
if [ -n "$2" ]; then
    echo "📄 Usando entrada do arquivo: $2"
    echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
    time "./$OUTPUT_FILE" < "$2"
else
    "./$OUTPUT_FILE"
fi

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "✅ Execução concluída!"
