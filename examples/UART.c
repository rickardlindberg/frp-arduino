// This file is automatically generated.

#include <avr/io.h>
#include <util/delay_basic.h>
#include <stdbool.h>

struct list {
    uint8_t size;
    void* values;
};

struct tuple2 {
    void* value0;
    void* value1;
};

struct tuple6 {
    void* value0;
    void* value1;
    void* value2;
    void* value3;
    void* value4;
    void* value5;
};

static void bootup();

static void input_timer();

static void stream_1(uint8_t arg, void* value);

static void stream_9(uint8_t arg, void* value);

static void stream_10(uint8_t arg, void* value);

static void stream_2(uint8_t arg, void* value);

static void stream_11(uint8_t arg, void* value);

static void stream_3(uint8_t arg, void* value);

static void stream_4(uint8_t arg, void* value);

static void stream_5(uint8_t arg, void* value);

static void stream_6(uint8_t arg, void* value);

static void stream_7(uint8_t arg, void* value);

static void stream_8(uint8_t arg, void* value);

static void bootup() {
  bool temp0;
  temp0 = 0;
  stream_1(0, (void*)(&temp0));
}

static void input_timer() {
  uint16_t temp1;
  temp1 = TCNT1;
  TCNT1 = 0;
  stream_2(1, (void*)(&temp1));
  stream_9(0, (void*)(&temp1));
}

static void stream_1(uint8_t arg, void* value) {
  bool input_0 = *((bool*)value);
  uint16_t temp2;
  temp2 = 10000;
  stream_2(0, (void*)(&temp2));
}

static void stream_9(uint8_t arg, void* value) {
  uint16_t input_0 = *((uint16_t*)value);
  struct list temp3;
  uint8_t temp4[7];
  uint8_t temp5[20];
  struct list temp6;
  struct list temp7;
  uint8_t temp8[2];
  temp4[0] = 100;
  temp4[1] = 101;
  temp4[2] = 108;
  temp4[3] = 116;
  temp4[4] = 97;
  temp4[5] = 58;
  temp4[6] = 32;
  temp3.size = 7;
  temp3.values = (void*)temp4;
  snprintf(temp5, 20, "%d", input_0);
  temp6.size = strlen(temp5);
  temp6.values = temp5;
  temp8[0] = 13;
  temp8[1] = 10;
  temp7.size = 2;
  temp7.values = (void*)temp8;
  stream_10(0, (void*)(&temp3));
  stream_10(0, (void*)(&temp6));
  stream_10(0, (void*)(&temp7));
}

static void stream_10(uint8_t arg, void* value) {
  struct list input_0 = *((struct list*)value);
  uint8_t temp9;
  for (temp9 = 0; temp9 < input_0.size; temp9++) {
    stream_11(0, (void*)(&((uint8_t*)input_0.values)[temp9]));
  }
}

static void stream_2(uint8_t arg, void* value) {
  static uint16_t input_0;
  static uint16_t input_1;
  uint16_t temp10;
  uint16_t temp11;
  struct tuple2 temp12;
  switch (arg) {
    case 0:
      input_0 = *((uint16_t*)value);
      break;
    case 1:
      input_1 = *((uint16_t*)value);
      break;
  }
  temp10 = input_0;
  temp11 = input_1;
  temp12.value0 = (void*)&temp10;
  temp12.value1 = (void*)&temp11;
  stream_3(0, (void*)(&temp12));
}

static void stream_11(uint8_t arg, void* value) {
  uint8_t input_0 = *((uint8_t*)value);
  while ((UCSR0A & (1 << UDRE0)) == 0) {
  }
  UDR0 = input_0;
}

static void stream_3(uint8_t arg, void* value) {
  struct tuple2 input_0 = *((struct tuple2*)value);
  static uint16_t temp13 = 0;
  static uint16_t temp14 = 0;
  static struct tuple2 input_1 = { .value0 = (void*)&temp13, .value1 = (void*)&temp14 };
  uint16_t temp15;
  uint16_t temp16;
  struct tuple2 temp17;
  uint16_t temp18;
  uint16_t temp19;
  struct tuple2 temp20;
  struct tuple2 temp21;
  temp15 = 0;
  temp16 = 0;
  temp17.value0 = (void*)&temp15;
  temp17.value1 = (void*)&temp16;
  temp18 = 1;
  temp19 = (*((uint16_t*)input_1.value1) + *((uint16_t*)input_0.value1));
  temp20.value0 = (void*)&temp18;
  temp20.value1 = (void*)&temp19;
  if (((*((uint16_t*)input_1.value1) + *((uint16_t*)input_0.value1)) > *((uint16_t*)input_0.value0))) {
    temp21 = temp17;
  } else {
    temp21 = temp20;
  }
  *((uint16_t*)input_1.value0) = *((uint16_t*)temp21.value0);
  *((uint16_t*)input_1.value1) = *((uint16_t*)temp21.value1);
  stream_4(0, (void*)(&input_1));
}

static void stream_4(uint8_t arg, void* value) {
  struct tuple2 input_0 = *((struct tuple2*)value);
  if (*((uint16_t*)input_0.value0) == 0) {
    stream_5(0, (void*)(&input_0));
  }
}

static void stream_5(uint8_t arg, void* value) {
  struct tuple2 input_0 = *((struct tuple2*)value);
  bool temp22;
  temp22 = 0;
  stream_6(0, (void*)(&temp22));
}

static void stream_6(uint8_t arg, void* value) {
  bool input_0 = *((bool*)value);
  static uint16_t input_1 = 0;
  input_1 = (input_1 + 1);
  stream_7(0, (void*)(&input_1));
}

static void stream_7(uint8_t arg, void* value) {
  uint16_t input_0 = *((uint16_t*)value);
  bool temp23;
  temp23 = (input_0) % 2 == 0;
  stream_8(0, (void*)(&temp23));
}

static void stream_8(uint8_t arg, void* value) {
  bool input_0 = *((bool*)value);
  if (input_0) {
    PORTB |= (1 << PB5);
  } else {
    PORTB &= ~(1 << PB5);
  }
}

int main(void) {
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  UBRR0H = 0;
  UBRR0L = 103;
  UCSR0C |= (1 << UCSZ01);
  UCSR0C |= (1 << UCSZ00);
  UCSR0B |= (1 << RXEN0);
  UCSR0B |= (1 << TXEN0);
  DDRB |= (1 << PB5);
  bootup();
  while (1) {
    input_timer();
  }
  return 0;
}
