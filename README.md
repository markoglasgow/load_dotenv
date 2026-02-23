# load_dotenv - .env Environment Variable Loader Helper for Windows

Small script and utility to load environment variables from `.env` files on Windows.

## Usage 

Copy [load_dotenv.bat](https://github.com/markoglasgow/load_dotenv/releases/) and [load_dotenv_helper.exe](https://github.com/markoglasgow/load_dotenv/releases/) to someplace in your `PATH`. Then in any directory with a `.env` file simply run:

```
load_dotenv.bat
```

The environment variables from the `.env` file will be set in your current shell. Any lines which are whitespace or have a `#` character in front will be ignored.

Equivalent of running:
```
export $(egrep -v '^#' .env | xargs)
```
... on Unix. 

## Security

Code was one-shotted with ChatGPT and hasn't been audited for security problems. Do not run this in directories you don't trust, as it is probably possible to escape the shell command and run malicious commands. 

## License

Public domain. Use at your own risk. No warranties. Author is not responsible for this code in any way and claims no ownership over it, use at your own risk. 

```
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
```