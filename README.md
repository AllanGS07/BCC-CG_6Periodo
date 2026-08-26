<div align="center">

# 🖥️ Computação Gráfica — 6º Período

### Bacharelado em Ciência da Computação

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![GCC](https://img.shields.io/badge/GCC-14.2-informational?style=for-the-badge&logo=gnu)](https://gcc.gnu.org/)
[![Docker](https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white)](https://www.docker.com/)
[![License: Apache 2.0](https://img.shields.io/badge/License-Apache_2.0-blue.svg?style=for-the-badge&logo=apache)](LICENSE)

<p align="center">
  Implementações práticas, estudos e algoritmos desenvolvidos durante a disciplina de <b>Computação Gráfica</b> no curso de Ciência da Computação.
</p>

</div>

---

## 📑 Sumário

- [🖥️ Computação Gráfica — 6º Período](#️-computação-gráfica--6º-período)
    - [Bacharelado em Ciência da Computação](#bacharelado-em-ciência-da-computação)
  - [📑 Sumário](#-sumário)
  - [📌 Sobre o Repositório](#-sobre-o-repositório)
  - [📂 Estrutura do Projeto](#-estrutura-do-projeto)
  - [🧠 Módulos e Algoritmos](#-módulos-e-algoritmos)
    - [01. Algoritmo de Corte (Clipping)](#01-algoritmo-de-corte-clipping)
      - [🔹 Algoritmo de Cohen-Sutherland](#-algoritmo-de-cohen-sutherland)
  - [🚀 Como Compilar e Executar](#-como-compilar-e-executar)
    - [Pré-requisitos](#pré-requisitos)
    - [Opção 1: Compilação Nativa (GCC / Clang)](#opção-1-compilação-nativa-gcc--clang)
      - [No Linux / macOS:](#no-linux--macos)
      - [No Windows (PowerShell / CMD com MinGW):](#no-windows-powershell--cmd-com-mingw)
    - [Opção 2: Execução via Docker 🐳](#opção-2-execução-via-docker-)
  - [🗺️ Roteiro de Tópicos (Roadmap)](#️-roteiro-de-tópicos-roadmap)
  - [🛠️ Tecnologias Utilizadas](#️-tecnologias-utilizadas)
  - [📄 Licença](#-licença)

---

## 📌 Sobre o Repositório

Este repositório contém os trabalhos, exercícios práticos e algoritmos implementados ao longo do 6º período da graduação em Ciência da Computação.

O principal objetivo é aplicar na prática os conceitos matemáticos e computacionais por trás da renderização gráfica 2D e 3D, trabalhando em baixo nível com a manipulação de primitivas, transformações no espaço Euclidiano e pipeline gráfico.

---

## 📂 Estrutura do Projeto

```text
├── 01. Algoritmo de Corte/
│   ├── Cohen-Sutherland.c     # Implementação completa e CLI do corte de retas
│   └── Dockerfile             # Configuração do ambiente Docker
├── .gitattributes
├── .gitignore
├── LICENSE                    # Termos de licença Apache 2.0
└── README.md                  # Documentação do projeto

```

---

## 🧠 Módulos e Algoritmos

### 01. Algoritmo de Corte (Clipping)

O módulo aborda o problema de recorte de primitivas 2D em relação a uma janela de visualização (*viewport* / *clipping window* delimitada por $x_{min}, x_{max}, y_{min}, y_{max}$ adaptada para coordenadas de tela, onde $y$ cresce de cima para baixo).

#### 🔹 Algoritmo de Cohen-Sutherland

Divide o plano bidimensional em 9 regiões através de códigos binários de 4 bits (**Outcodes**):

| Código (Bit) | Significado | Condição |
| --- | --- | --- |
| **Bit 3 (CIMA)** | Acima da janela | $y < y_{min}$ |
| **Bit 2 (BAIXO)** | Abaixo da janela | $y > y_{max}$ |
| **Bit 1 (DIREITA)** | À direita da janela | $x > x_{max}$ |
| **Bit 0 (ESQUERDA)** | À esquerda da janela | $x < x_{min}$ |

**Regras de Decisão:**

1. **Aceitação Trivial:** Se `(codeA | codeB) == 0`, ambos os pontos estão dentro da janela e o segmento é desenhado integralmente.
2. **Rejeição Trivial:** Se `(codeA & codeB) != 0`, ambos os pontos compartilham uma região externa comum e a reta é completamente descartada.
3. **Corte e Interseção:** Caso contrário, calcula-se o ponto de interseção da reta com as bordas da janela e reavalia-se iterativamente.

---

## 🚀 Como Compilar e Executar

### Pré-requisitos

* Compilador C (`gcc` ou `clang`)
* `docker` *(opcional, para ambiente isolado)*

---

### Opção 1: Compilação Nativa (GCC / Clang)

#### No Linux / macOS:

```bash
# Entre na pasta do módulo
cd "01. Algoritmo de Corte"

# Compile o arquivo fonte
gcc -Wall -Wextra -O2 "Cohen-Sutherland.c" -o corte

# Execute o programa
./corte

```

#### No Windows (PowerShell / CMD com MinGW):

```powershell
# Entre na pasta do módulo
cd "01. Algoritmo de Corte"

# Compile o executável
gcc -Wall -Wextra "Cohen-Sutherland.c" -o corte.exe

# Execute
.\corte.exe

```

---

### Opção 2: Execução via Docker 🐳

Para rodar em qualquer ambiente sem necessidade de instalar compiladores locais:

```bash
# Entre na pasta do módulo
cd "01. Algoritmo de Corte"

# Construa a imagem
docker build -t cg-corte .

# Execute o contêiner de forma interativa
docker run --rm -it cg-corte

```

---

## 🗺️ Roteiro de Tópicos (Roadmap)

* [x] **Algoritmos de Corte 2D (Clipping)**
* [x] Cohen-Sutherland (Segmentos de reta)
* [ ] Sutherland-Hodgman (Recorte de polígonos)


* [ ] **Rasterização de Primitivas Gráficas**
* [ ] Algoritmo DDA (Digital Differential Analyzer)
* [ ] Algoritmo de Bresenham (Retas e Circunferências)


* [ ] **Preenchimento de Áreas (Scanline & Flood Fill)**
* [ ] **Transformações Geométricas 2D e 3D**
* [ ] Translação, Rotação, Escala e Cisalhamento
* [ ] Coordenadas Homogêneas e Matrizes de Transformação


* [ ] **Projeções e Câmera Virtual**
* [ ] Projeção Ortográfica
* [ ] Projeção Perspectiva


* [ ] **Iluminação e Shading**
* [ ] Modelo de Reflexão de Phong
* [ ] Sombreamento Flat e Gouraud



---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C (Padrão C99 / C11)
* **Compilador:** GCC / Clang
* **Conteinerização:** Docker
* **Versionamento:** Git & GitHub

---

## 📄 Licença

Este projeto está sob a licença [Apache 2.0](https://www.google.com/search?q=LICENSE). Consulte o arquivo `LICENSE` para obter mais detalhes.
