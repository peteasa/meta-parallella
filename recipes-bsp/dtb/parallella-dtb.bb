include parallella-dtb.inc
SUMMARY = "Parallella Headless Devicetree"
COMPATIBLE_MACHINE = "parallella"

KERNEL_DEVICETREE = "zynq-parallella-headless.dtb"
PROVIDES += "virtual/dtb"