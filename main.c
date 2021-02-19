#include <stdio.h>
#include <stdlib.h>

void memoryLocate(char **ptr)                   // ptr address: 0x0424
{
    int yForTest = 5;                           // y address: 0x0423
    yForTest = 6;
    *ptr = (char *)malloc(500*sizeof(char));   // ptr address: 0x0424  // ptr content: 0x41E; 0x41E's value is set to 0xA002
    yForTest = 7;
}

void writeBuffer(char **ppBufDesWrite, char *pBufSrcWrite, int length)        // ppBufDesWrite: 0x426, ppBufScrWrite: 0x424
{
    int i = 0;

    for(i=0; i<length; i++)
    {
    **ppBufDesWrite = *pBufSrcWrite;
    *ppBufDesWrite = *ppBufDesWrite + 1;        //0x41E increase 1
    pBufSrcWrite = pBufSrcWrite +1;
    }
}


/**
 * main.c
 */
int main(void)
{
    char *pBufferDes = NULL;            // 0x041E
    char buffer1[] = "HelloWorld!";     // 0x0412
    char buffer2[] = "Steven Zhao";     // 0x0406
    int buffer3[] = {1,2,3,4,5,6,7,8,9,10,11,12};       //
    int iForTest;                       // 0x0405

    iForTest = sizeof(char);

    memoryLocate(&pBufferDes);          //

//    iForTest = 2;

    writeBuffer(&pBufferDes, buffer1, 12);
    writeBuffer(&pBufferDes, buffer2, 12);
    writeBuffer(&pBufferDes, buffer3, 12);

    return 0;
}
