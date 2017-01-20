#define direccion 7
#define steps 4
#define enable 8

#define button 13

bool state;

byte state0 = 0;

void setup() {
  pinMode(direccion, OUTPUT);
  pinMode(steps, OUTPUT);
  pinMode(enable, OUTPUT);

  pinMode(button, INPUT);

  digitalWrite(enable , 1);

  Serial.begin(115200);
  Serial.setTimeout(5);
}

void loop() {

  if (Serial.available() > 0) {
    int x = Serial.parseInt();
    if (x == 3) {
      state0 = 3; // home z
    }
    else if (x == 6) {
      state0 = 6; // mover z abajo
    }
    else if (x == 9) {
      state0 = 9; // mover z arriba
    }
    else if (x == 66) {
      state0 = 66; // mover z abajo 2 veces
    }
    else if (x == 99) {
      state0 = 99; // mover z arriba 2 veces
    }
    else if (x == 666) {
      state0 = 16; // apagar luz
    }
    else if (x == 999) {
      state0 = 19; // apagar luz
    }
    else if (x == 100) {
      state0 = 100; // prender luz
    }
    else if (x == 101) {
      state0 = 101; // apagar luz
    }
    else state0 = 0;
  }

  if (state0 == 3) {
    HomeZ();
    Serial.println("o");
  }
  else if (state0 == 6) {
    moverZ_abajo();
    Serial.println("o");
  }
  else if (state0 == 9) {
    moverZ_arriba();
    Serial.println("o");
  }
  else if (state0 == 66) {
    for (int i = 0; i <= 50; i++) {
      moverZ_abajo();
    }
    Serial.println("o");
  }
  else if (state0 == 99) {
    for (int i = 0; i <= 50; i++) {
      moverZ_arriba();
    }
    Serial.println("o");
  }
  else if (state0 == 16) {
    for (int i = 0; i <= 150; i++) {
      moverZ_abajo();
    }
    Serial.println("o");
  }
  else if (state0 == 19) {
    for (int i = 0; i <= 150; i++) {
      moverZ_arriba();
    }
    Serial.println("o");
  }
  else if (state0 == 100) {
    digitalWrite(12, 1);
  }
  else if (state0 == 101) {
    digitalWrite(12, 0);
  }
}

//--------- HOME Z ---------
void HomeZ() {
  byte BS = digitalRead(button);
  if (BS == 1) {
    digitalWrite(enable , LOW);
    digitalWrite(direccion , LOW);

    digitalWrite(steps , LOW);
    digitalWrite(steps , HIGH);
    delayMicroseconds(500);
  }
  if (BS == 0 and state == 0) {
    digitalWrite(enable , LOW);
    digitalWrite(direccion , HIGH);
    for (int i = 0; i <= 50 * 16; i++)
    {
      digitalWrite(steps , HIGH);
      digitalWrite(steps , LOW);
      delayMicroseconds(250);
    }
    state = true;
  }
  BS = digitalRead(button);
  if (BS == 0 and state == 1) {
    digitalWrite(enable , HIGH);
    state0 = 0;
    state = 0;
  }
}
//--------- MOVER Z ABAJO ---------
void moverZ_abajo() {
  digitalWrite(enable , 0);
  digitalWrite(direccion , HIGH);
  for (int i = 0; i <= 16; i++)
  {
    digitalWrite(steps , HIGH);
    digitalWrite(steps , LOW);
    delayMicroseconds(250);
  }
  digitalWrite(enable , 1);
  state0 = 0;
  state = 0;
}
//--------- MOVER Z ARRIBA ---------
void moverZ_arriba() {

  digitalWrite(enable , 0);
  digitalWrite(direccion , LOW);

  for (int i = 0; i <= 1 * 16; i++)
  {
    byte BS = digitalRead(button);

    digitalWrite(steps , LOW);
    digitalWrite(steps , HIGH);
    delayMicroseconds(250);

  }
  state0 = 0;
  state = 0;

  digitalWrite(enable , 1);
}


