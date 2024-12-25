# Debugging Starry
## Steps
### I. Compiling `musl`
1. the `gcc`s of the `musl` binaries at `musl.cc` cannot produce correct symbol tables for `first_process.c`, so you should compile `musl v1.2.5` [on your own](https://git.musl-libc.org/cgit/musl/)
2. edit `~/.bashrc` so that `riscv64-unknown-elf-gdb` points to your compiled `musl` tools
### II. Change Starry's First Process
> Starry starts `busybox` when kernel's ready, but we change it to 2 simple C programs to demonstrate our debugging tool.
1. in `build_img.sh`, append `sudo cp -r ./code-debug-testing/* ./mnt/` after `sudo cp -r ./testcases/$FILE/* ./mnt/`
2. copy `code-debug-testing` folder into Starry's root folder.
3. in `code-debug-testing` folder run `make clean && make run`
4. in Starry's root folder run `./build_img.sh -a riscv64`
5. go to `Starry/apps/monolithic_userboot/src/main.rs`, change `let testcase = "busybox sh";` to `let testcase = "first_process";`
6. build and run Starry in debug mode `make A=apps/monolithic_userboot ARCH=riscv64 NET=y BLK=y MODE=debug GDB=riscv64-unknown-elf-gdb run`. You will see:
```
Running testcase: first_process
hello, this is process 1! pid is 5
hello, this is process 2! pid is 5
```
### III. Modifying `launch.json`
1. create `.vscode` folder in Starry's root folder
2. copy `launch.json` into `.vscode` folder
3. search `.cargo/git/checkouts/` in `launch.json`. you will find some paths like `/home/oslab/.cargo/git/checkouts/REPO-COMMITID`.
   3.1 change `oslab` into your username.
   3.2 make sure the `COMMITID` is correct. If you don't know how to do it, just delete the whole `checkouts` folder and recompile Starry. Then only one possible choice remains in `checkouts` folder.
4. In VSCode, press RUN -> Start Debugging.

