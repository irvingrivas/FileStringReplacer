# FileStringReplacer

This executable replaces every string in a UTF-8 encoded text file with another. This is not SED and is a far inferior version of it, but was fun to do in C.

Here are some specifications
* File Size Limit of One MB
* Requires UTF-8 encoded file
* Works on hard and soft links
* Performs buffered manipulation as opposed to streamed (sed)

To build this, do the following on a Linux/MacOS terminal or Windows Command Prompt (hopefully with bash installed):
```sh
git clone "https://github.com/irvingrivas/FileStringReplacer"
cd FileStringReplacer
cmake .
make
```

To run the executable, do the following as an example
```sh
./stringreplace tmp.txt lorem quorum
```

This executable is a toy-version of sed and the below should do the same thing as the above for inputs within specs:
```sh
sed -i 's/lorem/quorum' tmp.txt
```
