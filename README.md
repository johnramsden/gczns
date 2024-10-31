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

## Design

**ZNS**:

* **Storage Structure**: 904 zones, each sized at 1.0518 GiB, totaling 950.79 GiB.
* **Concurrency**: Max of 14 zones active or open simultaneously.
* **Write Strategy**: Use 14 concurrent writers, each writing to a separate zone. When a zone completes, move on to a new one.

**SSD**:

* **Storage Structure**: 894.3 GiB total capacity, split into 904 equal regions (size equivalent to ZNS zones).
* **Concurrency**: Write to 14 regions concurrently.
* **Write Strategy**: As each region completes, transition to a new region, maintaining the 14 concurrent writers.

---

This setup provides parity between ZNS and SSD experiments by aligning the storage and write processes to allow for consistent comparisons.
