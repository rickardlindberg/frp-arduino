// This file is automatically generated.

#include <avr/io.h>
#include <stdbool.h>

static void input_pin12();

static void input_timer();

static void stream_1(int arg, void* value);

static void stream_2(int arg, void* value);

static void stream_3(int arg, void* value);

static void stream_4(int arg, void* value);

static void stream_5(int arg, void* value);

static void stream_6(int arg, void* value);

static void input_pin12() {
  bool temp0;
  temp0 = (PINB & (1 << PB4)) == 0U;
  stream_1(0, (void*)(&temp0));
}

static void input_timer() {
  int temp1;
  temp1 = TCNT1;
  TCNT1 = 0;
  stream_2(0, (void*)(&temp1));
}

static void stream_1(int arg, void* value) {
  static bool input_0;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
  }
  if (input_0) {
    PORTB |= (1 << PB5);
  } else {
    PORTB &= ~(1 << PB5);
  }
}

static void stream_2(int arg, void* value) {
  static int input_0;
  switch (arg) {
    case 0:
      input_0 = *((int*)value);
      break;
  }
  static int fold_state = 0;
  bool temp2;
  temp2 = fold_state > 10000;
  int temp3;
  temp3 = input_0 + fold_state;
  int temp4;
  temp4 = temp3 - 10000;
  int temp5;
  temp5 = input_0 + fold_state;
  int temp6;
  if (temp2) {
    temp6 = temp4;
  } else {
    temp6 = temp5;
  }
  fold_state = temp6;
  stream_3(0, (void*)(&fold_state));
}

static void stream_3(int arg, void* value) {
  static int input_0;
  switch (arg) {
    case 0:
      input_0 = *((int*)value);
      break;
  }
  bool temp7;
  temp7 = input_0 > 10000;
  bool temp8;
  temp8 = false;
  if (temp7) {
    temp8 = true;
  }
  if (temp8) {
    stream_4(0, (void*)(&input_0));
  }
}

static void stream_4(int arg, void* value) {
  static int input_0;
  switch (arg) {
    case 0:
      input_0 = *((int*)value);
      break;
  }
  static int fold_state = 0;
  int temp9;
  temp9 = fold_state + 1;
  fold_state = temp9;
  stream_5(0, (void*)(&fold_state));
}

static void stream_5(int arg, void* value) {
  static int input_0;
  switch (arg) {
    case 0:
      input_0 = *((int*)value);
      break;
  }
  bool temp10;
  temp10 = (input_0) % 2 == 0;
  stream_6(0, (void*)(&temp10));
}

static void stream_6(int arg, void* value) {
  static bool input_0;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
  }
  if (input_0) {
    PORTB |= (1 << PB3);
  } else {
    PORTB &= ~(1 << PB3);
  }
}

int main(void) {
  DDRB &= ~(1 << PB4);
  PORTB |= (1 << PB4);
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  DDRB |= (1 << PB5);
  DDRB |= (1 << PB3);
  while (1) {
    input_pin12();
    input_timer();
  }
  return 0;
}
