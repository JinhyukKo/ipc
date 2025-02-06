# 1. Interprocess Communication
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
you can check the Shared memory file named "OS"


