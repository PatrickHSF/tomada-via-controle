/* Carrega a biblioteca de controle do LCD; */
#include <LiquidCrystal.h>

/* Inclui a biblioteca para o Módulo IR. */
#include <IRremote.h>

/* Define os pinos que serão utilizados para ligação do
display; */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/* Programa: Acionar carga com Som */
/* Define os pinos que serão utilizados para os Módulos Sensor de
Som e Relé */
int pino_rele = 13;

/* Define o pino do Arduino que receberá os dados do receptor IR. */
int Pino_receptor = 7;

/* Variável que armazenará os códigos emitidos pelas teclas.      */
float armazenavalor;

unsigned long tecla_1 = 0xE718FF00;
unsigned long tecla_2 = 0xAD52FF00;

/* Variável booleana para armazenar o estado do Relé */
boolean estado = LOW;
void setup() {
/* Coloca o pino do Módulo Sensor de Som como entrada e o pino do
Módulo Relé como saída */
	pinMode(pino_rele, OUTPUT);

	/* Inicializa o receptor IR no pino definido. */

	IrReceiver.begin(Pino_receptor);

/* Define o número de colunas (16) e linhas (2) do LCD; */
	lcd.begin(16, 2);
}
void loop() {

	/* Se o receptor receber dados. */
	if (IrReceiver.decode()) {
		/* Armazena o código hexadecimal recebido na variável. */
		armazenavalor = IrReceiver.decodedIRData.decodedRawData;

		if (armazenavalor == tecla_1) {
			estado = LOW;
			lcd.clear();

			lcd.setCursor(1, 0);
			/* Envia o texto entre aspas para o LCD; */
			lcd.print("Prof. Patrick");

			lcd.setCursor(1, 1);
			/* Envia o texto entre aspas para o LCD; */
			lcd.print("Tomada: ON");

			 /* Operação NÃO: Se estiver LOW, passa pra HIGH, se estiver
HIGH passa para LOW */              
 /* Manda o valor da variável estado para o Relé */
			digitalWrite(pino_rele, estado); 
		}
		if (armazenavalor == tecla_2) {
			estado = HIGH;
			lcd.clear();

			lcd.setCursor(1, 0);
			/* Envia o texto entre aspas para o LCD; */
			lcd.print("Prof. Patrick");

			lcd.setCursor(1, 1);
			/* Envia o texto entre aspas para o LCD; */
			lcd.print("Tomada: OFF");

			 /* Operação NÃO: Se estiver LOW, passa pra HIGH, se estiver
HIGH passa para LOW */              
 /* Manda o valor da variável estado para o Relé */
			digitalWrite(pino_rele, estado); 
		}
		/* Realiza uma nova leitura no módulo. */
		IrReceiver.resume();
	}                             

}