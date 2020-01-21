#ifndef PCM_TO_WAV_H
#define PCM_TO_WAV_H

#include <memory.h>
#include <stdio.h>
#include <variable.h>
#include <string.h>

struct RIFF_HEADER
{
    char szRiffID[4]; // 'R','I','F','F'
    unsigned int dwRiffSize;
    char szRiffFormat[4]; // 'W','A','V','E'
};

struct WAVE_FORMAT
{
    unsigned short wFormatTag;
    unsigned short wChannels;
    unsigned int dwSamplesPerSec;
    unsigned int dwAvgBytesPerSec;
    unsigned short wBlockAlign;
    unsigned short wBitsPerSample;
};

struct FMT_BLOCK
{
    char szFmtID[4]; // 'f','m','t',' '
    unsigned int dwFmtSize;
    struct WAVE_FORMAT wavFormat;
};

union DWORD_CHAR
{
    int nValue;
    char charBuf[4];
};

int writeFile2Int(FILE *fp, int nWhere, int nValue);
void writeWaveHead(FILE *fp);
void writeWaveBody(FILE *fp, long filelength);
int pcm_to_wav();

#endif // PCM_TO_WAV_H
