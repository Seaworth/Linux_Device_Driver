make编译`globalmem.ko`和`multi_globalmem.ko`，以及`ioctl` bin程序。

### 验证globalmem.ko

1. 加载ko

```
sudo insmod globalmem.ko
```

`lsmod`查看ko是否加载成功。查看对应的字符设备驱动，对应的主设备号为230。

```
cat /proc/devices
```

2. 创建设备节点

```
mknod /dev/globalmem c 230 0
```

3. 验证设备的读和写

```
echo "hello" > /dev/globalmem
cat /dev/globalmem
```

4. 验证ioctl接口

```
sudo ./ioctl
```



### 验证multi_globalmem.ko

1. 加载ko

```
sudo insmod multi_globalmem.ko
```

`lsmod`查看ko是否加载成功。查看对应的字符设备驱动，对应的主设备号为230。

```
cat /proc/devices
```

2. 创建设备节点，主设备号为230，次设备号分别为0和1

```
mknod /dev/globalmem0 c 230 0
mknod /dev/globalmem1 c 230 1
```

3. 验证设备的读和写

```
echo "hello globalmem0" > /dev/globalmem0
cat /dev/globalmem0
echo "hello globalmem1" > /dev/globalmem1
cat /dev/globalmem1
```



