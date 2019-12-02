#include <Wire.h>
#include <avr/pgmspace.h>
#include "OLED.h"
const int out1 =  2;   
const int out2 =  3;   
const int out3 =  4;   
const int out4 =  5;   
const int out5 =  6;   
const int out6 =  7; 

void setup() {
for(int i=out1; i<=out6; i++)
{
  pinMode(i, INPUT);
  digitalWrite(i, LOW);
}
delay(300);
    Wire.begin();

    setActiveScreen(out1);
    print_text(2,"Screen1");
    drawCircle(40,60,20);
    drawCircle(40,70,20);
    drawCircle(100,60,20);
    drawCircle(100,70,20);
	update();

    setActiveScreen(out2);
    print_text(1,"Screen2");
    drawRectangle(50,60,20,20); 
    drawRectangle(100,60,20,20);
    drawRectangle(128,60,20,20);
	update();
   
    setActiveScreen(out3);
    print_text(1,"Screen3");
    invert_screen();
	update();
}
void loop() {
}

void setActiveScreen(int s){

for(int i=out1; i<=out6; i++)
{
	digitalWrite(i, LOW);
}
	digitalWrite(s, HIGH);
	clear_screen();
	send_command(0xAE);
	send_command_data(0xD5, __osc_freq << 4 | __clk_div);
	send_command_data(0xA8, __mux_ratio);
	send_command_data(0xd3, 0x00);
	send_command_data(0x8d, 0x14);
	send_command(0x40);
	send_command(0xa6);
	send_command(0xa4);
	send_command(0xa1);
	send_command(0xc8);
	send_command(0x20);
	send_command(0x00);
	send_command_data(0xda, 0x12);
	send_command_data(0x81, __contrast);
	send_command_data(0xd9, 0xf1);
	send_command_data(0xdb, 0x40);
	send_command(0xaf);
}