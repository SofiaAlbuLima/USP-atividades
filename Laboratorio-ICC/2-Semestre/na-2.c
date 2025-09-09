#include <stdio.h>

int main(){
    char texto[100];
    fgets(texto, 100, stdin);

    for(int i=0; texto[i] != '\n'; i++){
        if(texto[i]=='a' || texto[i]=='A'){
            texto[i]='b';
        }else if(texto[i]=='b' ){
            texto[i]='c';
        }else if(texto[i]=='c'){
            texto[i]='d';
        }else if(texto[i]=='d'){
            texto[i]='e';
        }else if(texto[i]=='e'){
            texto[i]='f';
        }else if(texto[i]=='f'){
            texto[i]='g';
        }else if(texto[i]=='g'){
            texto[i]='h';
        }else if(texto[i]=='h'){
            texto[i]='i';
        }else if(texto[i]=='i'){
            texto[i]='j';
        }else if(texto[i]=='j'){
            texto[i]='k';
        }else if(texto[i]=='k'){
            texto[i]='l';
        }else if(texto[i]=='l'){
            texto[i]='m';
        }else if(texto[i]=='m'){
            texto[i]='n';
        }else if(texto[i]=='n'){
            texto[i]='o';
        }else if(texto[i]=='o'){
            texto[i]='p';
        }else if(texto[i]=='p'){
            texto[i]='q';
        }else if(texto[i]=='q'){
            texto[i]='r';
        }else if(texto[i]=='r'){
            texto[i]='s';
        }else if(texto[i]=='s'){
            texto[i]='t';
        }else if(texto[i]=='t'){
            texto[i]='u';
        }else if(texto[i]=='u'){
            texto[i]='v';
        }else if(texto[i]=='v'){
            texto[i]='w';
        }else if(texto[i]=='w'){
            texto[i]='x';
        }else if(texto[i]=='x'){
            texto[i]='y';
        }else if(texto[i]=='y'){
            texto[i]='z';
        }else if(texto[i]=='z'){
            texto[i]='a';
        }else if(texto[i]=='0'){
            texto[i]='1';
        }else if(texto[i]=='1'){
            texto[i]='2';
        }else if(texto[i]=='2'){
            texto[i]='3';
        }else if(texto[i]=='3'){
            texto[i]='4';
        }else if(texto[i]=='4'){
            texto[i]='5';
        }else if(texto[i]=='5'){
            texto[i]='6';
        }else if(texto[i]=='6'){
            texto[i]='7';
        }else if(texto[i]=='7'){
            texto[i]='8';
        }else if(texto[i]=='8'){
            texto[i]='9';
        }else if(texto[i]=='9'){
            texto[i]='0';
        }else if(texto[i]=='-'){
            texto[i]='.';
        }else if(texto[i]==','){
            texto[i]='-';
        }else if(texto[i]=='/'){
            texto[i]='0';
        }else{
            texto[i]='!';
        }
    } 

    printf("%s", texto);
}