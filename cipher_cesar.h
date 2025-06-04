//
// Created by KoTz on 27/05/2025.
//

#ifndef CIFRACESAR_H
#define CIFRACESAR_H

#include <string>

typedef std::string STRING;
typedef std::string ENCRYPT,DECRYPT,MESSAGE;

class cipher_cesar {
private :
     const std::string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     std::string message_;
     int key;
     bool is_encrypt;
public :
    void encrypt_Cesar(ENCRYPT & TXT,int KEY);
    void decrypt_Cesar(DECRYPT & TXT,int KEY);

    STRING encrypt_Cesar();
    STRING decrypt_Cesar();

    cipher_cesar();
    cipher_cesar(MESSAGE TXT,int key);
    ~cipher_cesar();
};



#endif //CIFRACESAR_H
