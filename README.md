# Wine Task Watcher

## Shows after finishing a Wine-Task if everything was closed as desired.


Who does not know how to start WOW (Agent.exe) or Steam PC and after closing these or parts of this task are still active.

This is of course annoying as they can take up a lot of system resources.

That's why I wrote this little tool, it allows you to start an exe task with wine or wine64 and after finishing this task you can see if everything that requires CPU load is finished.


## What is needed:
A Linux Distro with Wine and pgrep (a standard Linux tool).

## Create with:
    cd ~/Wine-Task-Watcher/src/
    qmake && make
  
## Parameters for Wine Task Watcher:
Wine-Task-Watcher [32 or 64] 'Path to the executable file'
### Example 1:
    ./Wine-Task-Watcher 32 '/home/USERNAME/.wine/dosdevices/c:/Program Files (x86)/Internet Explorer/iexplore.exe'
### Example 2:
    ./Wine-Task-Watcher 32 '/home/USERNAME/.wine/dosdevices/c:/Program Files (x86)/Windows NT/Accessories/wordpad.exe'
### Example 3:
    ./Wine-Task-Watcher 64 '/home/USERNAME/DATA-POOL/Games/World of Warcraft/Wow.exe'

### After closing the Wine task, the information window with the following information, for example, is briefly displayed. 
![Screenshot A](https://github.com/MTrage/Wine-Task-Watcher/blob/master/screenshot/close_a.png)

### If everything could be closed successfully, the info window will look like this after a few seconds.
![Screenshot B](https://github.com/MTrage/Wine-Task-Watcher/blob/master/screenshot/close_b.png)

If the task is still open, you could write a small SH script for yourself, for example, which will always be terminated if it is still active after the end of the task.

I hope that this little tool is a help for you, have fun with it.
