<p align="center">
  <img width="256" height="256" src="https://user-images.githubusercontent.com/85266594/189078280-bc2c1230-91aa-40ad-8d0f-c91b9b5bb47d.png">
</p>

# L-DOS
[![Lines of code](https://tokei.rs/b1/github/XAMPPRocky/tokei?category=lines)](https://github.com/Luramoth/L-DOS)

A Dos-like from scratch operating system using Limine bootloader

## building
make sure you have these tools:
- `GCC/G++` to compile C/C++ (probably comes with your distrobution)
- `xorriso` to make the ISO image
- `QEMU` for if you want to run the ISO in a VM

To start you need to clone this repository with git

Open your terminal and just copy/paste this in line by line
```bash
git clone https://github.com/Luramoth/L-DOS

cd L-DOS
```
Congrats, you have the source code, mess with it how oyu like, it's GPL baby

Now while you're in here you're gonna want to get Limine which is the bootloader for LDOS

Again, copy this down
```bash
git clone https://github.com/limine-bootloader/limine
# dont worry, you dont have to cd into limine
```
Now you should be set for actually building

Line by line, copy these commands
```bash
make # build the OS source code

bash # ./buildiso.sh #run my custom script to make the ISO image
```
After a bunch of text vomit you should have a perfectly working ISO! theoretically you can slap this into a bootable USB stick
using somthing like belena etcher or what I use, ventoy

It will work in essentally any VM too, for simplicity i chose to use QEMU

```bash
# v- you may have to change this depending on your system
qemu-system-x86_64 -cdrom ldos_x64.iso 
```

### what about rapid testing?
I have a script for that too, it builds the OS, runs the ISO builder, then starts up QEMU

```bash
bash ./test.sh
```
