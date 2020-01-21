#include <memory.h>
#include <stdio.h>
#include <variable.h>
#include <string.h>
#include <pcm_to_wav.h>
#include <mainwindow.h>

//struct RIFF_HEADER
//{
//    char szRiffID[4]; // 'R','I','F','F'
//    unsigned int dwRiffSize;
//    char szRiffFormat[4]; // 'W','A','V','E'
//};

//struct WAVE_FORMAT
//{
//    unsigned short wFormatTag;
//    unsigned short wChannels;
//    unsigned int dwSamplesPerSec;
//    unsigned int dwAvgBytesPerSec;
//    unsigned short wBlockAlign;
//    unsigned short wBitsPerSample;
//};

//struct FMT_BLOCK
//{
//    char szFmtID[4]; // 'f','m','t',' '
//    unsigned int dwFmtSize;
//    struct WAVE_FORMAT wavFormat;
//};

//union DWORD_CHAR
//{
//    int nValue;
//    char charBuf[4];
//};



int writeFile2Int(FILE *fp, int nWhere, int nValue)
{
    if (fp == NULL )
    {
        return -1;
    }

    fseek(fp, nWhere, SEEK_SET);
    union DWORD_CHAR dc;
    dc.nValue = nValue;
    fwrite(dc.charBuf, 1, 4, fp);
    return 0;
}

void writeWaveHead(FILE *fp)
{
    if (fp)
    {
        //写WAV文件头
        struct RIFF_HEADER rh;
        memset(&rh, 0, sizeof(rh));
        strncpy(rh.szRiffFormat, "WAVE", 4);
        strncpy(rh.szRiffID, "RIFF", 4);

        fwrite(&rh, 1, sizeof(rh), fp);

        struct FMT_BLOCK fb;
        strncpy(fb.szFmtID, "fmt ", 4);
        fb.dwFmtSize = 16;
        fb.wavFormat.wFormatTag = 1;
        fb.wavFormat.wChannels = 2;
        fb.wavFormat.wBitsPerSample = 16;
        fb.wavFormat.dwSamplesPerSec = 44100;
        fb.wavFormat.wBlockAlign = fb.wavFormat.wChannels * fb.wavFormat.wBitsPerSample / 8; //4;
        fb.wavFormat.dwAvgBytesPerSec = fb.wavFormat.dwSamplesPerSec * fb.wavFormat.wBlockAlign;

        fwrite(&fb, 1, sizeof(fb), fp);

        char buf[] = { "data" };
        fwrite(buf, 1, sizeof(buf), fp);
    }
}

void writeWaveBody(FILE *fp, long filelength)
{
    //更新WAV文件dwRiffSize字段中的值
    int nWhere = 4;
    writeFile2Int(fp, nWhere, filelength + 40);

    //更新WAV文件DataChunk中Size字段的值
    nWhere = sizeof(struct RIFF_HEADER) + sizeof(struct FMT_BLOCK) + 4;
    writeFile2Int(fp, nWhere, filelength);
}




//extern bool ok;

int pcm_to_wav()
{
    FILE *fpS;
    FILE *fpD;
    const char *wsPCMFileName = "C:/buildtemp/takeaway/may16.pcm";
    const char *wsWAVEFileName = "C:/buildtemp/takeaway/may16.wav";

    fpS = fopen(wsPCMFileName, "rb");
    fpD = fopen(wsWAVEFileName, "wb+");
    if (fpS == NULL || fpD == NULL )
    {
        printf("[CIrrReplay::createScene]PCM转WAVE失败！\n");
        return 0;
    }
    fseek(fpS, 0, SEEK_END);
    long filelength = ftell(fpS);
    printf("filelength:%ld\n", filelength);
    writeWaveHead(fpD);
    writeWaveBody(fpD, filelength);

    fseek(fpS, 0, SEEK_SET);
    char buf[4];
    while (4 == fread(buf, 1, 4, fpS))
    {
        fwrite(buf, 1, 4, fpD);
    }
    fclose(fpS);
    fclose(fpD);

    //ok = true;
}
