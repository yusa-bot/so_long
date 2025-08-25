FROM ubuntu:22.04

# 基本ツール & Valgrind & X11関係
RUN apt-get update && apt-get install -y \
    build-essential git cmake valgrind gdb \
    libx11-dev libxext-dev libxrandr-dev xorg \
    && rm -rf /var/lib/apt/lists/*

# ユーザー追加（sudo権限付き）
RUN useradd -m vscode && echo "vscode ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
USER vscode
WORKDIR /work
