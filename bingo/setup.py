from distutils.core import setup, Extension

module1 = Extension('bingoc',
                    sources = ['bingocmodule.c'])

setup (name = 'bingo',
       version = '1.0',
       description = 'This is a bingo package',
       ext_modules = [module1])
