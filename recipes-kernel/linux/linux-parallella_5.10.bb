include linux-parallella.inc

LINUX_VERSION = "5.10"
KBRANCH = "y2024.2"
SRCREV = "c7f4a685860d78195fb5006f1d2d6f538d238bf2"
SRC_URI = "git://github.com/peteasa/parallella-linux.git;protocol=https;branch=${KBRANCH}"

# see https://lore.kernel.org/linux-arm-kernel/20211018140735.3714254-1-arnd@kernel.org/
FILESEXTRAPATHS:prepend := "${THISDIR}/linux-parallella/5.10:"
SRC_URI:append = " \
    file://0001-drop_cc_option.patch \
    "

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}/${LINUX_VERSION}:"

KBUILD_DEFCONFIG = "parallella_defconfig"

KERNEL_DEVICETREE = "zynq-parallella.dtb"
KERNEL_DEVICETREE:parallella = "zynq-parallella-headless.dtb"
KERNEL_DEVICETREE:parallella-hdmi = "zynq-parallella.dtb"
