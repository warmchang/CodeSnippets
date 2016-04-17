/*
 gcc -Os -o desstamac desstamac.c -lcrypto
 gcc -static -Os -o desstamac desstamac.c -lcrypto
*/
#include <stdio.h>
#include <string.h>
#include <openssl/des.h>


int DES_ecb( char *pcOut, char *pcInPut, char *pcKey, unsigned int wEncryptType )
{
    des_cblock      kk = { 0 };
    DES_key_schedule    ks;
    int             iRet        = 1;
    char            acHexStr[20]    = { 0 };
    unsigned int        wDataLenth  = 0;
    unsigned int        wDataRest   = 0;
    unsigned int        wLenth      = 0;
    unsigned int        wPad        = 0;
    unsigned int        wLoop       = 0;
    unsigned char       acTmpStr[8] = { 0 };
    unsigned char       acSrc[50]   = { 0 };
    unsigned char       acOut[8]    = { 0 };

    if ( (NULL == pcOut) || (NULL == pcInPut) || (NULL == pcKey) )
    {
        return (iRet);
    }

    wDataLenth  = strlen( pcInPut );
    wDataRest   = strlen( pcInPut ) % 8;
    wPad        = 8 - wDataRest;
    wLenth      = wDataLenth + wPad;

    // printf("wDataLenth is %d, wPad is %d, wLenth is %d \n", wDataLenth, wPad, wLenth);
    memset( acSrc, wPad, wLenth );
    memcpy( acSrc, pcInPut, wDataLenth );
    memcpy( &kk, pcKey, 8 );
    DES_set_key_unchecked( &kk, &ks );

    for ( wLoop = 0; wLoop < wDataLenth; wLoop += 8 )
    {
        memset( acTmpStr, 0, 8 );
        memset( acOut, 0, 8 );
        memcpy( acTmpStr, acSrc + wLoop, 8 );

        DES_ecb_encrypt( (des_cblock *) &acTmpStr, (des_cblock *) &acOut, &ks, wEncryptType );
        memset( acHexStr, 0, 20 );
        snprintf( acHexStr, sizeof(acHexStr), "%02x%02x%02x%02x%02x%02x%02x%02x",
                  acOut[0], acOut[1], acOut[2], acOut[3], acOut[4], acOut[5], acOut[6], acOut[7] );
        memcpy( pcOut + (wLoop * 2), acHexStr, 16 );
    }

    return (iRet);
}


/* desstamac.exe fc-64-ba-6f-04-1b */
void main( int argc, char** argv )
{
    char    acOutPut[50]    = { 0 };
    char    *pcInPut    = argv[1];
    if ( argc < 2 )
    {
        printf( "Useage: desstamac.exe fc-64-ba-6f-04-1b\n" );
        return;
    }
    DES_ecb( acOutPut, pcInPut, "12345678", DES_ENCRYPT ); /* DES_ENCRYPT DES_DECRYPT */
    printf( "BeforeEncrypt: %s\nAfterEncrypt: %s\n", pcInPut, acOutPut );
}
