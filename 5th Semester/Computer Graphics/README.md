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
