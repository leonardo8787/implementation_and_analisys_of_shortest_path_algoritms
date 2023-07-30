import numpy as np
import matplotlib.pyplot as plt

linhas=[]

# Ler o arquivo
with open(r'analise_completa\temposFloyd.txt') as arquivo:
    linhas = arquivo.readlines()

# Extrair os valores numéricos
valores = []
for linha in linhas:
    valor = float(linha.strip())  # Converter para float
    valores.append(valor)

# Gerar um gráfico
plt.plot(valores, 'o', label='Dados')
plt.xlabel('Índice')
plt.ylabel('Valores')
plt.title('Gráfico dos valores')

# Calcular a regressão linear
x = np.arange(len(valores))
slope, intercept = np.polyfit(x, valores, 1)
regressao_linear = slope * x + intercept

# Plotar a linha de regressão
plt.plot(x, regressao_linear, 'r-', label='Regressão Linear')

# Adicionar legenda
plt.legend()

# Salvar o gráfico como arquivo PNG
plt.savefig('grafico.png')

# Mostrar o gráfico
plt.show()

