Private fork for my own keyboards. Removed everything I didn't use.

The latest source code for the tmk_fimrware is available here: <http://github.com/tmk/tmk_keyboard>

# Compilation
Make is needed.

### Teensy LC
Quite easy to find arm compiler and standard library for linux, (arm-none-eabi-gcc 7.2.1 worked with no problem).

I have had no luck with Windows.

### Teensy 2.0
On windows I have got it to work with avr compiler and libc from: <https://sourceforge.net/projects/mobilechessboar/files/avr-gcc%20snapshots%20%28Win32%29/>

On ubunto it have worked with the avr-gcc and avr-libc from apt-get's default repository.

# Flashing
Teensy Loader can be found here: <https://www.pjrc.com/teensy/loader.html>

# Misc
Layout json files are for: <http://www.keyboard-layout-editor.com>
