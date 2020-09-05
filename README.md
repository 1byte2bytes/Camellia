### Installing the required tools on macOS

```
brew install llvm nasm cmake qemu
```

**NOTE:** we must install Brew's LLVM, Apple's built in copy does not support our target triple.

### Ubuntu
```
sudo apt install llvm nasm qemu grub-common grub-pc-bin xorriso
```