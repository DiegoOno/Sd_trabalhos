# Universidade Estadual de Maringá
## Sistemas Digitais - Trabalho 3
**Alunos:** 
**Bruno Emori R.A: 88736**   
**Diego Ono R.A: 90567**

**Profº Lucas Nanni**

**Objetivo:** Implementar um relógio, onde o mesmo deverá mostrar a data, hora, temperatura, umidade e uma breve previsão de tempo, utilizando a API OpenWeather para conseguir essas infomações. A cada 60 minutos uma requisição deverá ser realizada para a API, para a atualização das informações. E Durante os 60 minutos, com o uso do Arduino o tempo deverá ser contado.

**Informações**
1 - Para o funcionamento do display LCD é necessário que haja a conexão dos pinos seguindo a tabela abaixo, onde a primeira coluna representa o número do pino do Arduino e a segunda coluna representa os pinos do display LCD.
| Arduino | Display LCD |
|:-------:|:-----------:|
|    4    |      D4     |
|    5    |      D5     |
|    6    |      D6     |
|    7    |      D7     |
|    8    |    ENABLE   |
|    9    |      RS     |

2 - Para utilização do script em Python 3 é necessário a instalação da biblioteca PySerial. E para execução do script pode existir a necessidade de modificar a porta de comunicação serial dentro do código na linha 59, substituindo /dev/ttyACM1 para a porta utilizada. 

3 - Neste projeto também é utilizado um botão, e o mesmo deve ser conectado no pino 3. Para que ocorra a chamada de interruptções.

4 - Para enviar o código de extensão .ino para o Arduino Uno, basta utilizar a IDE.

