void setup() {
  Serial.begin(9600);
  PORTD = (1<<PORTD7)|(1<<PORTD6)|(1<<PORTD5)|(1<<PORTD4)|(1<<PORTD3)|(1<<PORTD2);
  PORTB = (1<<PORTB1)|(1<<PORTB0);
}
void loop() {
  byte inputs = PIND >> 2;
  char binStr[8];
  inputs += PINB << 6;
  Serial.println(inputs, BIN);
  getBin(inputs, binStr);
  Serial.print(" ");
  Serial.println(binStr);
  delay(1000);
}

void getBin(int num, char *str)
{
  *(str+5) = '\0';
  int mask = 0x80 << 1;
  while(mask >>= 1)
  {
    *str++ = !!(mask & num) + '0';
  }
}
