#!/usr/bin/env python
#coding=utf-8

import os, sys, plistlib, shutil

def out_fw(path,list1):
    fileList = os.listdir(path)
    for filename in fileList:
        pathTmp = os.path.join(path,filename)
        if os.path.isdir(pathTmp) and filename.find('framework')==-1:
            out_fw(pathTmp,list1)
        elif filename[-3:].upper() == '.SO':
            list1.append(pathTmp)

mulu = sys.argv[1]
begin = mulu + '_'

path = os.getcwd()
list1 = []
out_fw(path,list1)

buffer = ''
varbuffer = ''
for filepath in list1:
    spath = os.path.dirname(filepath)
    filename = os.path.basename(filepath)
    file1 = filename.split(".")[0]
    file2 = filename.split(".")[1]
    file3 = filename.split(".")[2]
    newfilename = begin + filename

    # 输出框架
    # idfa = 'com.goodclass.ClientPython.'+begin+file1
    idfa = 'ch.ada.'+begin+file1
    bName = begin+file1
    plist = {
        'CFBundleDevelopmentRegion': 'en',
        'CFBundleExecutable': newfilename,
        'CFBundleIdentifier': idfa,
        'CFBundleInfoDictionaryVersion': '6.0',
        'CFBundleName': bName,
        'CFBundlePackageType': 'FMWK',
        'CFBundleShortVersionString': '1.0',
        'CFBundleVersion': '1',
        'CFBundleSupportedPlatforms': ['iPhoneOS'],
        'MinimumOSVersion': '11.0'
    }

    fkdir = spath + '/' + begin + file1 + '.framework'
    os.mkdir(fkdir)
    plistlib.writePlist(plist,fkdir + "/Info.plist")
    shutil.move(filepath, fkdir + '/' + newfilename)
    
    # 输出方法参数
    index = filepath.find(mulu)
    so_model = filepath[index:].replace('/', '.').replace('.cpython-37m-darwin.so', '')
    varbuffer = varbuffer + "'" + so_model + "', "

    key = '__' + so_model.replace('.', '_')
    name = file1
    buffer = buffer + '[name addObject:@"' + name + '"];\t\t [key addObject:@"' + key + '"];\n'

fo = open("method.txt", "w")
fo.write(varbuffer + '\n\n')
fo.write(buffer)
fo.close()
