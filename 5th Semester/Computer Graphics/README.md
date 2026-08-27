# Computer Graphics

## Table of Contents
| Lab No. | Title | Link |
|---------|-------|------|
| 1 | Write a program to implement DDA Line Drawing Algorithm | [Lab 1](lab-1.cpp) |
| 2 | Write a program to implement Bresenham’s Line Drawing Algorithm | [Lab 2](lab-2.cpp) |
| 3 | Write a program to implement mid-point circle drawing algorithm | [Lab 3](lab-3.cpp) |
| 4 | Write a program to implement mid-point ellipse drawing algorithm | [Lab 4](lab-4.cpp) |
| 5 | Write a program to implement boundary fill algorithm | [Lab 5](lab-5.cpp) |
| 6 | Write a program to implement flood fill algorithm | [Lab 6](lab-6.cpp) |
| 7 | Write a program to implement 2D transformation on an object | [Lab 7](lab-7.cpp) |
| 8 | Write a program to implement Cohen-Sutherland Line Clipping Algorithm | [Lab 8](lab-8.cpp) |

---

# Install OpenGL and FreeGLUT

# Windows (MinGW)

1. Download [FreeGLUT (precompiled)](https://www.songho.ca/opengl/gl_freeglut.html) OR [Direct zip link](https://www.songho.ca/opengl/files/freeglut-mingw-3.8.0.zip)
2. Download the .zip archive provided under **Freeglut Binary for MinGW (g++)**
3. Inside `freeglut` includes:
   - `include/GL/` contains your header files.
   - `lib/` contains the 32-bit files (libfreeglut.dll.a, libfreeglut_static.a).
   - `bin/libfreeglut.dll` Shared dynamic link libraries (DLLs)
4. Go inside `freeglut` and **copy** `include/`, `lib/`, and `bin/`
5. **Paste** in `C:/MinGW/`
6. **Compile** and **Run**:
   ```powershell
   g++ main.cpp -o main.exe -lfreeglut -lglu32 -lopengl32
   ./main.exe
   ```
---

# Linux (Arch)

## 1. Install required packages

```bash
sudo pacman -S freeglut mesa mesa-utils
```

## 2. Compile and run

```bash
g++ lab-1.cpp -lglut -lGLU -lGL -o lab-1 && ./lab-1
```
