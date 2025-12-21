#!/bin/bash

### 1️⃣ Renomear diretórios (do mais profundo para o mais alto)
find . -depth -type d ! -name "*_bonus" | while read -r dir; do
    parent=$(dirname "$dir")
    base=$(basename "$dir")

    new="$parent/${base}_bonus"

    mv -- "$dir" "$new"
    echo "Pasta renomeada: $dir -> $new"
done

### 2️⃣ Renomear arquivos .c e atualizar include
find . -type f -name "*.c" ! -name "*_bonus.c" | while read -r f; do
    dir=$(dirname "$f")
    base=$(basename "$f" .c)
    new="$dir/${base}_bonus.c"

    mv -- "$f" "$new"
    echo "Arquivo renomeado: $f -> $new"

    sed -i 's/#include "minirt.h"/#include "minirt_bonus.h"/g' "$new"
    echo "Include atualizado em: $new"
done
