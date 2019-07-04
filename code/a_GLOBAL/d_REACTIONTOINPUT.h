#ifndef _d_REACTION_TO_INPUT_H
#define _d_REACTION_TO_INPUT_H
#include <TMRpcm.h>
#include <LiquidCrystal_I2C.h>

void inputReact(char mychar, int HowManySongs, int *currentSong ,TMRpcm tmrpcm, int *loudnessLevel, LiquidCrystal_I2C lcd){

  
//What if user wants to play song no.5 but it does not exitst
//What ig he plays next

//p for Play and Pause
//n for Next
//r for remove

 //converting from into to array of character that can be send as an argument to xxx.play() etc.
 String fileFormat= ".wav";
 String song = String(*currentSong)+fileFormat;
char buff[7];
song.toCharArray(buff, 7);
char *p = buff;

//END

   if(mychar == 'p' && tmrpcm.isPlaying()){
      tmrpcm.pause();   //PAUSE SONG
    } 
    else if(mychar == 'p'){ 
      tmrpcm.play(buff);      //PLAY SONG
    void  obtainStringMetadata(File FileMetadata,String buff);

    } 
    else if(mychar == 'n'){
      lcd.clear();
      tmrpcm.play(buff);    //PLAY NEXT SONG

char info[32];
char bottom[16];
  lcd.setCursor(0, 0);
  tmrpcm.listInfo(buff,info,0);
  lcd.print(info);//Serial.println(":"); 
  for(int i=16;i<32;i++)
  {
    bottom[i%16]=info[i];
    
    }
  lcd.setCursor(0,1);
  lcd.print(bottom);
  
     
        } 
    else if(mychar == 'r'){
      tmrpcm.disable();
   SD.remove(buff);
   setup();
   loop();
  //REMOVE SONG
    }
    //volume adjustment
  else if(mychar == 'q'){

    if(*loudnessLevel<=1)
    {*loudnessLevel=1;
    }
    else
    *loudnessLevel=*loudnessLevel-1;
tmrpcm.setVolume(*loudnessLevel);
 
    }

  else if(mychar == 'l'){
      if(*loudnessLevel>=7)
    {*loudnessLevel=7;
    }
    else
    *loudnessLevel=*loudnessLevel+1;
tmrpcm.setVolume(*loudnessLevel);

  } 
}
//SR

#endif
