#include <OneWire.h>
#include <DallasTemperature.h>
#define dados 2
#define led 12
#define alarme 46

OneWire oneWire(dados);
DallasTemperature sensors(&oneWire);

void setup(void) /* laço de configuração */
{
  pinMode (led, OUTPUT);
  Serial.begin(9600); /* definição de Baudrate de 9600 */
  Serial.println("Demostração do funcionamento do sensor"); /* Printa "Demostração do funcionamento do sensor" */
  sensors.begin(); /* inicia biblioteca */
}

void loop(void) /* laço de repetição */
{
  /* use sensors.requestTemperatures() para o requerimento de temperatura de todos os dispositivos ligados */
  /**********************************************************/
  Serial.print(" Requerimento de temperatura...");
  sensors.requestTemperatures(); /* Envia o comando para leitura da temperatura */
  Serial.println("Pronto"); /* Printa "Pronto" */
  /**********************************************************/
  Serial.print("A temperatura é: "); /*Printa "A temperatura é:"*/
  Serial.print(sensors.getTempCByIndex(0)); /* Endereço do sensor */
  if (sensors.getTempCByIndex(0) > alarme) { /* se a temperatura for maior que o alarme*/
    digitalWrite(led, HIGH); /* escreve nível lógico alto no LED (acende) */
  }
  else { /* caso contrário */
    digitalWrite(led, LOW); /* escreve nível lógico baixo no LED (apaga) */
  }
}

