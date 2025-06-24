include parallella-dtb.inc
SUMMARY = "Parallella HDMI Devicetree"
COMPATIBLE_MACHINE = "parallella-hdmi"

KERNEL_DEVICETREE = "zynq-parallella.dtb"
PROVIDES += "virtual/dtb"