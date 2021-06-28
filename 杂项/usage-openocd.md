# OpenOCD (Open On-Chip Debugger) Usage

## flash bin

```sh
STLINK_CFG=interface/stlink-v2-1.cfg
TARGET_CFG=target/stm32f3x.cfg
TARGET_ELF=test.elf

openocd -d0 -f $STLINK_CFG -f $TARGET_CFG -c init -c targets -c "halt" -c "flash write_image erase $TARGET_ELF" -c "verify_image $TARGET_ELF" -c "reset run" -c shutdown

```

## Reset

```sh
openocd -f $STLINK_CFG -f $TARGET_CFG -c "init" -c "halt" -c "wait_halt" -c "stm32f1x mass_erase 0" -c "sleep 200" -c "reset run" -c "shutdown"
```
