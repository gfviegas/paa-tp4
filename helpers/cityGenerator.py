#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
from os import path
from random import randint

# O primeiro argumento é o número N da matriz NxN
N = int(sys.argv[1])

# O segundo argumento é o número de obras a ser alocado na cidade
constructionsCount = int(sys.argv[2])

# O terceiro argumento é o caminho do arquivo a ser escrito
outputPath = str(sys.argv[3])

filePath = path.abspath(__file__ + '/../../' + outputPath)

print('Gerando arquivo para cidade {:d}x{:d}'.format(N, N))
print('Quantidade de construções: {:d}'.format(constructionsCount))

with open(filePath, 'w+') as f:
    orig = '{:d} {:d}\n'.format(randint(1, int(N / 4)), randint(1, int(N / 4)))
    dest = '{:d} {:d}\n'.format(randint(int(N / 2), N), randint(int(N / 2), N))

    f.write('{:d} {:d}\n'.format(N, N))
    f.write(orig)
    f.write(dest)
    for i in range(0, constructionsCount):
        direction = 'L' if randint(0, 1) else 'N'
        cons = '{:d} {:d} {}\n'.format(randint(1, N), randint(1, N), direction)
        f.write(cons)

print('Arquivo gerado com sucesso em {}'.format(filePath))
