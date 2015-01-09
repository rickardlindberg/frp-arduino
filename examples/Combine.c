// This file is automatically generated.

#include <avr/io.h>
#include <stdbool.h>

static void clock();

static void input_pin12();

static void stream_1(unsigned int input_0);

static void stream_2(bool input_0);

static void stream_3(int arg, void* value);

static void stream_4(bool input_0);

static void stream_5(bool input_0);

static void stream_6(int arg, void* value);

static void stream_7(bool input_0);

static void clock() {
  unsigned int output;
  static unsigned int temp0 = 0U;
  temp0++;
  output = temp0;
  stream_1(output);
}

static void input_pin12() {
  bool output;
  output = (PINB & 0x10U) == 0U;
  stream_2(output);
  stream_3(0, (void*)(&output));
  stream_6(0, (void*)(&output));
}

static void stream_1(unsigned int input_0) {
  bool output;
  output = (input_0) % 2 == 0;
  stream_3(1, (void*)(&output));
  stream_5(output);
}

static void stream_2(bool input_0) {
  if (input_0) {
    PORTB |= 0x20U;
  } else {
    PORTB &= ~(0x20U);
  }
}

static void stream_3(int arg, void* value) {
  bool output;
  static bool input_0;
  static bool input_1;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
    case 1:
      input_1 = *((bool*)value);
      break;
  }
  if (input_0) {
    output = input_1;
  } else {
    output = false;
  }
  output = output;
  stream_4(output);
}

static void stream_4(bool input_0) {
  if (input_0) {
    PORTB |= 0x08U;
  } else {
    PORTB &= ~(0x08U);
  }
}

static void stream_5(bool input_0) {
  bool output;
  output = !(input_0);
  stream_6(1, (void*)(&output));
}

static void stream_6(int arg, void* value) {
  bool output;
  static bool input_0;
  static bool input_1;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
    case 1:
      input_1 = *((bool*)value);
      break;
  }
  if (input_0) {
    output = input_1;
  } else {
    output = false;
  }
  output = output;
  stream_7(output);
}

static void stream_7(bool input_0) {
  if (input_0) {
    PORTB |= 0x04U;
  } else {
    PORTB &= ~(0x04U);
  }
}

int main(void) {
  TCCR1B = (1 << CS12) | (1 << CS10);
  DDRB &= ~(0x10U);
  PORTB |= 0x10U;
  DDRB |= 0x20U;
  DDRB |= 0x08U;
  DDRB |= 0x04U;
  while (1) {
    if (TCNT1 >= 10000) {
      TCNT1 = 0;
      clock();
    }
    input_pin12();
  }
  return 0;
}
