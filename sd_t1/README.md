## Universidade Estadual de Maringá
**Centro de Tecnologia - Departamento de Informática**

**Ciência da Computação - Disciplina: Sistemas Digitais**

**Profº. Lucas Pupulin Nanni**

**Aluno: Bruno Massaki Emori - R.A: 88736**

**Aluno: Diego Kazuo Ono - R.A: 90567**

## Primeiro trabalho 

### Bibliteca de IO

#### Função pinMode
    void pinMode(uint8_t pinNumber, uint8_t pinType);
O objetivo desta função é configurar um pino como entrada, saida ou pull-up.
Esta função recebe o número do pino do Arduino (0 a 19), no caso dos pinos 14 a 19 são os determinados como analógicos no Arduino. E o outro parâmetro é o tipo do pino, variando entre INPUT, OUTPUT ou PULL-UP. Com laços condicionais verifica-se em qual registrador deverá ser manipulado a partir do número do pino, assim caso o número do pino esteja entre 0 e 7 a configuração será no DDRD e no PORTD. Se o valor estiver entre 8 e 13 a configuração será no DDRB e no PORTB e caso esteja entre 14 e 19 a configuração será no DDRC e PORTC. Após encontrar os registradores para configurar o pino, é verificado o tipo dele com laços condicionais que se o parâmetro for INPUT será atribuído 1 no DDR desse pino, caso o parâmetro do tipo seja OUTPUT será atribuído 0 no DDR, e caso o parâmetro seja PULL-UP será atribuído 0  no DDR e será atribuído 1 no PORT do pino.

#### Função digitalWrite
    void digitalWrite(uint8_t pinNumber, uint8_t value);
O objetivo desta função é atribuir um valor no pino, sendo possível atribuir HIGH(1) ou LOW(1). Esta função rebece como parâmetros, o número do pino e o valor que será escrito. Da mesma forma que a função pinMode, primeiramente, a função busca os registradores de configuração. Em seguida é verificado o valor que será escrito, se for LOW, será atribuído 0 no PORT do pino, e caso seja HIGH, será atribuído 1 no PORT do pino.

### Biblioteca de LED:

#### Função createPinLed
    void createLedPin(uint8_t pinNumber);
O objetivo desta função é configurar um pino que oferece suporte ao funcionamento do LED, sendo assim um pino de saída. Esta função recebe o número do pino, e em seguida chama a função pinMode passando o número do pino e o tipo como OUTPUT.

#### Função turnLedOn
    void turnLedOn(uint8_t pinNumber);
Esta função tem como objetivo ligar um LED setando 1 no PORT do número do pino passado como parâmetro. Isso acontece com a chamada da função digitalWrite, passando o número do pino e HIGH como valor a ser escrito.

#### Função turnLedOff
    void turnLedOff(uint8_t pinNumber);
Esta função realiza quase os mesmos passos da função turnLedOn, porém o valor escrito é LOW, para desligar o LED.

#### Função changeLedState
    void changeLedState(uint8_t pinNumber);
Esta função recebe como parâmetro o número do pino. Seu objetivo é inverter o estado do LED, caso esteja desligado ele será ligado, e caso esteja ligado ele será desligado. Para isso é chamado uma macro contido no arquivo macro.h que realiza a inversão do valor no PORT do pino.

#### Função: blinkLed
    void blinkLed(uint8_t pinNumber, uint32_t ms_time); 
Esta função tem como objetivo fazer o LED piscar, assim ligado e desligado com um intervalo de tempo passado pelo usuário. Assim esta função recebe o número do pino, e um valor de tempo em mili segundos. Desta forma será chamado a função turnLedOn para o pino em seguida será chamado a função que realiza o delay em mili segundos (delay_ms()) passando o tempo recebido como parâmetro. Em seguida é chamado a função turnLedOff para o pino do LED e por fim é dado outro delay em mili segundos com o mesmo tempo do anterior.

### Biblioteca de botão

#### Função createButton 
    void createButton(uint8_t pinNumber);
Esta função tem como objetivo configurar um pino que fornece funcionamento para um botão. Ela recebe como parâmetro o número do pino. Para configurar o pino é chamado a função pinMode da biblioteca de IO, passando o número do pino e com o tipo PULL-UP.

#### Função waitClick
    uint8_t waitClick(uint8_t buttonPin);
Esta função tem como objetivo detectar o pressionamento do botão após a ocorrência do mesmo, ou seja, do momento de descida até a subida do botão. Isso acontece pela leitura do valor do pino passado como parâmetro pelo registrador PIN do pino, que é encontrado da mesma maneira que a função de configurar o pino da biblioteca de IO, no momento em que ele verificar o valor que indica a descida do botão, será executado um laço de repetição que ficará verificando se o botão ainda está apertado, no momento em que for solto será dado um delay para realizar o debouncing, por fim será retornado TRUE(1). Caso no inicío da leitura não seja verificado que o botão foi pressionado será retornado FALSE(0).

#### Função doNotWaitClick
    uint8_t doNotWaitClick(uint8_t buttonPin);
Esta função tem como objetivo verificar o pressionamento do botão sem esperar a subida do mesmo. Assim ela faz a leitura da mesma forma que a função waitClick, porém não é executado um laço para esperar a subida do botão. Então se for verificado pressionamento, será dado o debouncing e em seguida será retornado TRUE(1), ou se na leitura do botão não for verificado o pressionamento será retornado FALSE(0);

#### Função isPressed
    uint8_t isPressed(uint8_t buttonPin); 
Esta função recebe como parâmetro o pino que será realizado a leitura. Da mesma forma que as funções waitClick e doNotWaitClick, é buscado o PIN do pino para realizar a leitura, e caso seja detectado o pressionamento a função retornará TRUE(1) caso contrário retornará FALSE(0).

### Biblioteca de Delay

#### Função delay_ms
    void delay_ms(uint32_t time_ms);
Esta função recebe um valor de tempo para executar instruções "nulas" para que ocorra um delay, nesta função em mili segundos. O funcionamento dela ocorre utilizando um laço de repetição que em cada iteração executa um código em assembly que faz o delay de 1 mili segundo, tal laço possui o valor de tempo passado como parâmetro de iterações.

#### Função delay_us
    void delay_us(uint32_t time_us);
Esta função recebe um valor de tempo para executar instruções "nulas" para que ocorra um delay, nesta função em micro segundos. O funcionamento dela ocorre utilizando um laço de repetição que em cada iteração executa um código em assembly que faz o delay de 1 micro segundo, tal laço possui o valor de tempo passado como parâmetro de iterações.

### Biblioteca sevenSeg (Display de 7 segmentos)

#### Função createSevenSegPins
    void createSevenSegPins(uint8_t pins[]);
Esta função configura uma vetor de 7 valores onde cada um será um dos segmentos do display de 7 segmentos. Isso acontece por um laço de repetição que chama a função pinMode da 
biblioteca de IO, configurando esses pinos como pinos de saída.

#### Função clearAll
    void clearAll(uint8_t pins[], uint8_t display_type);
Esta função serve para desligar todos os segmentos do display, e pelo tipo do display (cátodo ou ânodo), é executado um laço de repetição que chama a função digitalWrite da biblioteca de IO para cada pino, se o display for ânodo a chamada atribuirá LOW(0) para o PORT do pino. Caso o display seja do tipo cátodo será atribuído HIGH(1) com a função digitalWrite para os pinos.  

#### Função selectHex
    void selectHex(uint8_t pins[], char character, uint8_t display_type);
Esta função tem como objetivo escolher o caracter que será impresso no display, por meio de um switch case com o caracter recebido por parâmetro, como variável, a partir do caracter é escolhido a chamada de uma função que passa o vetor de pinos e uma string que contém uma palavra binária de 7 bits, onde cada bit representa os segmentos que deverão ser ligados ou não para imprimir no display. A ordem dos segmentos dentro da string é "abcdefg". Juntamente aos parâmetros citados também é passado o tipo o display (cátodo ou ânodo). Um exemplo seria caso fosse recebido um caracter '0' na chamada do selectHex, no switch case iria ser escolhido a chamada da função writeHex da seguinte forma: 
Exemplo:    
    
    writeHex(vetor_pinos, '1111110', tipo_display);

#### Função writeHex
    void writeHex(uint8_t pins[], const char character[], uint8_t display_type);
A função writeHex recebe os parâmetros citados na função selectHex que são, o vetor de pinos, a palavra binária que diz quais pinos serão ativados ou não, e o tipo do display. Esta função irá ativar os segmentos para determinada palavra de maneiras diferentes, de acordo com o tipo de display. Se for um display do tipo ânodo haverá um laço que percorrerá a string e o vetor de pinos, e para cada caracter irá realizar uma ação no pino do mesmo índice. Se o caracter i for igual a zero, será chamado a função digitalWrite passando o pino i e o valor HIGH(1) e se o caracter i for igual a um a função digitalWrite será chamada passando o pino i e o valor LOW(0). Caso o display seja do tipo cátodo, o laço percorrerá da mesma forma que o display do tipo ânodo, porém quando o caracter i for igual a zero a função digitalWrite será chamada passando o pino i e o valor LOW(0) e quando o caracter i for igual a um a função digitalWrite será chamada passando o pino i e o valor HIGH(1).

OBS: Nas funções do display de 7 segmentos não foi considerado o uso do ponto do display (pino h).

### Biblioteca Ultrasonic (Sensor Ultrassonic - HC-SR04)

#### Função createUltrasonicPins
    void createUtrasonicPins(uint8_t triggerPin, uint8_t echoPin);
Esta função tem como objetivo configurar os pinos passados como parâmetros, onde é chamado a função pinMode passando o pino de Trigger (triggerPin) e o valor OUTPUT para defini-lo como pino de saída e novamente é chamado a função pinMode passando o pino de Echo (echoPin) e o valor INPUT para defini-lo como pino de entrada.

#### Função calculateDistance
    uint16_t calculateDistance(uint8_t triggerPin, uint8_t echoPin);
Esta função recebe como parâmetro os pinos de trigger e echo para realizar um disparo de uma onda sonora e recebe-la de volta, para calcular a distância entre o sensor e algum objeto. No inicio da execução desta função o contador CT1 (16 bits) é configurado com um prescaler de 8. Em seguida é ativado o pino de trigger por 10 micro segundos, após esse tempo de espera, desativa o pino de trigger, em seguida é executado um laço que faz a espera do pino de echo atingir um. No momento em que o valor do PIN do pino echo for igual a um, o TCNT1 é zerado para iniciar a contagem. Para aguarda a descida de nível do pino echo é executado um novo laço de espera. No momento em que ocorrer a descida uma variável chamada duration recebe o valor de contagem do TCNT1, para no final retornar duration / 116, que é o cálculo de distância visto em aula. 


### Compilar e enviar para o Arduino Uno com microcontrolador 328p

#### Compilar as bibliotecas
    $make libraries

#### Compilar código principal
**Primeiramente abrir o Makefile e modificar a variável PROG inserindo o nome do arquivo principal.**
Exemplo:

    PROG = nome_programa

**Em seguida digitar no terminal:**
    
    $make

#### Enviar para o Arduino
**Executar comando como administrador**

    $sudo make deploy
