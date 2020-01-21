# EMOsician Software
## User Guide
Welcome to be an EMOsician! You can also be a musician with your emotion, music preference and even professional music understanding.
EMOsician will provide you with three versions to compose and generate music.

Step 1: Choose Parameters:
1. Simple Version:
If you are just new users, this version is the simplest one and can let you get familiar with
EMOsician. You can choose your preferred emotion including sad, happy, excited, nervous, lonely, relaxed and blue, which will be the basic tone for your EMOsician song.
2. Advanced Version:
If you are advanced users, you further specify your preferences including choosing your preferred genre, saturation(the density of instruments), and style (the complexity and speed of rhythm).
3. Professional Version:
If you are professional user who wants to DIY your music, professional version is best fit. You can choose your preferred Tempo (BPM for the song), Melody(your root note progression), Lead Instrument, Template(Music Composition Template), Dynamic Plus(Volume Fluctuation). 

Step 2: Generate and Play New Song:
After choosing parameter, EMOsician will translate your input into self-created music parameters. After careful calculating, you can click ‘generate new song’ and get a brand new original songs, which is wholly composed by our software. When the ‘play’ button is working, you can click it and listen to your song in the music player board.

Step 3: Re-generate New Song:
Music is a journey of trial and error. A good song takes time to write and choose. If the music generated is not satisfying, you can just click generate new music and get another new piece of music. Your old music file will be replaced but your trackdata will be kept, which is more efficient and also creating a back-up.

Step 4: Save Your Song:
If you like this song, you can save it by clicking ‘save’ button. Hope you can enjoy it!

## Sample Output
https://pan.baidu.com/s/1qg9-p7ESS_5PsWXhipNhFg

## Software Highlight
1. Unique Idea:
EMOsician is, at first place, interesting in its uniqueness of the idea. There is currently no such program can take users’s emotion wholly based on programming to compose, generate and play music. There are only some programs generating MIDI and do not take users’s emotion. Therefore, EMOsician is actually the first music-emotion software. This uniqueness of idea is in essence a principle that some part of music language can be interpreted as human sensation and computer can be the intermediate to link these two.
2. Valuable Application:
This software is not only interesting in idea but also practical in market. There are three potential
user types that will be interested and get benefits in EMOsician. 1) For children, this software can help them get an early-stage understanding of the relationship between music and their sensation. Thereby, help them gain interests and intuition in music composition. 2) For adults, DIY music for their emotion is a fun way to relax and they will get the feeling of a private song composer. 3) For professional or amateur musician, this software will quicken their music composing process. They can just press one button and get random generated music, which helps them find the right riff and melody faster.

## Module Structure
Module 1 UI is interacting with users to get user input parameters and implement music player functions through clicking.

Module 2 Music Parameter Interpreter is to take user input parameter and return important music composing parameters including template, tempo, instruments set and volume curve.

Module 3 Melody Composer is to take template, emotion, genre, style and return the core part of song, accompany and lead melody.

Module 4 TrackData Generator is to take all note data from module 2&3 and return in class trackdata, write text file to save all composing history data.

Module 5 Song Generator is to take trackdata, transform it into MIDI, using fluidsyth to compose it into pcm file. After this, it will convert pcm file into wav file and interact with UI to play, save the music.
