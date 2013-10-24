from distutils.core import setup, Extension

guillotine_interop = Extension("guillotine_interop",
                               extra_compile_args=["--std=c++11"],
                               sources=["guillotine_interop.cpp",
                                        "layout1d.cpp",
                                        "layout2d.cpp",
                                        "result.cpp",
                                        "results_generator.cpp",
                                        "types.cpp"])
#guillotine_interop = ("guillotine_interop",
#        {'extra_compile_args': ["--std=c++11"],
#            'sources': ["guillotine_interop.cpp",
#                                        "layout1d.cpp",
#                                        "layout2d.cpp",
#                                        "result.cpp",
#                                        "results_generator.cpp",
#                                        "types.cpp"]})


setup(name="guillotineopt",
      version="0.1",
      description="test",
      #libraries=[guillotine_interop],
      ext_modules=[guillotine_interop],
      py_modules=['guillotineopt'],
      url="https://github.com/denisenkom/raskroy",
      author="Mikhail Denisenko",
      author_email="denisenkom@gmai.com")
