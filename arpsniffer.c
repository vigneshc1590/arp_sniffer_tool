#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <pcap/pcap.h>
#include <sys/socket.h>
#include <netinet/in.h>

int available_interface();

void version();

void version(){
printf("    ___    ____  ____  _____ _   ____________________________ \n");
printf("   ╱   │  ╱ __ ╲╱ __ ╲╱ ___╱╱ │ ╱ ╱  _╱ ____╱ ____╱ ____╱ __ ╲\n");
printf("  ╱ ╱│ │ ╱ ╱_╱ ╱ ╱_╱ ╱╲__ ╲╱  │╱ ╱╱ ╱╱ ╱_  ╱ ╱_  ╱ __╱ ╱ ╱_╱ ╱\n");
printf(" ╱ ___ │╱ _, _╱ ____╱___╱ ╱ ╱│  ╱╱ ╱╱ __╱ ╱ __╱ ╱ ╱___╱ _, _╱ \n");
printf("╱_╱  │_╱_╱ │_╱_╱    ╱____╱_╱ │_╱___╱_╱   ╱_╱   ╱_____╱_╱ │_│ \n");
printf("\t\t\t\t\t\t\t\tv0.1.0\n");
    exit(1);
}

int available_interface(){
    char error[PCAP_ERRBUF_SIZE];
    pcap_if_t *interfaces, *temp;
    int i=0;

    if(pcap_findalldevs(&interfaces, error) == -1){
        printf("No devices found on this network : %s \n",error);
        return -1;
    }

    for(temp=interfaces; temp; temp=temp->next){
        printf("%d : %s :\t %s\n", ++i, temp->name, temp->description);
    }
    
    return 0;
   
}

int help(){
    printf()
}




int main(int argc , char *argv[]){


}

