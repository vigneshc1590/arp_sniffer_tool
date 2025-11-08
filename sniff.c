#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <pcap/pcap.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){

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
