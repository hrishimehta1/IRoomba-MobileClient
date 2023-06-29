

void manualCmd()
{
  switch (command)
  {
    
    case 'm': 
      startSafe();
      Serial.print("Roomba in Safe mode");
      BT1.print("Roomba BT Ctrl OK - Safe mode");
      BT1.println('\n');
      command = 'f';
      playSound (3);
      break;
 
    case 'f': 
      driveStop(); //turn off both motors
      state = command;
      break;

    case 'w':  
      drive (motorSpeed, 0); 
      state = command;  
      break;

    case 'd':     
      driveRight(motorSpeed);
      break;

   case 'a': 
      driveLeft(motorSpeed);
      break;
    
    case 's':  
      drive (-motorSpeed, 0);
      state = command;
      break;

    case '+': 
      if (state == 'w')
      {
        motorSpeed = motorSpeed + 10;
        if (motorSpeed > MAX_SPEED) 
        { 
          motorSpeed = MAX_SPEED;
        }  
        command = 'w';
      } else {command = state;}
      break;

    case '-': 
 
      if (state == 'w')
      {
        motorSpeed = motorSpeed - 10;
      }     
      if (motorSpeed < MIN_SPEED ) 
      { 
        motorSpeed = MIN_SPEED;
      }
      Serial.println(motorSpeed); 
      command = state;
      break;
  }
}
