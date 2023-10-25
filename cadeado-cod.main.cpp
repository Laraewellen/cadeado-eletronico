#include <LiquidCrystal_I2C.h>


#incluir <SPI.h>
#include <MFRC522.h>
#include <Wire.h>

//Definimos o id que será liberado o acesso
#define ID "B2 A1 24 D9"
#define ID "10 B9 B7 56"

//define alguns pinos do esp32 que serão conectados aos módulos e componentes
#define tranca 2
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); //define os pinos de controle do módulo de leitura de cartões RFID

LiquidCrystal_I2Clcd(0x27, 16, 2); // define informações do lcd como o endereço I2C (0x27) e tamanho do mesmo
Configuração nula()
{
  SPI.begin(); // inicia a comunicação SPI que será usada para comunicação com o módulo RFID

  lcd.begin(); // inicia o lcd

  mfrc522.PCD_Init(); //inicia o módulo RFID

  Serial.begin(115200); // inicia a comunicação serial com o computador na velocidade de 115200 baud rate

  Serial.println("RFID + ESP32");
  Serial.println("Aguardando tag RFID para verificar o id da mesma.");

  //define alguns pinos como saida
  pinMode(tranca,OUTPUT);
}
loop vazio() {

lcd.home();    
  lcd.print("Aproximadamente"); //imprime na primeira linha a string "Aguardando"
  lcd.setCursor(0,1); // seta o cursor para a segunda linha
  lcd.print("o cartão"); // mostra na tela a string "Leitura RFID"

  if (! mfrc522.PICC_IsNewCardPresent()) {
     retornar; // se não tiver um cartão para ser lido, recomeça o void loop
  }
  if (! mfrc522.PICC_ReadCardSerial()) {
    retornar; //se não conseguir ler o cartão recomendado o void loop também
  }

  String conteudo = ""; // cria uma string

  Serial.print("id da tag:"); //imprime na serial o id do cartao

  for (byte i = 0; i < mfrc522.uid.size; i++){ // faz uma verificação dos bits da memória do cartão
     //ambos comandos abaixo vão concatenar as informações do cartao...
     //porem os 2 primeiros irao mostrar na serial e os 2 últimos salvarao os valores na string de conteúdo para fazer as verificações
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
Serial.println();
  conteudo.toUpperCase(); // deixa as letras da string todas maiusculas

  if (conteudo.substring(1) == ID){ // verifica se o ID do cartão lido tem o mesmo ID do cartão que queremos liberar o acesso

      lcd.claro(); // limpamos o que havia sido escrito no lcd
      lcd.print("Olá, bem vindo!!");

      digitalWrite(tranca,HIGH); //abrimos a tranca por 5 segundos

      for(byte s = 3; s > 0; s--){ //vai informar ao usuário quantos segundos faltam para a tranca ser fechada
        lcd.setCursor(8,1);
        lcd.imprimir(s);
        atraso(3000);
      }

      digitalWrite(tranca, LOW); // fecha a tranca
      lcd.claro(); // limpa os caracteres q estao escritos no lcd

  }else{ // caso o cartão lido não foi registrado

    for(byte s = 3; s > 0; s--){ // uma contagem / espera para poder fazer uma nova leitura

        lcd.claro(); // limpa as informações que estão na tela
        lcd.home(); // nota na posição inicial
        lcd.print("Não autorizado!!"); // infoma ao usuário que ele não tem acesso


        lcd.setCursor(8,1); // coloca o cursor na coluna 8 da linha 2
        lcd.imprimir(s); // informa quantos segundos faltam para poder fazer uma nova leitura
        atraso(3000);
        lcd.claro(); // limpa as informações do lcd
    }}}
