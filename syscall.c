#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(int args ,char const *argv[]){
    int INPUT,OUTPUT;
    char buffer[100];
    int n;
    INPUT=open("desd.txt",O_RDONLY);
    //write(fd,"hello\n",6);
    if(-1==INPUT){
        perror("error opening the file\n");
         exit(EXIT_FAILURE);
    }
   n=read(INPUT,&buffer,100);
   OUTPUT=open("newdesd.txt",O_CREAT|O_WRONLY,S_IRUSR|S_IRWXG|S_IRWXG|S_IROTH|S_IRWXU);
    if(OUTPUT==-1){
        perror("file not created");
        exit(EXIT_FAILURE);
    }
    write(OUTPUT,&buffer,100);
    close(INPUT);
    close(OUTPUT);
}