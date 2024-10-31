# GCZNS

## Hardware

ZNS:

```
sudo ./zbd report -i /dev/nvme0n2
```

* Vendor ID: WZS4C8T1TDSP303
* Zone model: host-managed
* Capacity: 1941.325 GB (3791650816 512-bytes sectors)
* Logical blocks: 473956352 blocks of 4096 B
* Physical blocks: 473956352 blocks of 4096 B
* Zones: 904 zones of 2048.0 MB
* Maximum number of open zones: 14
* Maximum number of active zones: 14

SSD:

* SN540
* WUS4B7696DSP303
* 894.3GiB

## ZNS Testing

```
sudo ./zbd reset /dev/nvme0n2
sudo ./zbd report -i /dev/nvme0n2
```

```
...
Zone 00000: swr, ofst 00000000000000, len 00002147483648, cap 00001129316352, wp 00000000000000, em, non_seq 0, reset 0
Zone 00001: swr, ofst 00002147483648, len 00002147483648, cap 00001129316352, wp 00002147483648, em, non_seq 0, reset 0
...
```

Open zone:

```
sudo ./zbd open -ofst 0 -len 2147483648 /dev/nvme0n2
```

Writing 1077MB to the first zone:

```
sudo dd if=/dev/nvme0n2 of=/dev/nvme0n2 oflag=direct bs=1M count=1077
```

```
1077+0 records in
1077+0 records out
1129316352 bytes (1.1 GB, 1.1 GiB) copied, 1.37482 s, 821 MB/s
```

```
Zone 00000: swr, ofst 00000000000000, len 00002147483648, cap 00001129316352, wp 00002147483648, fu, non_seq 0, reset 0
```

Full.

```
sudo ./zbd reset /dev/nvme0n2
sudo ./zbd open -ofst 0 -len 2147483648 /dev/nvme0n2
sudo dd if=/dev/nvme0n2 of=/dev/nvme0n2 oflag=direct bs=1M count=2048
```

```
dd: error writing '/dev/nvme0n2': Input/output error
1078+0 records in
1077+0 records out
1129316352 bytes (1.1 GB, 1.1 GiB) copied, 1.32677 s, 851 MB/s
```

Full, errorred at `00001129316352`

```
Zone 00000: swr, ofst 00000000000000, len 00002147483648, cap 00001129316352, wp 00002147483648, fu, non_seq 0, reset 0
Zone 00001: swr, ofst 00002147483648, len 00002147483648, cap 00001129316352, wp 00002147483648, em, non_seq 0, reset 0
```
