# [STM32F405RGT6] | Demo Playing a Music Segment via AD/DA Circuit
- Carry out the project to enhance experience with the STM32F405RGT6 microcontroller and its peripherals: Timer Trigger, DMA, and DAC. Although this is a school assignment, the level of focus is quite high.
- [Demo Video](https://www.youtube.com/shorts/kTc38kje_yg)

## Main features

- Convert 8-bit PCM audio to an 8-bit audio data stream.
- Implement a timer trigger based on the audio rate.
- Utilize DMA (Direct Memory Access) from Memory to Peripheral to transmit audio data to the DAC (Digital-to-- Analog Converter).

## Installation Guide

- Use **STM32CubeMX** to open the project **Music_DAC**.
- Execute the C program **mainBig.c** in the folder **SoundValue/Big/** to convert the audio from .wav PCM 8-bit format to data (Replace the audio file with your corresponding audio first).
- Substitute the received audio data into the file **Music_DAC/MDK-ARM/soundValue.c.**

## Contribution
- Please provide your feedback [here](https://tudienembedded.blogspot.com/2020/11/loi-mo-au.html?lr=1).

## Tác giả
### Huynh Chi That
- [My blogger](https://tudienembedded.blogspot.com)
- [Github](https://github.com/thathcmus)
- [Linkedin](https://www.linkedin.com/in/hcthat)
- [Facebook](https://www.facebook.com/Chithat2105)
