# GLFW + GLAD Window

> [!NOTE]
> This exercise serves as a starting template for [Joey de Vries' Learn OpenGL tutorial series.](https://learnopengl.com/)

For this exercise, CMake uses locally compiled libraries for GLFW and GLAD. These dependencies are included in the exercise files, within the *dep/* directory.

> [!TIP]
> If you want/need to compile these libraries yourself, download the *Source Package* from [GLFW's Download page](https://www.glfw.org/download.html) and the generated .zip file from [GLAD's website](https://glad.dav1d.de/), and add them to the *dep/* directory.

To build this exercise, navigate to the *build/* directory and run the following commands in your terminal:

``cmake ..``

``make``

If everything works correctly, you should now see an executable file called *Window_GLFW*.
