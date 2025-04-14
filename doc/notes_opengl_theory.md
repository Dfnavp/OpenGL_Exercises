# OpenGL 3.3+ Competence Development

## General information

This document gathers all the relevant technical and theoretical information, obtained during the competence development in computer graphics using OpenGL.

> [!NOTE]
> This documents follows the OpenGL tutorial developed by [Joey de Vries' Learn OpenGL Tutorial](https://learnopengl.com/).

### Reference Material

**Courses**:

- [Learn Modern OpenGL Programming](https://www.oreilly.com/videos/learn-modern-opengl/9781838829780/9781838829780-video1_1/) available in the O'Reilly database, through the BTH library.

**Tutorials**:

- [https://learnopengl.com/](learnopengl.com).
- [wikibooks' OpenGL_Programming](https://en.wikibooks.org/wiki/OpenGL_Programming).
- [Anton's OpenGL 4 Tutorials](https://antongerdelan.net/opengl/).

**Other useful resources**:

- [OpenGL Registry](https://registry.khronos.org/OpenGL/index_gl.php).
- [Learn C++](https://www.learncpp.com/)

### System information

All tutorials and exercises developed in, and for, Linux (Fedora 41 KDE Spin). This is the information form the system (i.e. hardware and software) used for the development of the exercises:

**Hardware** (gathered with `lshw --short`):

```bash

H/W path              Device        Class       Description
===========================================================
                                    system      Computer
/0                                  bus         Motherboard
/0/0                                memory      32GiB System memory
/0/1                                processor   AMD Ryzen 9 5950X 16-Core Processor
/0/100                              bridge      Starship/Matisse Root Complex
/0/100/0.2                          generic     Starship/Matisse IOMMU
/0/100/1.2                          bridge      Starship/Matisse GPP Bridge
/0/100/1.2/0                        bridge      Matisse Switch Upstream
/0/100/1.2/0/1                      bridge      Matisse PCIe GPP Bridge
/0/100/1.2/0/1/0      /dev/nvme0    storage     KINGSTON SFYRD2000G
/0/100/1.2/0/1/0/0    hwmon1        disk        NVMe disk
/0/100/1.2/0/1/0/2    /dev/ng0n1    disk        NVMe disk
/0/100/1.2/0/1/0/1    /dev/nvme0n1  disk        NVMe disk
/0/100/1.2/0/3                      bridge      Matisse PCIe GPP Bridge
/0/100/1.2/0/3/0      enp4s0        network     RTL8125 2.5GbE Controller
/0/100/1.2/0/5                      bridge      Matisse PCIe GPP Bridge
/0/100/1.2/0/5/0      enp5s0        network     I211 Gigabit Network Connection
/0/100/1.2/0/6                      bridge      Matisse PCIe GPP Bridge
/0/100/1.2/0/6/0      wlp6s0        network     Wi-Fi 6 AX200
/0/100/1.2/0/8                      bridge      Matisse PCIe GPP Bridge
/0/100/1.2/0/8/0                    generic     Starship/Matisse Reserved SPP
/0/100/1.2/0/8/0.1                  bus         Matisse USB 3.0 Host Controller
/0/100/1.2/0/8/0.3                  bus         Matisse USB 3.0 Host Controller
/0/100/1.2/0/9                      bridge      Matisse PCIe GPP Bridge
/0/100/1.2/0/9/0                    storage     FCH SATA Controller [AHCI mode]
/0/100/1.2/0/a                      bridge      Matisse PCIe GPP Bridge
/0/100/1.2/0/a/0                    storage     FCH SATA Controller [AHCI mode]
/0/100/3.1                          bridge      Starship/Matisse GPP Bridge
/0/100/3.1/0                        bridge      Navi 10 XL Upstream Port of PCI Express Switch
/0/100/3.1/0/0                      bridge      Navi 10 XL Downstream Port of PCI Express Switch
/0/100/3.1/0/0/0                    display     Navi 31 [Radeon RX 7900 XT/7900 XTX/7900 GRE/7900M]
/0/100/3.1/0/0/0.1    card1         multimedia  Navi 31 HDMI/DP Audio
/0/100/3.1/0/0/0.1/0  input6        input       HDA ATI HDMI HDMI/DP,pcm=3
/0/100/3.1/0/0/0.1/1  input7        input       HDA ATI HDMI HDMI/DP,pcm=7
/0/100/3.1/0/0/0.1/2  input8        input       HDA ATI HDMI HDMI/DP,pcm=8
/0/100/3.1/0/0/0.1/3  input9        input       HDA ATI HDMI HDMI/DP,pcm=9
/0/100/3.1/0/0/0.2                  bus         Navi 31 USB
/0/100/3.1/0/0/0.3                  bus         Advanced Micro Devices, Inc. [AMD/ATI]
/0/100/7.1                          bridge      Starship/Matisse Internal PCIe GPP Bridge 0 to bus[E:B]
/0/100/7.1/0                        generic     Starship/Matisse PCIe Dummy Function
/0/100/8.1                          bridge      Starship/Matisse Internal PCIe GPP Bridge 0 to bus[E:B]
/0/100/8.1/0                        generic     Starship/Matisse Reserved SPP
/0/100/8.1/0.1                      generic     Starship/Matisse Cryptographic Coprocessor PSPCPP
/0/100/8.1/0.3                      bus         Matisse USB 3.0 Host Controller
/0/100/8.1/0.4        card2         multimedia  Starship/Matisse HD Audio Controller
/0/100/8.1/0.4/0      input10       input       HD-Audio Generic Rear Mic
/0/100/8.1/0.4/1      input11       input       HD-Audio Generic Front Mic
/0/100/8.1/0.4/2      input12       input       HD-Audio Generic Line
/0/100/8.1/0.4/3      input13       input       HD-Audio Generic Line Out Front
/0/100/8.1/0.4/4      input14       input       HD-Audio Generic Line Out Surround
/0/100/8.1/0.4/5      input15       input       HD-Audio Generic Line Out CLFE
/0/100/8.1/0.4/6      input16       input       HD-Audio Generic Front Headphone
/0/100/14                           bus         FCH SMBus Controller
/0/100/14.3                         bridge      FCH LPC Bridge
/0/100/14.3/0                       system      PnP device PNP0c01
/0/100/14.3/1                       system      PnP device PNP0c02
/0/100/14.3/2                       system      PnP device PNP0b00
/0/100/14.3/3                       system      PnP device PNP0c02
/0/100/14.3/4                       system      PnP device PNP0c02
/0/101                              bridge      Starship/Matisse PCIe Dummy Host Bridge
/0/102                              bridge      Starship/Matisse PCIe Dummy Host Bridge
/0/103                              bridge      Starship/Matisse PCIe Dummy Host Bridge
/0/104                              bridge      Starship/Matisse PCIe Dummy Host Bridge
/0/105                              bridge      Starship/Matisse PCIe Dummy Host Bridge
/0/106                              bridge      Starship/Matisse PCIe Dummy Host Bridge
/0/107                              bridge      Starship/Matisse PCIe Dummy Host Bridge
/0/108                              bridge      Matisse/Vermeer Data Fabric: Device 18h; Function 0
/0/109                              bridge      Matisse/Vermeer Data Fabric: Device 18h; Function 1
/0/10a                              bridge      Matisse/Vermeer Data Fabric: Device 18h; Function 2
/0/10b                              bridge      Matisse/Vermeer Data Fabric: Device 18h; Function 3
/0/10c                              bridge      Matisse/Vermeer Data Fabric: Device 18h; Function 4
/0/10d                              bridge      Matisse/Vermeer Data Fabric: Device 18h; Function 5
/0/10e                              bridge      Matisse/Vermeer Data Fabric: Device 18h; Function 6
/0/10f                              bridge      Matisse/Vermeer Data Fabric: Device 18h; Function 7
/1                    card0         multimedia  Microphones
/2                    card3         multimedia  C930e
/3                    input0        input       Power Button
/4                    input1        input       Power Button
/5                    input17       input       MX MCHNCL Keyboard
/6                    input2        input       Generic Blue Microphones Consumer Control
/7                    input21       input       Logitech MX Master 3S
/8                    input3        input       Generic Blue Microphones
/9                    input4        input       PC Speaker
/a                    input5        input       Eee PC WMI hotkeys
```

**OpenGL Version** (gathered with `glxinfo | grep OpenGL`):

```bash
OpenGL vendor string: AMD
OpenGL renderer string: AMD Radeon RX 7900 XT (radeonsi, navi31, LLVM 19.1.0, DRM 3.59, 6.11.7-300.fc41.x86_64)
OpenGL core profile version string: 4.6 (Core Profile) Mesa 24.2.6
OpenGL core profile shading language version string: 4.60
OpenGL core profile context flags: (none)
OpenGL core profile profile mask: core profile
OpenGL core profile extensions:
OpenGL version string: 4.6 (Compatibility Profile) Mesa 24.2.6
OpenGL shading language version string: 4.60
OpenGL context flags: (none)
OpenGL profile mask: compatibility profile
OpenGL extensions:
OpenGL ES profile version string: OpenGL ES 3.2 Mesa 24.2.6
OpenGL ES profile shading language version string: OpenGL ES GLSL ES 3.20
OpenGL ES profile extensions:
```

**Development Environment**:

- OS: Fedora 41 (KDE Spin).
- IDE: Neovim + CMake.

## Learn OpenGL Tutorial - Key Ideas and Tips

> [!IMPORTANT]
> OpenGl requires key concepts from C++ programming and Linear algebra. Specifically:
> From C++ Programming: data types, functions and parameters, pointers and references, conditional statements, arrays, loops, strings, new and delete.
> From linear algebra: basic trigonometric functions, 3D vectors (dot and cross product), matrix operations.
> Make sure to have these under control!

### Section: OpenGL

- OpenGL: Graphics library written in C.
- Immediate mode: Older and deprecated pipeline of OpenGL (lots of abstraction and sub-optimized).
- Core-profile: Modern pipeline, established from version 3.2.
- The tutorial focuses on OpenGL 3.3.

- OpenGL supports the use of extensions, that are often developed by GPU manufacturers.
- Consider OpenGL as a big state machine: the way its variables are setup determine how it will behave.
- The state of OpenGL is called **Context**.
- In OpenGL there are *state-changing* functions and *state-using* functions.
- Objects: collection of options that represent a subset of OpenGL's state (i.e. a window and its parameters).

### Creating a Window

- OpenGL is a standard that just deals with graphics.
- We need to solve the creation of windows and the handling of I/O by ourselves.
- There are some *helper libraries* specialized for these tasks, that can be used together with OpenGL. Some of the most popular are: GLUT, SDL, SFML, and GLFW.

> [!NOTE]
> Most of examples and tutorials I have reviewed use either GLFW or SDL. GLFW is a lightweight library that provide a minimalistic environment for rendering graphics, and dealing with basic inputs and events. SDL is a much more robust library that provides low-level control for graphics, audio, I/O, and input devices. In my opinion, GLSW should be used when we need to just render graphics, and SDL should be used when we plan a more robust interactive application (i.e. video games).

#### Setting up GLFW and GLAD in Fedora 41

**[GLFW](https://www.glfw.org/)**

- Fedora 41 has the GLFW library under `/usr/lib64/libglfw.so.3.3`. However, it seems that it is there for other applications to refer to and use it, but not for development purposes.
- Since it is so lightweight, we can download and compile GLFW for every project that may required it. In my experience, this is the easiest way to work with GLFW in Linux.

> [!TIP]
> For more information, review the [Compiling GLFW](https://www.glfw.org/docs/latest/compile.html) official webpage.

> [!WARNING]
> For developing OpenGL applications with GLFW in Fedora, additional dependencies are required by the system. Before compiling GLFW, run the following command: `sudo dnf install wayland-devel libxkbcommon-devel libXcursor-devel libXi-devel libXinerama-devel libXrandr-devel`
> Also, Doxygen is requred by Fedora to complete the GLFW build from CMake.

**[GLAD](https://glad.dav1d.de/)**

- GLAD is an OpenGL loader (i.e. what brings the OpenGL standard into our application).
- Since the OpenGL standards and location varies between hardware manufacturers and OS, we need GLAD to help us locate and determine the specifications of the OpenGL standard that is used by the GPU.
- The GLAD files are directly downloaded from its official website (i.e. GLAD 1) and manually added to the OpenGL Project.

> [!TIP]
> I have published an [OpenGL exercise in my GitHub repository](https://github.com/Dfnavp/OpenGL_Exercises/tree/main/Create_Window/GLFW_GLAD), that shows how to correctly setup and compile GLFW and GLAD.
