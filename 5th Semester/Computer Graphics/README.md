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

## 1. Get FreeGLUT

Download FreeGLUT (precompiled):

- gives you:
  - `include/GL/freeglut.h`
  - `lib/freeglut.lib`
  - `bin/freeglut.dll`

## 2. Place files correctly

Assuming you use MinGW (g++):

### Headers

Copy:
`freeglut.h → C:\mingw64\include\GL\`

### Library

Copy:
`freeglut.lib → C:\mingw64\lib\`

### DLL (important)

Copy:

Either `freeglut.dll → C:\Windows\System32`

or `freeglut.dll → same folder as your .exe`

## 3. Compile and run

```powershell
g++ main.cpp -lfreeglut -lopengl32 -lglu32 -o app.exe
.\app.exe
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
