#include "Number.h"
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>

Number::Number(const char * value, int base){
    this->length= strlen(value);
    this->base=base;
    this->value=new char[this->length];
    for(int i=0;i<this->length;i++){
        this->value[i]= value[i];
    }
}
Number::Number(const Number &copy) {
    this->length=copy.length;
    this->base=copy.base;
    this->value=new char[copy.length];
    for(int i=0;i<copy.length;i++) this->value[i]=copy.value[i];
}
Number::Number(Number &&move) {
    this->length=move.length;
    this->base=move.base;
    move.length=move.base=0;
    this->value=move.value;
    move.value= nullptr;
}
Number& Number::operator=(Number&& move){
    if(this!=&move){
        this->length=move.length;
        this->base=move.base;
        move.length=move.base=0;
        this->value=move.value;
        move.value= nullptr;
    }
    return *this;
}
Number::~Number(){
    delete[] this->value;
}

void Number::Print() {
    for(int i=0;i<this->length;i++) std::cout<< this->value[i];
    std::cout<<'\n';
}

int Number::GetDigitsCount() {
    return this->length;
}
int Number::GetBase() {
    return this->base;
}

void Number::SwitchBase(int newBase) {
    int newValue=0;
    if(this->base!=10 || newBase==10){
        for(int i=0;i<this->length;i++){
            int numar=0;
            if(((int)this->value[i]-'0')<=9) numar=(int) this->value[i]-'0';
            else if((int)this->value[i]=='A') numar=10;
            else if((int)this->value[i]=='B') numar=11;
            else if((int)this->value[i]=='C') numar=12;
            else if((int)this->value[i]=='D') numar=13;
            else if((int)this->value[i]=='E') numar=14;
            else if((int)this->value[i]=='F') numar=15;
            newValue+=numar*pow(this->base,this->length-i-1);
        }
    }
    else{
        newValue=atoi(this->value);
    }
    if(newBase!=10){
        int temp[100],rest,poz=0,start=0;
        while(newValue>0){
            rest=newValue%newBase;
            newValue/=newBase;
            temp[poz++]=rest;
        }
        char* nr;
        nr= new char[poz];
        nr[poz]='\0';
        for(int i=poz-1;i>=0;i--){
            if(temp[i]<=9) nr[start]=temp[i]+'0';
            else{
                if(temp[i]==10) nr[i]='A';
                else if(temp[i]==11) nr[start]='B';
                else if(temp[i]==12) nr[start]='C';
                else if(temp[i]==13) nr[start]='D';
                else if(temp[i]==14) nr[start]='E';
                else if(temp[i]==15) nr[start]='F';
            }
            start++;
        }
        Number copy(nr,newBase);
        delete[] this->value;
        this->value=new char[copy.length];
        for(int i=0;i<copy.length;i++) this->value[i]=copy.value[i];
        this->length=copy.length;
        this->base=copy.base;
        //copy.~Number();
    }
    else{
        this->base=10;
        delete[] this->value;
        int poz=0,copy=newValue,marime=0;
        while(copy){
            marime++;
            copy/=10;
        }
        this->value=new char[marime];
        for(int i=marime-1;i>=0;i--){
            this->value[i]=(newValue%10)+'0';
            newValue/=10;
        }
    }
}

Number operator+(const Number& other1,const Number& other2){
    Number cother1=other1,cother2=other2;
    cother1.SwitchBase(10);
    cother2.SwitchBase(10);
    int val1,val2;
    val1=atoi(cother1.value);
    val2= atoi(cother2.value);
    val1+=val2;
    char string1[100];
    itoa(val1,string1,10);
    Number rezultat(string1,10);
    rezultat.SwitchBase(std::max(other1.base,other2.base));
    return rezultat;
}

Number operator-(const Number& other1,const Number& other2){
    Number cother1=other1,cother2=other2;
    cother1.SwitchBase(10);
    cother2.SwitchBase(10);
    int val1,val2;
    val1=atoi(cother1.value);
    val2= atoi(cother2.value);
    val1-=val2;
    char string1[100];
    itoa(val1,string1,10);
    Number rezultat(string1,10);
    rezultat.SwitchBase(std::max(other1.base,other2.base));
    return rezultat;
}

bool Number::operator>(const Number& other){
    Number cother1=*this,cother2=other;
    cother1.SwitchBase(10);
    cother2.SwitchBase(10);
    int val1,val2;
    val1=atoi(cother1.value);
    val2= atoi(cother2.value);
    if(val1>val2) return true;
    else return false;
}
bool Number::operator>=(const Number& other){
    Number cother1=*this,cother2=other;
    cother1.SwitchBase(10);
    cother2.SwitchBase(10);
    int val1,val2;
    val1=atoi(cother1.value);
    val2= atoi(cother2.value);
    if(val1>=val2) return true;
    else return false;
}
bool Number::operator < (const Number& other){
    Number cother1=*this,cother2=other;
    cother1.SwitchBase(10);
    cother2.SwitchBase(10);
    int val1,val2;
    val1=atoi(cother1.value);
    val2= atoi(cother2.value);
    if(val1<val2) return true;
    else return false;
}
bool Number::operator <= (const Number& other){
    Number cother1=*this,cother2=other;
    cother1.SwitchBase(10);
    cother2.SwitchBase(10);
    int val1,val2;
    val1=atoi(cother1.value);
    val2= atoi(cother2.value);
    if(val1<=val2) return true;
    else return false;
}
bool Number::operator ==(const Number& other){
    Number cother1=*this,cother2=other;
    cother1.SwitchBase(10);
    cother2.SwitchBase(10);
    int val1,val2;
    val1=atoi(cother1.value);
    val2= atoi(cother2.value);
    if(val1==val2) return true;
    else return false;
}
bool Number::operator--() {
    this->value=(this->value+1);
    this->length--;

}
bool Number::operator--(int a) {
    this->value[this->length-1]='\0';
    this->length--;
}
char Number::operator[](int poz) {
    return this->value[poz];
}
