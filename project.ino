RFID Read Code:
#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9); // RX, TX

int count = 0;

void setup()
{
  Serial.begin(9600);
 
  mySerial.begin(9600);
 
  Serial.println("EM18 RFID Read Code");
}
void loop()
{
  if(mySerial.available())
  {
    count = 0; // Reset count to zero// Keep reading Byte by Byte from the Buffer till the Buffer is empty
    {
      char input = mySerial.read();
      Serial.print(input);
      count++; //
      delay(5); //
    }
  }
}
----------------------------------------------------------------------------------------------------------------------------------------------------------
Main Code:

#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9); // RX, TX

/*
 * 520032FDBB26
 * 52000F80A07D
 * 520012C50481
 * 52000F8EBD6E
 */

#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char input[12];
int count = 0;

int t = 0;

int a = 0, b = 0, c = 0;

int w = 0, x = 0, y = 0, z = 0;

int i = 0;

#define RLed A0
#define GLed A1

#define Candidate1 A2
#define Candidate2 A3
#define Candidate3 A4
#define Result A5

void setup()
{
  Serial.begin(9600);

  mySerial.begin(9600);

  pinMode(RLed, OUTPUT);
  pinMode(GLed, OUTPUT);
    digitalWrite(RLed, LOW);
    digitalWrite(GLed, LOW);

  pinMode(Candidate1, INPUT_PULLUP);
  pinMode(Candidate2, INPUT_PULLUP);
  pinMode(Candidate3, INPUT_PULLUP);
  pinMode(Result, INPUT_PULLUP);
 
  lcd.begin(16, 2);
 
  lcd.setCursor(0, 0);
  lcd.print("RFID Voting Syst");
}

void loop()
{
  if(digitalRead(Result) == LOW)
  {
    lcd.setCursor(0, 1);
   
    if((a > b) && (a > c))
    {
      lcd.print(" CANDIDATE1 Win ");
    }
    else if((b > a) && (b > c))
    {
      lcd.print(" CANDIDATE2 Win ");
    }
    else if((c > a) && (c > b))
    {
      lcd.print(" CANDIDATE3 Win ");
    }
    else if((a == b) && (a > c))
    {
      lcd.print("CAN1 & CAN2 Tied");
    }
    else if((b == c) && (b > c))
    {
      lcd.print("CAN2 & CAN3 Tied");
    }
    else if((a == 0) && (b == 0) && (c == 0))
    {
      lcd.print("VOTE Not Casted ");
    }
   
    delay(2000);
  }
 
  if(i > 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("No of votes = ");
    lcd.print(i);
    lcd.print(" ");
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("No of votes = ");
    lcd.print(i);
    lcd.print(" ");
  }
 
  if (mySerial.available())
  {
    t = 0;
   
    count = 0;
   
    while (mySerial.available() && count < 12)
    {
      input[count] = mySerial.read();
      count++;
      delay(5);
    }
   
    if (count == 12)
    {
      if ((strncmp(input, "520032FDBB26", 12) == 0) && (t == 0))
      {
        w++;

        if(w >= 2)
        {
          lcd.setCursor(0, 1);
          lcd.print(" Already Voted  ");

          digitalWrite(GLed, LOW);
          digitalWrite(RLed, HIGH);
         
          delay(3000);

          lcd.setCursor(0, 1);
          lcd.print("                ");
          delay(500);
        }

        else if (w == 1)
        {
          lcd.setCursor(0, 1);
          lcd.print(" Cast Your Vote ");
         
          while(1)
          {
            if(digitalRead(Candidate1) == LOW)
            {
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              i++;
              a++;
             
              lcd.setCursor(0, 1);
              lcd.print("  Vote Casted   ");

              digitalWrite(RLed, LOW);
              digitalWrite(GLed, HIGH);
             
              delay(3000);
 
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              break;
            }
            else if(digitalRead(Candidate2) == LOW)
            {
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              i++;
              b++;
             
              lcd.setCursor(0, 1);
              lcd.print("  Vote Casted   ");

              digitalWrite(RLed, LOW);
              digitalWrite(GLed, HIGH);
                           
              delay(3000);
 
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              break;
            }
            else if(digitalRead(Candidate3) == LOW)
            {
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              i++;
              c++;
             
              lcd.setCursor(0, 1);
              lcd.print("  Vote Casted   ");

              digitalWrite(RLed, LOW);
              digitalWrite(GLed, HIGH);
                           
              delay(3000);
 
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              break;
            }
          }
        }
 
        z = 1;
      }
     
      else if ((strncmp(input, "52000F80A07D", 12) == 0) && (t == 0))//0B0028715705
      {
        x++;

        if(x >= 2)
        {
          lcd.setCursor(0, 1);
          lcd.print(" Already Voted  ");

          digitalWrite(GLed, LOW);
          digitalWrite(RLed, HIGH);
                       
          delay(3000);

          lcd.setCursor(0, 1);
          lcd.print("                ");
          delay(500);
        }

        else if (x == 1)
        {
          lcd.setCursor(0, 1);
          lcd.print(" Cast Your Vote ");
         
          while(1)
          {
            if(digitalRead(Candidate1) == LOW)
            {
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              i++;
              a++;
             
              lcd.setCursor(0, 1);
              lcd.print("  Vote Casted   ");

              digitalWrite(RLed, LOW);
              digitalWrite(GLed, HIGH);
                         
              delay(3000);
 
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              break;
            }
            else if(digitalRead(Candidate2) == LOW)
            {
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              i++;
              b++;
             
              lcd.setCursor(0, 1);
              lcd.print("  Vote Casted   ");

              digitalWrite(RLed, LOW);
              digitalWrite(GLed, HIGH);
                         
              delay(3000);
 
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              break;
            }
            else if(digitalRead(Candidate3) == LOW)
            {
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              i++;
              c++;
             
              lcd.setCursor(0, 1);
              lcd.print("  Vote Casted   ");
           
              digitalWrite(RLed, LOW);
              digitalWrite(GLed, HIGH);
             
              delay(3000);
 
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              break;
            }
          }
        }
 
        z = 1;
      }

      else if ((strncmp(input, "520012C50481", 12) == 0) && (t == 0))
      {
        y++;

        if(y >= 2)
        {
          lcd.setCursor(0, 1);
          lcd.print(" Already Voted  ");

          digitalWrite(GLed, LOW);
          digitalWrite(RLed, HIGH);
         
          delay(3000);

          lcd.setCursor(0, 1);
          lcd.print("                ");
          delay(500);
        }

        else if (y == 1)
        {
          lcd.setCursor(0, 1);
          lcd.print(" Cast Your Vote ");
         
          while(1)
          {
            if(digitalRead(Candidate1) == LOW)
            {
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              i++;
              a++;
             
              lcd.setCursor(0, 1);
              lcd.print("  Vote Casted   ");
           
              digitalWrite(RLed, LOW);
              digitalWrite(GLed, HIGH);
             
              delay(3000);
 
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              break;
            }
            else if(digitalRead(Candidate2) == LOW)
            {
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              i++;
              b++;
             
              lcd.setCursor(0, 1);
              lcd.print("  Vote Casted   ");
           
              digitalWrite(RLed, LOW);
              digitalWrite(GLed, HIGH);
             
              delay(3000);
 
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              break;
            }
            else if(digitalRead(Candidate3) == LOW)
            {
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              i++;
              c++;
             
              lcd.setCursor(0, 1);
              lcd.print("  Vote Casted   ");
           
              digitalWrite(RLed, LOW);
              digitalWrite(GLed, HIGH);
             
              delay(3000);
 
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              break;
            }
          }
        }
 
        z = 1;
      }
     
      else if ((strncmp(input, "52000F8EBD6E", 12) == 0) && (t == 0))//0B0028715705
      {
        z++;

        if(z >= 2)
        {
          lcd.setCursor(0, 1);
          lcd.print(" Already Voted  ");
         
          digitalWrite(GLed, LOW);
          digitalWrite(RLed, HIGH);
             
          delay(3000);

          lcd.setCursor(0, 1);
          lcd.print("                ");
          delay(500);
        }

        else if (z == 1)
        {
          lcd.setCursor(0, 1);
          lcd.print(" Cast Your Vote ");
         
          while(1)
          {
            if(digitalRead(Candidate1) == LOW)
            {
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              i++;
              a++;
             
              lcd.setCursor(0, 1);
              lcd.print("  Vote Casted   ");
           
              digitalWrite(RLed, LOW);
              digitalWrite(GLed, HIGH);
             
              delay(3000);
 
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              break;
            }
            else if(digitalRead(Candidate2) == LOW)
            {
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              i++;
              b++;
             
              lcd.setCursor(0, 1);
              lcd.print("  Vote Casted   ");
           
              digitalWrite(RLed, LOW);
              digitalWrite(GLed, HIGH);
             
              delay(3000);
 
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              break;
            }
            else if(digitalRead(Candidate3) == LOW)
            {
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              i++;
              c++;
             
              lcd.setCursor(0, 1);
              lcd.print("  Vote Casted   ");
           
              digitalWrite(RLed, LOW);
              digitalWrite(GLed, HIGH);
             
              delay(3000);
 
              lcd.setCursor(0, 1);
              lcd.print("                ");
              delay(500);
             
              break;
            }
          }
        }
 
        t = 1;
      }
           
      else
      {
        if (t != 1)
        {          
          lcd.setCursor(0, 1);
          lcd.print("  Access Denied ");
         
          digitalWrite(GLed, LOW);
          digitalWrite(RLed, HIGH);
             
          delay(3000);

          lcd.setCursor(0, 1);
          lcd.print("                ");
       
          t = 0;
        }
      }
    }
  }
}
