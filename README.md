# OpenLab on static and dynamic code analysis

Repository contains following files:

  * `Vagrantfile` for building virtual machine for modern C++ development
    - Based on modern Fedora with all developer tools
    - `bootstrap.sh` builds current LLVM toolchain
    - image uses default sudo-er user vagrant with password vagrant (you can install anything using `sudo dnf install`)
    - the toolchain is located in `/home/vagrant/bin`, if you want to use current clang instead Fedora's installed clang, run `alias clang=~/bin/clang` and `alias clang++=~/bin/clang++`. Other tools are used from LLVM toolchain

  * folder `vm-files` contains following examples:
    - `zune_bug.c` was mean as goal for static analyzers, but both failed to catch it. it is bug that disabled Microsoft Zune devices on 2012-21-31
    - `static_exaples/` takes [examples from clang static analyzer](https://clang-analyzer.llvm.org/available_checks.html) and [cppcheck examples](https://github.com/danmar/cppcheck/tree/master/samples)
    - `format/` shows demo on `clang-format` tool, but it is better as [live demo](https://youtu.be/uZI_Qla4pNA?t=1918)
    - `tidy/` shows modernize checks of `clang-tidy`, running notes are first line of the files
    - `dynamic/` compares `valgrind` with clang sanitizers, running notes are again the first line of code

## Sources

Please note I used following sources. I made the OpenLab to learn myself the tools, if I was not succesful to learn you these tools, the talks I have seen wil do so.

  * [Pacific++ 2017: Chandler Carruth "LLVM: A Modern, Open C++ Toolchain"](https://www.youtube.com/watch?v=uZI\_Qla4pNA) - this was the main source
  * [Tools from the C++ Ecosystem to save a leg - Anastasia Kazakova - Meeting C++ 2017](https://www.youtube.com/watch?v=Hlmp-zTyrxM)
  * [CppCon 2017: Kostya Serebryany "Fuzz or lose: why and how to make fuzzing a standard practice for C++"](https://www.youtube.com/watch?v=k-Cv8Q3zWNQ)

## Final thoughts

  * Use `clang`. It has no disadvantage to `gcc`, but better compilation messages. And it will be the future (better development)
  * Search for integration of `clang-tidy` and `clang-format` into your IDE. Else you won't use the tools. Once you start using them, it will motivate you to read about available checks. (CLion has `clang-tidy` integrated since 2017, [`clang-format` has to be added manualy](https://stackoverflow.com/questions/34648255/using-clang-format-in-clion); [QtCreator has clang-format plugin](https://doc.qt.io/qtcreator/creator-beautifier.html), but `clang-tidy` is not available as is [clang static analyser is](https://doc.qt.io/qtcreator/creator-clang-static-analyzer.html))
  * Use dynamic analysis for debugging! If you never used `valgrind`, start with it. If you know `vagrind`, try to substitute it with clang sanitizers, they are stronger (stack check, undefined behaviour sanitizer).
  * Write tests, or you won't be able to run dynamic analysis

# Note

Feel free to change anything in the tools. If you have some suggestions, write me :).
