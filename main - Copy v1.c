#include <stdio.h>
#include <stdlib.h>

void memoryLocate(char **ptr)                   // ptr address: 0x0424
{
    int y = 5;                                  // y address: 0x0423
    y = 6;
    *ptr = (char *)malloc(500*sizeof(char));   // ptr address: 0x0424
    y = 7;
}

void writeBuffer(int **ppBufDesWrite, int *pBufSrcWrite, int length)        // ppBufDesWrite: 0x426, ppBufScrWrite: 0x424
{
    int x = 2;
    **ppBufDesWrite = *pBufSrcWrite;

    *ppBufDesWrite = *ppBufDesWrite + 1;
    pBufSrcWrite = pBufSrcWrite +1;

    **ppBufDesWrite = *pBufSrcWrite;

    *ppBufDesWrite = *ppBufDesWrite + 1;
    pBufSrcWrite = pBufSrcWrite +1;


 //   **ppBufDes = *pBufSrc;
    x = 3;
}


/**
 * main.c
 */
int main(void)
{
    char *pBufferDes = NULL;            // 0x041E
//    char *pBufferOri = NULL;
    char buffer1[] = "HelloWorld!";     // 0x0412
    char buffer2[] = "Steven Zhao";     // 0x0406
    int i;                              // 0x0405

    i = sizeof(char);

    memoryLocate(&pBufferDes);          //

    i = 2;

    writeBuffer(&pBufferDes, buffer1, 3);
    writeBuffer(&pBufferDes, buffer2, 3);

//    printf("pBufferDes  %p   \n", pBufferDes);

    return 0;
}
