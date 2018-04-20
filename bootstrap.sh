#!/bin/bash

# Bootstrap script for environment recording VM

# Install workstation packages and updates
dnf install -y @workstation-product-environment
dnf update -y

# Set up GUI as default session
systemctl enable gdm
systemctl set-default graphical.target

# Set local timezone
rm /etc/localtime
ln -s /usr/share/zoneinfo/Europe/Prague /etc/localtime

## Prepare questionnaire link
#echo $RANDOM % 2 | bc >$DEVCONFDIR/questionnaire
#mkdir -p ~/.local/share/applications
#if [ cat $DEVCONFDIR/questionnaire -eq 0 ]
#then
#	cp $DEVCONFDIR/questionnaire-A.desktop ~/.local/share/applications
#else
#	cp $DEVCONFDIR/questionnaire-B.desktop ~/.local/share/applications
#fi

## Change background
#gsettings set org.gnome.desktop.background picture-uri 'file:///devconf/background.png'

# Disable lock screen
gsettings set org.gnome.desktop.lockdown disable-lock-screen true

# Set keyboard layouts (US + CZ)
gsettings set org.gnome.desktop.input-sources sources "[('xkb', 'us'), ('xkb', 'cz+qwerty')]"

# Enable desktop icons
# gsettings set org.gnome.desktop.background show-desktop-icons true

# clang for building llvm, svn for downloading llvm repo, imake for lndir
dnf install -y ninja-build qt-creator cppcheck clang svn imake gdb

export CC_COMPILER=gcc
export CXX_COMPILER=g++
export CMAKE_CC_COMPILER=gcc
export CMAKE_CXX_COMPILER=g++
export CC=gcc
export CXX=g++

#export CC_COMPILER=clang
#export CXX_COMPILER=clang++
#export CMAKE_CC_COMPILER=clang
#export CMAKE_CXX_COMPILER=clang++
#export CC=clang
#export CXX=clang++

cd /home/vagrant
mkdir examples
mkdir llvm_toolchain

#https://llvm.org/docs/GettingStarted.html#getting-started-quickly-a-summary
svn co http://llvm.org/svn/llvm-project/llvm/trunk llvm
cd llvm/tools  # ~/llvm/tools
svn co http://llvm.org/svn/llvm-project/cfe/trunk clang
cd clang/tools  # ~/llvm/tools/clang/tools
svn co http://llvm.org/svn/llvm-project/clang-tools-extra/trunk extra
cd ../..  # ~/llvm/tools/
svn co http://llvm.org/svn/llvm-project/lld/trunk lld
svn co http://llvm.org/svn/llvm-project/polly/trunk polly
cd ../projects/  # ~/llvm/projects/
svn co http://llvm.org/svn/llvm-project/compiler-rt/trunk compiler-rt
svn co http://llvm.org/svn/llvm-project/libcxx/trunk libcxx
svn co http://llvm.org/svn/llvm-project/libcxxabi/trunk libcxxabi
cd ..  # ~/llvm/
mkdir build
cd build  # ~/llvm/build/

#Git repository version is not working, try it later?
#git clone --depth=1 https://llvm.org/git/llvm.git
#cd llvm/tools
#git clone --depth=1 https://llvm.org/git/clang.git
#git clone --depth=1 https://llvm.org/git/lld.git
#cd clang/tools/
#git clone --depth=1 https://llvm.org/git/clang-tools-extra.git extra
#cd ../../../projects/
#git clone --depth=1 https://llvm.org/git/libcxx.git
#git clone --depth=1 https://llvm.org/git/libcxxabi.git
#git clone --depth=1 https://llvm.org/git/compiler-rt.git
#cd ..
#mkdir build
#cd build

CC=$CC_COMPILER CXX=$CXX_COMPILER \
  cmake -G Ninja .. \
        -DCMAKE_C_COMPILER=$CC_COMPILER -DCMAKE_CXX_COMPILER=$CXX_COMPILER \
        -DCMAKE_BUILD_TYPE=Release -DCOMPILER_RT_INCLUDE_TESTS=OFF -DLLVM_ENABLE_ASSERTIONS=OFF \
        -DLLVM_LINK_LLVM_DYLIB=ON -DLLVM_INSTALL_UTILS=ON -DLLVM_ENABLE_RTTI=ON \
        -DCMAKE_INSTALL_PREFIX=/home/vagrant/llvm_toolchain

ninja  # make
ninja install
lndir /home/vagrant/llvm_toolchain/ /home/vagrant/

#clang-7 --version
#clang version 7.0.0 (trunk 329623)
#Target: x86_64-unknown-linux-gnu
#Thread model: posix
#InstalledDir: /home/vagrant/bin



chown -R vagrant:vagrant /home/vagrant





