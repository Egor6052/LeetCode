Найпоширеніший інструмент для крос-компіляції для Windows CE — це MinGW (Minimalist GNU for Windows), хоча для Windows CE також існують інші специфічні компілятори, наприклад ARM toolchain або Windows CE SDK. 

```
sudo apt-get install mingw-w64
```
```
sudo apt-get install gcc-arm-linux-gnueabihf
```
##Або стандартний крос-компілятор:
```
sudo apt-get install gcc-arm-none-eabi
```
##Для 32-бітної версії Windows CE:
```
x86_64-w64-mingw32-gcc -o my_program.exe my_program.c
```

##Якщо вам потрібно компілювати під ARM-архітектуру для Windows CE:
```
armv7a-none-eabi-gcc -o my_program.exe my_program.c
```

##Після налаштування компілятора, ви можете скомпілювати ваш C-код для ARM-платформи.
```
arm-linux-gnueabihf-gcc -o my_program.exe my_program.c
```

