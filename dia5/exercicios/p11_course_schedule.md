# 📝 Problema 11: Course Schedule II

## 📌 Enunciado

Você deve tomar N cursos (0 até N-1). Alguns cursos têm pré-requisitos. Por exemplo, [0,1] significa que para fazer curso 0, você deve primeiro fazer curso 1.

Retorne uma ordem válida para fazer todos os cursos, ou uma lista vazia se impossível.

---

## 📥 Entrada

- **Linha 1**: Inteiro N (número de cursos)
- **Linha 2**: Inteiro M (número de pré-requisitos)
- **Próximas M linhas**: Dois inteiros (curso, pré-requisito)

---

## 📤 Saída

Uma ordem válida de cursos, espaço separada. Se impossível, imprima "IMPOSSIVEL".

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
2
1
1 0
```

**Saída**:

```
0 1
```

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5
- 0 ≤ M ≤ 10^5

---

## 💡 Dicas

- Use ordenação topológica
- Se houver ciclo, impossível
- Use Kahn's algorithm

---

## 🎯 Complexidade Esperada

- **Tempo**: O(N + M)
- **Espaço**: O(N + M)
