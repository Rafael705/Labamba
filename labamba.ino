#define   dir_clk      4     //clock do registrador no digital  4
#define   dir_ser      8     //dados do registrador no digital  8
#define   dir_latch   12     //latch do registrador no digital 12
#define   dir_en       7     //enable do registrador no digital 7

#define   servo1      10     //controle do Servo 1

void sendCommand(unsigned char value);   //Função para enviar o byte para saída do registrador
void servo0graus();
void servo90graus();
void servo180graus();

void setup()
{
  pinMode(dir_clk,   OUTPUT);    //saída para clock
  pinMode(dir_ser,   OUTPUT);    //saída para dados
  pinMode(dir_latch, OUTPUT);    //saída para latch
  pinMode(dir_en,    OUTPUT);    //saída para enable
  pinMode(servo1,    OUTPUT);    //saída para Servo 1

  digitalWrite(dir_en, LOW);
}
 
void loop()
{

  for(char i=0;i<100;i++) servo0graus();    //move o servo para a posição 0º por 2 segundos
  for(char i=0;i<100;i++) servo90graus();    //move o servo para a posição 90º por 2 segundos
  for(char i=0;i<100;i++) servo180graus();    //move o servo para a posição 180º por 2 segundos
  for(char i=0;i<100;i++) servo90graus();    //move o servo para a posição 90º por 2 segundos

  motor.setSpeed(255); //Define a velocidade maxima
  motor.run(FORWARD); //Gira o motor sentido horario
 
  delay(3000);
  motor.setSpeed(0);
  motor.run(RELEASE); //Desliga o motor
 
  delay(3000);
  motor.setSpeed(255);
  motor.run(BACKWARD); //Gira o motor sentido anti-horario
 
  delay(3000);
  motor.setSpeed(0);
  motor.run(RELEASE); //Desliga o motor
 
  delay(4000); //Aguarda 5 segundos e repete o processo
}

void sendCommand(unsigned char value)
{
   
    boolean verify;                  //bit de controle
 
    digitalWrite(dir_latch, LOW);    //desliga latch
    digitalWrite(dir_clk,   LOW);    //desabilita o clock
     
    for(unsigned char i=0x0; i<0x08; i++)    //loop finito para enviar os 8 bits
    {
       digitalWrite(dir_clk, LOW);   //clock em low
        
       if(value & (1<<i)) verify = HIGH;
       else verify = LOW;
        
       digitalWrite(dir_ser, verify); //Habilita saída de dados conforme condição acima
       digitalWrite(dir_clk, HIGH);
     
    }
     
     
    digitalWrite(dir_clk, LOW);
     
    digitalWrite(dir_latch, HIGH);
 
 
}
 
 
 
void servo0graus()              //Posiciona o servo em 0 graus
{
   digitalWrite(servo1, HIGH);  //pulso do servo
   delayMicroseconds(600);      //0.6ms
   digitalWrite(servo1, LOW);   //completa periodo do servo
   for(int i=0;i<32;i++)delayMicroseconds(600);
   
                               // 20ms = 20000us
                               // 20000us - 600us = 19400us
                               // 19400/600 = ~~32
 
}
 
 
void servo90graus()             //Posiciona o servo em 90 graus
{
   digitalWrite(servo1, HIGH);  //pulso do servo
   delayMicroseconds(1500);     //1.5ms
   digitalWrite(servo1, LOW);   //completa periodo do servo
   for(int i=0;i<12;i++)delayMicroseconds(1500);
   
                               // 20ms = 20000us
                               // 20000us - 1500us = 18500us
                               // 18500/1500 = ~~12 
 
}
 
 
void servo180graus()             //Posiciona o servo em 180 graus
{
   digitalWrite(servo1, HIGH);  //pulso do servo
   delayMicroseconds(2400);     //2.4ms
   digitalWrite(servo1, LOW);   //completa periodo do servo
   for(int i=0;i<7;i++)delayMicroseconds(2400);
   
                               // 20ms = 20000us
                               // 20000us - 2400us = 17600us
                               // 17600/2400 = ~~7
 
} 
