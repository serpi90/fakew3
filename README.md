# FakeW3

Used to bypass around *GameRanger* limitation of not being able to launch *Warcraft III* in windowed mode.

To run *Warcraft III* in windowed mode you must pass the `-window` argument to the game, but *GameRanger* does not have an option for that. The solution was to take a program that requires no arguments, but launches the game in windowed mode.

This program attempts to read the command line to execute from a configuration file. If file is missing or there is an error reading it, then it will tttempt to use default *Warcraft III* location: `C:\Program Files (x86)\Warcraft III\Frozen Throne.exe`.

## Configuration

The configuration file **fakew3.txt** only has the command line to execute, using the full path to the game (and passing the required `-window` argument). Example:

```
"C:\Program Files (x86)\Warcraft III\Frozen Throne.exe" -window
```

Please remember to wrap the path (but not the `-window` argument) with double quotes `"`, as shown in the example.

## Additional Files

Currently *GameRanger* requres an executable file named **Frozen Throne.exe** and a file named **War3x.mpq** to be present in the same folder to allow it to be selected as *Warcraft III: Frozen Throne*. An empty file with that name currently does the trick.

I have not tested it but my guess is that for *Warcraft III: Reign of Chaos* you need an empty file named **War3.mpq**, and rename this program to **Warcraft III.exe**
