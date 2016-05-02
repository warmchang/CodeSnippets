#!/usr/bin/env python
# coding=utf-8


from datetime import *
import tablib
# headers = ('area', 'user', 'recharge')
# data = [
#     ('1', 'Rooney', 20),
#     ('2', 'John', 30),
# ]
# data = tablib.Dataset(*data, headers=headers)

# 然后就可以通过下面这种方式得到各种格式的数据了。
# data.xlsx
# data.xls
# data.ods
# data.json
# data.yaml
# data.csv
# data.tsv
# data.html

# 增加行
# data.append(['3', 'Keven', 18])
# 增加列
# data.append_col([22, 20, 13], header='Age')
# print data.csv

# 删除行
# del data[1:3]
# 删除列
# del data['Age']
# print data.csv
# print data.xls
# print data.yaml

# 导出excel表
# 注意，因为excel表有二进制数据，所以必须要用二进制模式打开文件，即'wb'。
# open('xxx.yaml', 'wb').write(data.yaml)
# open('xxx.xls', 'wb').write(data.xls)

# 多个sheet的excel表
# >>book = tablib.Databook((data1, data2, data3))
# >>book.xls

# imported_data = tablib.Dataset().load(open('test_device_0.yaml').read())
# print imported_data[0]
# print imported_data.csv
# open('imported_data.xls', 'wb').write(imported_data.xls)


# uap-core-master
print ('-----------------------------------------------')
data = tablib.Dataset()
# imported_data = tablib.Dataset().load(open('test_device_1.yaml').read())
dt = datetime.now()
print ('datetime.now(): ' + str(dt.strftime('%Y-%m-%d %H:%M:%S %f')))
imported_data = data.load(open('test_device_1.yaml').read())
dt = datetime.now()
print ('datetime.now(): ' + str(dt.strftime('%Y-%m-%d %H:%M:%S %f')))
open('test_device_1.xls', 'wb').write(imported_data.xls)
dt = datetime.now()
print ('datetime.now(): ' + str(dt.strftime('%Y-%m-%d %H:%M:%S %f')))
