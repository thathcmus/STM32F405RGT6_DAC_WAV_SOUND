#include <stdio.h>
#include <stdint.h>
int main() {

    FILE *wavFile = fopen("recording.wav","rb");
    FILE *dac = fopen("dac_8bit.txt","w");
    fseek(wavFile,20,SEEK_SET);
    int data;
    fread(&data,2,1,wavFile);
    fprintf("Audio Format: %d\n",data);
    data = 0;
    fread(&data,2,1,wavFile);
    fprintf("Number Of Channels: %d\n",data);
    data = 0;
    fread(&data,4,1,wavFile);
    fprintf("Sample Rate: %d\n",data);
    data = 0;
    fread(&data,4,1,wavFile);
    fprintf("Byte Rate: %d\n",data);
    data = 0;
    fread(&data,2,1,wavFile);
    fprintf("Block Align: %d\n",data);
    data = 0;
    fread(&data,2,1,wavFile);
    fprintf("Bits Per Sample: %d\n",data);
    fseek(wavFile,40,SEEK_SET);
    data = 0;
    fread(&data,4,1,wavFile);
    fprintf("Size: %d\n",data);

    // Rest code only works  for unsigned 8-bit mono channel wav files.

    int x = 0;
    for(int i = 0 ; i < data ; i++) {
        uint8_t value;
        fread(&value,1,1,wavFile);
        fprintf(dac,"%d,",value);
        x++;
        if(x == 20) {
            fprintf(dac,"\n");
            x=0;
        }
    }



    fclose(wavFile);
    fclose(dac);

}
