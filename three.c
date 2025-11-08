#include <stdio.h>
#include <pcap.h>

int main(void) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs, *dev;
    int i = 0;

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    printf("Available network interfaces:\n");
    for (dev = alldevs; dev; dev = dev->next) {
        printf("%2d: %s", ++i, dev->name);
        if (dev->description)
            printf("  (%s)", dev->description);
        printf("\n");
    }

    pcap_freealldevs(alldevs);
    return 0;
}
