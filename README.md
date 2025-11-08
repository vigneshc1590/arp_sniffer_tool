# ARP Spoof Detector

Lightweight ARP spoofing detection tool written in **C** using **libpcap**.

A minimal, lab-friendly program that captures ARP traffic, correlates IP→MAC observations in a short time window, and emits JSON alerts and optional PCAP evidence when spoofing is suspected.

---

## Key features

* Live ARP sniffing on a specified interface using `libpcap`.
* Simple sliding-window detection: flags when multiple MAC addresses are observed for the same IP within the configured time window.
* Emits structured JSON alert lines to stdout (easy to ingest by SIEMs).
* Optional PCAP dump of suspicious packets for analyst validation.

---

## Requirements

* Linux (recommended) with `libpcap` support
* `gcc` or compatible C compiler
* `libpcap-dev` (Debian/Ubuntu) or equivalent
* Root privileges (or appropriate capabilities) to capture live traffic

Install (Debian/Ubuntu):

```bash
sudo apt update
sudo apt install build-essential libpcap-dev
```

---

## Build

```bash
gcc -o arp_detector arp_detector.c -lpcap
```

---

## Basic usage

```
sudo ./arp_detector -i <interface>
```

* `-i <interface>`: required. e.g., `eth0` or `wlan0`.
Example:

```bash
sudo ./arp_detector -i eth0 
```

## Testing (lab only)

* Test in an isolated lab environment (VMs or isolated VLAN).
* Capture a PCAP of ARP spoof-like traffic using `tcpdump` and verify the detector in offline mode (if supported) or run live on the test interface.

---

## Safety & legal

**Only use this tool on networks you own or have explicit permission to test.** Do not run active spoofing or attack traffic on production or third-party networks.

---

## License & contact

Include a license (e.g., MIT) in the repo. For questions or feedback, open an issue in the repository or add a short contact line in the README.

---

*Simple, focused, and ready for inclusion in a project portfolio or SOC demo.*
