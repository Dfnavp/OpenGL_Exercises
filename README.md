# OpenGL Exercises

This repository contains multiple OpenGL exercises, that were developed for personal reference and/or educational purposes.
All these exercises were developed in **Linux (Fedora 41 KDE Spin)**, using **Neovim** and **CMake**.

## Contents

### Create_Window

This exercises show how to initialize an OpenGL window using SDL+GLEW or GLFW+glad.

- For the **SDL+GLEW window exercise**, CMake makes use of the packages installed in the system. In case of not having these packages previously installed in your system, run the following command to install them:
  ``sudo dnf install glew-devel SDL2-devel SDL2_image-devel glm-devel freetype-devel``
- For the **GLFW+GLAD window exercise**, CMake makes use of libraries that were locally compiled. For this, you will need to download the *Source Package* from [GLFW's Download page](https://www.glfw.org/download.html), and the generated .zip file from [GLAD's website](https://glad.dav1d.de/).
