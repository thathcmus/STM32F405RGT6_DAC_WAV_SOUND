#include <stdio.h>
#include <stdint.h>
int main() {

    FILE *wavFile = fopen("recording.wav","rb");
    FILE *soundVal = fopen("soundVal_8bit.txt","w");
    fseek(wavFile,20,SEEK_SET);
    int data;
    fread(&data,2,1,wavFile);
    fprintf(soundVal, "Audio Format: %d\n",data);
    data = 0;
    fread(&data,2,1,wavFile);
    fprintf(soundVal, "Number Of Channels: %d\n",data);
    data = 0;
    fread(&data,4,1,wavFile);
    fprintf(soundVal, "Sample Rate: %d\n",data);
    data = 0;
    fread(&data,4,1,wavFile);
    fprintf(soundVal, "Byte Rate: %d\n",data);
    data = 0;
    fread(&data,2,1,wavFile);
    fprintf(soundVal, "Block Align: %d\n",data);
    data = 0;
    fread(&data,2,1,wavFile);
    fprintf(soundVal, "Bits Per Sample: %d\n",data);
    fseek(wavFile,40,SEEK_SET);
    data = 0;
    fread(&data,4,1,wavFile);
    fprintf(soundVal, "Size: %d\n\n",data);

    // Rest code only works  for unsigned 8-bit mono channel wav files.

    int x = 0;
    for(int i = 0 ; i < data ; i++) {
        uint8_t value;
        fread(&value,1,1,wavFile);
        fprintf(soundVal,"%d,",value);
        x++;
        if(x == 20) {
            fprintf(soundVal,"\n");
            x=0;
        }
    }



    fclose(wavFile);
    fclose(soundVal);

}
