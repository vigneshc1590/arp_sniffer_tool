#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>   // inet_ntop, inet_ntoa
#include <netinet/in.h>  // struct in_addr

int main(void) {
    char errbuf[PCAP_ERRBUF_SIZE];    // buffer for pcap error messages
    const char *dev;                  // device name returned by pcap_lookupdev()
    bpf_u_int32 netp, maskp;          // numeric network and netmask (32-bit unsigned)
    struct in_addr net_addr, mask_addr; // for converting to dotted decimal

    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "pcap_lookupdev failed: %s\n", errbuf);
        return 1;
    }

    if (pcap_lookupnet(dev, &netp, &maskp, errbuf) == -1) {
        fprintf(stderr, "pcap_lookupnet failed: %s\n", errbuf);
        return 1;
    }

    /* place the 32-bit values into struct in_addr, then convert to string */
    net_addr.s_addr  = netp;   // s_addr stores IPv4 address in network byte order
    mask_addr.s_addr = maskp;
    printf("Network: %s\n", dev);
    printf("Network: %s\n", inet_ntoa(net_addr));
    printf("Netmask: %s\n", inet_ntoa(mask_addr));
    return 0;

    
}
