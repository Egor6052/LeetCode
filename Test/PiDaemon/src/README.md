PiDaemon

PiDaemon is a program designed to monitor the state of a GPIO pin. Based on its state, it controls the activation or deactivation of a gyroscope system.
PiDaemon — це програма для моніторингу стану GPIO-піна. Залежно від його стану здійснюється керування вмиканням або вимиканням системи гіроскопа.

<!-- Daemon Management -->

Reload Daemons
```
sudo systemctl daemon-reload
```

Restart Daemon
```
sudo systemctl restart PiDaemon.service
```

Check Daemon Status
```
sudo systemctl status PiDaemon.service
```

Disable Daemon
```
sudo systemctl disable PiDaemon.service
```

Enable Daemon
```
sudo systemctl enable PiDaemon.service
```

<!-- GPIO Configuration -->

Start pigpio Daemon
```
sudo pigpiod
```

Set GPIO26 (pin 30) to Output Mode
```
pigs m 26 1
```

Turn On GPIO26
```
pigs w 26 1
```
    or  
```
gpio -g mode 26 out
gpio -g write 26 1
```

Turn Off GPIO26
```
pigs w 26 0
```
    or  
```
gpio -g write 26 0
```