//
// Created by KoTz on 27/05/2025.
//

#include "cipher_cesar.h"
#include  <iostream>

void cipher_cesar::encrypt_Cesar(std::string & str,int key) {
    auto strs = str;
    int position =0;
    str.clear();
    if (strs.empty() == false) {
        for (int a = 0; a < strs.length(); a++) {
            if (strs[a] == ' ') {
                str += ' ';
                continue;
            }
            if (isupper(strs[a])) {
                position = ((strs[a] - 'A') + key + 26) % 26;
            }
            if (islower(strs[a])) {
                position = ((strs[a] - 'a') + key + 26) % 26;
            }
             str += txt[position];
            if (a < strs.length() - 1) {
                is_encrypt = true;
            }
        }
    }
}
void cipher_cesar::decrypt_Cesar(std::string & str,int key) {
    std::string str_new;
    int position =0;

    if (is_encrypt == false) {
        return;
    }
    if (str.empty() == false) {
         for (int a = 0; a < str.length(); a++) {
               if (str[a] == ' ') {
                   str_new += ' ';
                   continue;
               }
             if (isupper(str[a])) {
                 position = ((str[a] - 'A') - key + 26) % 26;
             }
             if (islower(str[a])) {
                 position = ((str[a] - 'a') - key + 26) % 26;
             }
             str_new += txt[position];
         }
      }


     str.clear();
     str = str_new;


    return;
}

std::string cipher_cesar::encrypt_Cesar() {
    std::string strs = this->message_;
    int posicao =0;
    this->message_.clear();
    if (strs.empty() == false) {
        for (int a = 0; a < strs.length(); a++) {
            if (strs[a] == ' ') {
                this->message_ += ' ';
                continue;
            }
            if (isupper(strs[a])) {
                posicao = ((strs[a] - 'A') + key + 26) % 26;

            }
            if (islower(strs[a])) {
                posicao = ((strs[a] - 'a') + key + 26) % 26;

            }
            this->message_ += txt[posicao];
            if (a < strs.length() - 1) {
                is_encrypt = true;
            }
        }

    }
    return this->message_;

}

std::string cipher_cesar::decrypt_Cesar() {
    std::string str_new;
    int posicao =0;
    if (is_encrypt == false) {
        return "ERROR";
    }
    if (this->message_.empty() == false) {
        for (int a = 0; a < this->message_.length(); a++) {
            if (this->message_[a] == ' ') {
                str_new += ' ';
                continue;
            }
            if (isupper(this->message_[a])) {
                posicao = ((this->message_[a] - 'A') - key + 26) % 26;
            }
            if (islower(this->message_[a])) {
                posicao = ((this->message_[a] - 'a') - key + 26) % 26;
            }
            str_new += txt[posicao];
        }
    }
    this->message_.clear();
    this->message_ = str_new;
    return this->message_;

}

cipher_cesar::cipher_cesar():message_(""),key(0){

}
cipher_cesar::cipher_cesar(std::string str,int key):message_(str),key(key) {

}
cipher_cesar::~cipher_cesar() {

}
