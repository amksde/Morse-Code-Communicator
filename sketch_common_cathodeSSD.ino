#define SIZE 26
const int dotButton  = 12;
const int dashButton = 11;
const int breakButton = 10;

//Array of MorseCode for letters of English Language A to Z
String letters[SIZE]={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
// J to R 
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
// S to Z
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

void setup()
{
 
 //for seven segment
 pinMode(2,OUTPUT);//dot pin
 // modes
 pinMode(3,OUTPUT);//c
 pinMode(4,OUTPUT);//d
 pinMode(5,OUTPUT);//e
 pinMode(6,OUTPUT);//g
 pinMode(7,OUTPUT);//f
 pinMode(8,OUTPUT);//a
 pinMode(9,OUTPUT);//b
 // Buttons
 pinMode(10,INPUT);//for loop break & space between chas
 pinMode(11,INPUT);//for "."
 pinMode(12,INPUT);//for "-"
 Serial.begin(9600);
 
 Serial.println("\n\n Welcome!!");
   
}

void loop()
{
  main_func();
}
void main_func()
{
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);  
    
  int option = 0; //for input of option
  Serial.begin(9600);
  Serial.println("Please choose option\n1. Morse to Text\n2. Text to Morse");
  while(1)
  {
    if(Serial.available())
    {
       String input = Serial.readStringUntil('\n'); 
       option= input.toInt();
       break;
    }
    Serial.flush();
  }
  
 if(option==1)
 {
    //converts morse code to text
    while(1)
    {
      if(morse_to_text()==1)
        
        return;
    }
 }
 else if(option==2)
 {
    String inp = "";
    Serial.println("Enter String");
    Serial.flush();
   while(1){
     if(Serial.available())
    {
      inp = Serial.readStringUntil('\n');
      break;
    }
    Serial.flush();
    }
   Serial.println(inp);
   text_to_morse(inp);
 }
 else
 {
    Serial.println("Please input correct option!");
 }
}

void text_to_morse(String input)
{
  pinMode(10,OUTPUT);//for loop break & space between chas
  pinMode(11,OUTPUT); //for "."
  pinMode(12,OUTPUT);//for "-"
  int len = input.length();
  for(int i = 0; i<len; i++)
  {
    display_morse(input[i]);
  }
  pinMode(10,INPUT);//for loop break & space between chas
  pinMode(11,INPUT);//for "."
  pinMode(12,INPUT);//for "-"
}

void display_morse(char c)
{
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delay(500);
    String morse = letters[c-'A'];
    int len = morse.length();
    for(int i = 0; i<len; i++)
    {
      if(morse[i]=='.')
      {
        digitalWrite(12, HIGH);
        delay(500);
        digitalWrite(12, LOW);
        delay(500);
      }
      else
      {
        digitalWrite(11, HIGH);
        delay(500);
        digitalWrite(11, LOW);
        delay(500);
        
      }
    }

     digitalWrite(10, HIGH);
     delay(500);
     digitalWrite(10, LOW);
     delay(500);
  
     digitalWrite(10, LOW);
     digitalWrite(11, LOW);
     digitalWrite(12, LOW);
}



// morse code string to english character
int convertIntoText(String characterCode)
{
  
  for(int index=0; index<SIZE; index++)
  {
    if(characterCode == letters[index])
    {
      return (index);   
    } 
  }
  return -1;
  
}


int morse_to_text()
{
  int breakButtonState = 0;
  int dotButtonState = 0;
  int dashButtonState = 0;
  int generated=0;
  String morseCode = "";
  
 digitalWrite(2,HIGH);
 delay(50);
  
  while(1)
  {
    dotButtonState = digitalRead(dotButton);
    dashButtonState = digitalRead(dashButton);
    breakButtonState = digitalRead(breakButton);
    
    if(morseCode.length()==0&&breakButtonState == HIGH){
       digitalWrite(2,LOW);
     delay(50);
      return 1;
    }
    if(dashButtonState == HIGH)
    {
      morseCode.concat("-"); // Storing code in variable morseCode with the help of concatenation function
      delay(200);
    }
    else if(dotButtonState == HIGH)
    {
      morseCode.concat(".");  
      delay(200);
    }
    else if(breakButtonState == HIGH)
    {
      break;      
    }
  }
  generated = convertIntoText(morseCode);
  displaySSD(generated);
  
 digitalWrite(2,HIGH);
 delay(50);
  return 0;
}

void displaySSD(int n){
  //a-8
  //b-9
  //c-3
  //d-4
  //e-5
  //f-7
  //g-6
  
  if(n==-1){
    digitalWrite(6,HIGH);
  }
  else if(n==0){         //A
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(3,HIGH);
  }
  else if(n==1){      //B
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    
  }
  else if(n==2){      //C
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
  }
  else if(n==3){      //D
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
  }
  else if(n==4){      //E
    digitalWrite(8,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);

  }
  else if(n==5){      //F
    digitalWrite(8,HIGH);
    digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
  }
  else if(n==6){      //G
    digitalWrite(8,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
  digitalWrite(3,HIGH);
    digitalWrite(7,HIGH);
  }
  else if(n==7){      //H
    digitalWrite(9,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
  digitalWrite(3,HIGH);
    digitalWrite(7,HIGH);
  }
  else if(n==8){      //I
    digitalWrite(5,HIGH);
    digitalWrite(7,HIGH);
  }
  else if(n==9){      //J
    digitalWrite(9,HIGH);
  digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }
  else if(n==10){     //K
    digitalWrite(8,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
  digitalWrite(3,HIGH);
    digitalWrite(7,HIGH);
  }
  else if(n==11){     //L
    digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);    
  }
  else if(n==12){     //M
    digitalWrite(9,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
  }
  else if(n==13){     //N
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(5,HIGH);
  digitalWrite(3,HIGH);
    digitalWrite(7,HIGH);
  }
  else if(n==14){     //O
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(5,HIGH);
  digitalWrite(3,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(4,HIGH);
  }
  else if(n==15){     //P
    digitalWrite(9,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
  }
  else if(n==16){     //Q
    digitalWrite(9,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(8,HIGH);
  digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);
  }
  else if(n==17){     //R
    digitalWrite(9,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
  }
  else if(n==18){     //S
    digitalWrite(8,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
    digitalWrite(7,HIGH);
  }
  else if(n==19){     //T
    digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
  }
  else if(n==20){     //U
    digitalWrite(9,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
  digitalWrite(3,HIGH);
    digitalWrite(7,HIGH);
  }
  else if(n==21){     //V
    digitalWrite(9,HIGH);
    digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
    digitalWrite(7,HIGH);
  }
  else if(n==22){     //W
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
  digitalWrite(3,HIGH);
    digitalWrite(8,HIGH);
  }
  else if(n==23){     //X
    digitalWrite(8,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(4,HIGH);
  }
  else if(n==24){     //Y
    digitalWrite(7,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }
  else if(n==25){     //Z
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(4,HIGH);
  }
  delay(1000);
  digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  delay(100);
}
