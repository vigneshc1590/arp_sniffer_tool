#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <pcap/pcap.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc , char *argv[]){

    char error[PCAP_ERRBUF_SIZE];
    pcap_if_t *interfaces, *temp;
    int i=0;

    if(pcap_findalldevs(&interfaces,error)== -1){
        printf("No Devices interfaces found \n");
        return -1;
    }

    printf("The available interfaces are: \n");
    for(temp=interfaces; temp; temp=temp->next){
        printf(" %d : %s\n", ++i, temp->name);
    }
    printf("libpcap version: %s\n", pcap_lib_version());
    return 0;
        
   
}