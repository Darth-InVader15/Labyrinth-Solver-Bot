int ir1 = 3;
int ir2 = 4;
int ir3 = 5;
int motor1p = 8;
int motor2p = 9;
int motor1n = 10;
int motor2n = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
  pinMode(motor1p,OUTPUT);
  pinMode(motor2p,OUTPUT);
  pinMode(motor1n,OUTPUT);
  pinMode(motor2n,OUTPUT);
  Serial.begin(9600);
}

void Left(){
  digitalWrite(motor1p,0);
  digitalWrite(motor1n,1);
  digitalWrite(motor2p,1);
  digitalWrite(motor2n,0);
}

void Right(){
  digitalWrite(motor1p,1);
  digitalWrite(motor1n,0);
  digitalWrite(motor2p,0);
  digitalWrite(motor2n,1);
}

void Forward(){
  digitalWrite(motor1p,1);
  digitalWrite(motor1n,0);
  digitalWrite(motor2p,1);
  digitalWrite(motor2n,0);
}

void Stop(){
  digitalWrite(motor1p,0);
  digitalWrite(motor1n,0);
  digitalWrite(motor2p,0);
  digitalWrite(motor2n,0);
}

void U_Turn(){
  while(digitalRead(ir2!=1)){
      Right();
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  auto IR1 = digitalRead(ir1);
  auto IR2 = digitalRead(ir2);
  auto IR3 = digitalRead(ir3);

  if (IR1 == LOW && IR2 == HIGH && IR3 == LOW)//Straight path
    {
     Forward();
    }

  if (IR1 == HIGH && IR2 == LOW && IR3 == LOW)//Left turn
    {
     Left();
    }

  if (IR1 == LOW && IR2 == LOW && IR3 == HIGH)//Right Turn
    {
      Right();
    }

  if (IR1 == HIGH && IR2 == LOW && IR3 == HIGH)//T Intersection
    {
      Left(); // As left is possible
    }

  if (IR1 == HIGH && IR2 == HIGH && IR3 == LOW)//Left T Intersection
    {
      Left();// As Left is possible
    }

  if (IR1 == LOW && IR2 == HIGH && IR3 == HIGH)//Right T Tntersection
    {
     Forward();//As Straight path is possible
    }

  if (IR1 == LOW && IR2 ==LOW && IR3 == LOW)//Dead End
    {
     U_Turn(); //As no other direction is possible
    }

  if (IR1 == HIGH && IR2 == HIGH && IR3 == HIGH)//4 Lane intersection
    {
     Left(); //As no other direction is possible
    }

  if (IR1 == HIGH && IR2 == HIGH && IR3 == HIGH)//End of Maze
    {
     Stop(); //As no other direction is possible
    }
 
}
