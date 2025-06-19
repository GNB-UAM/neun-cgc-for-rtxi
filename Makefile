PLUGIN_NAME = neun_cgc_for_rtxi

HEADERS = neun-cgc-for-rtxi.h

SOURCES = neun-cgc-for-rtxi.cpp\
          moc_neun-cgc-for-rtxi.cpp\
        #   input_parser.cpp 

CXXFLAGS += -I/usr/local/Neun/0.3.2/
# LDLIBS += -lyaml-cpp
### Do not edit below this line ###

include $(shell rtxi_plugin_config --pkgdata-dir)/Makefile.plugin_compile
