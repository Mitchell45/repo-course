#coding:utf-8

import hashlib

def str_md5(content):
  #计算字符串md5
  text = hashlib.md5(str(content).encode())
  return text.hexdigest()
