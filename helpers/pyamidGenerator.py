#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
from os import path
from random import randint

# O primeiro argumento é a altura N da piramide
N = int(sys.argv[1])

# O segundo argumento é o maior numero possivel no random
maxRandom = int(sys.argv[2])

# O terceiro argumento é o caminho do arquivo a ser escrito
outputPath = str(sys.argv[3])

filePath = path.abspath(__file__ + '/../../' + outputPath)

print('Gerando arquivo para piramide de altura {:d}'.format(N))

with open(filePath, 'w+') as f:
    for i in range(0, N):
        for j in range(0, i + 1):
            f.write('{} '.format(randint(1, maxRandom)))
        f.write('\n')

print('Arquivo gerado com sucesso em {}'.format(filePath))
