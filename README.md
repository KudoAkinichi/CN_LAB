# Computer Networks Laboratory

Welcome to the Computer Networks Laboratory repository! This repository contains various lab exercises and assignments for the Computer Networks course (CS39003), focusing on socket programming using C.

## Table of Contents

- [Course Information](#course-information)
- [Lab Schedule and Contents](#lab-schedule-and-contents)
- [Getting Started](#getting-started)
- [Prerequisites](#prerequisites)
- [Building and Running](#building-and-running)
- [Online Resources](#online-resources)
- [Contributing](#contributing)
- [License](#license)

## Course Information

- **Course Name and Code**: Computer Networks Laboratory, CS39003 (L-T-P-Cr:1)
- **Instructor**: Dr. Pinaki Sankar Chatterjee
  - Email: [pinakifcs@kiit.ac.in](mailto:pinakifcs@kiit.ac.in)
  - Instructor Chamber: Faculty block-F211, Campus-15
- **Discipline**: CS/IT/CSCE/CSSE
- **Semester**: Autumn 2024 (5th Semester)

## Lab Schedule and Contents

### Lab 1: Overview of C Programming (Week 1)
- **Coverage**:
  - Importance of socket programming for data communication.
  - Review of C programming fundamentals: functions, pointers, structures, endianness.
- **Assignments**:
  1. Swap two variables using function and pointer.
  2. Populate and print structure members using call-by-value and call-by-address.
  3. Extract bytes from a number and print them.
  4. Store a number in a structure and print members, then reassemble the number.
  5. Check machine endianness and convert between Little and Big Endian.

### Lab 2: Basics of Socket Programming (Week 2)
- **Coverage**:
  - Basics of Socket Programming.
  - Connection-less socket programming APIs for TCP/IP stack using C.
- **Assignments**:
  1. Create sender and receiver programs using connection-less sockets, exchange messages continuously.

### Lab 3: Connection Oriented Socket Programming (Week 3)
- **Coverage**:
  - Connection-oriented socket programming APIs for TCP/IP stack using C.
- **Assignments**:
  1. Create client-server programs, exchange messages, and handle connection termination.

### Lab 4: Socket Programming with Multiple Clients (Week 4)
- **Coverage**:
  - I/O multiplexing and its types.
  - Designing concurrent chat server using fork() and select() API.
- **Assignments**:
  1. Design a concurrent chat server to handle multiple clients simultaneously.

### Lab 5: Packet Analysis using Wireshark (Week 5)
- **Coverage**:
  - Demonstration of Wireshark for packet analysis.
- **Assignments**:
  1. Capture and analyze packets using `ping` and `traceroute` commands.

### Lab 6: Introduction to Network Simulators (Week 6)
- **Coverage**:
  - Network configuration using network simulators like Cisco Packet Tracer/NS3.
- **Assignments**:
  1. Simulate routing in a LAN within the same and different subnets.

### Lab 7: Simulating Network Protocols in Network Simulators (Week 7)
- **Coverage**:
  - DHCP Protocol.
- **Assignments**:
  1. Create a network and demonstrate DHCP Protocol using a simulator.

### Lab 8: Fragmentation and Reassembly (Week 8)
- **Coverage**:
  - Fragmentation and reassembly of packets.
- **Assignments**:
  1. Implement client-server communication with fragmentation and reassembly.

### Lab 9: Designing a Stop-and-Wait Protocol (Week 9)
- **Coverage**:
  - Designing a stop-and-wait protocol on top of connectionless sockets.
- **Assignments**:
  1. Implement stop-and-wait and Go-back-N protocols using UDP sockets.

### Lab 10: Secured End-to-End Message Transmission (Optional, Week 10)
- **Coverage**:
  - Secure message transmission between clients.
- **Assignments**:
  1. Implement secure communication with encryption techniques.

### Lab 11: Comparison and Analysis of Existing Protocols (Optional, Week 11)
- **Coverage**:
  - Comparison and analysis of routing protocols using network simulators.
- **Assignments**:
  1. Compare and analyze different routing protocols.

## Getting Started

To get started with the lab exercises, clone this repository to your local machine using the following command:

```sh
git clone https://github.com/KudoAkinichi/CN_LAB.git
cd CN_LAB
```

## Online Resources
[Socket Programming Tutorial](https://www.youtube.com/playlist?list=PLOholRFa862SX9Ypgk3vsByrfMT_hMq-l)
