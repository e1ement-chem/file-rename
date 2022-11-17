# 右键菜单添加一键更改后缀名 （注册表实现）支持所有文件后缀转 txt bat 7z zip 等格式（其它后缀可按需添加）
---
## 效果图

![img](https://github.com/114514huster/file-rename/blob/main/imgs/show.png)
## gif
![img](https://github.com/114514huster/file-rename/blob/main/imgs/display.gif)
---
## How to Run
```
1.下载“更改文件后缀 - 20.44.52.reg”文件
```
```
2.下载“更改文件后缀.exe”文件
```
```
3.将exe文件放在一个稳定不会更改的目录下(最好是自己配置的环境文件目录)
```
```
4.将注册表中所有的“@="D:\\Dsystem\\environment\\更改文件后缀.exe \"%1%\" bat"”中的
路径 D:\\Dsystem\\environment\\更改文件后缀.exe 换成自己存放exe的路径
```
```
5.双击运行reg配置文件，进行注册表的写入
```

## 实现原理
- 修改注册表，在右键文件时菜单中添加一个二级菜单
注册表配置文件如下：
```reg
  Windows Registry Editor Version 5.00

  [HKEY_CLASSES_ROOT\*\shell\Item0]
  "MUIVerb"="更改文件后缀"
  "SubCommands"=""
  "Icon"="imageres.dll,242"

  [HKEY_CLASSES_ROOT\*\shell\Item0\shell]

  [HKEY_CLASSES_ROOT\*\shell\Item0\shell\Item0]
  "MUIVerb"="txt"

  [HKEY_CLASSES_ROOT\*\shell\Item0\shell\Item0\command]
  @="D:\\Dsystem\\environment\\更改文件后缀.exe \"%1%\" txt"

  [HKEY_CLASSES_ROOT\*\shell\Item0\shell\Item1]
  "MUIVerb"="bat"

  [HKEY_CLASSES_ROOT\*\shell\Item0\shell\Item1\command]
  @="D:\\Dsystem\\environment\\更改文件后缀.exe \"%1%\" bat"

  [HKEY_CLASSES_ROOT\*\shell\Item0\shell\Item2]
  "CommandFlags"=dword:00000008

  [HKEY_CLASSES_ROOT\*\shell\Item0\shell\Item3]
  "MUIVerb"="zip"

  [HKEY_CLASSES_ROOT\*\shell\Item0\shell\Item3\command]
  @="D:\\Dsystem\\environment\\更改文件后缀.exe \"%1%\" zip"

  [HKEY_CLASSES_ROOT\*\shell\Item0\shell\Item4]
  "MUIVerb"="rar"

  [HKEY_CLASSES_ROOT\*\shell\Item0\shell\Item4\command]
  @="D:\\Dsystem\\environment\\更改文件后缀.exe \"%1%\" rar"

  [HKEY_CLASSES_ROOT\*\shell\Item0\shell\Item40]
  "MUIVerb"="7z"

  [HKEY_CLASSES_ROOT\*\shell\Item0\shell\Item40\command]
  @="D:\\Dsystem\\environment\\更改文件后缀.exe \"%1%\" 7z"

```
- 修改文件实现(C++)
源码文件为“更改文件后缀.cpp”
