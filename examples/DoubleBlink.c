// This file is automatically generated.

#include <avr/io.h>
#include <stdbool.h>

static void input_timer();

static void stream_1(int arg, void* value);

static void stream_2(int arg, void* value);

static void stream_3(int arg, void* value);

static void stream_4(int arg, void* value);

static void stream_5(int arg, void* value);

static void stream_6(int arg, void* value);

static void stream_7(int arg, void* value);

static void input_timer() {
  int temp0;
  temp0 = TCNT1;
  TCNT1 = 0;
  stream_1(0, (void*)(&temp0));
}

static void stream_1(int arg, void* value) {
  static int input_0;
  switch (arg) {
    case 0:
      input_0 = *((int*)value);
      break;
  }
  static int fold_state = 0;
  bool temp1;
  temp1 = fold_state > 10000;
  int temp2;
  temp2 = input_0 + fold_state;
  int temp3;
  temp3 = temp2 - 10000;
  int temp4;
  temp4 = input_0 + fold_state;
  int temp5;
  if (temp1) {
    temp5 = temp3;
  } else {
    temp5 = temp4;
  }
  fold_state = temp5;
  stream_2(0, (void*)(&fold_state));
}

static void stream_2(int arg, void* value) {
  static int input_0;
  switch (arg) {
    case 0:
      input_0 = *((int*)value);
      break;
  }
  bool temp6;
  temp6 = input_0 > 10000;
  bool temp7;
  temp7 = false;
  if (temp6) {
    temp7 = true;
  }
  if (temp7) {
    stream_3(0, (void*)(&input_0));
  }
}

static void stream_3(int arg, void* value) {
  static int input_0;
  switch (arg) {
    case 0:
      input_0 = *((int*)value);
      break;
  }
  static int fold_state = 0;
  int temp8;
  temp8 = fold_state + 1;
  fold_state = temp8;
  stream_4(0, (void*)(&fold_state));
}

static void stream_4(int arg, void* value) {
  static int input_0;
  switch (arg) {
    case 0:
      input_0 = *((int*)value);
      break;
  }
  bool temp9;
  temp9 = (input_0) % 2 == 0;
  stream_5(0, (void*)(&temp9));
  stream_6(0, (void*)(&temp9));
}

static void stream_5(int arg, void* value) {
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

static void stream_6(int arg, void* value) {
  static bool input_0;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
  }
  bool temp10;
  temp10 = !(input_0);
  stream_7(0, (void*)(&temp10));
}

static void stream_7(int arg, void* value) {
  static bool input_0;
  switch (arg) {
    case 0:
      input_0 = *((bool*)value);
      break;
  }
  if (input_0) {
    PORTB |= (1 << PB4);
  } else {
    PORTB &= ~(1 << PB4);
  }
}

int main(void) {
  TCCR1B |= (1 << CS12);
  TCCR1B |= (1 << CS10);
  DDRB |= (1 << PB5);
  DDRB |= (1 << PB4);
  while (1) {
    input_timer();
  }
  return 0;
}
