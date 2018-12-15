## Universidade Estadual de Maringá
**Centro de Tecnologia - Departamento de Informática**

**Ciência da Computação - Disciplina: Sistemas Digitais**

**Profº. Lucas Pupulin Nanni**

**Aluno: Bruno Massaki Emori - R.A: 88736**

**Aluno: Diego Kazuo Ono - R.A: 90567**

## Objetivo
Implementar funcionalidades para utilizar o display LCD, juntamente com o sensor de temperatura e umidade DHT11, com avr-c, utilizando o microcontrolador ATMega-328p.

### Observações

1 - Para o funcionamento do display LCD é necessário que haja a conexão dos pinos seguindo a tabela abaixo, onde a primeira coluna representa o número do pino do Arduino e a segunda coluna representa os pinos do display LCD.

| Arduino | Display LCD |
|:-------:|:-----------:|
|    4    |      D4     |
|    5    |      D5     |
|    6    |      D6     |
|    7    |      D7     |
|    8    |    ENABLE   |
|    9    |      RS     |

**2 - Para compilar e enviar o código para o Arduino use os seguintes comandos seguindo a ordem:**
    1º make libraries
    2º make
    3º sudo make deploy
