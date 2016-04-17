# desstamac
The DES encryption with ECB, PKCS7 mode, and the ciphter is "12345678".

Input:
MAC address.

Output:
The ciphertext.

Build:
gcc -static -Os -o desstamac desstamac.c -lcrypto
