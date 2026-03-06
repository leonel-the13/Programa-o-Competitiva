# 📝 Problema 1: Anagramas em Grupo

## 📌 Enunciado

Dado um array de strings, agrupe as strings que são anagramas umas das outras.

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Próximas N linhas**: Uma string

---

## 📤 Saída

Grupos de anagramas. Cada grupo em uma linha, strings separadas por espaço.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
6
eat
tea
ate
tan
nat
ant
```

**Saída**:

```
eat tea ate
tan nat ant
```

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^4
- 1 ≤ tamanho string ≤ 100

---

## 💡 Dicas

- Use ordenação de caracteres como chave
- HashMap para agrupar

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n × m × log m) onde m = tamanho string
- **Espaço**: O(n × m)
