# STL代码

## 代码环境

编译器版本：gcc (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609

操作系统版本：Linux-4.15.0-140-generic-x86_64-with-glibc2.10

参考glibc的版本：glibc-2.23

参考gcc的源码版本：releases/gcc-5.4.0

程序头文件的搜索路径如下，我们可以从下面找到对应的STL模板库。

```bash
 /usr/include/c++/5
 /usr/include/x86_64-linux-gnu/c++/5
 /usr/include/c++/5/backward
 /usr/lib/gcc/x86_64-linux-gnu/5/include
 /usr/local/include
 /usr/lib/gcc/x86_64-linux-gnu/5/include-fixed
 /usr/include/x86_64-linux-gnu
 /usr/include
```

如何知道g++的头文件搜索路径

```c++
#include <no_include>
int main(){}
```

然后采用编译命令 g++ -v，会报以下错误，从而可以知道g++的头文件搜索路径

```
(base) yupeifeng@yupeifeng-fish:~$ g++ -v test.cpp 
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/5/lto-wrapper
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 5.4.0-6ubuntu1~16.04.12' --with-bugurl=file:///usr/share/doc/gcc-5/README.Bugs --enable-languages=c,ada,c++,java,go,d,fortran,objc,obj-c++ --prefix=/usr --program-suffix=-5 --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --with-sysroot=/ --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-libmpx --enable-plugin --with-system-zlib --disable-browser-plugin --enable-java-awt=gtk --enable-gtk-cairo --with-java-home=/usr/lib/jvm/java-1.5.0-gcj-5-amd64/jre --enable-java-home --with-jvm-root-dir=/usr/lib/jvm/java-1.5.0-gcj-5-amd64 --with-jvm-jar-dir=/usr/lib/jvm-exports/java-1.5.0-gcj-5-amd64 --with-arch-directory=amd64 --with-ecj-jar=/usr/share/java/eclipse-ecj.jar --enable-objc-gc --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.12) 
COLLECT_GCC_OPTIONS='-v' '-shared-libgcc' '-mtune=generic' '-march=x86-64'
 /usr/lib/gcc/x86_64-linux-gnu/5/cc1plus -quiet -v -imultiarch x86_64-linux-gnu -D_GNU_SOURCE test.cpp -quiet -dumpbase test.cpp -mtune=generic -march=x86-64 -auxbase test -version -fstack-protector-strong -Wformat -Wformat-security -o /tmp/ccfzCuOn.s
GNU C++ (Ubuntu 5.4.0-6ubuntu1~16.04.12) version 5.4.0 20160609 (x86_64-linux-gnu)
        compiled by GNU C version 5.4.0 20160609, GMP version 6.1.0, MPFR version 3.1.4, MPC version 1.0.3
GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
ignoring duplicate directory "/usr/include/x86_64-linux-gnu/c++/5"
ignoring nonexistent directory "/usr/local/include/x86_64-linux-gnu"
ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/5/../../../../x86_64-linux-gnu/include"
#include "..." search starts here:
#include <...> search starts here:
 /usr/include/c++/5
 /usr/include/x86_64-linux-gnu/c++/5
 /usr/include/c++/5/backward
 /usr/lib/gcc/x86_64-linux-gnu/5/include
 /usr/local/include
 /usr/lib/gcc/x86_64-linux-gnu/5/include-fixed
 /usr/include/x86_64-linux-gnu
 /usr/include
End of search list.
GNU C++ (Ubuntu 5.4.0-6ubuntu1~16.04.12) version 5.4.0 20160609 (x86_64-linux-gnu)
        compiled by GNU C version 5.4.0 20160609, GMP version 6.1.0, MPFR version 3.1.4, MPC version 1.0.3
GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
Compiler executable checksum: 85af4995304287cdd19cfa43cf5d6cf1
test.cpp:2:14: fatal error: no: 没有那个文件或目录
compilation terminated.
```

