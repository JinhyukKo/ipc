# 1. Interprocess Communication (Low-level APIs)
## 1. Version
5.15.0-1079-azure

## 2. How to use

### 2.1 POSIX Shared Memory


```bash
gcc producer.c -o producer -lrt
gcc consumer.c -o consumer -lrt
```
- shm_open is part of the POSIX shared memory API, which requires linking with the real-time library (librt) on Linux.
- By default, gcc does not automatically link against `librt`, so you must explicitly specify -lrt.

```bash
cd /dev/shm/
```
- you can check the Shared memory file named "OS"

## 2.2 Mach Message Passing


[[https://docs.darlinghq.org/internals/macos-specifics/mach-ports.html]]

```bash
gcc server.c -o server
gcc client.c -o client
```




<img width="421" alt="Screenshot 2025-02-06 at 23 00 36" src="https://github.com/user-attachments/assets/f32a3289-9d5f-40ae-beae-65c23d5bbd95" />


<img width="407" alt="Screenshot 2025-02-06 at 23 00 42" src="https://github.com/user-attachments/assets/d96e4f74-461c-4e68-85d7-b85ff89080a7" />
